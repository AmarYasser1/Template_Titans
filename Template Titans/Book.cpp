#include "Book.h"
Book::Book() : Title(""), Isbn(""), Author(""), Genre(""), isAvailable(true) { }
Book::Book(string Title, string Isbn, string Author, string Genre) {
	this->Author = Author;
	this->Genre = Genre;
	this->Isbn = Isbn;
	this->Title = Title;
	isAvailable = true;
}
Book::Book(const Book& other) : Title(other.Title), Isbn(other.Isbn), Author(other.Author), Genre(other.Genre), isAvailable(other.isAvailable) {}

void Book::setAuathor(string Author) { this->Author = Author; }
void Book::setTitle(string Title) { this->Title = Title; }
void Book::setIsbn(string Isbn) { this->Isbn = Isbn; }
void Book::setGenre(string Genre) { this->Genre = Genre; }
void Book::setAvailable(bool isAvailable) { (*this).isAvailable = isAvailable; }

string Book::getAuthor() const { return this->Author; }
string Book::getGenre() const { return this->Genre; }
string Book::getIsbn() const { return this->Isbn; }
string Book::getTitle() const { return this->Title; }
bool Book::Available() const { return this->isAvailable; }

void Book::read() {
	system("cls");
	cin.ignore();
	cout << "Enter the Author of the book : ";
	getline(cin, Author);
	cout << "Enter the Title of the  book : ";
	getline(cin, Title);
	cout << "Enter the Isbn of the book : ";
	getline(cin, Isbn);
	cout << "Enter the Genre of the book : ";
	getline(cin, Genre);
}
void Book::print() {
	cout << "Title : " << Title;
	cout << "| Isbn : " << Isbn;
	cout << "| Genre : " << Genre;
	cout << "| Author : " << Author;
	cout << "| Statu : ";
	cout << (isAvailable ? "Available" : "Not Available") << endl;
}

istream& operator >> (istream& in, Book& book) {
	system("cls");
	cin.ignore();
	printf("Enter the Author of the book : ");
	getline(in, book.Author);
	printf("Enter the Title of the book : ");
	getline(in, book.Title);
	printf("Enter the Isbn of the book : ");
	getline(in, book.Isbn);
	printf("Enter the Genre of the book : ");
	getline(in, book.Genre);

	return in;
}
ostream& operator << (ostream& out, const Book& book) {
	out << "Title : " << book.Title;
	out << "| Isbn : " << book.Isbn;
	out << "| Genre : " << book.Genre;
	out << "| Author : " << book.Author;
	out << "| Statu : ";
	out << (book.isAvailable ? "Available" : "Not Available") << endl;

	return out;
}