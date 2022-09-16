/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 16/09/2022
 *
 *************************************************************************/

#pragma once

#include <memory>

template<typename Engine>
class Car
{
public:
    Car(std::shared_ptr<Engine> engine) : engine_{std::move(engine)} {
        if (!engine_)
            throw std::invalid_argument("engine argument is nullptr");
    }

    inline auto start() { return engine_->start(); }
    inline auto stop() { engine_->stop(); }

private:
    std::shared_ptr<Engine> engine_;
};
