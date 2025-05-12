#include <stdio.h>

/*if语句*/
/*
  示例
  int x = 10;
  if (x == 10) {
    printf("x == 10\n");
  }
*/

/*switch语句*/
/*
  示例
  int x = 10;
  switch (x) {
    case 10:
      printf("x == 10\n");
      break;
    case 20:
      printf("x == 20\n");
      break;
    default:
      printf("x != 10 && x != 20\n");
      break;
  }
*/

/*if-else if - else*/
/*
  示例
  int x = 10;
  if (x == 10) {
    printf("x == 10\n");
  } else if (x == 20) {
    printf("x == 20\n");
  } else {
    printf("x != 10 && x != 20\n");
  }
*/

/*嵌套*/
/*
  示例
  int x = 10;
  if (x == 10) {
    printf("x == 10\n");
    if (x == 20) {
      printf("x == 20\n");
    }
  }
*/

/*三元运算符*/
/*
  示例
  int x = 10;
  x == 10 ? printf("x == 10\n") : printf("x != 10\n"); 
*/

/*while语句*/
/*
  示例
  int i = 0;
  while (i < 10) {
    printf("%d\n", i);
    i++;
  }
*/

/*do while语句*/ //至少执行一次
/*
  示例
  int i = 0;
  do {
    printf("%d\n", i);
    i++;
  } while (i < 10);
*/

/*for语句*/
/*
  示例
  for (int i = 0; i < 10; i++) {
    printf("%d\n", i);
  }
*/

/*break语句*/
/*
  示例
  for (int i = 0; i < 10; i++) {
    if (i == 5) {
      break;
    }
    printf("%d\n", i);
  }
*/

/*continue语句*/
/*
  示例
  for (int i = 0; i < 10; i++) {
    if (i == 5) {
      continue;
    }
    printf("%d\n", i);
  }
*/

/*goto语句*/
/*
  示例
  int i = 0;
  for (i = 0; i < 10; i++) {
    if (i == 5) {
      goto end;
    }
    printf("%d\n", i);
  }
end:
  printf("end\n");
*/