/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 06/08/2022
 *
 *************************************************************************/

#include "v8engine.h"

bool V8Engine::start()
{
    isRunning_ = true;
    return true;
}

void V8Engine::stop()
{
    isRunning_ = false;
}

bool V8Engine::isRunning() const
{
    return isRunning_;
}
