#include"ex.h"

//主菜单
void menu1(student *head, admin *head1){

	printf("*************************************************\n");
	printf("*\t欢迎使用学生管理系统\t*\n");
	printf("*\t\t请选择功能\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.管理员登入\t\t\t*\n");
	printf("*\t\t2.客户\t\t\t*\n");
	printf("*\t\t3.管理员注册\t\t\t*\n");
	printf("*\t\t0.退出系统\t\t\t*\n");
	printf("请选择您要的服务：");

	int choose;
	scanf("%d",&choose);	//输入所需调用的函数

	switch(choose){
	case 1:
	enter(head1,head);
	break;
	case 2:
	menu3(head,head1);
	case 3:
	login(head1,head);
	break;
	case 0:
	exit(1);
	break;
	//若输入命令错误
	default:
	printf("请输入正确指令\n");
	menu1(head,head1);
	break;
	}
	}

//菜单二
void menu2(student *head2,admin *node){
	printf("*************************************************\n");
	printf("*\t这里是管理员界面\t*\n");
	printf("*\t请选择功能      \t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.学生信息输入\t\t\t*\n");
	printf("*\t\t2.学生信息打印\t\t\t*\n");
	printf("*\t\t3.学生信息查找\t\t\t*\n");
	printf("*\t\t4.学生信息修改\t\t\t*\n");
	printf("*\t\t5.学生信息删除\t\t\t*\n");
	printf("*\t\t6.学生信息入库\t\t\t*\n");
	printf("*\t\t7.学生信息刷新\t\t\t*\n");
	printf("*\t\t0.返回主页面  \t\t\t*\n");

	int choose;
	printf("请选择您要的服务：");
	scanf("%d",&choose);	//输入所需调用的函数

	switch(choose){
	case 1:
	InputStudent(head2,node);
	break;
	case 2:
	PrintStudent(head2,node);
	break;
	case 3:
	FindStudent(head2,node);
	break;
	case 4:
	ChangeStudent(head2,node);
	break;
	case 5:
	DeleteStudent(head2,node);
	break;
	case 6:
	Save(head2,node);
	break;
	case 7:
	Newfile(head2,node);
	break;
	case 0:
	menu1(head2,node);
	break;
	//若输入错误命令
	default:
	printf("请输入正确指令\n");
	menu2(head2,node);
	break;
	}
	}

//菜单三
void menu3(student *head,admin *node){

	printf("*************************************************\n");
	printf("*\t学生信息自助查询中心\t*\n");
	printf("*\t\t请选择功能\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.查找指定学生信息\t\t\t*\n");
	printf("*\t\t0.返回主页面      \t\t\t*\n");
	printf("请选择您要的服务：");

	int choose;
	scanf("%d",&choose);	//输入所需调用函数

	switch(choose){
	case 1:
	FindStudent(head,node);
	case 0:
	menu1(head,node);
	break;
	//若输入错误命令
	default:
	menu3(head,node);
	printf("请输入正确指令\n");
	break;
	}
	}

//管理员注册
void login(admin *head,student *head2){

	FILE *fp;
	admin *s = (admin*)malloc(sizeof(admin));
	s->next = NULL;
	int name;
	printf("请输入用户名(数字)：");
	scanf("%d",&name);
	s->name=name;

	int code;
	printf("请输入密码：");
	scanf("%d",&code);
	s->code=code;

	int code1;
	printf("请再输入一遍密码：");
	scanf("%d",&code1);
	if(s->code==code1)
	{
	fp = fopen("code","a");	//以读写方式打开文件
	if(fp==NULL)
	printf("文件打开失败");

	else
	{
	admin *p = head;
	while(p->next != NULL){
	p=p->next;
	}

	p->next=s;

	fprintf(fp," %d %d",s->name,s->code);
	printf("注册成功\n");
	//private1(head);
	}
	fclose(fp);

	}

	else
	printf("两次密码不一样!\n注册失败!\n");
	menu1(head2,head);
	}



