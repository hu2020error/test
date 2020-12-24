#include<stdio.h>
#include<stdlib.h>
void th1(){
printf("1\n");
}

void th2(){

printf("2\n");
}


int main(){
int k;
while(1){
printf("please input a number :");
scanf("%d",&k);
//getchar();
//printf("the number is :%d",k);
switch(k)
{
case 1:
th1();
break;

case 2:
th2();
break;

default :
printf("no find\n");
break;

}
}
return 0;
}
