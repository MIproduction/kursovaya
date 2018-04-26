#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <Windows.h>
#include <conio.h>
#include <iostream>

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

int main() {
	int n;
	while(n != 4){
		system("cls");
		printf("Start""\n"
			"Rules""\n"
			"Records""\n"
			"Exit""\n");
		scanf("%d", &n);

		switch (n)
		{
		case 1:
			ninja();
			break;
		case 2:
			system("cls");
			printf("rules");
			system("pause");
			break;
		default: break;
		
	}
}
}
