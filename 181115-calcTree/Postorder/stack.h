#pragma once
#include <stdio.h>
#include <string.h>

#include "myBinaryTree.h"

/************************************************************************************
@bref stack struct 
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
typedef struct mySinglelist {
	int dataType;
	int n_Num;

	struct mySinglelist *p_Next;
}MYSINGLE;

MYSINGLE* create_topdummy(void);
MYSINGLE* stack_push(MYSINGLE* , MYTREE* );
MYSINGLE* result_push(MYSINGLE* , int);
int total_Push(MYSINGLE* const, MYTREE* const);

int stack_pop(MYSINGLE* const); 
void singleFree(MYSINGLE* );
MYSINGLE* twotime_Pop(MYSINGLE* const, const int);

int(__cdecl nData)(MYSINGLE* const);
int(__cdecl nAdd)(MYSINGLE* const);
int(__cdecl nSubtract)(MYSINGLE* const);
int(__cdecl nDivide)(MYSINGLE* const);
int(__cdecl nMutiply)(MYSINGLE* const);


