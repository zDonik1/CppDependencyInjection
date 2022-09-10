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


TEST(TestCar, CanStartTheEngine)
{
    constexpr auto SUCCESS{true};
    auto engine{make_shared<MockEngine>()};
    EXPECT_CALL(*engine, start).WillOnce(Return(SUCCESS));

    shared_ptr<Engine<MockEngine>> baseEngine{engine};
    Car car{baseEngine};

    ASSERT_THAT(car.start(), Eq(SUCCESS));
}
