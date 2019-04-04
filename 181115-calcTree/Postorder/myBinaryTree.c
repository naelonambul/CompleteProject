#include "myBinaryTree.h"
/************************************************************************************
@bref make tree, place memory
@details
@author 2gi-guyvera
@date 2018-11-06
*************************************************************************************/
MYTREE* createTree(MYDUAL* topDummy, MYTREE** totalBarry)
{
	if (topDummy == NULL || totalBarry == NULL) {
	printf("트리 형성중 매개변수 주소를 받지 못했습니다. createTree");}

	int i = 0;
	for (MYDUAL* q = topDummy->pNext; q != NULL; q = q->pNext)
	{
		if (q->dataType == cCbracket)
		{
			int nError = 0;
			bool tobeTrue = false;

			MYDUAL* pmDummy = (MYDUAL*)malloc(sizeof(MYDUAL));	//create inDuallist
			pmDummy = memset(pmDummy, 0, sizeof(MYDUAL));

			nError = my_Validation(q->cNum, pmDummy);			//do again parser
			tobeTrue = symbolcount_Validation(pmDummy);
			
			if (nError == cError || tobeTrue == false) 
			{
				printf("내부 문자열 분할과정에서 오류가 발생했습니다. createTree");
			}

			int j = 0;											//create inArray
			MYTREE** miniBarry = (MYTREE**)malloc(sizeof(MYTREE*) * 100);
			miniBarry = memset(miniBarry, 0, sizeof(MYTREE*) * 100);

 			for (MYDUAL* p = pmDummy->pNext; p != NULL; p = p->pNext)
			{
				miniBarry[j] = createNode(p);					//insert Node to array
				++j;
			}

			MYTREE* miniRoot = linkRoot(miniBarry, j);
			totalBarry[i] = miniRoot;
			++i;

			dualFree(pmDummy);										//delete inDualist
			free(miniBarry);
		}
		else
		{
			totalBarry[i] = createNode(q);
			++i;
		}
	}
		
		MYTREE* treeRoot = linkRoot(totalBarry, i);
	return treeRoot;
}
/************************************************************************************
@bref make root, place memory
@details
@author 2gi-guyvera
@date 2018-11-06
*************************************************************************************/
MYTREE* createNode(MYDUAL* nSource)
{
	MYTREE *nNode = (MYTREE*)malloc(sizeof(MYTREE));
	nNode = memset(nNode, 0, sizeof(MYTREE));

	nNode->dataType = nSource->dataType;
	strcpy_s(nNode->cNum, sizeof(char)*BUFFER, nSource->cNum);

	return nNode;
}
/************************************************************************************
@bref link to out tree from inRoot
@details
@author 2gi-guyvera
@date 2018-11-06
*************************************************************************************/
MYTREE* linkRoot(MYTREE** ppmBarry, int bIndex)
{
	int i = 0, j = 0;
	MYTREE* pmRoot = NULL;

	//link divide, mutipyl////////////////////////////////////////////////////////////
	for (i = 0; i < bIndex; ++i)								
	{
		pmRoot = ppmBarry[i];
		if (ppmBarry[i] == NULL) {}
		else if (ppmBarry[i]->p_Left != NULL && ppmBarry[i]->p_Right != NULL) {} //bracket intree check
		else if (ppmBarry[i]->dataType == cDivide || ppmBarry[i]->dataType == cMutiply)
		{
			if (i == 0) {}
			else if (ppmBarry[i - 1] != NULL)
			{
				if (ppmBarry[i - 1]->dataType == cData ||
					ppmBarry[i - 1]->p_Left != NULL && ppmBarry[i - 1]->p_Right != NULL)
				{
					pmRoot->p_Left = ppmBarry[i - 1];
					ppmBarry[i - 1] = NULL;
				}
			}
			else if (pmRoot->p_Left == NULL)
			{
				j = i;
				do
				{
					--j;
				} while (ppmBarry[j] == NULL && j > 0);

				pmRoot->p_Left = ppmBarry[j];
				ppmBarry[j] = NULL;
			}

			if (ppmBarry[i + 1] != NULL)
			{
				if (ppmBarry[i + 1]->dataType == cData ||
					ppmBarry[i + 1]->p_Left != NULL && ppmBarry[i + 1]->p_Right != NULL)
				{
					pmRoot->p_Right = ppmBarry[i + 1];
					ppmBarry[i + 1] = NULL;
				}
			}
			else if (pmRoot->p_Right == NULL)
			{
				j = i;
				do
				{
					++j;
				} while (ppmBarry[j] == NULL && j < bIndex);

				pmRoot->p_Right = ppmBarry[j];
				ppmBarry[j] = NULL;
			}
		}
		ppmBarry[i] = pmRoot;
	}

	//link subtract, add////////////////////////////////////////////////////////////
	for (i = 0; i < bIndex; ++i)								
	{
		pmRoot = ppmBarry[i];
		if (ppmBarry[i] == NULL) {}
		else if (ppmBarry[i]->p_Left != NULL && ppmBarry[i]->p_Right != NULL) {} //bracket intree check
		else if (ppmBarry[i]->dataType == cSubtract || ppmBarry[i]->dataType == cAdd)
		{
			if (i == 0) {}

			else if (ppmBarry[i - 1] != NULL)
			{
				if (ppmBarry[i - 1]->dataType == cData ||
					ppmBarry[i - 1]->p_Left != NULL && ppmBarry[i - 1]->p_Right != NULL)
				{
					pmRoot->p_Left = ppmBarry[i - 1];
					ppmBarry[i - 1] = NULL;
				}
			}
			else if (pmRoot->p_Left == NULL)
			{
				j = i;
				do
				{
					--j;
				} while (ppmBarry[j] == NULL && j > 0);

				pmRoot->p_Left = ppmBarry[j];
				ppmBarry[j] = NULL;
			}

			if (ppmBarry[i + 1] != NULL)
			{
				if (ppmBarry[i + 1]->dataType == cData ||
					ppmBarry[i + 1]->p_Left != NULL && ppmBarry[i + 1]->p_Right != NULL)
				{
					pmRoot->p_Right = ppmBarry[i + 1];
					ppmBarry[i + 1] = NULL;
				}
			}
			else if (pmRoot->p_Right == NULL)
			{
				j = i;
				do
				{
					++j;
				} while (ppmBarry[j] == NULL&& j < bIndex);

				pmRoot->p_Right = ppmBarry[j];
				ppmBarry[j] = NULL;
			}
		}
		ppmBarry[i] = pmRoot;		//insert node
	}

	for (i = 0; i < bIndex; ++i)
	{
		if (ppmBarry[i] != NULL)	//find last remain node
			j = i;
	}
	return ppmBarry[j];
}
/************************************************************************************
@bref release tree memory
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
void free_Tree(MYTREE* tobeDelete)
{
	if (tobeDelete == NULL)		return;

	free_Tree(tobeDelete->p_Left);
	free_Tree(tobeDelete->p_Right);
	free(tobeDelete);
}
/************************************************************************************
@bref print tree to console 
@details
@author 2gi-guyvera,naverblog_justkukaro
@date 2018-11-02
*************************************************************************************/
void print_Tree(MYTREE* const one_Tree)
{
	if (one_Tree == NULL)			return;
	
	print_Tree(one_Tree->p_Left);
	print_Tree(one_Tree->p_Right);
	
	printf("%s\t", one_Tree->cNum);
}
