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

TEST(TestConstV8Engine, NotRunningByDefault)
{
    const V8Engine engine;

    ASSERT_THAT(engine.isRunning(), IsFalse());
}

TEST_F(TestV8Engine, IsRunningAfterStarting)
{
    engine.start();

    ASSERT_THAT(engine.isRunning(), IsTrue());
}

TEST_F(TestV8Engine, NotRunningAfterStopping)
{
    engine.start();
    ASSERT_THAT(engine.isRunning(), IsTrue());

    engine.stop();

    ASSERT_THAT(engine.isRunning(), IsFalse());
}

TEST(TestV8EngineType, InheritsFromSpecializedEngine)
{
    ASSERT_THAT((is_base_of_v<Engine<V8Engine>, V8Engine>), IsTrue());
}
