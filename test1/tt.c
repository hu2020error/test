#include<stdio.h>
#include<stdlib.h>
int main(){

typedef struct Student{
char name[20];	//学生名字
int id;		//学生学号
int score;	//学生成绩
//int rank;	//学生排名
}student;

typedef struct node{
student *stu;
struct node *next;
}Node;

Node *node=(Node*)malloc(sizeof(Node));
node->stu = (student*)malloc(sizeof(student));

printf("请输入学生姓名：\n");
scanf("%s", node->stu->name);

printf("请输入学号：\n");
scanf("%d", &(node->stu->id));

printf("请输入成绩：\n");
scanf("%d", &(node->stu->score));



}
