#include <sstream>
#include <iomanip>
#include "product.h"
#include <string>
#include <iostream>

using namespace std;

Product::Product(const std::string category, const std::string name, double price, int qty) :
    name_(name),
    price_(price),
    qty_(qty),
    category_(category)
{

}

Product::~Product()
{

}

double Product::getPrice() const
{
    return price_;
}

std::string Product::getName() const
{
    return name_;
}

void Product::subtractQty(int num)
{
    qty_ -= num;
}

int Product::getQty() const
{
    return qty_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Product::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Product::dump(std::ostream& os) const
{
    os << category_ << "\n" << name_ << "\n" << price_ << "\n" << qty_ << endl;
}




/* // Product::Product(const std::string category, const std::string name, double price, int qty) :

int main () {
    string cat = "book";
    string name = "isaiah's book";
    double price = 4.20;
    int qty = 69;
    Product test (cat, name, price, qty);
    // cout << test->getName() << endl;
} */