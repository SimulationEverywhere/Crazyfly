#include <ecdboost/simulation.hpp>

using namespace std;
using namespace ecdboost::simulation;
using namespace ecdboost::simulation::pdevs;

using Value = int;

extern "C" {
  void led_blocking_assert(bool);
  void motorsSetRatio(uint32_t id, uint16_t ithrust);
}

template<class TIME, class MSG>
class MotorPort: public port<TIME, MSG> {

public:
  const int motor_num;

  explicit MotorPort(const std::string &name, const int& _motor_num) noexcept :
    port<TIME, MSG>(name),
    motor_num(_motor_num) { }

  void print() noexcept {}

  bool pDriver(Value &thrust) const noexcept {
    if (!(0 <= thrust && thrust <= 62000)){
      set_led_GL();
      time_loop();
      set_led_GR();
      time_loop();
    }

    led_blocking_assert(0 <= thrust && thrust <= 62000);

    motorsSetRatio(motor_num, (uint16_t) thrust);
    return true;
  }
};

