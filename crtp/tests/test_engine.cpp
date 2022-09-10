/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 07/09/2022
 *
 *************************************************************************/

#include <gmock/gmock.h>

#include <engine.h>

using namespace std;
using namespace testing;

class MockEngine : public Engine<MockEngine>
{
public:
    MOCK_METHOD(bool, start, ());
    MOCK_METHOD(void, stop, ());
    MOCK_METHOD(bool, isRunning, (), (const));
};


class TestEngine : public Test
{
public:
    shared_ptr<MockEngine> concreteEngine{make_shared<MockEngine>()};
    shared_ptr<Engine<MockEngine>> baseEnginePtr{concreteEngine};
};


class TestConstEngine : public Test
{
public:
    shared_ptr<const MockEngine> concreteEngine{make_shared<const MockEngine>()};
    shared_ptr<const Engine<MockEngine>> baseEnginePtr{concreteEngine};
};


TEST_F(TestEngine, StartReturnsSuccessOfStartMethodInDerived)
{
    constexpr auto SUCCESS{true};
    EXPECT_CALL(*concreteEngine, start)
        .WillOnce(Return(SUCCESS));

    ASSERT_THAT(baseEnginePtr->start(), Eq(SUCCESS));
}

TEST_F(TestEngine, StopCallsStopOnDerived)
{
    EXPECT_CALL(*concreteEngine, stop);

    baseEnginePtr->stop();
}

TEST_F(TestConstEngine, IsRunningReturnsValueOfIsRunningOnDerived)
{
    constexpr auto IS_RUNNING{true};
    EXPECT_CALL(*concreteEngine, isRunning)
        .WillOnce(Return(IS_RUNNING));

    ASSERT_THAT(baseEnginePtr->isRunning(), Eq(IS_RUNNING));
}
