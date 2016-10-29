#ifndef BOOK_LIST_H
#define BOOK_LIST_H

#include <string>
#include <iostream>
#include "Book.h"

//Vector related
#include <vector>
#include <algorithm>
#include <iterator>
//end of vector related

using namespace std;

class BookList {

public:
	BookList();
	~BookList();

	void insert(string title, int qty, double price);
	void search(string str);
	void print();
	void remove(string t);
	void sort();
	
	void increaseNumberOfCopies(Book* existingBook, int qty);
	Book* getBook(Book* b);
	int getIndex(Book* b);

	vector<Book*> books;

	//private:
	int count;
	Book* first;
	Book* last;

};

#endif