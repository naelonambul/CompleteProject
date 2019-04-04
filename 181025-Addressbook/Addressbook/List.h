#pragma once

#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>


struct Address *create_instance(char *name, char *number);
struct Address *Add_people(char *name, char *number, struct Address *before);
struct Address* search_instance(struct Address *head, char *searched_Name); 
struct Address* delete_instance(struct Address *head, char *searched_Name);
int print_struct(struct Address *p_node);


struct Address {
	char c_Name[32];
	char c_Number[20];

	struct Address *p_Next;
};
