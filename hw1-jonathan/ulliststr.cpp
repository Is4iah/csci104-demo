#include <cstddef>
#include <stdexcept>
#include <string>
#include <iostream>
#include "ulliststr.h"
using namespace std;

/**
   * Default constructor - empty list
   */
ULListStr::ULListStr()
{
  head_ = NULL;
  tail_ = NULL;
  size_ = 0; //numbers inside of the array
}

  /**
   * Destructor
   */
ULListStr::~ULListStr()
{
  clear();
}

  /**
   * Returns true if the list is empty, false otherwise
   *   - MUST RUN in O(1)
   */
bool ULListStr::empty() const
{
  return size_ == 0;
}

size_t ULListStr::size() const
{
  return size_;
}

 /**
   * Overwrites the old value at index, pos, with val
   *   - Can run in O(n)
   */
void ULListStr::set(size_t loc, const std::string& val)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  *ptr = val;
}

  /**
   * Returns the value at index, pos
   *   - Can run in O(n)
   */
std::string& ULListStr::get(size_t loc)
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

  /**
   * Returns the value at index, pos
   *   - Can run in O(n)
   */
std::string const & ULListStr::get(size_t loc) const
{
  std::string* ptr = getValAtLoc(loc);
  if(ptr == NULL){
    throw std::invalid_argument("Bad location");
  }
  return *ptr;
}

  /**
   * Deletes all items in the list
   */
void ULListStr::clear()
{
  while(head_ != NULL){
    Item *temp = head_->next;
    delete head_;
    head_ = temp;
  }
  tail_ = NULL;
  size_ = 0;
}



  /**
   * Adds a new value to the back of the list
   *   - MUST RUN in O(1)
   */
void ULListStr::push_back(const std::string& val){
      // cerr << "we got new here" << endl;

    if (head_ == NULL) {
      head_ = new Item();
      tail_ = head_;
      head_->val[head_->last] = val;
      head_->last++;
    }
    else {
      if (tail_->last == ARRSIZE) { //the array at this node is full
        Item* newNode = new Item(); //create a new last node
        tail_->next = newNode;
        newNode->prev = tail_;
        tail_ = newNode;
        
        tail_->val[tail_->last] = val;
        cerr << tail_->val[0] << endl;
        (tail_->last)++;
      }
      else {
        // cerr << val << endl;
        tail_->val[tail_->last] = val;
        // cerr << tail_->val[tail_->last] << endl;
        (tail_->last)++;
      }
    }
    size_++;
    // cerr << "test" << endl;
}

  /**
   * Removes a value from the back of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_back() {
    if (tail_->last == 1) {//checks if node needs to be deleted
      if (size_ < ARRSIZE) {
        delete head_;
        delete tail_;
        size_ = 0;
      }
      else {
        Item* temp = tail_->prev;
        temp->next = NULL;
        delete tail_;
        tail_ = temp;
      }
    }
    else {
      tail_->val[(tail_->last) - 1] = '0'; //'0' bc its a string array 
      (tail_->last)--;
    }
    size_--;
  } 
  
  /**
   * Adds a new value to the front of the list.
   * If there is room before the 'first' value in
   * the head node add it there, otherwise, 
   * allocate a new head node.
   *   - MUST RUN in O(1)
   */
   void ULListStr::push_front(const std::string& val) {

    if (head_ == NULL) {
      head_ = new Item();
      tail_ = head_;
      head_->val[head_->last] = val;
      head_->last++;
    }
    else {
      if (head_->first == 0) { //the array at this node is full
        Item* newNode = new Item(); //create a new last node
        head_->prev = newNode;
        newNode->next = head_;
        head_ = newNode;
        
        head_->val[ARRSIZE - 1] = val;
        head_->last = ARRSIZE;
        head_->first = ARRSIZE - 1;
      }
      else {
        // cerr << val << endl;
        head_->val[(head_->first) - 1] = val;
        // cerr << tail_->val[tail_->last] << endl;
        head_->first--;
      }
    }
    size_++;
  }

  /**
   * Removes a value from the front of the list
   *   - MUST RUN in O(1)
   */
  void ULListStr::pop_front(){
    if (head_->first + 1 >= 10) {//checks if node needs to be deleted
    
      Item* temp = new Item();
      temp = head_->next;
      temp->prev = NULL;
      delete head_;
      head_ = temp;
      delete temp;
    }
    else {
      head_->val[head_->first] = ""; //'0' bc its a string array 
      (head_->first)--;
    }
    size_--;
  }
  
  /**
   * Returns a const reference to the back element
   *   - MUST RUN in O(1)
   */
  string const & ULListStr::back() const{
    return tail_->val[tail_->last];
  }

  /**
   * Returns a const reference to the front element
   *   - MUST RUN in O(1)
   */
  string const & ULListStr::front() const{
    return head_->val[head_->last];
  }


  std::string* ULListStr::getValAtLoc(size_t loc) const {
  //Checks for valid location
  // if (loc > size_)
  // {
  //   return NULL;
  // } 
  // else 
  // {
  //   Item* tempNode = new Item();
  //   tempNode = head_; //start at head
  //   unsigned int index = head_->first; //where we are within each node. Keeps index inside the node
  //   for (unsigned int i = 0; i < loc; i++) { //i keeps track of iterations in the loop, not the index within the node
  //     index++;
  //     if (index == tempNode->last) //reached end of a node
  //     {
  //       tempNode = tempNode->next; //moves to next node
  //       index = 0;
  //     }
  //   }
  //   return &(tempNode->val[index]); //returns adress of tempnode at the index
  // }
  if (loc > size_) return NULL;
  else{
    //check if its in the first node
    if ( head_->last - head_->first > loc) {
      return &head_->val[loc];
    }
    else {
      //we need to itereate through the nodes
      //first we move to the seconnd node
      Item* temp = new Item;
      temp = temp->next;
      loc -= (head_->last - head_->first)
    }
  }
}