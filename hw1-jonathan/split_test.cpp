#include <iostream>
#include <cstddef>
#include "split.h"

using namespace std;

main() {
	Node* node1 = new Node(4,NULL);
	
	Node* node2 = new Node(3,node1);

	/*Node* node3 = new Node;
	node1->value = 2;
	node1->next = node2;

	Node* node4 = new Node;
	node1->value = 1;
	node1->next = node3;*/

	Node* evens = new Node(0,NULL);
	Node* odds = new Node(0,NULL);

	split(node2, odds, evens);
	
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