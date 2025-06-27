#include <stdio.h>

enum Color {
  RED,
  GREEN,
  BLUE
};

int main() {
  enum Color c = GREEN;
  printf("%d\n", c); // 输出 1
  return 0;
}

/*enum命令的用途*/
/*
  1. 为一组整数常量提供有意义的名称
  2. 使代码更具可读性
*/

/*enum命令的值*/
/*
  编译器会自动为enum成员分配从0开始的整数值
  enum Color {
    RED,
    GREEN,
    BLUE
  };
  // 声明一个enum变量
  enum Color c;
*/

/*typedef可以为enum起别名*/
/*
  typedef enum {
    SHEEP,
    WHEAT,
    WOOD,
    BRICK,
    ORE
  } RESOURCE;

  RESOURCE r;
*/  

/*使用enum声明一组常量*/
/*
  enum的属性会自动声明为常量，不能被修改

  enum是一个关键字，后面跟着一个代码块，常量就在代码内声明。ONE, TWO, THREE就是三个 Enum 常量
  示例:
  enum {ONE, TWO, THREE}; //0, 1, 2
  ONE = 2; //错误

  C 语言也允许为 ENUM 常量指定值，不过只能指定为整数，不能是其他类型
  示例:
  enum {ONE = 1, TWO = 2, THREE = 3};

  没有指定值的常量会从上一个指定了值的常量，开始自动递增赋值
  示例:
  enum {ONE = 1, TWO, THREE}; //1, 2, 3
*/

/*enum的作用域*/
/*
  在顶层声明，那么在整个文件内都有效；如果是在代码块内部声明，则只对该代码块有效
*/  