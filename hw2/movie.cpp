#include <iostream>
#include <string> 
#include "product.h" //there was an error squiggle
#include "movie.h"
#include "util.h"

using namespace std;


Movie::Movie(const std::string category_,
	     const std::string name_, 
		 double price_, int qty_, 
		 string genre_, string rating_) :
         Product(category_, name_, price_, qty_)
{
			 cout << "Constructing Movie : " << name_ << " , genre is " << genre_ << endl;
}



string Movie::getGenre() {
	return genre_;
}

string Movie::getRating() {
	return rating_;
}

Movie::~Movie() {
	
}

std::set<std::string> Movie::keywords() const {
	set<string>::iterator i;
	set<string> keywords = parseStringToWords(name_);

	set<string> temp = parseStringToWords(genre_);
	for(i = temp.begin(); i != temp.end(); i++ ) {
		keywords.insert( *i );
	}
	
	temp = parseStringToWords(rating_);
	for(i = temp.begin(); i != temp.end(); i++ ) {
		keywords.insert( *i );
	}

	return keywords;
}

std::string Movie::displayString() const {
	cout << name_ << endl;
	cout << "Genre: " << genre_ << " Rating: " << rating_ << endl;
	cout << price_ << " " << qty_ << " left." << endl;
}