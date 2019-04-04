#include "Handler.h"
#include "List.h"
#include "stringtool.h"

#define BUFFER_SIZE 256

int(__cdecl *aProcTable[5])(int);
int PrintMenu();
int read_line(FILE *fp, char str[], int n);
struct Address *load(FILE *fp);
 

enum MYMENU {
	MENU_ADD,
	MENU_SCH,
	MENU_PRN,
	MENU_DEL,
	MENU_EXT
}; 

int main()	//win32 api ���� �ּҷ�
{
	FILE *fp = NULL;
	fp = fopen("text.txt", "r");

	if (fp == NULL)
	{
		printf("������ ã���� �����ϴ�. ");
	}

	struct Address *head;
	head = load(fp);

	struct Address *(__cdecl *aProcTable[5])(head) =
	{		
		EXT,
		ADD,
		SCH,
		PRN,
		DEL,
	};

	int nMenu = 0;
	//Event loop
	while ((nMenu = PrintMenu()) != 0) 	{
			head = aProcTable[nMenu](head);
		}
	head = aProcTable[nMenu](head);

	return 0;
}


int PrintMenu()
{
	int nInput = 0;

	system("cls");
	printf("[1]Add\t[2]search\t[3]Print all\t[4]Delete\t[0]Exit\n:");
	scanf("%d*c", &nInput);

	while (1)
	{
		if (nInput > 0 && nInput < 5)
		{
			return nInput;
		}
		else
		{
			system("cls");
			printf("[1]Add\t[2]search\t[3]Print all\t[4]Delete\t[0]Exit\n");
			printf("�ٽ� �Է����ּ���.\n:");
			scanf("%d*c", &nInput);
		}
	}
}

struct Address *load(FILE *fp)
{
	char *pc_name, *pc_number;
	char buffer[BUFFER_SIZE] = { 0 };

	read_line(fp, buffer, BUFFER_SIZE);
	pc_name		= strtok(buffer, " ");
	pc_number	= strtok(NULL, " ");

	
	struct Address *head;
	head = create_instance(pc_name, pc_number);
	
	//while (i = 1) { �� ���ϳ� ������
	while (1){
	if (read_line(fp, buffer, BUFFER_SIZE) <= 0)
			break;

		pc_name		= strtok(buffer, " ");
		pc_number	= strtok(NULL, " ");

		Add_people(pc_name, pc_number, head);
	}
	return head;
}


