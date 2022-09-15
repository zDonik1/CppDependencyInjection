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

TEST(TestCar, StartCallsStartOnEngine)
{
    auto engine = make_shared<MockEngine>();
    EXPECT_CALL(*engine, start);

    Car car{engine};

    car.start();
}
