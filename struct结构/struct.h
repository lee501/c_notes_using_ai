/* struct.h */
#ifndef STRUCT_H
#define STRUCT_H

struct turtle
{
  char* name;
  char* species;
  int age; 
};

void paramstruct(struct turtle);
void happy(struct turtle*);
void genTree();
#endif