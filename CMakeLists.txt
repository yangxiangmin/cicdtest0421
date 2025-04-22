cmake_minimum_required(VERSION 3.10)
project(MathOps)

# 启用测试
enable_testing()

# 编译主库
add_library(math_ops src/math_ops.cpp)

# 编译单元测试
add_executable(unit_tests tests/unit_tests.cpp)
target_link_libraries(unit_tests math_ops gtest_main)

# 编译系统测试
add_executable(system_tests tests/system_tests.cpp)
target_link_libraries(system_tests math_ops gtest_main)

# 添加测试用例
add_test(NAME unit_tests COMMAND unit_tests)
add_test(NAME system_tests COMMAND system_tests)