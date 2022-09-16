#include <gmock/gmock.h>

#include <v8engine.h>
#include <fengine.h>

using namespace std;
using namespace testing;
using namespace pro;


class TestV8Engine : public Test
{
public:
    inline auto start() { return engine.invoke<Start>(); }
    inline auto isRunning() { return engine.invoke<IsRunning>(); }
    inline auto stop() { return engine.invoke<Stop>(); }

public:
    proxy<FEngine> engine{make_proxy<FEngine, V8Engine>()};
};


TEST_F(TestV8Engine, StartSucceeds)
{
    ASSERT_THAT(start(), IsTrue());
}

TEST_F(TestV8Engine, NotRunningByDefault)
{
    ASSERT_THAT(isRunning(), IsFalse());
}

TEST_F(TestV8Engine, IsRunningAfterStarting)
{
    start();

    ASSERT_THAT(isRunning(), IsTrue());
}

TEST_F(TestV8Engine, NotRunningAfterStopping)
{
    start();
    ASSERT_THAT(isRunning(), IsTrue());

    stop();

    ASSERT_THAT(isRunning(), IsFalse());
}
