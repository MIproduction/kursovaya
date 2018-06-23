#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <ctype.h>
#include <ctime> 
#define dl 100

FILE *rec;
char zap[dl];
char *a;
int len;
int score;
int dif;
int res;

HANDLE consoleHandle = 0;

void setupsystem();
void ninja();
void textinit();

int main() 
{
	int n;
	setupsystem();
	do
	{
		system("cls");
		printf("1.Start""\n"
			"2.Rules""\n"
			"3.Results""\n"
			"4.Exit""\n");
		printf("Enter the menu item:");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			ninja();
			break;
		case 2:
			system("cls");
			printf("\n\n\n\n\n\n\n"
			"\t\t\t\t\t\t\t\t\t\t\t\t                Rules\n"
			"\t\t\tKeyboardNinja is a program that can help you improve your typing skills on the keyboard. And you can track your progress with high score table that is in 'Records' menu item.""\n "
			"\t\t\tRules of this program are very simple: in 'Start' menu item you can choose the difficult of the text; you need to type the text on the screen;""\n"
			"\t\t\tAt the start of session you will have 1000 points; if you typed the right symbol it will change color to green,otherwise it will change color to red and you will lose 10 points;""\n"
			"\t\t\tThe session will end when you are typed all the text on the screen; your final score will be calculated by this formula-'your points/the time you are spent to type the text'.""\n\n\n"
			"\t\t\t\t\t\t\t\t\t\t\t\t\tGOOD LUCK & HAVE FUN!\n\n\n\n\n\n");
			system("pause");
			break;
		default: break;
		
		}
	} while (n != 4);
}

void setupsystem() 
{
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

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
			dif=1;
			len = 104;
			a = new char[len+1];
			file_ptr = fopen("EzText.txt", "r");
			fgets(a, len+1, file_ptr);
			break;
		case 2:
			dif=2;
			len = 144;
			a = new char[len+1];
			file_ptr = fopen("MedText.txt", "r");
			fgets(a, len+1, file_ptr);
			break;
		case 3:
			dif=3;
			len = 205;
			a = new char[len+1];
			file_ptr = fopen("HardText.txt", "r");
			fgets(a, len+1, file_ptr);
			break;
		default:
			printf("invalid input");
			Sleep(800);
			break;
		}
	} while (n != 1 && n != 2 && n != 3);

}

void ninja() 
{
	textinit();
	int step=0,i=0,triger=0,s=1000;
	time_t c=time(0);
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
					if ((a[i] == a[step]) && (triger==0)) 
					{
						SetConsoleTextAttribute(consoleHandle, 12);
						printf("%c", a[i]);
						triger = 1;
						s=s-10;
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
	clock_t t1 = clock(); 
	score = s/((t1-t0)/CLK_TCK);
	printf("\nScore: %i\n",score);
	rec = fopen("results.txt", "a");
	ltoa(score, zap, 10);
	printf("\nDo you want to save your result?\n 1-Yes 2-No\n");
	scanf("%d", &res);
	if(res==1)
	{
		if(dif==1)
		{
		fprintf(rec, "Easy\tscore = %s  \n", zap);
		}
		if(dif==2)
		{
		fprintf(rec, "Medium\tscore = %s  \n", zap);
		}
		if(dif==3)
		{
		fprintf(rec, "Hard\tscore = %s  \n", zap);
		}
		printf("\nBRAVO\n");
		system("pause");
	}
	else
	{
		printf("\nSee you next time!\n");
		system("pause");
	}
}
