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
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2) //AND

{
	//t is the set that we are going to be inputing matches into
	//s1 will be the SEARCH
	//s2 will be the KEYWORDS

	//find what they have in common 

	// 1.  create 2 iterators, one that will go through the search words 
	// 	(outer loop) and one that will search the keywords (inner loop)

	typename set<T>::iterator it1;
	// typename set<t>::iterator it2;
	set<string> intersect;
	
	for(it1 = s1.begin(); it1 != s1.end(); it1++) { //this is our search 
		if (s2.find( it1 ) != s2.end() ) { // 2. if words are found in both, we add the item to the typename set
			intersect.insert(it1);
		}
	}

	// // 3. once done with the loop we return 

	return intersect;
	

	

}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2)
{





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


