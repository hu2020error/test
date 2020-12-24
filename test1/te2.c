#include"ex.h"

int main()
{
	student *head = (student*)malloc(sizeof(student));
	head->next=NULL;
	admin *node = (admin*)malloc(sizeof(admin));
	node->next=NULL;
	menu1(head,node);
}	
