#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <ctype.h>
#include <ctime> 

HANDLE consoleHandle = 0;


void setupsystem();
void ninja();

int main() {
	int n;
	setupsystem();
	do{
		system("cls");
		printf("1.Start""\n"
			"2.Rules""\n"
			"3.Records""\n"
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

void setupsystem() {
	consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
}

void ninja() {
	char a[10];
	int step=0,i=0,triger=0,s=1000;
	time_t c=time(0);
	srand(c);
	for (i = 0; i < 10; i++) {
		a[i] = 'a' + rand() % (('z' - 'a') + 1);
	}
	system("cls");
	printf("\nReady?\n");
	for (i = 0; i < 5; i++) {
		printf(". ");
		Sleep(800);
	}
	printf("\nGo!\n");
	Sleep(1500);
	system("cls");
	for (i = 0; i < 10; i++) {
		if (i < step) {
			printf("%c", a[i]);
		}
		else {
			printf("%c", a[i]);
		}
	}
	clock_t t0 = clock(); 
	do
	{
		printf("\n%i", s);
		char input = _getch();
		triger = 0;
		if (input == a[step]) {
			step++;
			system("cls");
			for (i = 0; i < 10; i++) {
				if (i < step) {
					SetConsoleTextAttribute(consoleHandle, 10);
					printf("%c", a[i]);
					SetConsoleTextAttribute(consoleHandle, 15);
				}
				else {

					printf("%c", a[i]);

				}
			}
		}
		else {
			system("cls");
			for (i = 0; i < 10; i++) {
				if (i < step) {
					SetConsoleTextAttribute(consoleHandle, 10);
					printf("%c", a[i]);
				}
				else {
					if ((a[i] == a[step]) && (triger==0)) {
						SetConsoleTextAttribute(consoleHandle, 12);
						printf("%c", a[i]);
						triger = 1;
						s=s-10;
					}
					else {
						SetConsoleTextAttribute(consoleHandle, 15);
						printf("%c", a[i]);
					
					}
				}
			}
			SetConsoleTextAttribute(consoleHandle, 15);
			printf("\t\t\tYou made a mistake");
		}

	
	} while (step < 10);
	system("cls");
	SetConsoleTextAttribute(consoleHandle, 10);
	for (i = 0; i < 10; i++) {
		if (i < step) {
			printf("%c", a[i]);
		}
		else {
			printf("%c", a[i]);
		}
	}
	SetConsoleTextAttribute(consoleHandle, 15);
	clock_t t1 = clock(); 
	printf("               Score: %i\n",(s/((t1-t0)/CLK_TCK)));
	printf("\nBRAVO\n");
	system("pause");
}
