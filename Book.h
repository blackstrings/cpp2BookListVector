#ifndef BOOK_H
#define BOOK_H

#include <string>

using namespace std;

class Book {

public:
	Book(){ qty = 0;}
	~Book(){}
	string title;
	int qty;
	double price;
	Book* next;

};

#endif