#ifndef TreeSearch_h
#define TreeSearch_h
#include<stdio.h>
#include<stdlib.h>

typedef int Datatype;

typedef struct Node{
Datatype *key;
struct Node *left, *right;
}Pnode;

void insert(Pnode *,Datatype);
Pnode* search(Pnode *,Datatype);


#endif
