#include <string>
#include <iostream>

//Vector related
#include <vector>
#include <algorithm>
#include <iterator>
//end of vector related

#include "Book.h"
#include "BookList.h"

using namespace std;

int main(){

	cout << "hello" << endl;	

	//Book b;

	BookList list;
	list.insert("the dragon", 1, 2.99);
	list.insert("the dragon", 1, 2.99);
	list.insert("the dragon", 1, 2.99);
	list.insert("the Fish", 2, 3.99);
	list.insert("the Dam", 2, 3.99);
	list.insert("the Tooth", 2, 3.99);
	list.remove("the Fish");

	//Book* b = list.first;
	
	//cout << list.first->title << endl;
	//cout << list.last->title << endl;

	list.search("the Dam");

	list.print();

	/*
	////////////////////////////////////////////////////////////////////////////
	//if you going to pushback, don't define vector modify constructor(10)
	//push_back to add and pop_back to remove
	vector<string>arr;
	arr.push_back("tom");
	arr.push_back("mike");
	arr.push_back("sammy");
	arr.push_back("joardan");
	arr.push_back("son");
	arr.push_back("paoko");
	arr.pop_back();

	for(int i=0; i<arr.size(); i++){
		cout << arr[i] << endl;
	}

	string val = "son";
	if( std::find(arr.begin(), arr.end(), val) != arr.end()){
		cout << "founded " << endl;
	}else{
		cout << "not founded okay" << endl;
	}
	*/
	

	/*
	////////////////////////////////////////////////////////
	vector<Book*> books;

	Book* b = new Book;
	b->title = "My Book 1";
	books.push_back(b);

	b = new Book;
	b->title = "My Book 2";
	books.push_back(b);

	b = new Book;
	b->title = "My Book 3";
	books.push_back(b);

	cout << books[1]->title << endl;
	*/


	system("pause");

	return 0;
}