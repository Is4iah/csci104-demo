#include <iostream>
#include <sstream>
#include "product_parser.h"
#include "book.h"
#include "clothing.h"
#include "movie.h"
#include "util.h"
using namespace std;


ProductParser::ProductParser()
{

}


ProductParser::~ProductParser()
{

}


Product* ProductParser::parse(string category,
                              istream& is,
                              bool& error,
                              string& errorMsg,
                              int& lineno)
{

    parseCommonProduct(is, error, errorMsg, lineno);
    if(error) return NULL;
    return parseSpecificProduct(category, is, error, errorMsg, lineno);
}

void ProductParser::parseCommonProduct(std::istream& is,
                                       bool& error,
                                       string& errorMsg,
                                       int& lineno)
{
    //product Name
    string myline;
    getline(is, myline);
    myline = trim(myline);
    if(myline.size() == 0) {
        error = true;
        errorMsg = "Unable to find a product name";
        return;
    }
    prodName_ = myline;

    lineno++;

    //check to make sure there is another input
    getline(is, myline);
    if(is.fail()) {
        error = true;
        errorMsg = "Expected another line with the price";
        return;
    }

    // PRICE
    stringstream ss1(myline);
    ss1 >> price_;
    if( ss1.fail() ) {
        error = true;
        errorMsg = "Unable to read price";
        return;
    }

    //check to make sure there is another input
    lineno++;
    getline(is, myline);
    if(is.fail()) {
        error = true;
        errorMsg = "Expected another line with the quantity";
        return;
    }

    // QUANTITY
    stringstream ss2(myline);
    ss2 >> qty_;
    if( ss2.fail() ) {
        error = true;
        errorMsg = "Unable to read quantity";
        return;
    }
    lineno++;
}


  // BOOK PARSER
ProductBookParser::ProductBookParser() : ProductParser()
{

}


//this will be used for books, clothing, movies
//this function allws the user to specify a catagory 

Product* ProductBookParser::parseSpecificProduct(std::string category,
        std::istream& is,
        bool& error,
        std::string& errorMsg,
        int& lineno)
{
    string myline;
    getline(is, myline);
    stringstream ss3(myline);
    ss3 >> isbn_;
    if(ss3.fail()) {
        error = true;
        errorMsg = "Unable to read ISBN";
        return NULL;
    }

    lineno++;
    getline(is, author_);
    if(is.fail()) {
        error = true;
        errorMsg = "Unable to read author";
        return NULL;
    }
#ifdef DEBUG
    cout << "Making product " << prodName_ << endl;
#endif
    lineno++;
    if(error) {
        return NULL;
    }
    return makeProduct();

}

std::string ProductBookParser::categoryID()
{
    return "book";
}


/**
 * Your job to fill in the code to create a new book product
 * using the data members in this class and the parent ProductParser class
 * template: Book(string category_, string name_, double price_, int qty_, string author_, string ISBN_)
 */

Product* ProductBookParser::makeProduct()
{
    Product* BookItem = new Book( categoryID(), prodName_, price_, qty_, author_, isbn_);
    return BookItem;
}



 // CLOTHING PARSER
ProductClothingParser::ProductClothingParser()
{
}

Product* ProductClothingParser::parseSpecificProduct(std::string category,
        std::istream& is,
        bool& error,
        std::string& errorMsg,
        int& lineno)
{
    string myline;
    getline(is, myline);
    stringstream ss3(myline);
    ss3 >> size_;
    if(ss3.fail()) {
        error = true;
        errorMsg = "Unable to read size";
        return NULL;
    }

    lineno++;
    getline(is, brand_);
    if(is.fail() || (brand_.size() == 0)) {
        error = true;
        errorMsg = "Unable to read brand";
        return NULL;
    }
#ifdef DEBUG
    cout << "Making product " << prodName_ << endl;
#endif
    lineno++;
    if(error) {
        return NULL;
    }
    return makeProduct();

}

std::string ProductClothingParser::categoryID()
{
    return "clothing";
}


/**
 * Your job to fill in the code to create a new clothing product
 * using the data members in this class and the parent ProductParser class
 */
Product* ProductClothingParser::makeProduct()
{
    Product* clothingProduct = new Clothing( categoryID(), prodName_, price_, qty_, size_, brand_); //*********************

    //make this a product star
    return clothingProduct;
}



  // MOVIE PARSER
ProductMovieParser::ProductMovieParser()
{
}


Product* ProductMovieParser::parseSpecificProduct(std::string category,
        std::istream& is,
        bool& error,
        std::string& errorMsg,
        int& lineno)
{
    string myline;
    getline(is, myline);
    stringstream ss3(myline);
    ss3 >> genre_;
    if(ss3.fail()) {
        error = true;
        errorMsg = "Unable to read genre";
        return NULL;
    }

    lineno++;
    getline(is, myline);
    stringstream ss4(myline);
    ss4 >> rating_;
    if(ss4.fail()) {
        error = true;
        errorMsg = "Unable to read rating";
        return NULL;
    }
#ifdef DEBUG
    cout << "Making product " << prodName_ << endl;
#endif
    lineno++;
    if(error) {
        return NULL;
    }
    return makeProduct();

}

std::string ProductMovieParser::categoryID()
{
    return "movie";
}


/**
 * Your job to fill in the code to create a new movie product
 * using the data members in this class and the parent ProductParser class
 */
Product* ProductMovieParser::makeProduct() {
    Product* movieProduct = new Movie( categoryID(), prodName_, price_, qty_, genre_, rating_);

    return movieProduct;
}

