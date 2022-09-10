#include <gmock/gmock.h>

#include <v8engine.h>

using namespace std;
using namespace testing;

class TestV8Engine : public Test
{
protected:
    V8Engine engine;
};

TEST_F(TestV8Engine, TestStart)
{
    EXPECT_THAT(engine.start(), IsTrue());
    EXPECT_THAT(engine.isRunning(), IsTrue());
}

TEST(ConstV8EngineTest, TestIsRunningWhenNotStarted)
{
    const V8Engine engine;
    EXPECT_THAT(engine.isRunning(), IsFalse());
}

TEST_F(TestV8Engine, TestStop)
{
    engine.start();
    ASSERT_THAT(engine.isRunning(), IsTrue());

    engine.stop();
    EXPECT_THAT(engine.isRunning(), IsFalse());
}

TEST(TestV8EngineType, ConformsToEngineConcept)
{
    ASSERT_THAT(Engine<V8Engine>, IsTrue());
}
