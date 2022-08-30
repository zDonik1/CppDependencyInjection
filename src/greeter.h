/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 06/08/2022
 *
 *************************************************************************/

#pragma once

#include <string>

class Greeter
{
public:
    Greeter(std::string greetMessage);

    std::string_view greet();

private:
    std::string greetMessage_;
};
