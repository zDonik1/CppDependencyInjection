/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 10/09/2022
 *
 *************************************************************************/

#pragma once

#include "engine.h"

class V8Engine : public Engine<V8Engine>
{
public:
    bool start();
    void stop();
    bool isRunning() const;

private:
    bool isRunning_{false};
};
