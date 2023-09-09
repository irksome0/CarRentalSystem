#pragma once

#include <string>
using namespace std;


#ifndef MENU_H
#define MENU_H

class Menu {
public:
	static void login();
};

#endif

#ifndef LOGIN_H
#define LOGIN_H

class User: public Menu {
	private:
		string password;
	public:
		string username;
		bool check(string name, string pass);
		bool isPassValid(string pass);
		static void gotoxy(short, short);
		static void square(short, short, short, short);
		static void enter(vector<User>);
		static void userRegistration(vector<User>&);
		static vector<User> getUsers();
		User(string name, string pass) {
			username = name;
			password = pass;
		}
	};
#endif



