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
    led_blocking_assert(5000 < thrust && thrust <= 62000);

    motorsSetRatio(motor_num, (uint16_t) thrust);
    return true;
  }
};

