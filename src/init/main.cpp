// PDEVS
#include <ecdboost/simulation.hpp>
#include "eTime.h"
#include "eMessage_s.hpp"
#include "atomic_models/motor.hpp"
#include "ports/ports_impl.hpp"

using namespace std;
using namespace ecdboost::simulation;
using namespace ecdboost::simulation::pdevs;
using namespace ecdboost::simulation::pdevs::basic_models;

extern "C" {
    void setLed_1();
    void setLed_2();
    void setLed_8();
    void time_loop();

    void powerDistributionInit();
    void powerStop();
    void motorsSetRatio(uint32_t id, uint16_t ithrust);
}

void create_and_run_pdevs_model(Time until) {
    // Atomic models definition
    auto motorDEVS = make_atomic_ptr<MotorDEVS<Time, Message>>();

    //Coupled model definition
    shared_ptr<flattened_coupled<Time, Message>> ControlUnit( new flattened_coupled<Time, Message>{{motorDEVS}, {motorDEVS}, {}, {motorDEVS}});

    //Top I/O port definition
    // Input ports
    // autg sensor_in = make_port_ptr< MotionSensorPort<Time, Message>, const string &, const Time & >("port_motion_sensor", Time(0,0,1,0));
    auto cmd_in = make_port_ptr< CmdInputPort<Time, Message>, const string &, const Time & >("port_cmd_input", Time(0,0,2,0));

    // Output ports
    auto motor_1 = make_port_ptr<MotorPort<Time, Message>, const int&, const string &>(0, "port_motor1");
    auto motor_2 = make_port_ptr<MotorPort<Time, Message>, const int&, const string &>(1, "port_motor2");
    auto motor_3 = make_port_ptr<MotorPort<Time, Message>, const int&, const string &>(2, "port_motor3");
    auto motor_4 = make_port_ptr<MotorPort<Time, Message>, const int&, const string &>(3, "port_motor4");

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
    for (int i = 0; i < 20; i++) { time_loop(); };
}

void use_motors() {
    powerDistributionInit();

    setLed_8();
    setMotors(0);

    setLed_2();
    setMotors(5000);

    setLed_8();
    setMotors(20000);

    setLed_2();
    setMotors(40000);

    setLed_8();
    setMotors(20000);

    setLed_2();
    setMotors(5000);

    setLed_8();
    setMotors(0);
}

int main(){
    //create_and_run_pdevs_model(Time(0,0,15,0));

    use_motors();

    do {
        setLed_2();
        time_loop();
        setLed_1();
        time_loop();
    } while (true);

    return 0;
}
