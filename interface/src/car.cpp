/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 14/09/2022
 *
 *************************************************************************/

#include "car.h"

Car::Car(std::shared_ptr<IEngine> engine) : engine_{move(engine)} {}

bool Car::start()
{
    return engine_->start();
}
