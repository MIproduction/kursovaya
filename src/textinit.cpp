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

char *a;
int len;
int dif;

void textinit()
{
	FILE *file_ptr;
	int n;
	do
	{
		system("cls");
		printf("Select the difficulty of the text\n1.Easy\n2.Medium\n3.HARD\n");
		scanf("%d", &n);
		switch (n)
		{
		case 1:
			dif = 1;
			len = 104;
			a = new char[len + 1];
			file_ptr = fopen("EzText.txt", "r");
			fgets(a, len + 1, file_ptr);
			break;
		case 2:
			dif = 2;
			len = 144;
			a = new char[len + 1];
			file_ptr = fopen("MedText.txt", "r");
			fgets(a, len + 1, file_ptr);
			break;
		case 3:
			dif = 3;
			len = 205;
			a = new char[len + 1];
			file_ptr = fopen("HardText.txt", "r");
			fgets(a, len + 1, file_ptr);
			break;
		default:
			printf("invalid input");
			Sleep(800);
			break;
		}
	} while (n != 1 && n != 2 && n != 3);

}