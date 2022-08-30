/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 06/08/2022
 *
 *************************************************************************/

#include "v8engine.h"

using namespace std;

bool V8Engine::start()
{
    isRunning_ = true;
    return true;
}

bool V8Engine::isRunning() const
{
    return isRunning_;
}
