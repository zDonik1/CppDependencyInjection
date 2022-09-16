#include <gmock/gmock.h>
#include <proxy/proxy.h>

#include <v8engine.h>

using namespace std;
using namespace testing;
using namespace pro;


struct Start : pro::dispatch<bool()>
{
    template<class Self>
    inline auto operator()(Self &self)
    {
        return self.start();
    }
};

struct IsRunning : pro::dispatch<bool()>
{
    template<class Self>
    inline auto operator()(Self &self)
    {
        return self.isRunning();
    }
};

struct Stop : pro::dispatch<void()>
{
    template<class Self>
    inline auto operator()(Self &self)
    {
        self.stop();
    }
};

struct FEngine : pro::facade<Start, IsRunning, Stop>
{};


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
