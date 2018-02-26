#ifndef OPEN_LOOP_CONTROLLER__HPP
#define OPEN_LOOP_CONTROLLER__HPP

#include <ecdboost/simulation.hpp>

using namespace std;
using namespace ecdboost;

enum stage { waiting, starting, taking_off, flying, landing, stopped };

extern "C" {
  void set_led_GR();
  void set_led_RR();
  void set_led_GL();
  void time_loop();

  void led_blocking_assert(bool condition);
}

template<class TIME, class MSG>
class OpenLoopController : public ecdboost::atomic<TIME, MSG> {
  private:
    mutable int thrust;
    mutable stage current_stage;
    TIME next_internal;

  public:
    explicit OpenLoopController() noexcept :
      atomic<TIME, MSG>("OpenLoopController"),
      thrust(0) {
      next_internal = TIME(0,0,1,0);
      current_stage = stage::waiting;
    }

    // Not working, wrong model
    // ta ends --> out executes --> internal executes

    void internal() noexcept {
      switch (current_stage) {
        case stage::waiting:
          current_stage = stage::starting;
          thrust = 20000;
          next_internal = TIME(0,0,5,0);
          break;
        case stage::starting: 
          current_stage = stage::taking_off;
          thrust = 35000;
          next_internal = TIME(0,0,0,4);
          break;
        case stage::taking_off:
          current_stage = stage::landing; // should go to stage::flying
          thrust = 20000;
          next_internal = TIME(0,0,5,0);
          break;
        case stage::landing:
          current_stage = stage::stopped;
          thrust = 0;
          next_internal = TIME::Infinity;
          break;
        default:
          led_blocking_assert(false);

      }
    }

    TIME advance() const noexcept { return next_internal; }

    vector<MSG> out() const noexcept {
      vector<MSG> output;
      MSG output_m1("motor_1", thrust),
          output_m2("motor_2", thrust),
          output_m3("motor_3", thrust),
          output_m4("motor_4", thrust);

      output.push_back(output_m1);
      output.push_back(output_m2);
      output.push_back(output_m3);
      output.push_back(output_m4);

      return output;
    }

    void external(const std::vector<MSG>& mb, const TIME& t) noexcept {
      // Should never happen
      set_led_GL();
      time_loop();
      led_blocking_assert(false);
    }

    virtual void confluence(const std::vector<MSG>& mb, const TIME& t) noexcept {
      internal();
    }

    void print() noexcept {}

};

#endif // OPEN_LOOP_CONTROLLER__HPP
