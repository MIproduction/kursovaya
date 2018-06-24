#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <ctype.h>
#include <ctime> 
#include "head.h"
#define dl 100

FILE *rec;
char zap[dl];
extern char *a;
extern int len;
int score;
extern int dif;
int res;

HANDLE consoleHandle = 0;

void ninja()
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
	textinit();
	int step = 0, i = 0, triger = 0, s = 1000;
	time_t c = time(0);
	srand(c);
	system("cls");
	printf("\nReady?\n");
	for (i = 1; i < 6; i++)
	{
		printf("%d ", i);
		Sleep(300);
	}
	printf("\nGo!\n");
	Sleep(800);
	system("cls");
	printf("%s", a);
	clock_t t0 = clock();
	do
	{
		printf("\nPoints:%i", s);
		char input = _getch();
		triger = 0;
		if (input == a[step])
		{
			if (input == 32 && a[step] == 32) a[step] = '_';
			step++;
			system("cls");
			for (i = 0; i < len; i++)
			{
				if (i < step)
				{
					SetConsoleTextAttribute(consoleHandle, 10);
					printf("%c", a[i]);
					SetConsoleTextAttribute(consoleHandle, 15);
				}
				else
				{
					printf("%c", a[i]);
				}
			}
		}
		else
		{
			system("cls");
			for (i = 0; i < len; i++)
			{
				if (i < step)
				{
					SetConsoleTextAttribute(consoleHandle, 10);
					printf("%c", a[i]);
				}
				else
				{
					if ((a[i] == a[step]) && (triger == 0))
					{
						SetConsoleTextAttribute(consoleHandle, 12);
						printf("%c", a[i]);
						triger = 1;
						s = s - 10;
					}
					else
					{
						SetConsoleTextAttribute(consoleHandle, 15);
						printf("%c", a[i]);
					}
				}
			}
			SetConsoleTextAttribute(consoleHandle, 15);
			printf("\nYou made a mistake");
		}


	} while (step < len);

	clock_t t1 = clock();
	score = s / ((t1 - t0) / CLK_TCK);

	do
	{
		system("cls");
		SetConsoleTextAttribute(consoleHandle, 10);
		for (i = 0; i < len; i++)
		{
			if (i < step)
			{
				printf("%c", a[i]);
			}
			else
			{
				printf("%c", a[i]);
			}
		}
		SetConsoleTextAttribute(consoleHandle, 15);
		printf("\nScore: %i\n", score);
		rec = fopen("results.txt", "a");
		_ltoa(score, zap, 10);
		printf("\nDo you want to save your result?\n 1-Yes 2-No\n");
		scanf("%d", &res);
		if (res == 1)
		{
			if (dif == 1)
			{
				fprintf(rec, "Easy\tscore = %s  \n", zap);
			}
			if (dif == 2)
			{
				fprintf(rec, "Medium\tscore = %s  \n", zap);
			}
			if (dif == 3)
			{
				fprintf(rec, "Hard\tscore = %s  \n", zap);
			}
			printf("\nBRAVO\n");
			printf("\nTo update the result table, restart the program\n");
		}
		else
		{	
			if (res != 2)
			{
				printf("\ninvalid input\n");
				Sleep(800);
			}
		}
	} while (res != 2 && res != 1);
	printf("\nSee you next time!\n");
	system("pause");
}