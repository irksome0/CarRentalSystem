#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "loginSystem.h"

using namespace std;

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_Q 113
#define KEY_ENTER VK_RETURN

int main() {
	User::square(25, 10, 15, 5);
	User::gotoxy(19, 6);
	cout << "CAR RENTAL SYSTEM";
	User::gotoxy(18, 8);
	cout << "=SELECT LOGIN TYPE=";
	User::gotoxy(21, 10);
	cout << ">> Profile <<";
	User::gotoxy(23, 12);
	cout << "Car List" << endl;
	int choice = 0;
	int KB_KEY = KEY_UP;
	while (KB_KEY != KEY_Q) {

		if (KB_KEY == KEY_UP && choice != 0) {
			choice--;
		}
		else if (KB_KEY == KEY_DOWN && choice != 1) {
			choice++;
		}
		else if (KB_KEY == KEY_ENTER) {
			if (!choice) {
				Menu::login();
			}
		}
		switch (choice) {
		case 0:
			User::square(25, 10, 15, 5);
			User::gotoxy(19, 6);
			cout << "CAR RENTAL SYSTEM";
			User::gotoxy(18, 8);
			cout << "=SELECT LOGIN TYPE=";
			User::gotoxy(21, 10);
			cout << ">> Profile <<";
			User::gotoxy(23, 12);
			cout << "Car List" << endl;
			break;
		case 1:
			User::square(25, 10, 15, 5);
			User::gotoxy(19, 6);
			cout << "CAR RENTAL SYSTEM";
			User::gotoxy(18, 8);
			cout << "=SELECT LOGIN TYPE=";
			User::gotoxy(24, 10);
			cout << "Profile";
			User::gotoxy(20, 12);
			cout << ">> Car List <<" << endl;
			break;
		default:
			choice++;
		}
		KB_KEY = _getch();
	}
}