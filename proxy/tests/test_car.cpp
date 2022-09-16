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
    MOCK_METHOD(void, stop, ());
    MOCK_METHOD(bool, isRunning, ());
};


TEST(TestCar, StartingCarStartsEngine)
{
    MockEngine engine;
    EXPECT_CALL(engine, start());

    Car car{&engine};

    car.start();
}
