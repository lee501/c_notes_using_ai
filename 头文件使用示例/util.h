// 使用ifndef防止重复加载
#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <stdlib.h>

// 函数声明
int add(int a, int b);
void print_message(const char* msg);

// 宏定义
#define MAX_SIZE 1024
#define PI 3.14159

// 结构体定义
typedef struct {
    int x;
    int y;
} Point;

#endif // UTILS_H