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

extern "C" {
void motorsInit();
}

enum MotorEnum {
    MOTOR_1, MOTOR_2, MOTOR_3, MOTOR_4
};

//std::vector<std::string> MotorPortName { "port_motor1", "port_motor2", "port_motor3", "port_motor4" };


template<class TIME, class MSG>
class MotorPort: public port<TIME, MSG> {

public:

//    using Value = Datagram;
	using Value = int;

    int motor_num;

    /**
     * @brief motor1_port constructor.
     *
     * @param n name assigned to the port
     */
//    explicit MotorPort(const int & _motor_num) noexcept
//            : port<TIME, MSG>(MotorPortName.at(_motor_num)),
//              motor_num(_motor_num)
	explicit MotorPort(const int& _motor_num, const std::string &n) noexcept
			: port<TIME, MSG>(n), motor_num(_motor_num)
    {  }

    void print() noexcept {} //printf("MOTOR 1 \n");
    bool pDriver(Value &v) const noexcept;
};

#endif /* OUTPUT_PORTS_HPP */
