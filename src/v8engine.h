/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 06/08/2022
 *
 *************************************************************************/

#pragma once

#include <string>

class V8Engine
{
public:
    bool start();
    void stop();
    bool isRunning() const;

private:
    bool isRunning_ = false;
};
