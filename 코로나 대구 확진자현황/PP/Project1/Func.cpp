#include "Func.h"

/*
[평가항목 3] : 배열 
*/
struct Covid x[800]; // 날짜별_확진자 수
char inp[20]; // 명령어

/*
[평가항목 6] : 포인터 활용 
*/
void (*F[3])(void) = { exitt, print1,print2 };
const char* word1[] = { "/exit","/print1","/print2" };
const char* word2[] = { "0","1","2"};

/*
[평가항목 7] : 파일 입출력
*/
/*
[평가항목 4] : 포인터 
*/
void File()
{
	char Line[300], * str;
	FILE* fp = NULL;

	if (fopen_s(&fp, "Data.csv", "rt") == 0)
	{
		int i = 0;
		while (fgets(Line, sizeof(Line), fp) != NULL)
		{
			str = Line; 				
			strcpy_s(x[i].data, str); 
			i++;
		}
		fclose(fp);
	}
}

void Menu() // 메인화면
{
	printf("대구광역시 Covid-19 일일 감염자 수\n");
	printf("0 또는 /exit : 프로그램 종료\n");
	printf("1 또는 /print1 : 확진자 오름차순 출력\n");
	printf("2 또는 /print2 : 확진자 내림차순 출력\n");
	printf(": ");
	scanf_s("%s",inp, sizeof(inp));
	Commend(inp);
}

void Commend(char com[])
{
	if (strcmp(com, word1[0]) == 0 || strcmp(com, word2[0]) == 0)
	{
		F[0]();
	}
	else if (strcmp(com, word1[1]) == 0 || strcmp(com, word2[1]) == 0)
	{
		F[1]();
	}
	else if (strcmp(com, word1[2]) == 0 || strcmp(com, word2[2]) == 0)
	{
		F[2]();
	}
	else
	{
		printf(" 잘못된 입력값입니다.\n\n");
	}
}

void print1() 
{
	int i;
	printf("---------------------------------------\n");
	printf("확진자 현황 오름차순 출력\n");
	printf("몇일치를 출력하시겠습니까?\n");
	printf("1 ~ 799\n");
	printf("---------------------------------------\n\n");
	printf(": ");
	scanf_s("%d", &i, sizeof(i));

	if (i >= 1 && i < 800) // 잘못된 범위 입력
	{
		for (int j = 0; j < i; j++)
			printf("· %s\n", x[j].data);
		printf("\n---------------------------------------\n\n");	
	}
	else
	{
		printf(" 잘못된 입력값입니다.\n\n");
	}
}
void print2()
{
	int i;
	printf("---------------------------------------\n");
	printf("확진자 현황 내림차순 출력\n");
	printf("몇일치를 출력하시겠습니까?\n");
	printf("1 ~ 799\n");
	printf("---------------------------------------\n\n");
	printf(": ");
	scanf_s("%d", &i, sizeof(i));

	if (i >= 1 && i < 800) // 잘못된 범위 입력
	{
		for (int j = 798; j > 798 - i; j--)
			printf("· %s\n", x[j].data);
		printf("\n---------------------------------------\n\n");
	}
	else
	{
		printf(" 잘못된 입력값입니다.\n\n");
	}
}

void exitt() 
{
	exit(0);
}