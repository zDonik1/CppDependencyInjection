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
    void stop();

private:
    pro::proxy<FEngine> engine_;
};
