#include <iostream>
#include <string> 
#include "product.h" //there was an error squiggle
#include "movie.h"

using namespace std;


Movie::Movie(const std::string category_,
	     const std::string name_, 
		 double price_, int qty_, 
		 string genre_, string rating_) :
         Product(category_, name_, price_, qty_)
{
			 cout << "ConstructingMovie movie: " << name_ << " by " << genre_ << endl;
}

string Movie::getGenre() {
	return genre_;
}

string Movie::getRating() {
	return rating_;
}

Movie::~Movie() {
	
}
