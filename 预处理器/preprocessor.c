#include <stdio.h>

/* #define*/
/*
  用来将指定的词替换成另一个词#define指令从#开始，一直到换行符为止。
  如果整条指令过长，可以在折行处使用反斜杠，延续到下一行。
  #define PI 3.141592
  #define OW "C programming language is invented \
  in 1970s."

  #define允许多重替换，即一个宏可以包含另一个宏。
  #define PI 3.141592
  #define RADIUS 5
  #define AREA PI * RADIUS * RADIUS

  同名的宏可以重复定义，只要定义是相同的，就没有问题。如果定义不同，就会报错。
  #define PI 3.141592
  #define PI 3.141592 //正确
  #define PI 3.1415926 //错误
*/
#define PI 3.141592

/* 带参数的宏 */
//宏的名称与左边圆括号之间，不能有空格
#define MAX(a, b) ((a) > (b) ? (a) : (b))
/*
  #define SQUARE(X) ((X) * (X))
  printf("%d\n", SQUARE(3 + 4));
  //等同于
  printf("%d\n", ((3 + 4) * (3 + 4)));

  #define SQUARE(X) X*X
  printf("%d\n", SQUARE(3 + 4));
  //不使用圆括号，结果会导致意想不到的结果
  printf("%d\n", (3 + 4*3 + 4));
*/

/* #运算符和##运算符*/
/*
  #运算符：将参数转换为字符串
    #define STR(x) #x     //如果x前面没有#，这会被解释成一个浮点数

    // 等同于 printf("%s\n", "3.14159");
    printf("%s\n", STR(3.14159));

  ##运算符：连接两个标记
    #define CONCAT(x, y) x##y

    // 等同于 printf("%d\n", 1234);
    printf("%d\n", CONCAT(12, 34));


    #define MK_ID(n) i##n
    int MK_ID(1), MK_ID(2), MK_ID(3);
    // 替换成
    int i1, i2, i3; 
*/

/*宏写成多行*/
/*
  #define PRINT_NUMS_TO_PRODUCT(a, b) { \
    int product = (a) * (b); \
    for (int i = 0; i < product; i++) { \
      printf("%d\n", i); \
    } \
  }
*/

/*不定长参数的宏*/
/*
  #define X(a, b, ...) (10*(a) + 20*(b)), __VA_ARGS__
  1. X(a, b, ...)表示X()至少有两个参数， 多余的参数使用...表示
  2. 在替换文本中，__VA_ARGS__代表多余的参数（每个参数之间使用逗号分隔）

  用法:
   X(5, 4, 3.14, "Hi!", 12)
  // 替换成
  (10*(5) + 20*(4)), 3.14, "Hi!", 12
*/

/* #undef指令，用来取消使用#define定义的宏*/
/*
  示例：
  #define PI 3.141592
  #undef PI
*/

/* #include 指令*/
/*
  用于编译时将其他源码文件，加载进入当前文件
  #include "header.h" //包含当前目录 用户提供的文件
  #include <header.h> //包含系统目录 尖括号

  #include最常见的用途，就是用来加载包含函数原型的头文件（后缀名为.h）
*/

/*GCC编译器*/
/*
1. GCC 的-U选项可以在命令行取消宏的定义，相当于#undef。
gcc -UPI program.c -o program

2. GCC 编译器的-I参数，也可以用来指定include命令中用户文件的加载路径。
gcc -Iinclude/ program.c -o program

3. GCC 的-D参数可以在编译时指定宏的值，因此可以很方便地打开调试开关。
gcc -DDEBUG=1 program.c -o program
*/

/*#if...#endif指令*/
/*
  #if...#endif指令用于预处理器的条件判断，满足条件时，内部的行会被编译，否则就被编译器忽略。

  #if...#endif指令的语法如下：
  #if condition
    // 条件为真时编译的代码
  #endif

  示例:
  #define FOO 1

  #if FOO == 1
    printf("defined\n");
  #elif FOO == 2
    printf("FOO is 2\n");
  #else
    printf("not defined\n");
  #endif

  #if的常见应用就是打开（或关闭）调试模式。

  #define DEBUG 1

  #if DEBUG
    printf("Debug mode\n");
  #endif
*/

/*#ifdef...#endif指令*/
/*
  #ifdef...#endif指令指令用于判断某个宏是否定义过。
  源码文件可能会重复加载某个库，这时可以使用#ifdef来避免重复定义。

  示例：
  #ifdef FOO
    printf("I'm extra happy!\n");
  #endif

  示例：  #ifdef...#else...#endif可以用来实现条件加载。
  #ifdef MAVIS
    #include "foo.h"
    #define STABLES 1
  #else
    #include "bar.h"
    #define STABLES 2
  #endif
*/

/*defined运算符*/
/*
  上面的#ifdef FOO 等同与 #if defined(FOO)

  defined运算符用于判断某个宏是否定义过。

  示例：
  #if defined(FOO)
    printf("FOO is defined\n");
  #endif
*/

/*#ifndef...#endif指令*/
/*
  #ifndef...#endif指令与#ifdef...#endif指令相反，用来判断宏没有被定义过
  
  
  示例：#ifndef常用于防止重复加载。举例来说，为了防止头文件myheader.h被重复加载，可以把它放在#ifndef...#endif里面加载。

  #ifndef MYHEADER_H
    #define MYHEADER_H
    #include "myheader.h"
  #endif
*/
int main() {
  int x = 10;
  int y = 20;
  printf("%d\n", MAX(x, y));
  printf("%f\n", PI);

  printf("This function: %s\n", __func__);
  printf("This file: %s\n", __FILE__);
  printf("This line: %d\n", __LINE__);
  printf("Compiled on: %s %s\n", __DATE__, __TIME__);
  printf("C Version: %ld\n", __STDC_VERSION__);


/* 输出如下

This function: main
This file: preprocessor.c
This line: 199
Compiled on: Mar 29 2021 19:19:37
C Version: 201710L

*/
  return 0;
}

/*c语言预定义宏*/
/*
  __DATE__：编译日期，格式为“Mmm dd yyyy”的字符串（比如 Nov 23 2021）。
  __TIME__：编译时间，格式为“hh:mm:ss”。
  __FILE__：当前文件名。
  __LINE__：当前行号。
  __func__：当前正在执行的函数名。该预定义宏必须在函数作用域使用。
  __STDC__：如果被设为1，表示当前编译器遵循 C 标准。
  __STDC_HOSTED__：如果被设为1，表示当前编译器可以提供完整的标准库；否则被设为0（嵌入式系统的标准库常常是不完整的）。
  __STDC_VERSION__：编译所使用的 C 语言版本，是一个格式为yyyymmL的长整数，C99 版本为“199901L”，C11 版本为“201112L”，C17 版本为“201710L”。
*/

/*#error指令*/
/*
#if __STDC_VERSION__ != 201112L
#error Not C11
#endif
*/

/*#pragma指令用来修改编译器属性*/
/*
也可以用来防止重复加载头文件
// 文件: math_utils.h
#pragma once
*/


