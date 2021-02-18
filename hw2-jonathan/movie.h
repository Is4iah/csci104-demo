#include <iostream>
#include <string> 
#include "product.h" //there was an error squiggle

using namespace std;

class Movie : public Product {
public: 
	Movie();
	~Movie();
	Movie(const std::string category_,
	     const std::string name_, 
		 double price_, int qty_, 
		 string genre_, string rating_);
	
	string getGenre();
	string getRating();

private:
	string genre_;
	string rating_;
};

