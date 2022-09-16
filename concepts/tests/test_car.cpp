/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 07/09/2022
 *
 *************************************************************************/

#include <gmock/gmock.h>

#include <car.h>

using namespace std;
using namespace testing;


class MockEngine
{
public:
    MOCK_METHOD(bool, start, ());
    MOCK_METHOD(void, stop, ());
    MOCK_METHOD(bool, isRunning, (), (const));
};
static_assert(Engine<MockEngine>);


class TestCar : public Test
{
public:
    TestCar() : engine{make_shared<MockEngine>()}, car{engine} {}

protected:
    shared_ptr<MockEngine> engine;
    Car<MockEngine> car;
};


TEST_F(TestCar, StartCallsStartOnEngine)
{
    EXPECT_CALL(*engine, start());

    car.start();
}

TEST_F(TestCar, StartingCarReturnsEngineStartSuccess)
{
    constexpr auto SUCCESS = true;
    EXPECT_CALL(*engine, start()).WillOnce(Return(SUCCESS));

    ASSERT_THAT(car.start(), Eq(SUCCESS));
}

TEST_F(TestCar, StoppingCarStopsEngine)
{
    EXPECT_CALL(*engine, stop());

    car.stop();
}

TEST(TestCarConstructor, ThrowsInvalidArgumentOnNullptrEngine)
{
    ASSERT_THROW(Car<MockEngine>{nullptr}, invalid_argument);
}
