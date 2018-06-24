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

extern FILE *rec;
extern char zap[dl];

void results()
{
	int g;
	system("cls");
	rec = fopen("results.txt", "r");
	while (fgets(zap, dl, rec))
	{
		fprintf(stdout, "%s", zap);
	}
	printf("\n1. Clean the results board\n");
	printf("\n2. Exit\n");
	scanf("%d", &g);
	do
	{
		switch (g)
		{
		case 1:
			rec = fopen("results.txt", "w");
			break;
		case 2:
			break;
		default:
			printf("invalid input");
			Sleep(800);
			break;
		}
	} while (g != 2 && g != 1);
	system("pause");
}