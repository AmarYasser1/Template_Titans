#pragma once
#include<iostream>
#include<string>
using namespace std;

class Book {
	string Title;
	string Isbn;
	string Genre;
	string Author;
	bool isAvailable{ false };
public:
	Book();
	Book(string, string, string, string);
	Book(const Book&);

	void setTitle(string);
	void setIsbn(string);
	void setGenre(string);
	void setAuathor(string);
	void setAvailable(bool);

	bool Available() const;
	string getTitle() const;
	string getIsbn() const;
	string getGenre() const;
	string getAuthor() const;

	void read();
	void print();

	friend ostream& operator << (ostream&, const Book&);
	friend istream& operator >> (istream&,  Book&);
};