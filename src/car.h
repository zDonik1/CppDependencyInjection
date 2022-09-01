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
    Car(EnginePtr engine) : engine_{engine} {}

    bool start() { return engine_->start(); }

private:
    EnginePtr engine_;
};
