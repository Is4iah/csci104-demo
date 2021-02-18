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
	
	std::set<std::string> keywords() const;
	string getGenre();
	string getRating();
	std::string displayString() const;

private:
	string genre_;
	string rating_;
};