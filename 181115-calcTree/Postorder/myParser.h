#pragma once

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <stdbool.h>

#define BUFFER 256

/************************************************************************************
@bref symbol datatype
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
typedef enum N_FLAG {
	cError		= -1,		//ERORR
	cData		= 0,		//number
	cAdd		= 1,		// +
	cSubtract	= 2,		// -
	cDivide		= 3,		// /
	cMutiply	= 4,		// *
	cObracket	= 5,		// (
	cCbracket	= 6			// )
} N_FLAG;
/************************************************************************************
@bref tree struct
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
typedef struct myDual {
	int dataType;	//0 data, 1 plus...
	char cNum[BUFFER];

	struct myDual *pPrev;
	struct myDual *pNext;
} MYDUAL;

int read_line(FILE *fp, char str[], int n); 
int my_Validation(char* const , MYDUAL*);
char* removeBracket(char *buffer);
MYDUAL* dualNew(char*, MYDUAL *const, const int, const int);
void dualFree(MYDUAL*);
bool ASCII_Validation(char* const);
bool symbolcount_Validation(MYDUAL* );

