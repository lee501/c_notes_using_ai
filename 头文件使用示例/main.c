// 文件: main.c
#include "utils.h"    // 包含头文件
#include "utils.h"    // 重复包含 - 不会出错！
#include "utils.h"    // 再次重复包含 - 仍然不会出错！

int main() {
    // 使用头文件中定义的结构体
    Point p1 = {10, 20};
    Point p2;
    p2.x = 30;
    p2.y = 40;
    
    // 使用头文件中声明的函数
    int result = add(p1.x, p1.y);
    printf("Add result: %d\n", result);
    
    // 使用头文件中的函数
    print_message("Hello from utils!");
    
    // 使用头文件中的宏
    printf("Max size: %d\n", MAX_SIZE);
    printf("PI value: %.5f\n", PI);
    
    // 创建数组使用宏定义的大小
    char buffer[MAX_SIZE];
    snprintf(buffer, MAX_SIZE, "Buffer size is %d", MAX_SIZE);
    printf("%s\n", buffer);
    
    return 0;
}
/*
编译步骤：

1. 编译源文件：
   gcc -c utils.c -o utils.o
   gcc -c main.c -o main.o

2. 链接生成可执行文件：
   gcc utils.o main.o -o program

或者一步完成：
   gcc utils.c main.c -o program

*/