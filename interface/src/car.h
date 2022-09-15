/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 14/09/2022
 *
 *************************************************************************/

#pragma once

#include <memory>

#include "iengine.h"

class Car
{
public:
    Car(std::shared_ptr<IEngine> engine);

    void start();

private:
    std::shared_ptr<IEngine> engine_;
};
