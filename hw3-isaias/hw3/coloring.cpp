#include <iostream>
#include <vector>
#include "maps.h"
#include <fstream>
using namespace std;

int main (int argc, char **argv) {
	//this is where we test the program 
	cout << "Check output file" << endl;
	if(argv[1] == NULL) {
		cout << "NO INPUT FILE" << endl;
	}

	string inFile = argv[1];
	string outFile = argv[2];

	Map* my_map = new Map(inFile);
	// my_map->print();
	// my_map->solve();

	// int x = 0;
	// char newX =  static_cast<char>(x);
	// newX += 'A';
	// cout << "new x is " << newX << endl;


}