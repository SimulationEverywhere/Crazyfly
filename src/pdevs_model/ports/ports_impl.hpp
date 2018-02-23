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
    v = interaction_counter;
    interaction_counter = (interaction_counter + 1) % 4;

    if (interaction_counter == 1) setLed_2();
    else setLed_8();

    return true;
}

template<class TIME, class MSG>
bool MotionSensorPort<TIME, MSG>::pDriver(Value &v) const noexcept {
    return true;
}

/* OUTPUT PORTS DRIVERS */
template<class TIME, class MSG>
bool MotorPort<TIME, MSG>::pDriver(Value& v) const noexcept {
    int selected_motor = v;

    uint16_t val = 40000;
    //if (motor_num != selected_motor) val = 25000;

    motorsSetRatio(motor_num, val);

    return true;
}

#endif /* PORTS_IMPL_HPP */
