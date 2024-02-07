#include "Library.h"
#include <stdlib.h>
#include<conio.h>
#include<windows.h>
#include<stdio.h>
#include<process.h>
#define endl "\n"
#define fast ios_base::sync_with_stdio(NULL);cin.tie(NULL);cout.tie(NULL);cin.exceptions(ios::badbit | ios::failbit);
using namespace std;

Library lb;
void HandleInterface() {
	int ch = 1;

	do {
		system("cls");

		printf("Select from choices .\n");
		printf("*********************\n");

		cout << "1) Student ." << endl;
		cout << "2) Liberian." << endl;
		cout << "0) Exit." << endl;
		cout << "Enter your choise : ";
		cin >> ch;

		switch (ch) {
		case 1:
			lb.HandleStudentChoice();
			break;
		case 2:
			lb.HandleLiberianChoice();
			break;
		case 0:
			system("cls");
			cout << "-----------------------------------------------------" << endl;
			cout << "   Thank you for visiting our humble library (^_^)   " << endl;
			cout << "-----------------------------------------------------" << endl;
			return;
		default:
			printf("\n* IN VALID CHOICE . Try again !\n");
			system("pause");
		}
	}while (ch);
}
///////////////////////////////////////////
void color(int cnt) {
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), cnt);
}
void menu(int pos) {
	int mx_size = 4;
	vector<string> v = { "Add .", "Remove .", "Search .", "Exit ." };


	for (auto i = 0; i < mx_size; ++i) {
		if (pos == i) {
			color(12);
			cout << "-> ";
			cout << v[i] << endl;
			color(7);
		}
		else {
			cout << v[i] << endl;
		}
	}
}
void test() {
	system("cls");
	int i = 0;
	char ch;
	menu(0); // For basic veiw

	while (1) {
		ch = _getch();
		switch (ch) {
		case 27:
			exit(0);
			break;
		case 72: // UP
			system("cls");
			i = (i - 1 + 4) %4;
			menu(i);
			break;
		case 80: // DOWN
			system("cls");
			i = (i + 1) % 4;
			menu(i);
			break;
		case '\r':
			if (i == 1) {
				system("cls");
				cout << "Add succefully ." << endl;
				return;
			}
			if (i == 4) {
				system("cls");
				cout << "Thank you" << endl;
				return;
			}
			break;
		default:
			break;
		}
	}
}
int main()
{
	fast;
	HandleInterface();
	return 0;
}