#ifndef MAPS_H
#define MAPS_H
#include <fstream>
#include <string> 
#include <list>
#include <map>
#include <set>
using namespace std;

class Map {

public:
	// Map();
	Map( const std::string& filename);
	// ~Map();

	bool isValid(char country);
	void solve(); // solves the puzzle
	void print(); // prints the puzzle
	bool solveHelper(int countryIndex);
	void answ();

private:
	// bool isValid(int row, int col);
	// bool solveHelper(int row, int col);
	// int world[15][80][80];
	int countries_, rows_, col_;
	char** world_map;
	std::string inFile;
	
	char* countryNames;
	std::map<char, int> countryColors;
	std::map<char, set<char> >neighbors; //avoids double counting
	int solved;

};

#endif

//understand how insertiom, pop works
//take into consideration the edge cases 