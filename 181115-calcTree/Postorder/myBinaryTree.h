#pragma once
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

#include "myParser.h"

/************************************************************************************
@bref tree struck
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
typedef struct myTree {
	int dataType;			//symbol
	char cNum[BUFFER];

	struct myTree *p_Left;
	struct myTree *p_Right;
} MYTREE;

MYTREE* createTree(MYDUAL* , MYTREE**);
MYTREE* linkRoot(MYTREE** , int );
MYTREE* createNode(MYDUAL*);

void free_Tree(MYTREE*);
void print_Tree(MYTREE* const);


