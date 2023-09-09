#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <stdio.h>
#include <conio.h>
#include <windows.h>
#include "loginSystem.h"
#include "connect.h"
#include "carList.h"

#define KEY_UP 119
#define KEY_DOWN 115
#define KEY_Q 113
#define KEY_ENTER VK_RETURN

bool User::isPassValid(string pass) {
	bool digits = 0;
	bool alphas = 0;
	if (pass.length() < 7)
		return 0;
	if (pass == "")
		return 0;
	for (auto symbol : pass) {
		if (isdigit(symbol)) {
			digits = 1;
		}
		else if (isalpha(symbol)) {
			alphas = 1;
		}
	}
	if (!alphas || !digits)
		return 0;
	return 1;

}
bool User::check(string name, string pass) {
	if (name == username && pass == password)
		return 1;
	return 0;
}
void User::gotoxy(short a, short b) 
{
	COORD coordinates; 
	coordinates.X = a; 
	coordinates.Y = b; 

	SetConsoleCursorPosition(
		GetStdHandle(STD_OUTPUT_HANDLE), coordinates);

}
void User::square(short a, short b, short x, short y) {
	gotoxy(x, y);
	for (int i = 0; i < a; i++) {
		cout << "=";
	}
	for (int i = 0; i < b - 2; i++) {
		gotoxy(x, y + i + 1);
		cout << "|";
		for (int j = 0; j < a - 2; j++) {
			cout << " ";
		}
		cout << "|";
	}
	cout << endl;
	gotoxy(x, y + b - 1);
	for (int i = 0; i < a; i++) {
		cout << "=";
	}
}

vector<User> User::getUsers() {
	vector<User>users;
	ifstream usersList("usersList.txt");
	if (!usersList.is_open()) {
		cout << "< The file wasn't found! >" << endl;
		ofstream newuserlist;
		newuserlist.open("usersList.txt");
		square(35, 5, 9, 4);
		gotoxy(10, 5);
		cout << "The file has recently been created!" << endl;
		newuserlist << "ADMIN ADMIN" << endl;
		gotoxy(10, 6);
		cout << "Admin profile is created!";
		users = getUsers();
		newuserlist.close();
		return users;
	}
	while (usersList.good()) {
		string name;
		getline(usersList, name, ' ');
		string pass;
		getline(usersList, pass, '\n');
		if (name != "" && pass != "") {
			users.push_back(User(name, pass));
		}
	}
	return users;
}

void User::enter(vector<User>users) {
	string username, password;
	square(33, 5, 9, 4);
	gotoxy(10, 5);
	cout << " Please enter your information " << endl;
	gotoxy(10, 7);
	cout << "> Login: "; cin >> username;
	square(33, 7, 9, 4);
	gotoxy(10, 5);
	cout << " Please enter your information " << endl;
	gotoxy(10, 7);
	cout << "> Login: " << username << endl;
	gotoxy(10, 8);
	cout << "> Password: "; cin >> password;
	for (auto user : users) {
		if (user.check(username, password)) {
			if (username == "ADMIN" && password == "ADMIN") {
				system("cls");
				square(54, 3, 9, 4);
				gotoxy(10, 5);
				cout << "< You are successfully logged in the admin account >" << endl;
				gotoxy(11, 7);
				system("pause");
				return;
			}
			else {
				system("cls");
				square(35, 3, 9, 4);
				gotoxy(10, 5);
				cout << "< You are successfully logged in >" << endl;
				gotoxy(11, 7);
				system("pause");
				return;
			}
		}
	}
	system("cls");
	square(35, 3, 9, 4);
	gotoxy(10, 5);
	cout << "<! The information is not valid !>" << endl;
	gotoxy(11, 7);
	system("pause");
	return;
}
void User::userRegistration(vector<User>& users) {
	ofstream newUser;
	newUser.open("usersList.txt", std::ios::app);

	string username, password;
	square(40, 3, 9, 4);
	gotoxy(10, 5);
	cout << " Enter your username: ";
	cin >> username;
	while (1) {
		square(40, 5, 9, 4);
		gotoxy(10, 5);
		cout << " Enter your username: " << username;
		gotoxy(10, 6);
		cout << " Enter you password: ";  cin >> password;
		if (users[0].isPassValid(password)) {
			break;
		}
		gotoxy(10, 7);
		cout << " Your password is not valid, try again ";
	}

	newUser << username << " " << password << endl;
	users.push_back(User(username, password));
	return;
}

void Menu::login() {
	system("cls");
	vector<User>users = User::getUsers();;
	int choice;
	choice = 1;
	int KB_KEY = KEY_UP;
	while (KB_KEY != KEY_Q) {
		
		User::square(22, 7, 9, 4);
		User::gotoxy(10, 5);
		cout << " Choose your option " << endl;
		User::gotoxy(14, 6);
		cout << ">> Login <<" << endl;
		User::gotoxy(15, 7);
		cout << "Register" << endl;
		User::gotoxy(17, 8);
		cout << "Exit" << endl;
		if (KB_KEY == KEY_UP && choice != 1) {
			choice--;
		}
		else if (KB_KEY == KEY_DOWN && choice != 3) {
			choice++;
		}
		else if (KB_KEY == KEY_ENTER) {
			switch (choice) {
			case 1:
				system("cls");
				User::enter(users);
				system("cls");
				break;
			case 2:
				system("cls");
				User::userRegistration(users);
				system("cls");
				break;
			case 3:
				system("cls");
				return;
			}
		}
		switch (choice) {
		case 1:
				User::square(22, 7, 9, 4);
				User::gotoxy(10, 5);
				cout << " Choose your option " << endl;
				User::gotoxy(14, 6);
				cout << ">> Login <<" << endl;
				User::gotoxy(15, 7);
				cout << "Register" << endl;
				User::gotoxy(17, 8);
				cout << "Exit" << endl;
				break;
		case 2:
				User::square(22, 7, 9, 4);
				User::gotoxy(10, 5);
				cout << " Choose your option " << endl;
				User::gotoxy(17, 6);
				cout << "Login" << endl;
				User::gotoxy(12, 7);
				cout << ">> Register << " << endl;
				User::gotoxy(17, 8);
				cout << "Exit" << endl;
				break;
		case 3:
				User::square(22, 7, 9, 4);
				User::gotoxy(10, 5);
				cout << " Choose your option " << endl;
				User::gotoxy(17, 6);
				cout << "Login" << endl;
				User::gotoxy(15, 7);
				cout << "Register" << endl;
				User::gotoxy(14, 8);
				cout << ">> Exit <<" << endl;
				break;
		default:
			choice++;
		}
		KB_KEY = _getch();
	}
	system("cls");
}
