#include "Library.h"
Library::Library() : book(new BookCatalog) {}

void Library::HandleStudentChoice() {
	int ch = 1;

	do {
		system("cls");

		printf("1) Student\n");
		printf("*************\n");

		cout << "1) Search ." << endl;
		cout << "2) Borrow ." << endl;
		cout << "3) Book Statistics ." << endl;
		cout << "4) Show sorted books by genre ." << endl;
		cout << "5) Veiw all books ." << endl;
		cout << "0) Exit ." << endl;
		cout << "Enter your choice : ";
		cin >> ch;

		string choice;
		switch (ch) {
		case 1:
			cout << "Enter the isbn of the book : ";
			cin >> choice;

			if (book->Search(choice)) {
				cout << '\n' << *book->Search(choice) << endl;
				system("pause");
			}
			else {
				printf("* Sorry ! This book is not available .\n");
				system("pause");
			}
			break;
		case 2:
			cout << "Enter the isbn of the book : ";
			cin >> choice;

			if (book->Borrow(choice)) {
				char Ch;
				printf("Do you want to show it ? [Y / N] . ");
				cin >> Ch;

				if (Ch == 'Y' || Ch == 'y') {
					cout << '\n' << *book->Borrow(choice) << endl;
					system("pause");
				}

				book->Borrow(choice)->setAvailable(false);	
			}
			else {
				printf("* Sorry ! This book is not available .\n");
				system("pause");
			}
			break;
		case 3:
			book->Statictics();
			system("pause");
			break;
		case 4:
			book->Sort();
			system("pause");
			break;
		case 5:
			book->printList();
			system("pause");
			break;
		case 0:
			return;
		default:
			printf("\n* IN VALID CHOICE . Try again !\n");
			system("pause");
		}
	} while (ch);
}

void Library::HandleLiberianChoice() {
	int ch = 1;

	do {
		system("cls");

		printf("2) Liberian .\n");
		printf("*************\n");

		cout << "1) Add ." << endl;
		cout << "2) Remove ." << endl;
		cout << "3) Sort ." << endl;
		cout << "4) Veiw all books ." << endl;
		cout << "0) Exit ." << endl;
		cout << "Enter your choice : ";
		cin >> ch;

		switch (ch) {
		case 1:
			book->Add();
			break;
		case 2:
			cout << (book->Remove() ? "* The book has been deleted successfully ." : "* Not Exist .") << endl;
			system("pause");
			break;
		case 3:
			book->Sort();
			break;
		case 4:
			book->printList();
			system("pause");
			break;
		case 0:
			return;
		default:
			printf("\n* IN VALID CHOICE . Try again !\n");
			system("pause");
		}
	} while (ch);
}