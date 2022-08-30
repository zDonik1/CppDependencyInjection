#include <gmock/gmock.h>

#include <greeter.h>

using namespace testing;

TEST(GreeterTest, Greets)
{
    constexpr auto GREET_TEXT = "Hello world!";
    Greeter greeter{GREET_TEXT};
    EXPECT_THAT(greeter.greet(), StrEq(GREET_TEXT));
}
