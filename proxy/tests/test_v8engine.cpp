#include <gmock/gmock.h>

#include <v8engine.h>

using namespace std;
using namespace testing;

TEST(TestV8Engine, StartSucceeds)
{
    V8Engine engine;

    ASSERT_THAT(engine.start(), IsTrue());
}

TEST(TestV8ConstEngine, NotRunningByDefault)
{
    const V8Engine engine;

    ASSERT_THAT(engine.isRunning(), IsFalse());
}
