#pragma once
#include "DynamicContainer.h"
#include "Book.h"
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;

class BookCatalog {
	DynamicContainer<Book*> DC;
	Book* book;
public:
	BookCatalog();
	~BookCatalog();

	bool Remove();
	Book* Borrow(string&);
	Book* Search(string&);

	int numberBooks();
	int AvailableBooks();
	unordered_map<string , int> numberBooksByGenre();

	void Add();
	void Sort();
	void Statictics();
	void printList();
};