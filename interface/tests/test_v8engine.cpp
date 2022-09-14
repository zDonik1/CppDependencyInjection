#include <gmock/gmock.h>

#include <v8engine.h>

using namespace std;
using namespace testing;

TEST(TestV8Engine, StartShouldSucceed)
{
    V8Engine engine;

    ASSERT_THAT(engine.start(), IsTrue());
}

TEST(TestConstV8Engine, IsRunningReturnsBeforeStarting)
{
    const V8Engine engine;

    ASSERT_THAT(engine.isRunning(), IsFalse());
}