//管理员登入
void enter(admin *head, student *head2){

	FILE *fp2;
	fp2=fopen("code","r");

	int num = 0;
	admin *s = head;
	while(!feof(fp2)){
	admin *p=(admin*)malloc(sizeof(admin));

	fscanf(fp2,"%d %d ",&p->name,&p->code);
	s->next = p;
	s = s->next;
	num++;
	}
	s->next = NULL;
	fclose(fp2);


	if(head->next==NULL){
	printf("文件库没有管理员信息\n");
	menu1(head2,head);
	}

	else{
	admin *t=head->next;
	int name;
	printf("请输入输入用户名：");
	scanf("%d",&name);

	int i=0;
	while(t->name != name && i < num-1)
	{t=t->next;
	i++;
	}

	if(t->name != name)
	{
	printf("用户名输入有误！\n");
	menu2(head2,head);
	}
	else
	{
	int code1;
	printf("请输入密码：");
	scanf("%d",&code1);
	if(code1==t->code)
	{
	printf("密码正确\n");
	menu2(head2,head);
	}
	else

	{
	printf("*************************************************\n");
	printf("*\t学生信息自助查询中心\t*\n");
	printf("*\t\t请选择功能\t\t*\n");
	printf("*************************************************\n");
	printf("*\t\t1.重新尝试登入\t\t\t*\n");
	printf("*\t\t0.返回主页面      \t\t\t*\n");

	printf("请选择您要的服务：");

	int choose;
	scanf("%d",&choose);	//输入所需调用函数

	switch(choose){
	case 1:
	enter(head,head2);
	case 0:
	menu1(head2,head);
	break;
	//若输入错误命令
	default:
	printf("请输入正确指令\n");
	menu1(head2,head);
	break;
	}
	}
	}
	}
	}

//数据导入文件
void Save(student *head,admin *ad){
	if(head->next == NULL)	//判断链表是否为空
	{printf("the data is empty!\n");
	exit(1);}
	
	FILE *fp;
	char filename[30];	//定义文件名
	printf("please input the filename\n");
	scanf("%s",filename);	//输入文件名
	fp=fopen(filename,"a");	//以写的方式打开文件

	student *p = head->next;

	//将每个节点内容输入文件
	while(p != NULL){
	fprintf(fp," %d %d %d %s",p->id,p->score,p->rank,p->name);
	p=p->next;}

	fclose(fp);	//关闭文件
	menu2(head, ad);
	}

//数据导入链表
void Newfile(student *head,admin *ad){
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
	student *p=(student*)malloc(sizeof(student));	//用指针p接收中间值
	fscanf(fp1,"%d %d %d %s ",&p->id,&p->score,&p->rank,p->name);	//将文件中的值输入到节点
	s->next=p;	//s下一个指向节点p

	s=s->next;	//将s移到s的下一个位置
	}

	s->next=NULL;
	fclose(fp1);	//关闭文件
	PrintStudent(head,ad);
	menu2(head, ad);
	}

//插入学生信息
void InputStudent(student *head,admin *ad){
	//定义一个指向学生信息的指针
	student* node = (student*)malloc(sizeof(student));
	//节点下一个指向空
	node->next = NULL;

	//录入学生信息
	printf("请输入学生姓名：\n");
	scanf("%s", node->name);
	printf("请输入学号：\n");
	scanf("%d", &(node->id));
	printf("请输入成绩：\n");
	scanf("%d", &(node->score));

	student* p = head->next;
	//找到链表的最后一个节点
	while (head->next != NULL && p->next != NULL)
	{
		p = p->next;
	}

	//如果链表为空把node节点插到第一个节点
	if (head->next == NULL) {
	head->next = node;
	printf("学生信息录入成功!\n");
	}
	else	//链表不为空最后一个节点指向node节点
	p->next = node;
	menu2(head, ad);
	}

//打印学生信息
void PrintStudent(student *head,admin *ad){
	if(head->next == NULL)	//判断链表是否为空
	{printf("the data is empty!\n");
	exit(1);}
	
	Sort(head,ad);	//打印前进行排序
	
	student *p=head->next;
        //遍历学生信息
	while(p != NULL){
 	printf("\t学号\t名字\t成绩\t排名\t\n");
	//输出学生信息
	printf("\t%d\t%s\t%d\t%d\t\n",p->id,p->name,p->score,p->rank);
	
        p=p->next;
	}
	CountStudent(head,ad);
	menu2(head, ad);
	}

//计算学生总人数
void CountStudent(student *head,admin *ad){
	if(head->next == NULL)	//若链表为空
	{printf("the data is empty!\n");
	exit(1);}
	
	int i=0;
	student *p=(student*)malloc(sizeof(student));
	p=head->next;
	//遍历链表直到最后一个为空
	while(p != NULL){
	p=p->next;
	i++;}
	
	printf("the number of student is: %d\n",i);	//输出学生总人数
	}

