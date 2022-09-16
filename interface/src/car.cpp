/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 14/09/2022
 *
 *************************************************************************/

#include "car.h"

using namespace std;

Car::Car(shared_ptr<IEngine> engine) : engine_{move(engine)}
{
    if (!engine_)
        throw invalid_argument("engine argument is nullptr");
}

bool Car::start()
{
    return engine_->start();
}

void Car::stop()
{
    engine_->stop();
}
