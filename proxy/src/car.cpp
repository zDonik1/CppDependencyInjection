/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 16/09/2022
 *
 *************************************************************************/

#include "car.h"

using namespace std;
using namespace pro;

Car::Car(proxy<FEngine> engine) : engine_{move(engine)} {}

bool Car::start()
{
    return engine_.invoke<Start>();
}
