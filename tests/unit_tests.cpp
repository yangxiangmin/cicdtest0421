#include "math_ops.h"
#include <gtest/gtest.h>

TEST(MathTest, Add) {
    EXPECT_EQ(add(2, 3), 5);
}

TEST(MathTest, DivideByZero) {
    EXPECT_EQ(divide(5, 0), 0);  // 测试除零处理
}