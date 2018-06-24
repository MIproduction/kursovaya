#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>
#include <ctype.h>
#include <ctime> 
#include "head.h"

int main()
{
	int n;
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
		case 3:
			results();
			break;
		default: break;

		}
	} while (n != 4);
}