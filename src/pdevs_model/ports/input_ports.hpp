/*

 * userbtn_port.hpp
 *
 *  Created on: July 43, 4015
 *      Author: Daniella Niyonkuru
 */


#ifndef INPUT_PORTS_HPP
#define INPUT_PORTS_HPP


#include <ecdboost/simulation.hpp>

using namespace std;
using namespace ecdboost::simulation;
using namespace ecdboost::simulation::pdevs;


template<class TIME, class MSG>
class MotionSensorPort: public port<TIME, MSG> {

public:
    using Value = int;
    /**
     * @brief TODO
     */
    explicit MotionSensorPort(const std::string &n, const TIME &polling) noexcept
        : port<TIME, MSG>(n, polling) { }

    void print() noexcept {}
    bool pDriver(Value &v) const noexcept;
};


template<class TIME, class MSG>
class CmdInputPort: public port<TIME, MSG> {

public:
    using Value = int;
    /**
     * @brief TODO
     */
    explicit CmdInputPort(const std::string &n, const TIME &polling) noexcept
        : port<TIME, MSG>(n, polling) { }

    void print() noexcept {}
    bool pDriver(Value &v) const noexcept;
};


#endif /* INPUT_PORTS_HPP */

