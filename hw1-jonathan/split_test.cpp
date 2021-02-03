#include <iostream>
#include <cstddef>
#include "split.h"

using namespace std;

main() {
	Node* node1 = new Node;
	node1->value = 4;
	node1->next = NULL;
	
	Node* node2 = new Node;
	node1->value = 3;
	node1->next = node1;

	Node* node3 = new Node;
	node1->value = 2;
	node1->next = node2;

	Node* node4 = new Node;
	node1->value = 1;
	node1->next = node3;

	Node* evens = NULL;
	Node* odds = NULL;

	split(node4, odds, evens);
	
	cout << "Odds: " << endl;

	while (odds != NULL) {
		cout << odds->value << " ";
		odds = odds->next;
	}

	cout << "Evens: " << endl;
	while (evens != NULL) {
		cout << evens->value << " ";
		evens = evens->next;
	}
}