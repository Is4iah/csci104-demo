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
	std::string displayString() const;

private:
	string author_;
	string ISBN_;
};


