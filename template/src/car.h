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
    Car(std::shared_ptr<Engine> engine) : engine_{std::move(engine)} {}

    inline auto start() { return engine_->start(); }

private:
    std::shared_ptr<Engine> engine_;
};
