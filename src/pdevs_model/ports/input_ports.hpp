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

using Value = int;

template<class TIME, class MSG>
class MotionSensorPort: public port<TIME, MSG> {
    public:
        explicit MotionSensorPort(const std::string &name, const TIME &polling) noexcept
            : port<TIME, MSG>(name, polling) { }

        void print() noexcept {}
        bool pDriver(Value &v) const noexcept;
};


template<class TIME, class MSG>
class CmdInputPort: public port<TIME, MSG> {
    public:
        explicit CmdInputPort(const std::string &name, const TIME &polling) noexcept
            : port<TIME, MSG>(name, polling) { }

        void print() noexcept {}
        bool pDriver(Value &v) const noexcept;

    private:
        mutable int interaction_counter;
};


#endif /* INPUT_PORTS_HPP */

