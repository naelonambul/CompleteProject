#include "myParser.h"
/************************************************************************************
@bref remove bracket
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
char* removeBracket(char *buffer)
{
	int i = 0, j = 0;
	for (i = 0; buffer[i] != '\0'; ++i)
	{
		if (buffer[i] == '(')
		{
			for (j = i + 1; buffer[j] != '\0'; ++j)
			{
				buffer[i] = buffer[j];
				++i;
			}
			buffer[j-1] = '\0';
		}
	}
	return buffer;
}
/************************************************************************************
@bref save to char array from FILE pointer(ex. stdin)
@details
@author kwon-oh-hum
@date 2018-11-02
*************************************************************************************/
int read_line(FILE *fp, char str[], int n)
{
	int ch, i = 0;
	while ((ch = fgetc(fp)) != '\n' && ch != EOF)
		if (i < n - 1)
			str[i++] = ch;

	str[i] = '\0';
	return i;
}
/************************************************************************************
@bref input char validation, parsing
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
int my_Validation(char* const cInput, MYDUAL* topDummy)
{
	char validBuffer[BUFFER] = { "" };		//Buffer

	int nBcount = 0;									//validBuffer	index;

	int nFlag = 0;			//  number = 0,  + = 1, - = 2		ERORR = -1
							//  /= 3, * = 4, ( = 5, ) = 6		6 = bracket fomula

	int cLength = strlen(cInput);
	
	int i = 0;											//cInput		index;
	do {
			for (i = 0; i < cLength + 1; ++i)
			{
				if (cInput[i] == '\0')						//last char validation
				{
					if (nFlag == cData || nFlag == cCbracket)
					{
						dualNew(validBuffer, topDummy, nFlag, nBcount);
						nBcount = 0;
					}
					else
					{
						printf("마지막 문자를 잘못 입력하셧습니다. :%s", cInput);
						nFlag = cError;
					}
					break;
				}
				else if (cInput[i] >= '0' && cInput[i] <= '9')	//string check without list char
				{
					if (nFlag < cObracket && nFlag > cData)		//Flag check
					{
						if (strstr(validBuffer, "(") == NULL)
						{
							dualNew(validBuffer, topDummy, nFlag, nBcount);
							nBcount = 0;
						}
					}
					else if (nFlag == cCbracket)				//')' check
					{
						dualNew(validBuffer, topDummy, nFlag, nBcount);
						nBcount = 0;

					}
					validBuffer[nBcount] = cInput[i];
					++nBcount;
					nFlag = cData;
				}


					switch (cInput[i])							//symbol check without number
					{
					case ')':
					{
						if (nFlag > cData && nFlag < cCbracket)
						{
							printf("괄호 수식을 잘못 입력하셧습니다. :%s", cInput);
							nFlag = cError;
						}
						else if (nFlag == cData && (strstr(validBuffer, "(") != NULL))
						{
							validBuffer[nBcount] = cInput[i];
							nFlag = cCbracket;
						}
						else if (strstr(validBuffer, "(") == NULL)
						{
							printf("괄호의 짝이 맞지 않습니다.\n");
							nFlag = cError;
						}
						break;
					}
					case'(':
					{
						if (validBuffer[0] == '\0')
						{
							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cObracket;
							break;
						}
						else if (nFlag == cObracket || nFlag == cCbracket)
						{
							printf("괄호의 중복은 지원하지 않습니다. :%s", cInput);
							nFlag = cError;
							break;
						}
						else if (nFlag > cData && nFlag < cCbracket)
						{
							dualNew(validBuffer, topDummy, nFlag, nBcount);
							nBcount = 0;

							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cObracket;
							break;
						}
						else if(strstr(cInput+i, ")") == NULL)
						{
							printf("괄호의 짝이 맞지 않습니다.");
							nFlag = cError;
							break;
						}
					}
					case'*':
					{
						if (nFlag > cData && nFlag < cCbracket)
						{
							printf("곱하기 수식을 잘못 입력하셨습니다. :%s", cInput);
							nFlag = cError;
						}
						else if (cInput[i + 1] == '\0')
						{
							printf("곱하기 수식을 잘못 입력하셧습니다. :%s", cInput);
							nFlag = cError;
						}
						else if (nFlag == cData)
						{
							if (strstr(validBuffer, "(") == NULL)
							{
								dualNew(validBuffer, topDummy, nFlag, nBcount);
								nBcount = 0;
							}
							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cMutiply;
						}
						else if (nFlag == cCbracket)
						{
							dualNew(validBuffer, topDummy, nFlag, nBcount);
							nBcount = 0;

							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cMutiply;
						}
						break;
					}
					case'/':
					{
						if (nFlag > cData && nFlag < cCbracket)
						{
							printf("나누기 수식을 잘못 입력하셨습니다. :%s", cInput);
							nFlag = cError;
							break;
						}
						else if (cInput[i + 1] == '\0')
						{
							printf("나누기 수식을 잘못 입력하셧습니다. :%s", cInput);
							nFlag = cError;
							break;
						}
						else if (nFlag == cData)
						{
							if (strstr(validBuffer, "(") == NULL)
							{
								dualNew(validBuffer, topDummy, nFlag, nBcount);
								nBcount = 0;
							}
							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cDivide;
						}
						else if (nFlag == cCbracket)
						{
							dualNew(validBuffer, topDummy, nFlag, nBcount);
							nBcount = 0;

							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cDivide;
						}
						break;
					}
					case'-':
					{
						if (nFlag > cData && nFlag < cCbracket)
						{
							printf("빼기 수식을 잘못 입력하셨습니다. :%s", cInput);
							nFlag = cError;
							break;
						}
						else if (cInput[i + 1] == '\0')
						{
							printf("빼기 수식을 잘못 입력하셧습니다. :%s", cInput);
							nFlag = cError;
							break;
						}
						else if (nFlag == cData)
						{
							if (strstr(validBuffer, "(") == NULL)
							{
								dualNew(validBuffer, topDummy, nFlag, nBcount);
								nBcount = 0;
							}
							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cSubtract;
						}
						else if (nFlag == cCbracket)
						{
							dualNew(validBuffer, topDummy, nFlag, nBcount);
							nBcount = 0;

							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cSubtract;
						}
						break;
					}
					case'+':
					{
						if (nFlag > cData && nFlag < cCbracket)
						{
							printf("더하기 수식을 잘못 입력하셨습니다. :%s", cInput);
							nFlag = cError;
						}
						else if (cInput[i + 1] == '\0')
						{
							printf("더하기 수식을 잘못 입력하셧습니다. :%s", cInput);
							nFlag = cError;
						}
						else if (nFlag == cData)
						{
							if (strstr(validBuffer, "(") == NULL)
							{
								dualNew(validBuffer, topDummy, nFlag, nBcount);
								nBcount = 0;
							}
							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cAdd;
						}
						else if (nFlag == cCbracket)
						{
							dualNew(validBuffer, topDummy, nFlag, nBcount);
							nBcount = 0;

							validBuffer[nBcount] = cInput[i];
							++nBcount;
							nFlag = cAdd;
						}
						break;
					}
				}
			}
	} while (cInput[i] != '\0' && nFlag != cError);		//When The char is NULL, stop parsing
	return nFlag;
}
/************************************************************************************
@bref create New dual linked list, return value is tail node 
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
MYDUAL* dualNew(char* validBuffer, MYDUAL *const topDummy, const int nFlag, const int nBcount)
{
	validBuffer[nBcount] = '\0';
	MYDUAL* pSecond = (MYDUAL*)malloc(sizeof(MYDUAL));
	pSecond = memset(pSecond, 0, sizeof(MYDUAL));

	if (nFlag == cCbracket)	removeBracket(validBuffer);
	
	strcpy_s(pSecond->cNum, sizeof(pSecond->cNum), validBuffer);
	pSecond->dataType = nFlag;

	MYDUAL* pmTail = topDummy;
	while (pmTail->pNext != NULL) { pmTail = pmTail->pNext; }

	pmTail->pNext = pSecond;
	pSecond->pPrev = pmTail;									//pSecond become tail;

	memset(validBuffer, '\0', sizeof(validBuffer));				//clear valid buffer
	return topDummy;
}
/************************************************************************************
@bref delete dual linked list.
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
void dualFree(MYDUAL* tobeDelete)
{	
	MYDUAL* tmp = NULL;

	while (tobeDelete->pNext != NULL)
	{
		tmp = tobeDelete->pNext;
		tobeDelete->pNext = tobeDelete->pNext->pNext;
		
		free(tmp);
	}

	free(tobeDelete);
}
/************************************************************************************
@bref ASCII validation
@details
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
bool ASCII_Validation(char* const cArray)
{
	for (int i = 0; cArray[i] != '\0'; ++i)
		if (cArray[i] > '0'	 && cArray[i] < '9'  ||
			cArray[i] == '-' || cArray[i] == '+' ||
			cArray[i] == '/' || cArray[i] == '*' ||
			cArray[i] == '(' || cArray[i] == ')')
			return true;

	
	printf("다시 입력해주세요. :\n");
	return false;
}/************************************************************************************
@bref symbol validation
@details	topDummy haven't any bracket. so closebracket is fomula
@author 2gi-guyvera
@date 2018-11-02
*************************************************************************************/
bool symbolcount_Validation(MYDUAL* topDummy)
{
	MYDUAL* q = topDummy->pNext;

	int numberCount = 0;
	int symbolCount = 0;

	bool prevCount = false;
	for (q; q != NULL; q = q->pNext)
	{
		if (q->dataType == cData)
			++numberCount;

		else if (q->dataType > cData && q->dataType < cObracket)
			++symbolCount;
		else if (q->dataType == 6)
			++numberCount;				//miniduallinked already validation.
	}
	
	if (numberCount <= symbolCount)		return false;
	else								return true;
}
