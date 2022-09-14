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

TEST(TestConstV8Engine, IsRunningIsFalseByDefault)
{
    const V8Engine engine;

    ASSERT_THAT(engine.isRunning(), IsFalse());
}

TEST_F(TestV8Engine, IsRunningReturnsTrueAfterStart)
{
    engine.start();

    ASSERT_THAT(engine.isRunning(), IsTrue());
}

TEST_F(TestV8Engine, IsRunningReturnsFalseAfterStopped)
{
    engine.start();

    engine.stop();

    ASSERT_THAT(engine.isRunning(), IsFalse());
}
