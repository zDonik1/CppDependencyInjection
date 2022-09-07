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
};


class EngineTest : public Test
{
public:
    shared_ptr<MockEngine> concreteEngine{make_shared<MockEngine>()};
    shared_ptr<Engine<MockEngine>> baseEnginePtr{concreteEngine};
};


TEST_F(EngineTest, StartReturnsSuccessOfStartMethodInDerived)
{
    constexpr auto SUCCESS{true};
    EXPECT_CALL(*concreteEngine, start)
        .WillOnce(Return(SUCCESS));

    ASSERT_THAT(baseEnginePtr->start(), Eq(SUCCESS));
}
