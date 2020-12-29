#include"TreeSearch.h"
#include"BinarySearch.h"
#include"Hash.h"

int main()
{
int j , addr;
HashTable H;
Init(&H);

Pnode* root = (Pnode*)malloc(sizeof(Pnode));
Datatype arr[7]={12,34,11,6,3,2,32};

for (j = 0; j<7; j++)
{
	Insert(&H, arr[j]);
}

int i,s;
printf("存储的元素\n");
for(i=0; i<7 ;i++){
printf("%d\t",arr[i]);
insert(root, arr[i]);
}

printf("\n散列表元素显示\n");
Result(&H);

InsertSort(arr,7);

Datatype locate;
printf("\nplease input you want:");

scanf("%d",&locate);
s=BinarySearch1(arr, 7, locate);

addr = Search(&H, locate);

printf("the BinarySearch sort result is :%d\n",s);

if (addr == -1)
printf("元素不存在\n");
	else
printf("%d元素在表中的位置是:%d\n", locate,addr);

Pnode *res;
if((res = search(root, locate)) != NULL){
printf("TreeSearch Finding the number:%d\n",*(res->key));
}
else
	printf("the TreeSearch is not find\n");

}
