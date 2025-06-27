#include <stdio.h>
#include "struct.h"
#include <string.h>
#include <stdlib.h>
void cpstruct();
void arraystruct(); 

/*struct声明*/
/*
  //数据类型的声明
  struct student {
    char name[20];
    int age;
    char gender;
  };

  //声明变量
  struct student s1;
  //赋值的几种方式
  //方式1
  struct student s2 = {"zhangsan", 18, 'm'};
  //方式2
  struct student s3;
  s3.name = "lisi";
  s3.age = 20;
  s3.gender = 'f';
  //方式3
  struct student s4 = {.name = "wangwu", .age = 21, .gender = 'm'};
*/

/*struct 数据类型声明和变量声明合并*/
/*
  struct student {
    char name[20];
    int age;
    char gender;
  } s1;
  s1 = {"zhangsan", 18, 'm'};

  声明匿名数据类型
  struct {
    char name[20];
    int age;
    char gender;
  } s2;
*/

/*typedef 定义struct结构别名*/
/*
  typedef struct my_student {
    char name[20];
    int age;
    char gender;
  } student;
  student s1, s2, s3;
*/

/*指针变量指向struct结构*/
/*
  struct student {
    char name[20];
    int age;
    char gender;
  } s1;
  struct student* ps = &s1;

  struct book {
    char title[500];
    char author[100];
    float value;
  }* b1;
*/

/*struct结构占用存储空间*/
/*
  struct student {
    char* a// 8个字节
    char name[20]; //20
    int age; //4
    char gender; //1
  } s1;
  printf("%d\n", sizeof(s1)); //80
*/

/*指针变量和字符数组空间大小*/
/*
  1. char *b（字符指针）
含义：b 是一个指针变量，存储一个内存地址（指向 char 类型数据）。
占用空间：
32位系统：指针通常占 4字节（32位寻址）。
64位系统：指针通常占 8字节（64位寻址）。
关键点：
指针本身的大小与它指向的数据无关（无论指向单个 char 还是字符串，指针大小不变）。
指针需要额外分配内存来存储实际数据（例如通过 malloc）。
2. char b[20]（字符数组）
含义：b 是一个固定大小的数组，直接存储20个 char 类型元素。
占用空间：
固定为 20字节（因为每个 char 占1字节，共20个连续的 char）。
关键点：
数组名 b 在大多数情况下会退化为指向首元素的指针（但编译器仍会为其分配连续的内存块）。
sizeof(b) = 20（数组的大小是编译时确定的）。
*/

/*关于结构体大小和内存对齐*/
/*
  对齐规则： 每个成员的起始地址必须是其类型大小的整数倍。
  struct foo {
      char c;   // 1字节 0开始 填充3个字节
      int a;    // 4字节  需要从4的倍数地址开始（即 0,4,8,...）
      char* b;  // 4字节（32位系统）或8字节（64位系统）
  };
*/
int main() {
  struct foo {
      char c;   // 1字节
      int a;    // 4字节
      char* b;  // 4字节（32位系统）或8字节（64位系统）
  } s1;
  printf("%lu\n", sizeof(s1)); //16字节
  cpstruct();

  struct turtle myTurtle = {"MyTurtle", "sea turtle", 99};
  paramstruct(myTurtle);
  printf("Age is %i\n", myTurtle.age); // 输出 99
  happy(&myTurtle);
  printf("Age is %i\n", myTurtle.age); // 输出 100
  arraystruct();
  genTree();
  return 0;
}

/*struct的复制*/
/*
 struct 变量可以使用赋值运算符（=），复制给另一个变量，这时会生成一个全新的副本。
 系统会分配一块新的内存空间，大小与原来的变量相同，把每个属性都复制过去，
 即原样生成了一份数据
 
 示例:
  struct cat { char name[30]; short age; } a, b;

  strcpy(a.name, "Hula");
  a.age = 3;

  b = a;
  b.name[0] = 'M';

  printf("%s\n", a.name); // Hula
  printf("%s\n", b.name); // Mula
  */

void cpstruct() {
  struct cat { char* name; short age; } a, b;

  a.name = "Hula";
  a.age = 3;

  b = a; //复制同一个地址Hula, a.name 和b.name都指向Hula的首地址
  printf("%s\n", b.name); //Hula
  b.name = "Haha"; //修改b.name指向Haha
  printf("%s\n", a.name); //Hula a.name不受影响
  printf("%s\n", b.name); //Haha b.name受影响
  printf("%p\n", &a.name); //b name地址与a的地址不同
  printf("%p\n", &b.name);
}

