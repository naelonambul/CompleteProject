#include "stack.h"
/************************************************************************************
@bref make stack dummy
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
MYSINGLE* create_topdummy(void)
{
	MYSINGLE* topdummy = (MYSINGLE*)malloc(sizeof(MYSINGLE));
	topdummy = memset(topdummy, 0, sizeof(MYSINGLE));

	return topdummy;
}
/************************************************************************************
@bref call stack push order to  traversal
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
int total_Push(MYSINGLE* const topDummy, MYTREE* const One_Tree)
{
	if (One_Tree == NULL)	return 1;

	total_Push(topDummy, One_Tree->p_Left);
	total_Push(topDummy, One_Tree->p_Right);

	if(One_Tree->dataType == 0) stack_push(topDummy, One_Tree);
	else	twotime_Pop(topDummy, One_Tree->dataType);

	return 0;
}
/************************************************************************************
@bref push Linked list, to Tree node
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
MYSINGLE* stack_push(MYSINGLE* topdummy, MYTREE* psingle)
{
	MYSINGLE* pm_New = (MYSINGLE*)malloc(sizeof(MYSINGLE));
	pm_New = memset(pm_New, 0, sizeof(pm_New));
	
	pm_New->p_Next = topdummy->p_Next;
	topdummy->p_Next = pm_New;

	pm_New->dataType = psingle->dataType;
	
	if(pm_New->dataType == 0) pm_New->n_Num = atoi(psingle->cNum);
	else pm_New->n_Num = (int)psingle->cNum;

	return pm_New;
}
/************************************************************************************
@bref push result, to stack
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
MYSINGLE* result_push(MYSINGLE* topdummy, int nResult)
{
	MYSINGLE* pm_New = (MYSINGLE*)malloc(sizeof(MYSINGLE));
	pm_New = memset(pm_New, 0, sizeof(pm_New));

	pm_New->p_Next = topdummy->p_Next;
	topdummy->p_Next = pm_New;

	pm_New->dataType = 0;
	pm_New->n_Num = nResult;
	
	return pm_New;
}
/************************************************************************************
@bref stack pop for dummynext pointer
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
int stack_pop(MYSINGLE* const topdummy)
{
	if (topdummy == NULL)
		printf("스택 메모리를 팝하는 과정에서 더미 주소를 입력받지 못했습니다.");

	MYSINGLE* tobeDelete = topdummy->p_Next;
	topdummy->p_Next = topdummy->p_Next->p_Next;

	int nNum = 0;
	nNum = tobeDelete->n_Num;

	free(tobeDelete);
	if (nNum < 0) nNum = 0;
	return nNum;
}
/************************************************************************************
@bref call stack pop for process
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
MYSINGLE* twotime_Pop(MYSINGLE* const topDummy, const int dataType)
{
	if (topDummy == NULL)
		printf("스택 상단 메모리를 팝하는 과정에서 더미값을 입력받지 못했습니다. ");

	int nResult = 0;

	int(__cdecl *aProcTable[5])(topDummy) =
	{
			nData,
			nAdd,
			nSubtract,
			nDivide,
			nMutiply,
	};

	while (1)
	{
		if (nResult != 0)	break;	

		nResult = aProcTable[dataType](topDummy);
	}

	MYSINGLE* resultStack = NULL;
	resultStack = result_push(topDummy, nResult);
	return resultStack;
}
/************************************************************************************
@bref do not treat data
@details
@author 2gi-guyvera
@date 2018-11-06
*************************************************************************************/
int(__cdecl nData)(MYSINGLE* const topDummy)
{
	return 0;
}
/************************************************************************************
@bref add function
@details
@author 2gi-guyvera
@date 2018-11-06
*************************************************************************************/
int(__cdecl nAdd)(MYSINGLE* const topDummy)
{
	int a = 0;
	int b = 0;
	b = stack_pop(topDummy);
	a = stack_pop(topDummy);

	return b+a;
}
/************************************************************************************
@bref substract function
@details
@author 2gi-guyvera
@date 2018-11-06
*************************************************************************************/
int(__cdecl nSubtract)(MYSINGLE* const topDummy)
{
	int a = 0;
	int b = 0;
	b = stack_pop(topDummy);
	a = stack_pop(topDummy);

	return a-b;
}
/************************************************************************************
@bref divide function
@details
@author 2gi-guyvera
@date 2018-11-06
*************************************************************************************/
int(__cdecl nDivide)(MYSINGLE* const topDummy)
{
	int a = 0;
	int b = 0;
	b = stack_pop(topDummy);
	a = stack_pop(topDummy);

	return a/b;
}
/************************************************************************************
@bref nMutiply function
@details
@author 2gi-guyvera
@date 2018-11-06
*************************************************************************************/
int(__cdecl nMutiply)(MYSINGLE* const topDummy)
{
	int a = 0;
	int b = 0;
	b = stack_pop(topDummy);
	a = stack_pop(topDummy);

	return a*b;
}
/************************************************************************************
@bref release single linked list
@details
@author 2gi-guyvera
@date 2018-11-06
*************************************************************************************/
void singleFree(MYSINGLE* tobeDelete)
{
	while (tobeDelete->p_Next != NULL)
	{
		MYSINGLE* q = tobeDelete->p_Next;
		tobeDelete->p_Next = tobeDelete->p_Next->p_Next;
		free(q);
	} 

	free(tobeDelete);
}