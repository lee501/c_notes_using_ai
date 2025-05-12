#include <stdio.h>
/*指针的作用是指向某个内存地址*/

/* *表示指针，&表示取地址，*和&是成对的，通过*来访问指针变量，通过&来访问地址 */
/*
  示例
  int x = 10;
  int* p = &x;
  printf("%d\n", *p); //10
*/

//&运算符与*运算符互为逆运算
/*
  示例
  int i = 5;

  if (i == *(&i)) {
    printf("i == *(&i)\n"); //true
  }
*/

int main() {
  int x = 10;
  if (x == *(&x)) {
    printf("x == *(&x)\n"); //输出
  } 
  short* j;
  short* k;
  j = (short*)0x1234;
  k = (short*)0x1236;
  printf("%ld\n", k - j);

  return 0;
}

/* 指针变量的初始化 */
/*
  示例
  int x = 10;
  int* p = &x; //指向一个已经分配好的内存地址
  printf("%d\n", *p); //10

  防止读写未初始化的指针变量, 将未初始化的指针变量设为NULL
  int* p = NULL;
*/

/* 指针变量的复制 */
/*
  示例
  int x = 10;
  int* p = &x; 
  int* q = p; 指向同一个内存地址
  printf("%d\n", *q); //10
*/

/* 指针变量的传递*/
/*
  示例传递到函数
  int x = 10;
  int* p = &x;
  声明个函数
  void func(int* p) {
    printf("%d\n", *p); //10
  }
  func(p);
*/

/* 指针的运算*/
/*
  指针与整数值的加减
  short* j;
  j = (short*)0x1234;
  j = j + 1; //0x1236 指针向内存地址的高位移动一个单位，这里short的单位是2字节，所以是0x1236


  两个指针的减法
  short* j;
  short* k;
  j = (short*)0x1234;
  k = (short*)0x1236;
  printf("%d\n", k - j); //1 距离是相隔多少个单位
*/