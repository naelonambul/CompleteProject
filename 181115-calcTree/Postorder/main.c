#include <conio.h>
#include <locale.h>  

#include "stack.h"

#define BUFFER_SIZE 1024

//Global Valiable
struct MY_CONTEXT 
{
	int g_int;
};

/************************************************************************************
@bref Input fomula save to tree, print postorder, calcurate and print result
@details char validation, make tree, make result stack.
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
int main(void)
{
	//Test string
	//char cInput[BUFFER_SIZE] = { "(1+2+3)+4" };
	//char cInput[BUFFER_SIZE] = { "(1*2*3)*4" };
	//char cInput[BUFFER_SIZE] = { "(1+2*3)+3" };
	//char cInput[BUFFER_SIZE] = { "(1+2*3)-3" };
	//char cInput[BUFFER_SIZE] = { "(1+2*3)+(1+2*3)" };
	//char cInput[BUFFER_SIZE] = { "(1+2*3)*(1+2*3)" };
	//char cInput[BUFFER_SIZE] = { "(1+2*3(1+2*3" };
	//char cInput[BUFFER_SIZE] = { "1+2*3)-4*2" };
	char cInput[BUFFER_SIZE] = { " " };

	MYDUAL* topDummy = (MYDUAL*)malloc(sizeof(MYDUAL));
	topDummy = memset(topDummy, 0, sizeof(MYDUAL));

	int nFlag = 0;
	bool tobeTrue = false;

	do {
		printf("\n���� �Է��ϼ���.\n");
		printf("���� ������ �������� �ʽ��ϴ�.\n\n");

		read_line(stdin, cInput, sizeof(cInput));				//save input

		if (sizeof(cInput) > BUFFER_SIZE)
		{
			printf("������ ���̰� �ʹ���ϴ�. �ٽ� �Է����ּ���. : %s\n", cInput);
			_getch();
			_getch();
		}

		tobeTrue = ASCII_Validation(cInput);
		if (tobeTrue == false)
		{
			printf("������ �ʴ� ���ڿ��� �� �ֽ��ϴ�.");
			break;
		}

		nFlag = my_Validation(cInput, topDummy);

		tobeTrue = symbolcount_Validation(topDummy);

		if (tobeTrue == false)
		{
			printf("������ �ʴ� ���ڿ��� �� �ֽ��ϴ�.");
			break;
		}
	} while (sizeof(cInput) > BUFFER_SIZE || nFlag == -1);

	if (nFlag != -1)
	{
		MYTREE** totalBarry = (MYTREE**)malloc(sizeof(MYTREE) * 100);
		totalBarry = memset(totalBarry, 0, sizeof(MYTREE) * 100);

		MYTREE* totalRoot = NULL;
		totalRoot = createTree(topDummy, totalBarry);
		print_Tree(totalRoot);								//print Tree

		MYSINGLE* const singleDummy = create_topdummy();		//buffer stack

		total_Push(singleDummy, totalRoot);
		printf("\n\n����� : %d\n\n", singleDummy->p_Next->n_Num);


		dualFree(topDummy);
		singleFree(singleDummy);
		free_Tree(totalRoot);
		free(totalBarry);
	}
	return 0;
}