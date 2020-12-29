#ifndef Hash_h
#define Hash_h
#include<stdio.h>
#include<stdlib.h>

#define HASHSIZE 9 // 定义散列表长度 
#define NULLKEY -222 
 
typedef struct Hash{
	int *elem; // 数据元素存储地址，动态分配数组 
	int count; //  当前数据元素个数 
}HashTable;

int Init(HashTable *);
int Hash(int );
void Insert(HashTable *, int );
int Search(HashTable *, int );
void Result(HashTable *);//散列表元素显示


#endif
