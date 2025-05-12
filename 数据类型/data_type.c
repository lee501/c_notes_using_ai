#include <stdio.h>
#include <stdlib.h>
//基本数据类型
//char, short, int, long, float, double

/*
  char c = 66;
  // 等同于
  char c = 'B';
*/


/*
  char c1 = 066; //八进制
  char c2 = 0x66; //16进制

  八进制如何转十进制
  66 = 6 * 10 + 6 = 66

  16进制如何转十进制
  66 = 6 * 16 + 6 = 102

  10进制转换十六进制
  102 % 16 = 6
  -- 102 / 16 = 6
  6 % 16 = 6
*/
char* decToHex(int decimal) {
  char *hexDigits = "0123456789ABCDEF";
  char *result = (char *)malloc(sizeof(char) * 16);
  int index = 0;
  
  if (decimal == 0) {
    result[index++] = '0';
  } else {
    while (decimal != 0) {
      char hex = hexDigits[decimal % 16];
      decimal /= 16;
      result[index++] = hex;
    }
  }
  
  char *hex = (char *)malloc(sizeof(char) * (index + 1));
  for (int i = 0; i < index; i++) {
    hex[i] = result[index - i - 1];
  }
  hex[index] = '\0';
  
  free(result);
  return hex;
}

int main() {
  int decimal;
  printf("请输入一个十进制数: ");
  scanf("%d", &decimal);
  
  printf("十六进制表示为: \n");
  char *hex = decToHex(decimal);
  
  if (hex[0] == '\0') {
    printf("没有结果\n");
  } else {
    printf("%s\n", hex);
  }
  free(hex);
  return 0;
}

//各个数据类型大小
/*
  char: 1 byte -127～128
  short: 2 bytes
  int: 4 bytes
  long: 4 bytes
  long long: 8 bytes
  float: 4 bytes
  double: 8 bytes
*/

/*
printf()的进制相关占位符如下。

%d：十进制整数。
%o：八进制整数。
%x：十六进制整数。
%#o：显示前缀0的八进制整数。
%#x：显示前缀0x的十六进制整数。
%#X：显示前缀0X的十六进制整数。

*/

/*boolean
  int x = 0;
  int b = 1; 0为false, 非0为true

  #include <stdbool.h>
  bool flag = false;
*/

/*如何避免溢出, 将运算结果与类型的极限值比较*/
/*
  UINT_MAX = 4294967295
  INT_MAX = 2147483647  
*/

//sizeof()函数
/*
  sizeof()函数返回的是字节的个数
  返回size_t类型, 通常是unsigned int类型, 大小为4个字节，它的取值范围为[0, UINT_MAX]
  printf("%zd\n", sizeof(int));
*/

/*类型的自动转换*/
/*
  char c = 'a';
  int i = c;
  printf("%d\n", i); //97

  浮点数赋值给整数变量
  float f = 3.14;
  int i = f;
  printf("%d\n", i); //3 直接丢弃消暑部分

  整数赋值给浮点数变量
  int i = 3;
  float f = i;
  printf("%f\n", f); //3.000000

  窄类型赋值给宽类型, 类型提升(宽度小于int的类型，运算结果会自动提升为int。)
  int i = 3;
  long l = i;
  printf("%ld\n", l); //3
*/

/*
  unsigned char a = 66;

  if ((-a) < 0) printf("negative\n"); 类型提升，导致-a是int类型，输出负数
  else printf("positive\n");
*/


/*类型的强制转换*/
/*
  int i = 3;
  char c = (char)i;
  printf("%d\n", c); //3
*/