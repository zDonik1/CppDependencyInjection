/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 10/09/2022
 *
 *************************************************************************/

#pragma once

class V8Engine
{
public:
    bool start();
    void stop();
    bool isRunning();

private:
    bool isRunning_{false};
};
