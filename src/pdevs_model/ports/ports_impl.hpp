/*
 *
 *  Created on: July 23, 2015
 *      Author: Daniella Niyonkuru
 */

#ifndef PORTS_IMPL_HPP
#define PORTS_IMPL_HPP


extern "C" {
    void setLed_Switch();

    void setLed_ON();
    void setLed_OFF();

    void setLed_Amb();
    void time_loop();

    //void motorsSetRatio(int id, uint16_t ratio);
    void motorsSetRatio(uint32_t id, uint16_t ithrust);
}

#include <led.h>
#include <motors.h>

#include <ecdboost/simulation.hpp>

#include "ports/input_ports.hpp"
#include "ports/output_ports.hpp"


using namespace std;
using namespace ecdboost::simulation;
using namespace ecdboost::simulation::pdevs;

using Value = int;

extern bool ledOn;
extern int ali_count;
extern int values[];


/* INPUT PORTS DRIVERS */
template<class TIME, class MSG>
bool CmdInputPort<TIME, MSG>::pDriver(Value &v) const noexcept {
    v = 0;
    if (ali_count < 7) {
        v = values[ali_count++];
    }
    return true;
}

template<class TIME, class MSG>
bool MotionSensorPort<TIME, MSG>::pDriver(Value &v) const noexcept {
    return true;
}

/* OUTPUT PORTS DRIVERS */
template<class TIME, class MSG>
bool MotorPort<TIME, MSG>::pDriver(Value& v) const noexcept {
    motorsSetRatio(motor_num, v);
    return true;
}

#endif /* PORTS_IMPL_HPP */
