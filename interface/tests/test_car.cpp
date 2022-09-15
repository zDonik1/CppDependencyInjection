/**************************************************************************
 *
 *   @author Doniyorbek Tokhirov <tokhirovdoniyor@gmail.com>
 *   @date 14/09/2022
 *
 *************************************************************************/

#include <gmock/gmock.h>

#include <car.h>

using namespace std;
using namespace testing;


class MockEngine : public IEngine
{
public:
    MOCK_METHOD(bool, start, (), (override));
};


class TestCar : public Test
{
public:
    shared_ptr<MockEngine> engine{make_shared<MockEngine>()};
    Car car{engine};
};


TEST_F(TestCar, StartCallsStartOnEngine)
{
    EXPECT_CALL(*engine, start);

    car.start();
}

TEST_F(TestCar, StartReturnsSuccessOfEngineStart)
{
    constexpr auto SUCCESS{true};
    EXPECT_CALL(*engine, start).WillOnce(Return(SUCCESS));

    ASSERT_THAT(car.start(), Eq(SUCCESS));
}
