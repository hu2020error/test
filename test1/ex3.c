#include"ex.h"


//数据导入文件
void Save(student *head){
	if(head->next == NULL)	//判断链表是否为空
	{printf("the data is empty!\n");
	exit(1);}
	
	FILE *fp;
	char filename[30];	//定义文件名
	printf("please input the filename\n");
	scanf("%s",filename);	//输入文件名
	fp=fopen(filename,"w");	//以写的方式打开文件

	student *p = head->next;
	//将每个节点内容输入文件
	while(p != NULL){
	fprintf(fp," %d %d %d %s",p->id,p->score,p->rank,p->name);
	p=p->next;}

	fclose(fp);	//关闭文件
	}

//数据导入链表
void Newfile(student *head){
	FILE *fp1;
	char filename[30];	//定义文件名
	printf("please input the filename\n");	//进入指定文件
	scanf("%s",filename);
	fp1=fopen(filename,"r");	//以读取方式打开文件
	//判断是否读取成功
	if(fp1==NULL){
	printf("Can't find the file");
	exit(1);}

	int i=0;
	student *s=head;
	//遍历文件
	while(!feof(fp1)){
	//将s移到s的下一个位置
	student *p1=(student*)malloc(sizeof(student));	//用指针p接收中间值
	fscanf(fp1,"%d %d %d %s ",&p1->id,&p1->score,&p1->rank,p1->name);	//将文件中的值输入到节点
	s->next=p1;	//s下一个指向节点p
	s=s->next;	//将s移到s的下一个位置
	}

	s->next=NULL;
	fclose(fp1);	//关闭文件
}

/*void InputStudent(student *head){
	//定义一个指向学生信息的指针
	student* node = (student*)malloc(sizeof(student));
//指针下一个指向空
	node->next = NULL;

	//录入学生信息
	printf("请输入学生姓名：\n");
	scanf("%s", node->name);
//	getchar();
	printf("请输入学号：\n");
	scanf("%d", &(node->id));
	printf("请输入成绩：\n");
	scanf("%d", &(node->score));

//head->next=node;
	student* p = head->next;
	while (head->next != NULL && p->next != NULL)
	{
		p = p->next;
	}

	//把节点插到链表的尾节点
	if (head->next == NULL) {
		head->next = node;
	printf("学生信息录入成功!\n");
	}
	else {
	p->next = node;
                       }

	}
*/

void PrintStudent(student *head){
       if(head->next == NULL)	//判断链表是否为空
	{printf("the data is empty!\n");
	exit(1);}
	
	Sort(head);	//打印前进行排序
	
	student *p=(student*)malloc(sizeof(student));
	p=head->next;
	//遍历学生信息
	while(p != NULL){
 	printf("\t学号\t名字\t成绩\t排名\t\n");
	//输出学生信息
	printf("\t%d\t%s\t%d\t%d\t\n",p->id,p->name,p->score,p->rank);
	
        p=p->next;
	}
	}

//
void CountStudent(student *head)
	{
        if(head->next == NULL)
	{printf("the data is empty!\n");
	exit(1);}
	
	int i=0;
	student *p=(student*)malloc(sizeof(student));
	p=head->next;
/*        if(p = NULL)
	{printf("the data is empty!!!!\n");
	exit(1);}*/
	while(p != NULL){
	p=p->next;
	i++;
//printf("sacss");
                 	}
	printf("the number of student is: %d\n",i);

	}

void FindStudent(student *head){
//	empty();
        if(head->next == NULL)
	{printf("the data is empty!\n");
	exit(1);}

	student *p=(student*)malloc(sizeof(student));
	p=head->next;
	int id;
	printf("please input ID");
	scanf("%d",&id);
	while(p->id != id && p != NULL){
	p=p->next;
	}
	if(p==NULL){
	//printf("")
	printf("Did not find the information about the ID\n");}
	else
	//return p;
 	{printf("\t学号\t名字\t成绩\t排名\t\n");
	printf("\t%d\t%s\t%d\t\n",p->id,p->name,p->score);
	}
	}

void ChangeStudent(student *head){
//empty();
        if(head->next == NULL)
	{printf("the data is empty!\n");
	exit(1);}
	student *p=head->next;
	int id;
	printf("please input ID");
	scanf("%d",&id);
	while(p->id != id && p != NULL){
	p=p->next;
	}
	if(p==NULL)
	printf("Did not find information about the ID\n");

	else
	{ 
	int k;
	printf("The before is %d\n",p->score);

	printf("the score you want is :");
	scanf("%d",&k);
	p->score=k;

	printf("The after is %d\n",p->score);
	}
	}

void DeleteStudent(student *head){
//empty();
        if(head->next == NULL)
	{printf("the data is empty!\n");
	exit(1);}

	student *p=head->next;
	int id;
	printf("please input ID");
	scanf("%d",&id);
	student *node1 = (student*)malloc(sizeof(student));
	
	while(p->id != id && p != NULL){
	node1 = p;
	p=p->next;
	}

	if(p == NULL)
	printf("Did not find the information about the ID");
	else

	if (head->next->id == id)
	{head->next=NULL;
	printf("the information is delete!!!\n");
	}
	else{//p=node1;
//p->next=node1->next->next;
	node1->next=p->next;  
	free(p);
	p=NULL;
	printf("the information is delete!!!\n");}

	}


void Sort(student *head){
	student *p=head->next;
	student *t=head->next;
	int i=0;
	while(t != NULL){
	t=t->next;
	i++;
	}
//printf("the num %d\n",i);
//printf("shurucg\n");

	int j,k,m;

	for(k=1;k<i+1;k++){
//printf("shurucg\n");
	m = 0;
//printf("the num ");
	j = p->score;
//printf("\t%d\t",j);

	if( i==1 && p->next == NULL)
	p->rank=1;
	else{
	student *s=head->next;
	while(s != NULL ){
	if(j > s->score)
	m++;
	else
	if(j == s->score && s != p)
	m++;
	s = s->next;
	}

	p->rank = i-m;
	p=p->next;
	}
	}

	}










	
