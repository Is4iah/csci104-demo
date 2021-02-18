book.cpp


#include <iostream>
#include <string> 
#include "product.h" //there was an error squiggle
#include "book.h"
#include "util.h"

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

std::set<std::string> Book::keywords() const {
	set<string>::iterator i;
	set<string> keywords = parseStringToWords(name_);

	set<string> temp = parseStringToWords(author_);
	for(i = temp.begin(); i != temp.end(); i++ ) {
		keywords.insert( *i );
	}
	
	keywords.insert(ISBN_);

	return keywords;
}


/*********************************************************
 */

book.h file 


#include <iostream>
#include <string> 
#include "product.h" //there was an error squiggle

using namespace std;

class Book : public Product {
public: 
	Book();
	~Book();
	Book(const std::string category_,
	     const std::string name_, 
		 double price_, int qty_, 
		 string author_, string ISBN_);
	
	string getAuthor();
	string getISBN();

	std::set<std::string> keywords() const;

private:
	string author_;
	string ISBN_;
};