/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 15/09/2022
 *
 *************************************************************************/

#pragma once

class IEngine
{
public:
    virtual ~IEngine() = default;

    virtual bool start() = 0;
};
