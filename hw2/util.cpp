#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"
#include <string>

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords)
{
    rawWords = convToLower(rawWords);
    rawWords = trim(rawWords);
    //split every word greater than 2 char into its own string

    //first CREATE A SET

    // ALL POSSIBLE PUNCTUATIONS
    char space = ' ', p = '.', apos = '\'', comm = ',', simiC = ';', col = ':'; 

    set< char > stops;

    stops.insert(space);
    stops.insert(p);
    stops.insert(apos);
    stops.insert(comm);
    stops.insert(simiC);
    stops.insert(col);


    // cout << stops.find(' ') << endl << endl;

    // if (stops.find(' ') != stops.end()) {
    //     cout << "it was found " << endl;
    // }


    set< string > keyWords; //this will hold the set of words whos length is >= 2;
    size_t i = 0; //keep track of iterations

    while ( !rawWords.empty() ){
        rawWords = ltrim(rawWords); //CALLING TRIM ONLY ON LEFT SIDE
        // char space = ' ', p = '.', apos = '\'', comm = ',', simiC = ';', col = ','; 

        // cout << "iteration "<< i << " and char count is " << i << endl;

        if(rawWords.at(i) == space || rawWords.at(i) == p || rawWords.at(i) == apos || rawWords.at(i) == comm || rawWords.at(i) == simiC || rawWords.at(i) == col) {
        // if (stops.find( rawWords.at(i) ) != stops.end() ) { 
            if (i >= 2) {
                // cout << "count = " << cnt << endl;
                // cout << "int = " << i;
                // cout << rawWords[i - cnt] << " - ";
                // cout << rawWords[i - 1] << endl;
                string temp = rawWords.substr(0, i);
                // cout << "our key is \"" << temp << "\"" << endl;
                keyWords.insert(temp);

                //create new string

                rawWords = rawWords.substr(i + 1, rawWords.size() - 1);
                // cout << "our new string is \"" << rawWords << "\"" << endl;
                i = 0;
                continue;
            }   
            else {                                                      // word is smaller than 2 char
                rawWords = rawWords.substr(i + 1, rawWords.size() - 1);
                i = 0;
            }
        }
        if (i == rawWords.size() - 1) {                                 //if this happens we know we are at the last step!!!
            if (i + 1 >= 2) {                                               //if the final word has at least 2 char we add it to the map
                string temp = rawWords.substr(0, i + 1);
                // cout << "our key is \"" << temp << "\"" << endl;
                keyWords.insert(temp);
                break;
            }
            else { break; }                                             //else we just break
        }
        i++;
    }
    set<string>::iterator itr;
    cout << "Our Keywords are: ";
    for(itr = keyWords.begin(); itr != keyWords.end(); itr++) {
        cout << *itr << " ";
    }
    

    // cout << rawWords.size() << endl;

    return keyWords;

}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

int main() {
    
    string rawWords = "    isaiah       is        super    cool     and        whats         up             ";
    
    
    set<string> Keywords = parseStringToWords(rawWords);

    set<string> search;

    search.insert("isaiah");
    search.insert("up");

    // set<string> results = set_intersection<string>(Keywords, search);

}





































































// for( size_t i = 0; i < rawWords.size(); i++) {
//         char space = ' ';
//         char p = '.';
//         // cout << i << ": \"" << rawWords[i] << "\"" << endl;

//         cout << rawWords << endl;

//         if(rawWords.at(i) == space || rawWords.at(i) == p) {
//             if (cnt >= 2) {
//                 // cout << "count = " << cnt << endl;
//                 // cout << "int = " << i;
//                 // cout << rawWords[i - cnt] << " - ";
//                 // cout << rawWords[i - 1] << endl;
//                 string temp = rawWords.substr( i - cnt, i);
//                 cout << "our key is \"" << temp << "\"" << endl;
//                 cnt = 0;
//                 continue;
//             }

//             if( (i == rawWords.size() - 1) ) { //if we reach the end of the string
//                 cout << "passed first if statement" << endl;
//                 if(cnt >= 2) { 
//                 string temp = rawWords.substr(i - cnt, i);
//                 cout << "our key is \"" << temp << "\"" << endl;
//                 }
//             }
//         }
//         cnt++;

//         // if ( *space == " " ) {
//         //     cout <<"theyre eual" << endl;
//         // }
//         // if (*p == ".") {
//         //     cout << "they;re equal" << endl;
//         // }

//         // if(rawWords.at(i) == space || rawWords.at(i) == p) {
//         //     if (cnt >= 2) {
//         //         string temp = rawWords.substr( i - cnt, i - 1);
//         //         cnt = 0;
//         //         continue;
//         //     }
//         // }
//     }