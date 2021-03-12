#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Map {
public:
    // Object Constructor
    Map(const int c, const int r, const int colmns, std::string file);

    // 


private:
    void setrows();
    char** array; // 2-D char array -> map
    int countries;
    int rows;
    int col;

}