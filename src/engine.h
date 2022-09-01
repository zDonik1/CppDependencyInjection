/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 01/09/2022
 *
 *************************************************************************/

#pragma once

#include <concepts>

template<typename EngineType>
concept CEngine = requires(EngineType engine)
{
    { engine.start() } -> std::same_as<bool>;
    { engine.stop() } -> std::same_as<void>;
    { engine.isRunning() } -> std::same_as<bool>;
};
