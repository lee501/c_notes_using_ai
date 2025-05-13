
/*参数的传值引用*/
/*
  示例
  参数是一个变量，可以传值，也可以传引用
  传值
  void swap(int a, int b) {
    int temp = a;
    a = b;
    b = temp;
  }
  传引用
  void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
  }
*/

/*函数的返回值*/
/*
  示例
  int max(int a, int b) {
    if (a > b) {
      return a;
    } else {
      return b;
    }
  }

  函数内部不要返回内部变量的指针
  函数结束后，内部变量会被销毁，返回的地址是无效的
  int* f(void) {
    int i;
    // ...
    return &i; 
  }
*/

/*函数指针*/
/*
  示例
  int a = 10;
  int b = 20;
  int (*p)(int, int) = max; //max==&max是相同的
  printf("%d\n", (*p)(a, b)); //20 等同于 max(a, b)
*/

/*函数的递归*/
/*
  示例
  int fact(int n) {
    if (n == 0) {
      return 1;
    } else {
      return n * fact(n - 1);
    }
  }
*/

/*函数说明符*/
/* 
  extern: 声明一个外部函数
    源码文件会用到其他文件声明的函数。这时，当前文件里面，需要给出外部函数的原型，并用extern说明该函数的定义来自其他文件。
    由于函数原型默认就是extern，所以这里不加extern，效果是一样的。
    extern int foo(int arg1, char arg2);

    int main(void) {
      int a = foo(2, 3);
      // ...
      return 0;
    }
  推荐使用头文件，不推荐使用extern
  创建头文件： 在定义函数的源文件旁创建对应的.h头文件，如utils.c对应utils.h
  头示例:
  // utils.h
  #ifndef UTILS_H
  #define UTILS_H

  int external_function(int param1, char param2);

  #endif
  在使用处包含头文件： #include "utils.h"
  // main.c
  #include "utils.h"

  int main() {
      external_function(10, 'a');
      return 0;
  }
*/  

/*
  static: 
  1.声明一个静态函数
    表示该函数只能在当前文件里使用，如果没有这个关键字，其他文件也可以使用这个函数（通过声明函数原型）
  
  2.static用于函数内部声明变量时，表示该变量只需要初始化一次，不需要在每次调用时都进行初始化。也就是说，它的值在两次调用之间保持不变。
  #include <stdio.h>

  void counter(void) {
    static int count = 1;  // 只初始化一次
    printf("%d\n", count);
    count++;
  }

  int main(void) {
    counter();  // 1
    counter();  // 2
    counter();  // 3
    counter();  // 4
  }

  3.static修饰的变量初始化时，只能赋值为常量，不能赋值为变量。
  int i = 3;
  static int j = i; // 错误
*/

/*头文件声明的函数与定义的函数*/
/*
  project/
    ├── include/
    │   └── example.h       // 声明
    ├── src/
    │   └── example.c       // 定义
    └── main.c              // 调用函数

  // example.h
  #ifndef EXAMPLE_H
  #define EXAMPLE_H

  // 声明函数（无具体实现）
  void external_function(int arg);

  #endif

  // example.c
  #include "example.h"

  void external_function(int arg) {
    printf("Value: %d\n", arg);
  }

  // main.c
  #include "example.h"

  int main(void) {
    external_function(10);
    return 0;
  }
  普通编译
  gcc -I./include src/example.c main.c -o program
*/
