#include <gmock/gmock.h>
//#include <gtest/gtest.h>

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

TEST(CarTest, TestStart)
{
    auto engine{make_shared<MockEngine>()};
    EXPECT_CALL(*engine, start())
        .WillOnce([] { return true; });

    Car<MockEngine> car{engine};
    EXPECT_THAT(car.start(), IsTrue());
}
