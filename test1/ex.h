#ifndef ex2_h
#define ex2_h
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

//结构体保存学生信息
typedef struct Student{
char name[20];	//学生名字
int id;		//学生学号
int score;	//学生成绩
int rank;	//学生排名
struct Student *next;
}student;

//管理员密码
typedef struct Admin{
int name;
int code;
struct Admin *next;
}admin;

void login(admin *,student *);//管理员注册界面
void enter(admin *,student *);//管理员登入界面

void Newfile(student *,admin *);//把文件中数据导入链表
void Save(student *,admin *);//把数据导入文件中

void InputStudent(student *, admin *);//插入学生信息
void PrintStudent(student *,admin *);//打印学生信息
void CountStudent(student *, admin *);//计算学生总人数
void FindStudent(student *, admin *);//打印指定学生信息
void ChangeStudent(student *, admin *);//修改学生信息
void DeleteStudent(student *,admin *);//删除学生信息
void Sort(student *,admin *);//对学生进行排序

void menu1(student *, admin *);//打印主菜单
void menu2(student *,admin *);//打开管理员界面
void menu3(student *,admin *);//打开普通用户界面

#endif
