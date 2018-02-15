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

#include <motors.h>

#include <ecdboost/simulation.hpp>

#include "ports/input_ports.hpp"
#include "ports/output_ports.hpp"


using namespace std;
using namespace ecdboost::simulation;
using namespace ecdboost::simulation::pdevs;

using Value = int;

extern int ali_count;

/* INPUT PORTS DRIVERS */
template<class TIME, class MSG>
bool CmdInputPort<TIME, MSG>::pDriver(Value &v) const noexcept {
    if (ali_count < 10) {
        ali_count++;
    } else {
        ali_count = 0;
    }

    v = (Value) ali_count * 20;

    setLed_2();
    time_loop();
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
    //if (motor_num == 1) { val = (uint16_t)(0.99*(1<<16)); }
    if (motor_num == 0) { val = 50; }
    if (motor_num == 1) { val = 500; }
    if (motor_num == 2) { val = 5000; }
    if (motor_num == 3) { val = 50000; }

    motorsSetRatio(motor_num, val);

    return true;
}

#endif /* PORTS_IMPL_HPP */
