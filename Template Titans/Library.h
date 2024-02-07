#pragma once
#include "BookCatalog.h"

class Library {
	BookCatalog* book;
public:
	Library();

	void HandleStudentChoice();
	void HandleLiberianChoice();
};