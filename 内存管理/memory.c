#include <stdio.h>
#include <stdlib.h>

void* mellocArray(size_t size);
void reallocDemo();
/*
  系统管理的内存: 函数内部的变量，存放在stack中
  手动管理的内存: 存放在heap中
*/

/*void指针*/
/*
  void 指针等同于无类型指针，只有内存块的地址信息。
  void 指针与其他所有类型指针之间是互相转换关系
       任一类型的指针都可以转为void指针, void指针也可以转为任一类型的指针
       
  示例:
  int x = 10;

  void* p = &x; 整型指针转为void
  int* q = &p; void转整型

  由于不知道 void 指针指向什么类型的值，所以不能用*运算符取出它指向的值
  char a = 'X';
  void* p = &a;

  printf("%c\n", *p); // 报错
*/

/*malloc 和 free*/
/*
  原型: 定义在stdlib.h
  void* malloc(size_t size); 返回void指针
  void free(void* ptr);
  示例
  malloc()为任意类型的数据分配内存，常见的做法是先使用sizeof()函数，算出某种数据类型所需的字节长度，然后再将这个长度传给malloc()
  int* p = malloc(sizeof(int));
  p = 12;
  free(p);

  对malloc()返回的指针进行一次强制类型转换。
  int* p = (int*) malloc(sizeof(int));
  *p = 12;
  free(p);
*/

int main() {
  int *p = malloc(sizeof(int));
  *p = 12;
  printf("%d\n", *p);
  free(p);

  int* arr = mellocArray(10);
  for (int i = 0; i < 10; i++) {
    printf("%d\n", arr[i]);
  }
  reallocDemo();
  return 0;
}

/*NULL值*/
/*
  NULL是一个指针常量，它的值是0
  int* p = NULL;

  可以用来检测内存分配失败
  int* p = malloc(sizeof(int));

  if (p == NULL) {
    // 内存分配失败
  }
*/

/*使用malloc为数组和自定义数据结构分配内存*/
/*
  int* p = malloc(sizeof(int) * 10);
  for (int i = 0; i < 10; i++) {
    p[i] = i; 
  }
  for (int i = 0; i < 10; i++) {
    *p = i;
    p++;
  }
*/
void* mellocArray(size_t size) {
  int* p = malloc(sizeof(int) * size);
  int* res = p; //返回指针首地址 若使用数组方式赋值, 不需要声明新的指针
  for (int i = 0; i < size; i++) {
    *p = i;
    p++;
  }
  return res;
}

/*calloc函数*/
/*
  原型: 定义在stdlib.h
  void* calloc(size_t num, size_t size); 
  1. 参数: 接受两个参数
      num: 指定要分配的内存块的个数
      size: 指定每个内存块的大小(数据类型单位大小)
  2. 对分配的内存进行初始化 calloc()相当于malloc() + memset()
  返回值: 返回void指针
  示例
  int* p = calloc(10, sizeof(int));
  for (int i = 0; i < 10; i++) {
    printf("%d\n", p[i]);
  }
*/

/*realloc函数*/
/*
  原型: 定义在stdlib.h
  void* realloc(void* ptr, size_t size);
  1. 参数: 接受两个参数
      ptr: 指定要重新分配的内存块的首地址
      size: 指定要重新分配的内存块的大小

      如果新内存块小于原来的大小，则丢弃超出的部分;
      如果大于原来的大小，则不对新增的部分进行初始化（程序员可以自动调用memset()函数进行初始化）
  2. 返回值: 返回void指针
  示例
  int* p = calloc(10, sizeof(int));
  for (int i = 0; i < 10; i++) {  
    printf("%d\n", p[i]);   
  }
  p = realloc(p, sizeof(int) * 20);
  for (int i = 0; i < 20; i++) {  
    printf("%d\n", p[i]);   
  }

  realloc()的第一个参数可以是 NULL，这时就相当于新建一个指针。
  char* p = realloc(NULL, 3490);
  // 等同于
  char* p = malloc(3490);
*/

void reallocDemo() {
  int* p = calloc(10, sizeof(int));
  // for (int i = 0; i < 10; i++) {  
  //   printf("%d\n", p[i]);   
  // }
  p = realloc(p, sizeof(int) * 20);
  for (int i = 0; i < 20; i++) {  
    printf("%d\n", p[i]);   //超过10的部分是不初始化的，这里打印看到是0偶然现象
  }
  free(p);
}

/*restrict说明符*/
/*
  原型: 定义在stddef.h
  void* restrict
  1. 参数: 无
  2. 返回值: 无
  示例
  int* restrict p;
  p = calloc(10, sizeof(int)); //受限指针，只能通过p来访问
  for (int i = 0; i < 10; i++) {  
    printf("%d\n", p[i]);   
  }

  int* q = p; //违背restrict说明符，报错
*/

/*memcpy函数*/
/*
  原型: 定义在string.h
  void* memcpy(void* restrict dest, const void* restrict src, size_t n);
  1. 参数: 接受三个参数
      dest: 指定要拷贝到的内存块的首地址
      src: 指定要拷贝的内存块的首地址
      n: 指定要拷贝的内存块的大小
  2. 返回值: 返回void指针
  示例
  int a[] = {3, 5, 7, 3};
  int b[] = {1, 2, 3, 4};
  memcpy(b, a, 4 * sizeof(int));
  for (int i = 0; i < 4; i++) {
    printf("%d\n", b[i]);
  }


  memcpy()可以取代strcpy()进行字符串拷贝，而且是更好的方法，不仅更安全，速度也更快，它不检查字符串尾部的\0字符

  char* s = "hello world";

  size_t len = strlen(s) + 1;
  char *c = malloc(len);

  if (c) {
    // strcpy() 的写法
    strcpy(c, s);

    // memcpy() 的写法
    memcpy(c, s, len);
}
*/

/*自定义复制内存的函数*/
void* my_memcpy(void* dest, const void* src, size_t n) {
  char* d = dest;
  const char* s = src;
  while (n--) {
    *d++ = *s++;
  }
  return dest;
}

/*memmove函数*/
/*
  原型: 定义在string.h
  void* memmove(void* dest, const void* src, size_t n);
  允许目标区域与源区域有重叠。如果发生重叠，源区域的内容会被更改；如果没有重叠，它与memcpy()行为相同
  1. 参数: 接受三个参数
      dest: 指定要拷贝到的内存块的首地址
      src: 指定要拷贝的内存块的首地址
      n: 指定要拷贝的内存块的大小
  2. 返回值: 返回void指针
  示例
  char x[] = "Home Sweet Home";

  // 输出 Sweet Home Home
  printf("%s\n", (char *) memmove(x, &x[5], 10));
*/

/*memcmp函数*/
/*
  原型: 定义在string.h
  int memcmp(const void* s1, const void* s2, size_t n);
  如果两者相同，返回0；如果s1大于s2，返回大于0的整数；如果s1小于s2，返回小于0的整数。
  1. 参数: 接受三个参数
      s1: 指定要比较的内存块的首地址
      s2: 指定要比较的内存块的首地址
      n: 指定要比较的内存块的大小
  2. 返回值: 返回int值
  示例
  char x[] = "Home Sweet Home";
  char y[] = "Home Sweet Home";
  printf("%d\n", memcmp(x, y, 10)); //0
*/













