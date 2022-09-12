/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 10/09/2022
 *
 *************************************************************************/

#include <gmock/gmock.h>

#include <car.h>

using namespace std;
using namespace testing;

class MockEngine : public Engine<MockEngine>
{
public:
    MOCK_METHOD(bool, start, ());
    MOCK_METHOD(void, stop, ());
    MOCK_METHOD(bool, isRunning, (), (const));
};


class TestCar : public Test
{
public:
    shared_ptr<Engine<MockEngine>> baseEngine{makeEngine<MockEngine>()};
    shared_ptr<MockEngine> engine{static_pointer_cast<MockEngine>(baseEngine)};
    Car<MockEngine> car{baseEngine};
};


TEST_F(TestCar, CanStartTheEngine)
{
    constexpr auto SUCCESS{true};
    EXPECT_CALL(*engine, start).WillOnce(Return(SUCCESS));

    ASSERT_THAT(car.start(), Eq(SUCCESS));
}

TEST_F(TestCar, CanStopTheEngine)
{
    EXPECT_CALL(*engine, stop);

    car.stop();
}
