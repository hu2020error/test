#include<stdio.h>
#include<stdlib.h>


typedef struct node{
int id;
int score;
int rank;
//char name[6];
}Node;


void save(Node *p){

FILE *fp;
char filename[30];
printf("please input the filename\n");
scanf("%s",filename);
fp=fopen(filename,"a");


p->id=1;
p->score=2;
p->rank=3;
//p->name='qq';

fprintf(fp,"%d %d %d ",p->id,p->score,p->rank);
fclose(fp);
}

void new1(Node *p){
FILE *fp1;
char filename[30];

printf("please input the filename\n");
scanf("%s",filename);
fp1=fopen(filename,"r");
if(fp1==NULL){
printf("Can't find the file");
exit(0);}
while(!feof(fp1)){
fscanf(fp1,"%d %d %d ",&p->id,&p->score,&p->rank);
printf("%d\t%d\t%d\t",p->id,p->score,p->rank);}
fclose(fp1);
}

int main(){


Node *head=(Node*)malloc(sizeof(Node));
//save(head);
new1(head);
}
