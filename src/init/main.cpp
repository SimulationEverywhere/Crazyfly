// PDEVS
#include <ecdboost/simulation.hpp>
#include <ecdboost/utilities/embedded_time.hpp>
#include <ecdboost/utilities/embedded_message.hpp>

#include "CF2_timer.hpp"
#include "atomic_models/motor.hpp"
#include "atomic_models/open_loop_controller.hpp"
#include "ports/command_input_port.hpp"
#include "ports/motor_port.hpp"

using namespace std;
using namespace ecdboost;

using Time = EmbeddedTime<CF2Timer>;
using Message = EmbeddedMessage<Time, int>;

extern "C" {
  void set_led_GR();
  void set_led_GL();
  void set_led_RR();
  void time_loop();

  void ledInit();
  void powerDistributionInit();
  void pmInit();

  void motorsSetRatio(uint32_t id, uint16_t ithrust);
}

void open_loop_model(Time until) {
  auto open_loop = make_atomic_ptr<OpenLoopController<Time, Message>>();

  shared_ptr<flattened_coupled<Time, Message>> ControlUnit( new flattened_coupled<Time, Message>{{open_loop}, {open_loop}, {}, {open_loop}});

  auto motor_1 = make_port_ptr< MotorPort< Time, Message >, const string &, const int& >("motor_1", 0);
  auto motor_2 = make_port_ptr< MotorPort< Time, Message >, const string &, const int& >("motor_2", 1);
  auto motor_3 = make_port_ptr< MotorPort< Time, Message >, const string &, const int& >("motor_3", 2);
  auto motor_4 = make_port_ptr< MotorPort< Time, Message >, const string &, const int& >("motor_4", 3);

  erunner<Time, Message> root{
    ControlUnit,
    {  },
    { {motor_1, open_loop}, {motor_2, open_loop}, {motor_3, open_loop}, {motor_4, open_loop} }
  };

  root.runUntil(until);
}

void basic_model(Time until) {
  // Atomic models definition
  auto motorDEVS = make_atomic_ptr<MotorDEVS<Time, Message>>();

  //Coupled model definition
  shared_ptr<flattened_coupled<Time, Message>> ControlUnit( new flattened_coupled<Time, Message>{{motorDEVS}, {motorDEVS}, {}, {motorDEVS}});

  //Top I/O port definition
  // Input ports
  auto cmd_in = make_port_ptr< CommandInputPort< Time, Message >, const string &, const Time & >("port_cmd_input", Time(0,0,1,0));

  // Output ports
  auto motor_1 = make_port_ptr< MotorPort< Time, Message >, const string &, const int& >("port_motor1", 0);
  auto motor_2 = make_port_ptr< MotorPort< Time, Message >, const string &, const int& >("port_motor2", 1);
  auto motor_3 = make_port_ptr< MotorPort< Time, Message >, const string &, const int& >("port_motor3", 2);
  auto motor_4 = make_port_ptr< MotorPort< Time, Message >, const string &, const int& >("port_motor4", 3);

  // Execution parameter definition
  erunner<Time, Message> root{
    ControlUnit,
    { {cmd_in,motorDEVS} },
    { {motor_1,motorDEVS}, {motor_2,motorDEVS}, {motor_3,motorDEVS}, {motor_4,motorDEVS} }
  };

  root.runUntil(until);
}

void setMotors(uint16_t thrust) {
  for (int i = 0; i < 4; i++) { motorsSetRatio(i, thrust); };
  Time ts = Time::currentTime();
  while ((Time::currentTime() - ts) < Time(0,0,2,0)) {}
}

void use_motors() {
  set_led_RR();
  setMotors(0);

  set_led_GR();
  setMotors(5000);

  set_led_RR();
  setMotors(20000);

  set_led_GR();
  setMotors(40000);

  set_led_RR();
  setMotors(20000);

  set_led_GR();
  setMotors(5000);

  set_led_RR();
  setMotors(0);
}

int main(){
  ledInit();
  pmInit();
  powerDistributionInit();
  
  //open_loop_model(Time(0,0,15,0));
  basic_model(Time(0,0,15,0));
  //use_motors();

  do {
    set_led_GR();
    time_loop();
    set_led_GL();
    time_loop();
  } while (true);

  return 0;
}

