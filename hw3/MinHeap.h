#ifndef MINHEAP_H
#define MINHEAP_H
#include <iostream>
#include <map>


template <class T>
class MinHeap {
    public:
    MinHeap (int d);
    /* Constructor that builds a d-ary Min Heap
        This should work for any d >= 2,
        but doesn't have to do anything for smaller d.*/

    ~MinHeap ();

    void add (T item, int priority);
        /* adds the item to the heap, with the given priority. */

    const T & peek () const;
        /* returns the element with smallest priority.  
        Break ties however you wish.  
        Throws an exception if the heap is empty. */

    void remove ();
        /* removes the element with smallest priority.
        Break ties however you wish.
        Throws an exception if the heap is empty. */

    bool isEmpty ();
        /* returns true iff there are no elements on the heap. */

private:
    // whatever you need to naturally store things.
    int D;       // Number of children
    int index;   // Number of nodes
    int P;       // Priority
    T key;       
    std::map<int,set<MinHeap>> children;

    // You may also add helper functions here.
};

MinHeap<T>::MinHeap (int d) {
    this->D = d;
    this->index = 0;
    this->P = 0;
}

bool MinHeap<T>::isEmpty() {
    return this->children.isempty();
}

void MinHeap<T>::add (T item, int priority) {
    if (this->index == 0) {
        this->P = priority;
        this->key = item;
    }
    else if (this->P > priority) {
        if (children.isempty()) {
            this->chidren.insert( make_pair(this->node + 1,item));
        }
    }
}


