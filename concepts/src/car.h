/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 30/08/2022
 *
 *************************************************************************/

#include <memory>

#include "engine.h"

template<Engine EngineType>
class Car
{
private:
    using EnginePtr = std::shared_ptr<EngineType>;

public:
    Car(EnginePtr engine) : engine_{std::move(engine)}
    {
        if (!engine_)
            throw std::invalid_argument("engine argument is nullptr");
    }

    inline auto start() { return engine_->start(); }
    inline auto stop() { engine_->stop(); }

private:
    EnginePtr engine_;
};
