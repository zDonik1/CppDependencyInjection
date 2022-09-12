/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 07/09/2022
 *
 *************************************************************************/

#include <gmock/gmock.h>

#include <engine.h>

#include "mock_engine.h"

using namespace std;
using namespace testing;


class TestEngine : public Test
{
public:
    shared_ptr<Engine<MockEngine>> baseEngine{makeEngine<MockEngine>()};
    shared_ptr<MockEngine> engine{static_pointer_cast<MockEngine>(baseEngine)};
};


class TestConstEngine : public Test
{
public:
    shared_ptr<const Engine<MockEngine>> baseEngine{makeEngine<const MockEngine>()};
    shared_ptr<const MockEngine> engine{static_pointer_cast<const MockEngine>(baseEngine)};
};


TEST_F(TestEngine, StartReturnsSuccessOfStartMethodInDerived)
{
    constexpr auto SUCCESS{true};
    EXPECT_CALL(*engine, start)
        .WillOnce(Return(SUCCESS));

    ASSERT_THAT(baseEngine->start(), Eq(SUCCESS));
}

TEST_F(TestEngine, StopCallsStopOnDerived)
{
    EXPECT_CALL(*engine, stop);

    baseEngine->stop();
}

TEST_F(TestConstEngine, IsRunningReturnsValueOfIsRunningOnDerived)
{
    constexpr auto IS_RUNNING{true};
    EXPECT_CALL(*engine, isRunning)
        .WillOnce(Return(IS_RUNNING));

    ASSERT_THAT(baseEngine->isRunning(), Eq(IS_RUNNING));
}

TEST(TestEngineType, CantConstructEngine)
{
    ASSERT_THAT(is_constructible_v<Engine<MockEngine>>, IsFalse());
}
