#include "maps.h"
#include <vector>
#include <iostream>
#include <fstream>
#include <string>
#include <list>

using namespace std;

Map::Map(const std::string& filename) { 
	solved = 0;
	inFile = filename;

	ifstream fin;
	fin.open(inFile);

	fin >>  countries_;
	fin >>  rows_;
	fin >>  col_;

	//create map 
	world_map = new char*[rows_];
	for (int i = 0; i < rows_; i++) {
		world_map[i] = new char[col_];
	}



	//insert countries into map
	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < col_; j++ ) {
			fin >> world_map[i][j];
		}
	}

	//create keys

	//create country names
	char* countryNames =  new char[countries_];
	for(int i = 0; i < countries_; i++) {
		char temp = static_cast<char>(i) + 'A';
		countryNames[i] = temp;
	}

	//check countrynames

	cout << "our countries are: 1" << endl;
	for(int i = 0; i < countries_; i++) {
		cout << countryNames[i] << " ";
	}cout << endl;


	//create the neightbor map and colors map!!!
	for(int i = 0; i < countries_; i++) {
		set<char> border;
		neighbors.insert( make_pair( countryNames[i] , border) );
		countryColors.insert( make_pair( countryNames[i], -1));
	}

	

	//insert neighbors 
	for (int i = 0; i < rows_ ; i++) {
		for (int j = 0; j < col_ ; j++ ) {
			//right
			if(j + 1 != col_ ) { 
				if(world_map[i][j] != world_map[i][j+1]) {
					// them as neighbors
					neighbors[ world_map[i][j]   ].insert(world_map[i][j+1]);
					neighbors[ world_map[i][j+1] ].insert(world_map[i][j]  );
				}
			}
			//left
			if(j - 1 >= 0 ) { 
				if(world_map[i][j] != world_map[i][j-1]) {
					// them as neighbors
					neighbors[ world_map[i][j]   ].insert(world_map[i][j-1]);
					neighbors[ world_map[i][j-1] ].insert(world_map[i][j]  );
				}
			}
			//below
			if( i + 1 < rows_ ) { 
				if(world_map[i][j] != world_map[i + 1][j]) {
					// them as neighbors
					neighbors[ world_map[i][j]   ].insert(world_map[i + 1][j]);
					neighbors[ world_map[i + 1][j] ].insert(world_map[i][j]    );
				}
			}
			//above
			if( i - 1 >= 0 ) { 
				if(world_map[i][j] != world_map[i - 1][j]) {
					// them as neighbors
					neighbors[ world_map[i][j]   ].insert(world_map[i - 1][j]);
					neighbors[ world_map[i - 1][j] ].insert(world_map[i][j]    );
				}
			}

		}
	}


	//world_map 
	//check block up, down, left, right, 
	//make seperate check function to pass in dimension of map and pass in index to see if that index 
	//is valid
    // largest i can be is m
	// 

	cout << "adjecency list is: " << endl;
	for(int i = 0; i < countries_; i++) {
		char key = countryNames[i];
		cout << key << " : " ;
		for (set<char>::iterator j = neighbors[key].begin(); j != neighbors[key].end(); j++) {
			cout << (*j) << " ";
		}
		cout << endl;
	}

}


/* prints the map */
void Map::print() {

	ofstream fout;
	fout.open(outFile);

	for (int i = 0; i < rows_; i++) {
		for (int j = 0; j < col_; j++ ) {
			fout << world_map[i][j];
		}
		fout << endl;
	}
}

void Map::solve() {

	//base cases
	//num countries <= 2; then only 1 or 2 colors are necessary

	if(this->countries_ == 0) { 
	}
	else if(this->countries_ == 1) {
		cout << "A: 1" << endl;
	}
	else if(this->countries_ == 2) {
		cout << "A: 1" << endl;
		cout << "B: 2" << endl;
	}
	else {
		if( solveHelper(0)) { //a solution was found
			answ();
		}
		else {
			cout << "no solution was found" << endl;
		}
	}

}

bool Map::isValid(char currCountry) {

	//check if possible color is held by a neighbors

	//make sure that its color is not equal to any of its neighbors colors
	set<char> countryNeighbors = neighbors[currCountry];

	for(set<char>::iterator i = countryNeighbors.begin(); i != countryNeighbors.end(); i++) {
		//if a neighbor already has a the color than it is invalid coloring
		if( countryColors[currCountry] == countryColors[*i]) {
			return false;
		}
	}

	return true;

/* 	for(int i = 0; i < row_; i++) {
		//how to know if same country or diff country;
		if (value == world_map[i][col_]) { //same country
			continue;
		}

		//diff country 

	} */
}

bool Map::solveHelper(int countryIndex) {

	
	//country index will hold a countries index for the array of country names
	if (countryIndex == countries_) { return true;}

	//recursively check the first country, then second, then third... etc. 

	char currCountry = this->countryNames[countryIndex];

	for (int i = 1; i < 5; i++) { 
		countryColors[currCountry] = i;

		if( isValid(currCountry)) {

			if (solveHelper( countryIndex + 1 )) return true;

		}
	}

	//reset country color to -1 and try next number;
	countryColors[currCountry] = -1;
	return false;

}

void Map::answ() {
	// cout << "our countries are: 1" << endl;
	// for(int i = 0; i < countries_; i++) {
	// 	cout << countryNames[i] << " ";
	// }cout << endl;

	for(int j = 0; j < countries_; j++) { 
		// for(map<char,int>::iterator i = countryColors.begin(); i != countryColors.end(); i++) { //ordered alphabetically 
		// }
		cout << countryNames[j] << " : " << countryColors[countryNames[j]] << endl;
	}

	// cout << "our countries are: 2" << endl;
	// for(int i = 0; i < countries_; i++) {
	// 	cout << countryNames[i] << " ";
	// }cout << endl;
}




















	/* //create our array of countries
	int counted = 0;
	countryNames[0] = world_map[0][0]; //A

	for(int i = 0; i < rows_; i++) {
		for(int j = 0; j< col_; j++) {
			//checks horizontally
			if (countryNames[counted] == world_map[i][j]) { //if they have the same name
				continue;
			}
			else { //diff names
				countryNames[]
			}
		}
	} */