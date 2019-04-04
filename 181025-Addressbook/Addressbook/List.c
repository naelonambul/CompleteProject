#include <stdio.h>
#include <stdlib.h>

#include "stringtool.h"
#include "List.h"


struct Address *create_instance(char *name, char *number)
{
	struct Address *ptr_people = (struct Address*)malloc(sizeof(struct Address));
	strcpy(ptr_people->c_Name, name);
	strcpy(ptr_people->c_Number, number);
	ptr_people->p_Next = NULL;

	return ptr_people;
}

struct Address *Add_people(char *name, char *number, struct Address *head)
{
	struct Address *pN_before	= NULL;
	struct Address *pN_tail		= head;

	while (pN_tail != NULL){
		pN_before = pN_tail;
		pN_tail = pN_tail->p_Next;
	}
	pN_tail = create_instance(name, number);

	pN_before->p_Next = pN_tail;

	pN_tail->p_Next = NULL;

	return pN_tail;
}

struct Address* search_instance(struct Address *head, char *searched_Name)
{
	struct Address *p = head;

	int a = -1;

	while (p != NULL && strcmp(p->c_Name, searched_Name) != 0)
		p = p->p_Next;
	
	return p;
}

struct Address* delete_instance(struct Address *head, char *searched_Name)
{
	struct Address *pN_before = NULL;
	struct Address *pN_now = head;

	while (pN_now != NULL && strcmp(pN_now->c_Name, searched_Name) != 0)
	{
		pN_before = pN_now;
		pN_now = pN_now->p_Next;
	}

	if (pN_before == NULL) {
		pN_now = head->p_Next;
		free(head);
		head = pN_now;
		return head;
	}
	else {
		pN_before->p_Next = pN_now->p_Next;
		free(pN_now);
		return head;
	}
}

int print_struct(struct Address *p_node)
{
	if (p_node != NULL) {
		printf("%p\t%s\t%s\t%p\n", p_node, p_node->c_Name, p_node->c_Number, p_node->p_Next);
		return 0;
	}
	else{
		printf("대상을 찾지 못했습니다.");
		
		_getch();
		return 1;
	}
}