/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 16/09/2022
 *
 *************************************************************************/

#include "car.h"

#include <stdexcept>

using namespace std;
using namespace pro;

Car::Car(proxy<FEngine> engine) : engine_{move(engine)}
{
    if (!engine_.has_value())
        throw invalid_argument("engine argument is nullptr");
}

bool Car::start()
{
    return engine_.invoke<Start>();
}

void Car::stop()
{
    engine_.invoke<Stop>();
}
