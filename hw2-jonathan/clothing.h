#include <iostream>
#include <string> 
// #include "product.h" //there was an error squiggle

using namespace std;

class Clothing : public Product {
public: 
	// Clothing();
	~Clothing();
	Clothing(const std::string category_,
	     const std::string name_, 
		 double price_, int qty_, 
		 string size_, string brand_);
         
	string getBrand();
	string getSize();
private:
	string size_;
	string brand_;
};