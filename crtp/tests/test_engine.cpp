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

TEST(EngineTest, CallsStartOnDerived)
{
    auto concreteEngine = make_shared<MockEngine>();
    EXPECT_CALL(*concreteEngine, start);

    shared_ptr<Engine<MockEngine>> enginePtr = concreteEngine;
    enginePtr->start();
}
