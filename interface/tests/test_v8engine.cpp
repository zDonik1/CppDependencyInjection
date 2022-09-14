#include <gmock/gmock.h>

#include <v8engine.h>

using namespace std;
using namespace testing;


class TestV8Engine : public Test
{
public:
    V8Engine engine;
};


TEST_F(TestV8Engine, StartShouldSucceed)
{
    ASSERT_THAT(engine.start(), IsTrue());
}

TEST(TestConstV8Engine, IsRunningReturnsBeforeStarting)
{
    const V8Engine engine;

    ASSERT_THAT(engine.isRunning(), IsFalse());
}

TEST_F(TestV8Engine, IsRunningReturnsTrueAfterStarting)
{
    engine.start();

    ASSERT_THAT(engine.isRunning(), IsTrue());
}
