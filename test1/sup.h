#ifndef sup_h
#define sup_h
#include<stdio.h>
#include<stdlib.h>

typedef struct item{
char name[20];
int ID;
int input;
int output;
int num;
struct item *next;
}List;


int menu1(List *); //主界面菜单
int menu2(List *); //管理员菜单
//int menu3(); //顾客菜单

void InGoods(List *);
void OutGoods(List *);
void ChangeGoods(List *);
void FindGoods(List *);


#endif
