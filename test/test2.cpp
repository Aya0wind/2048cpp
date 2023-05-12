#include "gtest/gtest.h"

TEST(TestAddInt, test_add_int_1)
{
    int res = 40 + 96;
    EXPECT_EQ(res, 136);
}
