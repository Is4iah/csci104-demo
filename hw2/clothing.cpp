#include <iostream>
#include <string> 
#include "product.h" //there was an error squiggle
#include "clothing.h"
#include "util.h"

using namespace std;

Clothing::~Clothing() {
	
}

Clothing::Clothing(const std::string category_,
	     const std::string name_, 
		 double price_, int qty_, 
		 string size_, string brand_) :
		 Product (category_, name_, price_, qty_) 
{
			 cout << "Constructing clothes: " << name_ << " by " << brand_ << endl;
}



string Clothing::getBrand() {
	return brand_;
}

string Clothing::getSize() {
	return size_;
}

std::set<std::string> Clothing::keywords() const {
	set<string>::iterator i;
	set<string> keywords = parseStringToWords(name_);

	set<string> temp = parseStringToWords(brand_);
	for(i = temp.begin(); i != temp.end(); i++ ) {
		keywords.insert( *i );
	}
	
	temp = parseStringToWords(size_);
	for(i = temp.begin(); i != temp.end(); i++ ) {
		keywords.insert( *i );
	}

	return keywords;
}

std::string Clothing::displayString() const {
	cout << name_ << endl;
	cout << "Size: " << size_ << " Brand: " << brand_ << endl;
	cout << price_ << " " << qty_ << " left." << endl;
}
	


