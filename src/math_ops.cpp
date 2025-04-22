#include <stdio.h>

// 加法函数
double add(double a, double b) {
    return a + b;
}

// 减法函数
double subtract(double a, double b) {
    return a - b;
}

// 乘法函数
double multiply(double a, double b) {
    return a * b;
}

// 除法函数
double divide(double a, double b) {
    if (b == 0) {
        printf("错误：除数不能为零\n");
        return 0; // 返回0或其它错误处理方式
    }
    return a / b;
}

// 混合运算函数
double mixed_operations(double a, double b, double c, double d) {
    double result = add(a, b);           // a + b
    result = multiply(result, c);        // (a + b) * c
    result = subtract(result, d);        // ((a + b) * c) - d
    return result;
}
