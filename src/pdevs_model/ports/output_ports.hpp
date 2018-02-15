/*
 * motors_port.hpp
 *
 *  Created on: July 23, 2015
 *      Author: Daniella Niyonkuru
 */

#ifndef OUTPUT_PORTS_HPP
#define OUTPUT_PORTS_HPP

#include <ecdboost/simulation.hpp>

using namespace std;
using namespace ecdboost::simulation;
using namespace ecdboost::simulation::pdevs;

//extern "C" {
    ////void motorsInit();
    //void powerDistributionInit();
//}

template<class TIME, class MSG>
class MotorPort: public port<TIME, MSG> {

public:

    using Value = int;

    int motor_num;

    /**
     * @brief motor1_port constructor.
     *
     * @param n name assigned to the port
     */
    explicit MotorPort(const int& _motor_num, const std::string &n) noexcept
        : port<TIME, MSG>(n), motor_num(_motor_num) {
        // motorsInit();
    }

    void print() noexcept {}
    bool pDriver(Value &v) const noexcept;
};

#endif /* OUTPUT_PORTS_HPP */

