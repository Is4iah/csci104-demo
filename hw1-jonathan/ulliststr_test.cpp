
#include "ulliststr.h"
#include <iostream>
using namespace std;


int main()
{
  //Making New Nodes In Linked List///
  ULListStr* list = new ULListStr;

  //Testing Push Back//

  //filling up a node with push back and printing it out
 for (int i = 0; i < 100; i++) { 
   list->push_back("Ojani");
   cout << i << ": " << list->get(i) << endl;
 }
 for (int i = 0; i < 99; i++) {
   list->pop_back();
     
 }
}
//  list->push_back("next node");
//  cout << list->get(10) << endl;

//  //Testing Pop Back//
//  list->pop_back();
//  //cout << list->get(10) << endl;
//  for (int i = ARRSIZE-1; i >= 0; i--) { 
//    list->pop_back();
//    //cout << list->get(i) << endl;
//  }
//  //Making a new node again
//  list->push_back("After pop back. I'm the new slot in the array at index 0! :)");
//  cout << list->get(0) << endl;
//  list->pop_back();

// //Testing Push Front//
//  for (int i = 0; i < ARRSIZE; i++) { 
//    list->push_front("Sam");
//    cout << list->get(i) << endl;
//  }
//   return 0;
// }
