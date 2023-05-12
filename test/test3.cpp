#include "gtest/gtest.h"

TEST(TestMulInt, test_mul_int_1)
{
    int res = 40 * 96;
    EXPECT_EQ(res, 3840);
}
