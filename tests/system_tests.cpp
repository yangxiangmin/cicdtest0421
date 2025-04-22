#include "math_ops.h"
#include <gtest/gtest.h>

TEST(SystemTest, MixedOps) {
    // 测试: ((1 + 2) * 3) - 4 = 5
    EXPECT_EQ(mixed_operations(1, 2, 3, 4), 5);
}