#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>

using namespace std;

/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */

//do not NOT modify the contents as you iterate

template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2) 
{

//begin
	//s1 will be the SEARCH
	//s2 will be the KEYWORDS

	//the iterator for the intersection 
	typename std::set<T>::iterator it1;

	//the Intersection set
	typename std::set<T> intersect; 

	//Debug
	cout << "the number of search words is " << s1.size() << endl;


	//begin SEARCH
	for(it1 = s1.begin(); it1 != s1.end(); it1++) { //cycling through the search words
		if (s2.find( *it1 ) != s2.end() ) { //if the search word is found in item keywords, add word to intersect list
			intersect.insert(*it1);
		}
	}
//end
	return intersect;
}

template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{
//begin 
	/* NOTES:
		- we want to return all items that have any of the search words in it
			1. create iterator, temp set
			2. search the search words looking for keywords
			3. if search word is found, add it to the temp set
				3.1 if none of the search words were found, return an empty set
			
			s1 = search
			s2 = keywords

			POSSIBLE PROBLEMS WITH UNION, DOUBLE COUNTING
	*/

	//the iterator for the union 
	typename std::set<T>::iterator i;
	//the union set
	typename std::set<T> union_set; 
	/*
		Possible solution to DOUBLE COUNTING:

		by iterating through the keywords and checking if they match with the search word we make sure to not
		double count. 

	*/ 

	for( i = s1.begin(); i != s1.end(); i++) {
			union_set.insert( *i );
	}
	for( i = s2.begin(); i != s2.end(); i++) {
		if(union_set.find( *i ) == union_set.end() ) { 
			union_set.insert( *i );
		}
	}

	return union_set;
//end
	/* Implementation notes:
		- CURRENT: checks 1 product per function call:
			- pros
				- we will check every item so none will be skipped. 
			- cons
				- can be slow
					- maybe O(N^2 log N)  >>>  O(N) ??
		
		- ALT: Checks all products with one function call:
			- pros:
				- if done correctly we can search thorugh all product's keywords in O(N*log N)
			- cons: 
				- What if the word is found in multiple products and we possibly skip over one?


		- its best if we create a set that maps every keyword to its product (ie:  set<string, product> keyWords)
	*/
}



/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif


