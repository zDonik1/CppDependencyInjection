/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 10/09/2022
 *
 *************************************************************************/

#include <gmock/gmock.h>

#include <car.h>

#include "mock_engine.h"

using namespace std;
using namespace testing;


class TestCar : public Test
{
public:
    shared_ptr<Engine<MockEngine>> baseEngine{makeEngine<MockEngine>()};
    shared_ptr<MockEngine> engine{static_pointer_cast<MockEngine>(baseEngine)};
    Car<MockEngine> car{baseEngine};
};


TEST_F(TestCar, StartingCarStartsEngine)
{
    EXPECT_CALL(*engine, start);

    car.start();
}

TEST_F(TestCar, StartingCarReturnsEngineStartSuccess)
{
    constexpr auto SUCCESS{true};
    EXPECT_CALL(*engine, start).WillOnce(Return(SUCCESS));

    ASSERT_THAT(car.start(), Eq(SUCCESS));
}

TEST_F(TestCar, StoppingCarStopsEngine)
{
    EXPECT_CALL(*engine, stop);

    car.stop();
}

TEST(TestCarConstructor, ThrowsInvalidArgumentOnNullptrEngine)
{
    ASSERT_THROW(Car<MockEngine>{nullptr}, invalid_argument);
}
