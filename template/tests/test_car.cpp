/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 16/09/2022
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
};


class TestCar : public Test
{
public:
    shared_ptr<MockEngine> engine{make_shared<MockEngine>()};
    Car<MockEngine> car{engine};
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
