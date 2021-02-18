#include <iostream>
#include <string> 
#include "product.h" //there was an error squiggle
#include "clothing.h"

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