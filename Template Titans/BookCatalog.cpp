#include "BookCatalog.h"
BookCatalog::BookCatalog() : book(new Book) { }
BookCatalog::~BookCatalog() { delete book; }

void BookCatalog::Add() {
	book = new Book;
	cin >> *book;
	DC.insertEnd(book);
}

bool BookCatalog::Remove() {
	string isbn;
	cout << "Enter the isbn of the book : ";
	cin >> isbn;

	for (auto i = 0; i < DC.getSize(); ++i)
		if (isbn == DC.findElement(i)->getIsbn()) {
			DC.removeAt(i);
			return true;
		}

	return false;
}

int BookCatalog::numberBooks() { return DC.getSize(); }
int BookCatalog::AvailableBooks() {
	int cnt = 0;
	for (auto i = 0; i < DC.getSize(); ++i) 
		if (DC.findElement(i)->Available()) ++cnt;

	return cnt;
}

unordered_map<string, int> BookCatalog::numberBooksByGenre() {
	unordered_map<string, int> ump;
	for (auto i = 0; i < DC.getSize(); ++i)
		ump[DC.findElement(i)->getGenre()]++;

	return ump;
}

Book* BookCatalog::Search(string& isbn) {
	for (auto& it : DC) 
		if (isbn == it->getIsbn())
			return it;

	return nullptr;
}

Book* BookCatalog::Borrow(string& isbn) {
	for (auto& it : DC)
		if (isbn == it->getIsbn())
			if (it->Available())
				return it;

	return nullptr;
}

void BookCatalog::Sort() {
	vector<Book> v;

	for (auto& it : DC) v.push_back(*it);
	auto comp = [&](const Book& b1,const Book& b2) -> bool {
		return b1.getGenre() < b2.getGenre();
	};

	sort(v.begin(), v.end(), comp);
	system("cls");
	printf("============== Sorted list of book by genre ============\n");
	for (auto& it : v)
		cout << it << endl;
}

void BookCatalog::Statictics() {
	system("cls");
	printf("===================== Book Statistics =============\n");

	auto n_books = numberBooks();
	auto a_books = AvailableBooks();
	cout << "* The number of total books : " << n_books << endl;
	cout << "* The number of available books : " << a_books << endl;
	cout << "* The number of borrowed books : " << n_books - a_books << endl;
	for (auto& it : numberBooksByGenre())
		cout << "* The number of [" << it.first << "] books : " << it.second << endl;
}

void BookCatalog::printList() {
	system("cls");
	cout << "============== List of Books ==================" << endl << endl;

	for (auto i = 0; i < DC.getSize(); ++i) {
		cout << "============= Book " << i + 1 << " info================" << endl;
		cout << *DC.findElement(i);
	}
		
	cout << endl;
}