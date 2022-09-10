/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 10/09/2022
 *
 *************************************************************************/

#include <gmock/gmock.h>

#include <v8engine.h>

using namespace std;
using namespace testing;

TEST(TestV8Engine, StartSucceeds)
{
    V8Engine engine;
    ASSERT_THAT(engine.start(), IsTrue());
}
