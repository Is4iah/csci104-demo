#include <iostream>
#include <fstream>
#include <string>
#include "maps.h"

using namespace std;

Map::Map(const std::string file1, const std::string file2) {
    // open file 
    ifstream fin;
    fin.open(file);
    
    countries = c;
    rows = r;
    col = colmns;


    array = new char*[rows];
    for (int i = 0; i < rows; i++) {
        array[i] = new char[col];
        for (int j = 0; j < col; j++) {
            fin >> arra[i][j];
        }
    }
}

Map::setrows() {
    for (int i = 0; i < col; i )
}