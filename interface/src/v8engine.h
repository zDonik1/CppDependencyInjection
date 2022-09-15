/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 06/08/2022
 *
 *************************************************************************/

#pragma once

#include "iengine.h"

class V8Engine : public IEngine
{
public:
    bool start() override;
    void stop() override;
    bool isRunning() const override;

private:
    bool isRunning_{false};
};