//打印指定学生信息
void FindStudent(student *head,admin *ad){
        if(head->next == NULL)	//判断链表是否为空
	{printf("the data is empty!\n");
	exit(1);}

	student *p=(student*)malloc(sizeof(student));
	p=head->next;
	int id;
	printf("please input ID");
	scanf("%d",&id);
	//找到id的节点
	while(p->id != id && p != NULL){
	p=p->next;
	}
	
	if(p==NULL)	//遍历结束没有找到id
	{printf("Did not find the information about the ID\n");
	menu2(head, ad);}
	else
 	{printf("\t学号\t名字\t成绩\t排名\t\n");
	printf("\t%d\t%s\t%d\t%d\t\n",p->id,p->name,p->score,p->rank);
	menu2(head, ad);
	}
	}

//修改学生信息
void ChangeStudent(student *head,admin *ad){
        if(head->next == NULL)	//判断链表是否为空
	{printf("the data is empty!\n");
	exit(1);}
	
	student *p=(student*)malloc(sizeof(student));
	p=head->next;
	int id;
	printf("please input ID");
	scanf("%d",&id);
	//找到id的节点
	while(p->id != id && p != NULL){
	p=p->next;
	}
	
	if(p==NULL)	//遍历到结束没有找到id
	printf("Did not find information about the ID\n");

	else	//若找到id
	{ 
	
	printf("the before\n");	//打印修改修改前的信息
	printf("\t学号\t名字\t成绩\t排名\t\n");
	printf("\t%d\t%s\t%d\t%d\t\n",p->id,p->name,p->score,p->rank);

	printf("if want to change score 输入 1\n");
	int a;
	scanf("%d",&a);
	if(a == 1)	//判断是否需要修改
	{printf("the score you want is :");
	scanf("%d",&p->score);}
	else
	printf("the score is not change\n");


	printf("if want to change name 输入 1\n");
	int b;
	scanf("%d",&b);
	if(b == 1)	//判断是否需要修改
	{printf("the name you want is :");
	scanf("%s",p->name);}
	else
	printf("the name is not change\n");
	
	Sort(head,ad);	//对修改后的信息重新排序

	printf("The after\n");	//打印修改后的信息
	printf("\t学号\t名字\t成绩\t排名\t\n");
	printf("\t%d\t%s\t%d\t%d\t\n",p->id,p->name,p->score,p->rank);
	
	menu2(head, ad);
	}
	}

//删除学生信息
void DeleteStudent(student *head,admin *ad){
        if(head->next == NULL)	//判断是否为空
	{printf("the data is empty!\n");
	exit(1);}

	student *p=(student*)malloc(sizeof(student));
	p=head->next;
	int id;
	printf("please input ID");
	scanf("%d",&id);
	student *node1 = (student*)malloc(sizeof(student));
	
	while(p->id != id && p != NULL){
	node1 = p;	//前一个指针
	p=p->next;
	}

	if(p == NULL)	//判断id是否存在
	printf("Did not find the information about the ID");
	else

	if(head->next->id == id)	//如果只有一个节点时
	{head->next=NULL;
	printf("the information is delete!!!\n");

	menu2(head, ad);
	}
	else{
	//node1->next=p->next;	//删除id所在的节点
	//free(p);
	//p=NULL;
	p=node1;
	p->next=p->next->next;
	printf("the information is delete!!!\n");
	menu2(head, ad);
	}
	}

//对学生进行排序
void Sort(student *head,admin *ad){
	student *p=head->next;
	student *t=head->next;

	//计算学生总人数
	int i=0;
	while(t != NULL){
	t=t->next;
	i++;
	}

	int j,k,m;

	//学生成绩信息遍历
	for(k=1;k<i+1;k++){
	m = 0;
	j = p->score;//对每个成绩与所有比较

	if( i==1 && p->next == NULL)//只有一个节点
	p->rank=1;
	else{
	student *s=head->next;
	
	//学生成绩进行遍历
	while(s != NULL ){
	if(j > s->score)	//计算小于指定成绩的个数
	m++;
	else
	if(j == s->score && s != p)//成绩相等时判断是否是自己
	m++;		//不是自己加一
	s = s->next;
	}

	p->rank = i-m;
	p=p->next;
	}
	}
	}
