#include"Hash.h"

int m;

int Init(HashTable *H)
{
	int i;
 
	m = HASHSIZE;
	H->elem = (int *)malloc(m * sizeof(int)); //分配内存
	H->count = m;
	for (i = 0; i<m; i++)
	{
		H->elem[i] = NULLKEY;
	}
	return 1;
}
 
 
int Hash(int k)
{
	return k % m;//除留余数法
}
 
 
void Insert(HashTable *H, int k)
{
	int addr = Hash(k); 					 
	while (H->elem[addr] != NULLKEY)
	{
		addr = (addr+1) % m;//开放定址法
	}
	H->elem[addr] = k;
}
 
int Search(HashTable *H, int k)
{
	int addr = Hash(k); //求哈希地址
 
							
	while (H->elem[addr] != k)//开放定址法解决冲突
	{
		addr = (addr+1) % m;
 
		if (H->elem[addr] == NULLKEY || addr == Hash(k))
			return -1;
	}
	return addr;
}
 
void Result(HashTable *H)//散列表元素显示
{
	int i;
	for (i = 0; i<H->count; i++)
	{
		printf("%d\t", H->elem[i]);
	}
//	printf("\t");
}
 
