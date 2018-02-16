/*
 *
 *  Created on: July 23, 2015
 *      Author: Daniella Niyonkuru
 */

#ifndef PORTS_IMPL_HPP
#define PORTS_IMPL_HPP


extern "C" {
    void setLed_1();
    void setLed_2();
    void setLed_8();
    void time_loop();

    void motorsSetRatio(uint32_t id, uint16_t ithrust);
}

extern int ali_count;
extern int devs_activation_count[4];

#include <motors.h>

#include <ecdboost/simulation.hpp>

#include "ports/input_ports.hpp"
#include "ports/output_ports.hpp"


using namespace std;
using namespace ecdboost::simulation;
using namespace ecdboost::simulation::pdevs;

using Value = int;

/* INPUT PORTS DRIVERS */
template<class TIME, class MSG>
bool CmdInputPort<TIME, MSG>::pDriver(Value &v) const noexcept {
    v = ali_count;
    ali_count = (ali_count + 1) % 4;

    return true;
}

template<class TIME, class MSG>
bool MotionSensorPort<TIME, MSG>::pDriver(Value &v) const noexcept {
    return true;
}

/* OUTPUT PORTS DRIVERS */
template<class TIME, class MSG>
bool MotorPort<TIME, MSG>::pDriver(Value& v) const noexcept {
    uint16_t val = 0;
    int selected_motor = v;

    if (motor_num == 0) {
        if (selected_motor == 0) { setLed_2(); }
        if (selected_motor == 1) { setLed_8(); }
    }

    if (motor_num != selected_motor) {
        switch (motor_num) {
            case 0:
                val = 12000;
                break;
            case 1:
                val = 27000;
                break;
            case 2:
                val = 47000;
                break;
            case 3:
                val = 60000;
                break;
        }
    }

    motorsSetRatio(motor_num, val);

    return true;
}

#endif /* PORTS_IMPL_HPP */
