/*
CSCI 104: Homework 1 Problem 1

Write a recursive function to split a sorted singly-linked
list into two sorted linked lists, where one has the even 
numbers and the other contains the odd numbers. Students 
will receive no credit for non-recursive solutions. 
To test your program write a separate .cpp file and #include
split.h.  **Do NOT add main() to this file**.  When you submit
the function below should be the only one in this file.
*/

#include "split.h"
#include <cstddef>
#include <iostream>
using namespace std;

/* Add a prototype for a helper function here if you need */


void split(Node*& in, Node*& odds, Node*& evens)
{
	Node* head = in;

	if (head == NULL) return;

	Node* temp = NULL;

	if (head->value % 2 == 0) {
		evens = head;
		temp = head->next;
		evens->next = NULL;
		split(temp, odds, evens->next);
	}
	else {
		odds = head;
		temp = head->next;
		odds->next = NULL;
		split(temp, odds->next, evens);
	}
}

int main() {
    Node* node1 = new Node(1, NULL);

    Node* node2 = new Node(2, node1);

    Node* node3 = new Node(3, node2);

    Node* node4 = new Node(4, node3);

    Node* node5 = new Node(5, node4);
    Node* node6 = new Node(6, node5);
    Node* node7 = new Node(7, node6);
    Node* node8 = new Node(0, node7);
    Node* node9 = new Node(9, node8);
    Node* node10 = new Node(10, node9);
    Node* node11 = new Node(11, node10);
    Node* node12 = new Node(12, node11);
    Node* node13 = new Node(13, node12);


    Node* evens = NULL;
    Node* odds = NULL;

    split(node13, odds, evens);

    cout << "Odds: ";

    while (odds != NULL) {
        cout << odds->value << " ";
        odds = odds->next;
    }
    cout << endl;

    cout << "Evens: ";
    while (evens != NULL) {
        cout << evens->value << " ";
        evens = evens->next;
    }
    cout << endl;
}
/* If you needed a helper function, write it here */
