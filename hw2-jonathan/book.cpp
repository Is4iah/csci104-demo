#include <iostream>
#include <string> 
#include "product.h" //there was an error squiggle
#include "book.h"

using namespace std;


Book::Book(const std::string category_,
	     const std::string name_, 
		 double price_, int qty_, 
		 string author_, string ISBN_) :
		 Product (category_, name_, price_, qty_) 
{
			 cout << "Constructing book: " << name_ << " by " << author_ << endl;
}

string Book::getAuthor() {
	return author_;
}

string Book::getISBN() {
	return ISBN_;
}

Book::~Book() {
	
}

