
#include "datastore.h" 
#include "util.h"
#include <iostream> 
#include <map>
#include <cstdlib>
#include <string>
#include "mydatastore.h"
#include "product.h"

using namespace std;

MyDataStore::MyDataStore() {

}

MyDataStore::~MyDataStore() {
	
}

vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) 
{
	vector<Product*>::iterator it;
	set<string>::     iterator itString;
	vector<string>::  iterator itString2;
	vector<string>             matches;
	set<string> 			   intersect;
	vector<Product*> 		   finalProducts;
	set<string> 			   tempProducts1,
							   tempProducts2;

	/* AND */
	if( type == 0) { 
		for(size_t i = 0; i < terms.size(); i ++) {  				//will look for all search words
			if( products.find( terms.at(i) ) != products.end() )  { /* the search word is a keyword */
				matches.push_back( terms.at(i) );  					//add the keyword into matches
			}
		}

		//base case, only one search match
		if( matches.size() == 1) {
			return products[ matches[0] ];						   //type vector<prod*> ... remember map<string, vector<prod*>
		}
		/* base case, no search matches */
		else if (matches.size() == 0 ) {
			return finalProducts;
		}
		else {
			/* gets the first keywords set of products and puts it in a set<string> format*/
			for(it = products[ matches[0] ].begin(); it != products[ matches[0] ].end(); it++ ) {
				tempProducts1.insert( (*it)->getName() );
			}

			for( size_t j = 0; j < matches.size() - 1; j++) {													//  this loop will run the program through loops of intersection functions 
				/* gets the next keywords set of products and puts it in a set<string> format */				// 	to make ensure that there is a commonalaty between all keywords. (an intersect)
				for(it = products[ matches[j + 1] ].begin(); it != products[ matches[j + 1] ].end(); it++ ) {
					tempProducts2.insert( (*it)->getName() );
				}

				if(j == 0) {
					intersect = setIntersection( tempProducts1, tempProducts2 );								//through law of associativity, we know that this works :)
				}
				else {
					intersect = setIntersection( intersect, tempProducts2 );									//this too
				}
			}
		}
	}
	else { // UNION
		for(size_t i = 0; i < terms.size(); i ++) { //will look for all search words
			if( products.find( terms.at(i) ) != products.end() )  {/* the search word is a keyword */
				//add the keyword into matches??
				matches.push_back( terms.at(i) ); 
			}
		}

		//base case, only one search match
		if( matches.size() == 1) {
			return products[ matches[0] ]; //type vector<prod*> ... remember map<string, vector<prod*>
		}
		/* base case, no search matches */
		else if (matches.size() == 0 ) {
			return finalProducts;
		}
		else {
			for(it = products[ matches[0] ].begin(); it != products[ matches[0] ].end(); it++ ) { 
				tempProducts1.insert( (*it)->getName() );
			}

			for( size_t j = 0; j < matches.size() - 1; j++) {
				/* gets the next keywords set of products and puts it in a set<string> format */
				for(it = products[ matches[j + 1] ].begin(); it != products[ matches[j + 1] ].end(); it++ ) {
					tempProducts2.insert( (*it)->getName() );
				}

				if(j == 0) {
					intersect = setUnion( tempProducts1, tempProducts2 );
				}
				else {
					intersect = setUnion( intersect, tempProducts2 );
				}
			}
		}
	}

	if(type == 0) { //AND
	// for(itString2 = matches.begin(); itString2 != matches.end(); itString2++) {
		for(size_t k = 0; k < products[ matches.at(0) ].size(); k++) { 					 //since we know that all matches contain the word contained in the intersection 
			for(itString = intersect.begin(); itString != intersect.end(); itString++) { //cylce thorugh names in intersect
				if( products[ matches.at(0) ].at(k)->getName() == (*itString) ) { 
					finalProducts.push_back( products[ matches.at(0) ].at(k) );
				}
			}
		}
	// }
	}
	if(type == 1) { //OR
		for(itString2 = matches.begin(); itString2 != matches.end(); itString2++) {
			for(size_t k = 0; k < products[ *itString2 ].size(); k++) { 					 //since we know that all matches contain the word contained in the intersection 
				for(itString = intersect.begin(); itString != intersect.end(); itString++) { //cylce thorugh names in intersect
					if( products[ *itString2 ].at(k)->getName() == (*itString) ) { 
						finalProducts.push_back( products[ *itString2 ].at(k) );
						intersect.erase( *itString );										 //if we find the name, we add it to the vector of products and then delete it from the list of names so we dont double count
					}
				}
			}
		}
	}



	return finalProducts;
}

// void MyDataStore::addProduct(Product* p) {
// 	vector<Product*>::iterator i;
// 	set<string> tempWords = p->keywords();


// 	vector<Product*> temp;
// 	temp.push_back(p);

// 	for(i = tempWords.begin(); i!= tempWords.end(); i++) {
// 		/* if keyword does not exist */
// 		if(products.find( *i ) == products.end() ) {
// 			products.insert( (*i) , temp );
// 		}
// 		/* Keyword already exist in the map */
// 		else { 
// 			i->temp.pushback(p);
// 		}
// 	}
	

// 	products.insert(p->keywords(); p)
// }