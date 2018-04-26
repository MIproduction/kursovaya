#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>


void ninja();

int main() {
	int n;
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
			printf("KeyboardNinja is a program that can help you improve your typing skills on the keyboard. And you can track your progress with high score table that is in 'Records' menu item.""\n "
			"Rules of this program are very simple: in 'Start' menu item you can choose the difficult of the text; you need to type the text on the screen;""\n"
			"at the start of session you will have 1000 points; if you typed the right symbol it will change color to green,otherwise it will change color to red and you will lose 10 points;""\n"
			"the session will end when you are typed all the text on the screen; your final score will be calculated by this formula-'your points/the time you are spent to type the text'.""\n"
			"Good Luck & Have Fun!");
			system("pause");
			break;
		default: break;
		
		}
	} while (n != 4);
}

void ninja() {
	char a[10];
	int step=0,i=0;
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
	do
	{
		system("cls");
		for (i = 0; i < 10; i++) {
			if (i < step) {
				printf("%c", 176);
			}
			else {
				printf("%c", a[i]);
			}
		}
		char input = _getch();
		if (input == a[step]) {
			step++;
		}
		else {
			printf("\nYou are made mistake\n");
			Sleep(500);
		}
	} while (step < 10);
	system("cls");
	for (i = 0; i < 10; i++) {
			printf("%c", 176);
		}
	printf("\nBRAVO\n");
}
