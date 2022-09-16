/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 16/09/2022
 *
 *************************************************************************/

#pragma once

#include "fengine.h"

class Car
{
public:
    Car(pro::proxy<FEngine> engine);

    bool start();

private:
    pro::proxy<FEngine> engine_;
};
