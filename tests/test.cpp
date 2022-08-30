#include <gmock/gmock.h>

#include <v8engine.h>

using namespace std;
using namespace testing;

TEST(V8EngineTest, TestStart)
{
    V8Engine engine;
    EXPECT_THAT(engine.start(), Eq(true));
    EXPECT_THAT(engine.isRunning(), Eq(true));
}
