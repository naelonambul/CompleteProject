#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <string.h>

#include "Handler.h"
#include "List.h"
#include "stringtool.h"

#define CHAR_NAME 32
#define CHAR_NUMBER 20


struct Address * (__cdecl ADD)(struct Address *head)
{
	char c_name[CHAR_NAME], c_number[CHAR_NUMBER];

	printf("이름를 입력해주세요. : ");
	scanf("%s%*c", c_name);
	
	putchar('\n');
	printf("전화번호를 입력해주세요. :");
	scanf("%s%*c", c_number);

	
	if (search_instance(head, c_name) == NULL)
	{
		Add_people(c_name, c_number, head);
	}
	else
	{
		printf("같은 이름을 가진 주소록이 존재합니다.");
	}

	_getch();
	return head;
}

struct Address * (__cdecl SCH)(struct Address *head)
{
	printf("검색할 이름을 입력해주세요. :");

	char c_name[CHAR_NAME];	
	scanf("%s%*c", c_name);
	
	struct Address *pN_found;
	pN_found = search_instance(head, c_name);

	int result = 0;
	result = print_struct(pN_found);


	_getch();
	return head;
}

struct Address * (__cdecl PRN)(struct Address *head)
{
	struct Address *pN_null = head;
	while (pN_null != NULL)
	{
		print_struct(pN_null);
		pN_null = pN_null->p_Next;
	}
	
	_getch();
	return head;
}

struct Address * (__cdecl DEL)(struct Address *head)
{
	char c_name[CHAR_NAME];
	printf("삭제할 주소록의 이름을 입력해주세요. :");
	scanf("%s%*c", c_name);
	head = delete_instance(head, c_name);

	_getch();
	return head;
}

struct Address * (__cdecl EXT)(struct Address *head)
{
	printf("파일을 저장후 종료하겠습니다. ");
	struct Address *pN_source = head;
	FILE *fp = NULL;
	fp = fopen("text.txt", "w");

	while (pN_source != NULL) {
			fprintf(fp, "%s %s\n", pN_source->c_Name, pN_source->c_Number);
			pN_source = pN_source->p_Next;
	}

	fclose(fp);
	_getch();
	return head;
}

