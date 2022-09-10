/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 10/09/2022
 *
 *************************************************************************/

#pragma once

#include <memory>

#include "engine.h"

template<typename ConcreteEngine>
class Car
{
public:
    Car(std::shared_ptr<Engine<ConcreteEngine>> engine) : engine_{engine} {}

    inline auto start() { return engine_->start(); }

private:
    std::shared_ptr<Engine<ConcreteEngine>> engine_;
};
