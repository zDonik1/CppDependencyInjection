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
    MOCK_METHOD(void, start, ());
};


TEST(TestCar, StartingCarStartsEngine)
{
    shared_ptr<MockEngine> engine{make_shared<MockEngine>()};
    EXPECT_CALL(*engine, start);

    Car car{engine};

    car.start();
}
