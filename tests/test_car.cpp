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


class CarTest : public Test
{
public:
    CarTest() : engine{make_shared<MockEngine>()}, car{engine} {}

protected:
    shared_ptr<MockEngine> engine;
    Car<MockEngine> car;
};

TEST_F(CarTest, TestStart)
{
    EXPECT_CALL(*engine, start())
        .WillOnce([] { return true; });

    EXPECT_THAT(car.start(), IsTrue());
}

TEST_F(CarTest, TestStop)
{
    EXPECT_CALL(*engine, stop());
    car.stop();
}
