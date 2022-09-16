/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 16/09/2022
 *
 *************************************************************************/

#pragma once

#include <proxy/proxy.h>

struct Start : pro::dispatch<bool()>
{
    template<class Self>
    inline auto operator()(Self &self)
    {
        return self.start();
    }
};

struct Stop : pro::dispatch<void()>
{
    template<class Self>
    inline auto operator()(Self &self)
    {
        self.stop();
    }
};

struct IsRunning : pro::dispatch<bool()>
{
    template<class Self>
    inline auto operator()(Self &self)
    {
        return self.isRunning();
    }
};


struct FEngine : pro::facade<Start, Stop, IsRunning>
{};
