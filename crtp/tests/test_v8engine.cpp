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

class TestV8Engine : public Test
{
public:
    V8Engine engine;
};


TEST_F(TestV8Engine, StartSucceeds)
{
    ASSERT_THAT(engine.start(), IsTrue());
}

TEST_F(TestV8Engine, StartSetsIsRunningToTrue)
{
    ASSERT_THAT(engine.isRunning(), IsFalse());

    engine.start();

    ASSERT_THAT(engine.isRunning(), IsTrue());
}
