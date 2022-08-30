#include <gmock/gmock.h>

#include <v8engine.h>

using namespace std;
using namespace testing;

class V8EngineTest : public Test
{
protected:
    V8Engine engine;
};

TEST_F(V8EngineTest, TestStart)
{
    EXPECT_THAT(engine.start(), Eq(true));
    EXPECT_THAT(engine.isRunning(), Eq(true));
}

TEST(ConstV8EngineTest, TestIsRunningWhenNotStarted)
{
    const V8Engine engine;
    EXPECT_THAT(engine.isRunning(), Eq(false));
}

TEST_F(V8EngineTest, TestStop)
{
    engine.start();
    ASSERT_THAT(engine.isRunning(), Eq(true));

    engine.stop();
    EXPECT_THAT(engine.isRunning(), Eq(false));
}
