#include <stdio.h>
#include <string.h>

int main() {
  //多行赋值
  char greeting[20] = "Hello, "
  "how are you "
  "today!";
  //字符串指针声明
  char* s = "hello, world";
  //字符数组不能改变左值，字符指针不能改变右值; 字符串字面量保存在只读区
  //字符数组声明后，名字对应的地址是固定的，编译器为数组单独分配一段内存，将字符串字面量存到这段内存
  //greeting = "你好"; //不能为greeting指向新地址
  //s = "nihao"; 指针类型可以指向新地址

  //如果只声明字符数组,初始化未赋值, 后续需要使用strcpy函数赋值
  char s1[10];  //s1 = "123"报错 使用strcpy(s, "abc")

  char* str = "hello";
  //strlen()返回字节长度, 不包含\0
  /*  
    strlen  //字符串长度，返回字符串的字节数，不包含\0
    sizeof //字符串变量的总字节数，包括\0
  */
  int len = strlen(str);  //长度为5

  /*
    赋值运算符只能将字符串字面量赋值给*s 不能复制给字符数组变量
    使用strcpy复制
  */
  char str1[10];
  strcpy(str1, "abc"); //注意字符变量的长度

  /*
    字符串指针变量，指向同一个字符串的地址，非复制s2给s3
  */
  char* s2, s3;
  s2 = "abc";
  s3 = s2; 

  /*
    strcpy(char dest[], const char source[])
  */
  
  return 0;
}

//strncpy函数
//strncpy(char *dest, const char *src, size_t n);
/*
  char dest[20];
  char src[] = "hello, world";
  strncpy(dest, src, sizeof(dest)-1);
  printf("%s\n", dest); //hello, world
*/  

//字符串链接函数
//strcat(char *dest, const char *src); 会改变第一个字符串
/*
  char dest[20] = "hello";
  char src[] = ", world";
  strcat(dest, src);
  printf("%s\n", dest); //hello, world
*/
//char *strncat(char *dest, const char *src, size_t n);
/*
  示例
  char dest[20] = "hello";
  char src[] = ", world"; 
  strncat(dest, src, sizeof(dest) - sizelen(dest) -1); 字符串变量长度减去字符串长度
  printf("%s\n", dest); //hello, world
*/  

//字符串比较函数
//strcmp(const char *s1, const char *s2); 相同返回0; 小于返回负数; 大于返回正数
//strncmp(const char *s1, const char *s2, size_t n);

//自定义字符串长度函数
int my_strlen(char *s) {
  int count = 0;
  while (s[count] != '\0') {
    count++;
  }
  return count;
}

//sprintf函数, 用于将数据写入到字符串中, 返回值是写入变量的字符数量（不计入尾部的空字符\0）。如果遇到错误，返回负值。
//snprintf()总是会自动写入字符串结尾的空字符。如果你尝试写入的字符数超过指定的最大字符数，snprintf()会写入 n - 1 个字符，留出最后一个位置写入空字符
/*
int sprintf(char *str, const char *format, ...);
int snprintf(char *str, size_t size, const char *format, ...);

示例
char str[20];
sprintf(str, "%d", 123);  //str = "123"

snprintf(str, sizeof(str), "%d", 123);
*/

/*字符串数组*/
//每个字符串本身是字符数组，字符串数组需要通过二维数组实现，字符串数组是字符串指针数组
/*
  char weekdays[7][10] = { //7个字符串，每个字符串有10个字符
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday",
  "Sunday"
};

char* weekdays[] = {
  "Monday",
  "Tuesday",
  "Wednesday",
  "Thursday",
  "Friday",
  "Saturday",
  "Sunday"
};

遍历字符串
for (int i = 0; i < 7; i++) {
  printf("%s\n", weekdays[i]);
}
*/