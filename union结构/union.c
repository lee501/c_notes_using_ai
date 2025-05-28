
/*union结构
  用于不同的场合表示不同数据类型的一种数据结构

  union foo {
    int i;
    float f;
    char c;
  };
  赋值
  union foo f;
  f.i = 10;
  f.f = 3.14;
  f.c = 'A'; 

  // 写法一
  union foo q;
  q.i = 4;

  // 写法二
  union foo q = {.i=4};

  // 写法三
  union foo q = {4}; //不指定属性名，就会赋值给第一个属性。
*/

/*union结构指针 使用指针运算符->取值*/ 
/*
  union quantity {
    short count;
    float weight;
    float volume;
  };

  union quantity q;
  q.count = 4;

  union quantity* ptr;
  ptr = &q;

  printf("%d\n", ptr->count);

  #Union 结构指针与它的属性有关，当前正在按照哪个属性解读数据，它的指针就是对应的数据类型。
  union foo {
    int a;
    float b;
  } x;

  int* foo_int_p = (int *)&x;
  float* foo_float_p = (float *)&x; //取地址转换指针

  x.a = 12;
  printf("%d\n", x.a);           // 12
  printf("%d\n", *foo_int_p);    // 12

  x.b = 3.141592;
  printf("%f\n", x.b);           // 3.141592
  printf("%f\n", *foo_float_p);  // 3.141592
*/