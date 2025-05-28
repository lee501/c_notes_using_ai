
/*typedef命令 用来给数据类型起别名*/
/*
  typedef type name; type代表类型名，name代表别名。

  
  typedef unsigned char BYTE;

  BYTE c = 'z';
*/

/*给指针起别名*/
/*
  typedef int* p_int;
  p_int p = NULL;
*/

/*给数组起别名*/
/*
  typedef int array[10];
  array a = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  与
  int a[5] = {11, 22, 33, 44, 55}; 数组的声明和赋值
*/

/*给函数起别名*/
/*
  typedef int (*p_func)(int, int);
  p_func是一个指针，代表函数 int* call(int a, int b)
*/

/*给结构起别名*/
/*
  struct Node {
    int a;
    int b;
  };
  typedef struct Node* Tree;
  Tree s = {1, 2};

  简介写法
  typedef struct {
    int a;
    int b;
  } Node;

  typedef Node* Tree;

  Tree s = &(Node){1, 2}; // 使用复合字面量

  
  typedef struct {
    char *name;
    int leg_count, speed;
  } animal; //相当于为一个匿名的数据类型起了别名animal
*/

