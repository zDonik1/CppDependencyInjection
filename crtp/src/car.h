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
    Car(std::shared_ptr<Engine<ConcreteEngine>> engine) : engine_{std::move(engine)}
    {
        if (!engine_)
            throw std::invalid_argument("engine argument is nullptr");
    }

    inline auto start() { return engine_->start(); }
    inline auto stop() { return engine_->stop(); }

private:
    std::shared_ptr<Engine<ConcreteEngine>> engine_;
};