/*struct变量传参*/
/*如果将 struct 变量传入函数，函数内部得到的是一个原始值的副本*/
/*
  struct turtle myTurtle = {"MyTurtle", "sea turtle", 99};
  paramstruct(myTurtle);
  printf("Age is %i\n", myTurtle.age); // 输出 99
*/ 

/*
  对于 struct 变量名，使用点运算符（.）获取属性；
  对于 struct 变量指针，使用箭头运算符（->）获取属性
  myStruct.prop == (*ptr).prop == ptr->prop //三种写法等价
*/
void paramstruct(struct turtle t) {
  t.age = t.age + 1;
}

/*struct指针传参*/
/* 传入的是指向struct变量的指针*/
void happy(struct turtle* t) {
  t->age = t->age + 1; //(*t).age = (*t).age + 1;
}

/*struct嵌套*/
/*
  struct species {
    char* name;
    int kinds;
  };

  struct fish {
    char* name;
    int age;
    struct species breed;
  };
*/  
void nestedstruct() {
  struct species {
    char* name; //字符串指针，无法修改字符串字面量的元素
    int kinds;
  };
  struct fish {
    char* name;
    int age;
    struct species breed;
  };
  //赋值
  struct fish f1 = {"Nemo", 1, {"Dory", 2}};  //写法1
  struct fish shark = {.name = "Shark", .age = 2, .breed = {"Nemo", 1}}; //写法2
  struct fish f2 = {.name = "Nemo", .age = 1, .breed.name = "Dory", .breed.kinds = 2}; //写法3
  struct species s1 = {"Dory", 2}; //写法4
  struct fish f4 = {"Nemo", 1, s1};
}

/*数组类型的struct嵌套*/
/*
  自定义类型student的name属性是另一个自定义类型，
  如果要引用后者的属性，就必须使用两个.运算符，比如student1.name.first。
  另外，对字符数组属性赋值，要使用strcpy()函数，不能直接赋值
  struct name {
    char first[50];
    char last[50];
  };

  struct student {
    struct name name;
    short age;
    char sex;
  } student1;
  strcpy(student1.name.first, "John");
*/ 
void arraystruct() {
  struct name {
    char first[50];
    char last[50];
  };
  struct student {
    struct name name;
    short age;
    char sex;
  } student1;
  //strcpy(student1.name.first, "John");

  struct name n = {"John", "Doe"};
  student1 = (struct student){n, 20, 'm'};
  printf("%s\n", student1.name.first);
  student1.name.first[0] = 'H';
  printf("%s\n", student1.name.first);
  strcpy(student1.name.first, "Yang");
  printf("%s\n", student1.name.first);
}

/*struct的自我引用*/
/*
  struct Node {
    int value;
    struct Node* next;
  };
*/
void genTree() {
  struct Node {
    int value;
    struct Node* next;
  };
  struct Node n1 = {.value = 1};
  struct Node n2 = {.value = 2};
  struct Node n3 = {.value = 3};
  struct Node n4 = {.value = 4, .next = NULL};
  n1.next = &n2;
  n2.next = &n3;
  n3.next = &n4;
  struct Node* p = &n1;
  while (p != NULL) {
    printf("%d\n", p->value);
    p = p->next;
  }

  //使用malloc生成节点
  struct Node* head = malloc(sizeof(struct Node));
  head->value = 1;
  head->next = NULL;
  struct Node* another = head;
  for (int i = 2; i <= 4; i++) {
    struct Node* newNode = malloc(sizeof(struct Node));
    newNode->value = i;
    newNode->next = NULL;
    if (head->next == NULL) {
      head->next = newNode;
    }
    head = head->next;
  }

  while (another != NULL) {
    printf("%d\n", another->value);
    another = another->next; //63569 segmentation fault  ./struct
  }
}

/*struct定义二进制组成的数据结构, 位字段*/
/*
  struct {
  unsigned int ab:1;
  unsigned int cd:1;
  unsigned int ef:1;
  unsigned int gh:1;
  } synth;

  synth.ab = 0;
  synth.cd = 1;
*/

/*弹性数组成员*/
//不能事先确定数组成员的数量时，可以定义一个 struct 结构
//弹性数组成员有一些专门的规则。首先，弹性成员的数组，必须是 struct 结构的最后一个属性。另外，除了弹性数组成员，struct 结构必须至少还有一个其他属性
/*
  struct mstring {
    int len;
    char b[];
  };
  为struct mstring分配它需要的内存：它本身占用的内存长度，再加上n个数组成员占用的内存长度。最后，len属性记录一下n是多少。
  struct mstring* m = malloc(sizeof(struct mstring) + sizeof(char) * n);
  m->len = n;
*/
