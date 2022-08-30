/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 06/08/2022
 *
 *************************************************************************/

#include "greeter.h"

using namespace std;

Greeter::Greeter(string greetMessage) : greetMessage_{move(greetMessage)} {}

string_view Greeter::greet()
{
    return greetMessage_;
}
