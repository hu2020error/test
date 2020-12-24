#include<stdio.h>
#include<stdlib.h>

typedef struct Student{
char name[20];	//学生名字
int id;		//学生学号
int score;	//学生成绩
int rank;	//学生排名
}student;

typedef struct node{
student *stu;
struct node *next;
}Node;

void Menu(){
	printf("*************************************************\n");
	printf("*\t欢迎使用高校学生成绩管理系统\t*\n");
	printf("*\t\t请选择功能\t\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.录入学生信息\t\t\t*\n");
	printf("*\t\t2.打印学生信息\t\t\t*\n");
	printf("*\t\t3.统计所有学生人数\t\t*\n");
	printf("*\t\t4.查找学生信息\t\t\t*\n");
	printf("*\t\t5.修改学生信息\t\t\t*\n");
	printf("*\t\t6.删除学生信息\t\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("*************************************************\n");
}
void InputStudent(Node *head){
	//定义一个指向学生信息的指针
	Node* node = (Node*)malloc(sizeof(Node));
	//指针下一个指向空
	node->next = NULL;

	//录入学生信息
	printf("请输入学生姓名：\n");
	scanf("%s", node->stu->name);
	printf("请输入学号：\n");
	scanf("%d", &(node->stu->id));
	printf("请输入成绩：\n");
	scanf("%d", &(node->stu->score));

	printf("学生信息录入成功!\n");
	Node* p = head;
	while (head != NULL && p->next != NULL)
	{
		p = p->next;
	}

	//把节点插到链表的尾节点
	if (head == NULL) {
		head = node;
	}
	else {
	p->next = node;
                       }
	}

void PrintStudent(Node *head){
 //	empty();
        Node *p=head;
        while(p != NULL){

	//输出学生信息
 	printf("\t学号\t名字\t成绩\t排名\t\n");
	printf("\t%d\t%s\t%d\t\n",p->stu->id,p->stu->name,p->stu->score);
        p=p->next;
	}

	}

void CountStudent(Node *head)
	{
//	empty();
	int i=0;
	Node *p=head;
	while(p != NULL){
	p=p->next;
	i++;
                 	}
printf("the number of student is %d\n",i);

	}

void FindStudent(Node *head, int id){
//	empty();
	Node *p=head;
	while(p->stu->id != id && p != NULL){
	p=p->next;
	}
	if(p=NULL){
	//printf("")
	printf("Did not find the information about the ID\n");}
	else
	//return p;
 	{printf("\t学号\t名字\t成绩\t排名\t\n");
	printf("\t%d\t%s\t%d\t\n",p->stu->id,p->stu->name,p->stu->score);
}
	}

void ChangeStudent(Node *head,int id){
//empty();
Node *p=head;
while(p->stu->id != id && p != NULL){
p=p->next;
}
if(p=NULL)
printf("Did not find information about the ID\n");
// return -1;                           }

else
{ 
int k;
Node *s = p;
printf("the score you want is :");
scanf("%d",&k);
p->stu->score=k;

printf("The before is %d\n",s->stu->score);
printf("The after is %d\n",p->stu->score);
	}
}

void DeleteStudent(Node *head,int id){
//empty();
Node *p=head;
Node *node1 = (Node*)malloc(sizeof(Node));
while(p->stu->id != id && p != NULL){
node1 = p;
p=p->next;
}

if(p = NULL)
printf("Did not find the information about the ID");
else
{p=node1;
p->next=node1->next->next;
  free(node1);
printf("the information is delete!!!");
}

}


int main(){
         	Node *head=NULL;
		Menu();	
		
}
return 0;
}
