#include "BookList.h"

BookList::BookList(){
	count = 0;
}
BookList::~BookList(){}

void BookList::insert(string title, int qty, double price){

	//b is a helper, a book pointer
	Book* b = new Book;
	b->title = title;
	b->price = qty;
	b->price = price;
	b->next = NULL;


	//check if this new book already exist, if so only up the copies or quantity

	//------------------------------------------
	string titleSearchValue = b->title;
	//this method checks to see if this new incoming book title is already in the books vector
	//note: we are finding a specific value within our book, unlike a direct string search
	//so we have guide the search of what to compare
	//if( find(books.begin(), books.end(), b)!= books.end() ){

	Book* existingBook = NULL;
	if(count > 0){
		existingBook = getBook(b);
	}
	if(existingBook != NULL){
		cout << "Book Already Exist " << endl;
		//so we only up the value
		
		increaseNumberOfCopies(existingBook, qty);

	}else{

		
		//cout << "This is a new book" << endl;
	
		//put book into vector
		books.push_back(b);

		//is this first book?
		if(count < 1){
			first = b;
			first->next = NULL;

		//is this 2nd book
		}else if(count == 1){
			last = b;
			last->next = NULL;
			first->next = last;

		//is this 3rd book and beyond?
		}else{
			
			//last->next = b;	//error

			last = b;
			/*
			//newBook is another book point, it acts as a temp helper
			Book* newBook = b;

			last->next = newBook;
			newBook->next = NULL;

			last = newBook;

			newBook = NULL;	//we no longer need this LOCAL pointer
			*/
			
		}

	}

	//increase the current count by however many quantity this new book has
	//count += b->qty;
	count++;

	b = NULL; //we no longer need this temp pointer
	
}

Book* BookList::getBook(Book* b){
	for(int i=0; i<books.size(); i++){
		if(books[i]->title.compare(b->title) == 0){
			return books[i];
			break;
		}
	}
	return NULL;
}

void BookList::increaseNumberOfCopies(Book* existingBook, int qty){
	existingBook->qty += qty;
}

void BookList::search(string str){

	/*
	Book* currentBook = first;
	bool isFound = false;

	do{

		if(currentBook->title == str){
			cout << "found book" << endl;
			isFound = true;
		}else{
			//cout << "no book found" << endl;
			currentBook = currentBook->next;
		}

	}while(isFound == false && currentBook->next != NULL);	
	*/

	bool isFound = false;
	for(int i=0; i<books.size(); i++){
		if(books[i]->title.compare(str) == 0){
			isFound = true;
			cout << "book found" << endl;
			break;
		}
	}

	if(!isFound){
		cout << "book not found" << endl;
	}
}

void BookList::print(){
	/*
	Book* currentBook = first;
	do{
		cout << currentBook->title << endl;
		currentBook = currentBook->next;
	}while(currentBook->next != NULL);
	*/

	cout << "/////////////////////////////////" << endl;
	for(int i=0; i<books.size(); i++){
		cout << books[i]->title << ", " << books[i]->qty << ", " << books[i]->price << endl;
	}
	cout << "/////////////////////////////////" << endl;
		
}

void BookList::sort(){
	/*
	Book* currentBook = first;
	do{
		cout << currentBook->title << endl;
		currentBook = currentBook->next;
	}while(currentBook->next != NULL);
	string* str = new "kdfd";
	return str;
	*/
}

void BookList::remove(string t){
	Book* b = new Book;
	b->title = t;
	Book* result = getBook(b);

	if(result != NULL){
		int index = getIndex(result);
		if(index > -1){
			cout << "removing: " << books[index]->title << endl;
			books.erase(books.begin() + index);
			return;
		}
	}
}

int BookList::getIndex(Book* b){
	for(int i=0; i<books.size(); i++){
		if(books[i]->title.compare(b->title) == 0){
			return i;
		}
	}

	return -1;
}

