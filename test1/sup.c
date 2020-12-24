#include"sup.h"


int menu1(List *head1){

printf("*************************************************\n");
printf("*\t欢迎使用超市管理系统\t*\n");
printf("*\t\t请选择功能\t\t\t*\n");
printf("*************************************************\n");
printf("*\t\t1.管理员\t\t\t*\n");
printf("*\t\t2.客户\t\t\t*\n");
printf("*\t\t0.退出系统\t\t\t*\n");
printf("*************************************************\n");


int choose;
printf("请选择您要的服务：");
scanf("%d",&choose);
switch(choose){
case 1:
menu2(head1);
break;
case 2:
//menu3();
break;
case 0:
exit(1);
break;
default:
printf("请输入正确指令\n");
menu1(head1);
break;
}
}
//管理员界面
int menu2(List *head2){

printf("*************************************************\n");
printf("*\t这里是管理员界面\t*\n");
printf("*\t\t请选择功能\t\t\t*\n");
printf("*************************************************\n");
printf("*\t\t1.商品入库\t\t\t*\n");
printf("*\t\t2.商品下架\t\t\t*\n");
printf("*\t\t3.商品信息修改\t\t\t*\n");
printf("*\t\t4.商品信息查询\t\t\t*\n");
printf("*\t\t0.返回主页面\t\t\t*\n");
printf("*************************************************\n");

int choose;
printf("请选择您要的服务：");
scanf("%d",&choose);
switch(choose){
case 1:
InGoods(head2);
break;
case 2:
OutGoods(head2);
break;
case 3:
ChangeGoods(head2);
break;
case 4:
FindGoods(head2);
break;
case 0:
menu1(head2);
break;
default:
printf("请输入正确指令\n");
menu2(head2);
break;
}
}

void InGoods(List *head3){

List *node1=head3;
while(node1->next != NULL){
node1=node1->next;
printf("洒出八十八出口市场");
}

List *node = (List*)malloc(sizeof(List));
node->next=NULL;

//node1=node;
node1->next=node;

printf("*\t\t请依次输入商品信息\t\t\t*\n");
printf("*\t\t请输入商品名字：\t\t\t*\n");
scanf("%s",node->name);
//getchar();
printf("*\t\t请输入商品ID：\t\t\t*\n");
scanf("%d",&node->ID);
//getchar();
printf("*\t\t请输入商品进价：\t\t\t*\n");
scanf("%d",&node->input);
//getchar();
printf("*\t\t请输入商品售价：\t\t\t*\n");
scanf("%d",&node->output);
printf("*\t\t请输入商品数量：\t\t\t*\n");
scanf("%d",&node->num);
//getchar();

printf("\t\t商品名字\t商品ID\t商品进价\t商品售价\t商品数量\n\t\t%s\t%d\t%d\t%d\t%d\t\t\n",node->name,node->ID,node->input,node->output,node->num);
//FindGoods(head3);
printf("*\t\t请选择功能\t\t\t*\n");
printf("*************************************************\n");
printf("*\t\t1.商品入库\t\t\t*\n");
printf("*\t\t2.商品下架\t\t\t*\n");
printf("*\t\t3.商品信息修改\t\t\t*\n");
printf("*\t\t4.商品信息查询\t\t\t*\n");
printf("*\t\t0.返回主页面\t\t\t*\n");
printf("*************************************************\n");

int choose;
printf("请选择您要的服务：");
scanf("%d",&choose);
switch(choose){
case 1:
InGoods(head3);
break;
case 2:
OutGoods(head3);
break;
case 3:
ChangeGoods(head3);
break;
case 4:
FindGoods(head3);
break;
case 0:
menu1(head3);
break;
default:
break;
}
}

void OutGoods(List *head4){
int k;
printf("*\t\t请输入你想查找的商品ID\t\t*\n");
scanf("%d",&k);

List *node1;
List *node = head4->next;
while(node != NULL && node->ID != k ){
node1 = node;
node=node->next;
}


if(node == NULL)
printf("没有找到该商品相关信息\n");
else
{
node1->next = node->next;
free(node);
node=NULL;
printf("已经删除该商品\n");
}



}

void ChangeGoods(List *head){
int k;
printf("*\t\t请输入你想修改的商品ID\t\t*\n");
scanf("%d",&k);

List *node = head->next;
while(node != NULL && node->ID != k){
node=node->next;
}

if(node == NULL)
printf("没有找到该商品相关信息\n");
else
{
printf("*\t\t请依次输入商品信息\t\t\t*\n");
printf("*\t\t请输入商品名字：\t\t\t*\n");
scanf("%s",node->name);
//getchar();
printf("*\t\t请输入商品ID：\t\t\t*\n");
scanf("%d",&node->ID);
//getchar();
printf("*\t\t请输入商品进价：\t\t\t*\n");
scanf("%d",&node->input);
//getchar();
printf("*\t\t请输入商品售价：\t\t\t*\n");
scanf("%d",&node->output);
printf("*\t\t请输入商品数量：\t\t\t*\n");
scanf("%d",&node->num);

printf("商品信息已经修改\n");
}

}

void FindGoods(List *head){

int k;
printf("*\t\t请输入你想查找的商品ID\t\t*\n");
scanf("%d",&k);

List *node = head->next;
while(node != NULL && node->ID != k){
node=node->next;
}

if(node == NULL)
printf("没有找到该商品相关信息\n");

else
printf("\t\t商品名字\t%s\t商品ID\t商品进价\t商品售价\t商品数量\t\t\n\t\t\t%d\t%d\t%d\t%d\t\t\n",node->name,node->ID,node->input,node->output,node->num);

}


