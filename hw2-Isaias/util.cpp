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
    //split every word greater than 2 char into its own string

    //first CREATE A SET

    set< string> keyWords; //this will hold the set of words whos length is >= 2;

    size_t i = 0; //keep track of iterations

    while (!rawWords.empty() ){
        char space = ' ';
        char p = '.';
        // cout << "iteration "<< i << " and char count is " << i << endl;

        if(rawWords.at(i) == space || rawWords.at(i) == p) {
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
            else { // word is smaller than 2 char
                rawWords = rawWords.substr(i + 1, rawWords.size() - 1);
                i = 0;
            }
        }
        if (i == rawWords.size() - 1) { //if this happens we know we are done!!!
            string temp = rawWords.substr(0, i + 1);
            // cout << "our key is \"" << temp << "\"" << endl;
            keyWords.insert(temp);
            break;
        }
        i++;
    }
    set<string>::iterator itr;
    cout << "the set begins: " << endl;
    for(itr = keyWords.begin(); itr != keyWords.end(); itr++) {
        cout << *itr << " ";
    }
    cout << "\nthe set ends" << endl;
    
    


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
    
    string rawWords = "hello my name is Mr. isaiah";
    parseStringToWords(rawWords);

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