#include <stdio.h>

void checkAddr();
void copy(const int* src, int* const dst, int len);

/*数组的声明和赋值*/
/*
  示例
  int arr[5];
  arr[0] = 10;
  arr[1] = 20;
  arr[2] = 30;
  arr[3] = 40;
  arr[4] = 50;

  int arr[5] = {10, 20, 30, 40, 50};

  int a[5];
  a = {22, 37, 3490, 18, 95}; // 报错 原因不能修改数组变量a指向的地址

  值少于数组成员数量，未初始化的成员值为0
  int a[5] = {22, 37, 3490};
  // 等同于
  int a[5] = {22, 37, 3490, 0, 0};

  指定位置赋值
  int a[15] = {[9] = 7, [14] = 48, [2] = 29};

  自动确定数组长度
  int a[] = {22, 37, 3490};
*/

/*数组长度*/
/*
  数组字节长度
  int a[5];
  printf("%d\n", sizeof(a)); //20

  数组元素个数
  int a[5];
  printf("%zd\n", sizeof(a) / sizeof(int)); //5

  sizeof返回值的数据类型是size_t，所以sizeof(a) / sizeof(a[0])的数据类型也是size_t。
  在printf()里面的占位符，要用%zd或%zu
*/

/*二维数组*/
/*
  int a[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
  
  指定位置赋值
  int a[3][4] = {[0][2] = 7, [2][3] = 48, [1][2] = 29};
*/

/*数组地址*/
/*  
  int a[5] = {11, 22, 33, 44, 55};

  int* p = &a[0];
  // 等同于
  int* p = a;
*/

/*函数接受数组作为参数*/
/*
  // 写法一
  int sum(int arr[], int len);
  // 写法二
  int sum(int* arr, int len);
*/

/*数组指针的加减法*/
/*
  示例
  int a[5] = {11, 22, 33, 44, 55};
  int* p = a;
  printf("%d\n", *(p + 3)); //44

  int a[5] = {11, 22, 33, 44, 55};

  for (int i = 0; i < 5; i++) {
    printf("%d\n", *(a + i)); //printf("%d\n", a[i]);
  }

  数组名与指针是等价的，所以下面的等式总是成立。
    a[b] == *(a + b)

  ⚠️ 数组名指向的地址是固定的，不能a++, 需要将a赋值给指针变量后p, 再使用p++
*/ 

int sum(int* start, int* end) {
  int total = 0;
  //通过地址比较
  while (start < end) {
    total += *start;
    start++;
  }

  return total;
}
int main() {
  int arr[5] = {20, 10, 5, 39, 4};
  printf("%i\n", sum(arr, arr + 5));
  checkAddr();

  int b[5];
  copy(arr, b, 5);
  printf("%d\n", b[0]);
  return 0;
}

/*二维数组的指针加减法*/
/*
  int arr[4][2];

  // 指针指向 arr[0]
  arr;
  等同于
  // 指针指向 arr[0][0]地址
  arr[0];

  // 指针指向 arr[1]
  arr + 1;

  // 指针指向 arr[0][1]
  arr[0] + 1

  // 取出 a[0][0] 的值
  *(a[0]);
  // 等同于
  **a
*/

void checkAddr() {
  int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int *p, *q;
  p=arr[0]; // 一维数组{1, 2, 3}首地址
  q=&arr[0][0]; //  元素地址
  printf("%p\n", p);
  printf("%p\n", q);

  printf("%p\n", arr); //指向数组首地址
  printf("%p\n", arr[0]); //指向数组首地址
  printf("%p\n", &arr[0][0]); //这三个都是指向数组首地址

  int (*node)[3]=arr; // 指向数组的指针
  printf("%p\n", node[0]);
  printf("%p\n", node);
  printf("%d\n", node[0][0]);
  printf("%d\n", **node);
}

/*指针数组和指向数组的指针*/
/*
  int *p[3] 这是一个指针数组, 每个元素是一个指向int的指针
  int (*p)[3] 指向数组的指针, 每个元素指向一个int数组, 通常用于指向二维数组
  
  int arr[3][3] = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
  int (*p)[3] = arr;
  int (*q)[3] = arr[0];
  int (*r)[3] = &arr;
*/

/*数组的复制*/
void copy(const int* src, int* const dst, int len) {
  for (int i = 0; i < len; i++) {
    dst[i] = src[i];
  }
}

/*memcpy方法复制数组*/
/*
  示例:
  void copy(int* src, int* dst, int len) {
    memcpy(dst, src, len * sizeof(int));
  }
  memcpy原型函数
  void *memcpy(void *dest, const void *src, size_t n);
*/

/*声明参数数组*/
/*
  int sum_array(int* start, int n) {
    int total = 0;
    int i = 0
    while (i < end) {
      total += *start;
      start++;
      i++;
    }
    return total;
  }
  int a[] = {3, 5, 7, 3};
  int sum = sum_array(a, 4);
*/

/*变长数组*/
/*
  函数原型，可以使用*代替变量名，也可以省略变量名
  int sum_array(int, int [*]);
  int sum_array(int, int []);

  int sum_array(int n, int a[n]) { //n要放在前面
  // ...
  }

  int a[] = {3, 5, 7, 3};
  int sum = sum_array(4, a); 
*/

/*数组作为字面量传入参数*/
/*
  // 数组变量作为参数
  int a[] = {2, 3, 4, 5};
  int sum = sum_array(a, 4);

  // 数组字面量作为参数
  int sum = sum_array((int []){2, 3, 4, 5}, 4); //(int [])类似于强制的类型转换，告诉编译器怎么理解这组值
*/