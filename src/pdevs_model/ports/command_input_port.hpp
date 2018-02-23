#include <ecdboost/simulation.hpp>

using namespace std;
using namespace ecdboost::simulation;
using namespace ecdboost::simulation::pdevs;

extern "C" {
  void set_led_GR();
  void set_led_RR();
}
using Value = int;

template<class TIME, class MSG>
class CommandInputPort: public port<TIME, MSG> {
  public:
    explicit CommandInputPort(const std::string &name, const TIME &polling) noexcept
      : port<TIME, MSG>(name, polling) { }

    void print() noexcept {}
    bool pDriver(Value &v) const noexcept {
      v = interaction_counter;
      interaction_counter = (interaction_counter + 1) % 4;

      if (interaction_counter == 1) set_led_GR();
      else set_led_RR();

      return true;
    }

  private:
    mutable int interaction_counter;
};

