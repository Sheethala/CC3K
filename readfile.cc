#include "readfile.h"
#include "cell.h"
#include "floorplangenerator.h"
#include <fstream>
#include <ios>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define Wall 1
#define Blank 0
#define Doorway 2
#define Passage 3
#define Stairs 4
#define Floor 5

ReadFile::ReadFile(): filename("") {}

vector<vector<vector<char> > > ReadFile::read_layouts (string file){
    filename = file;
    ifstream fs(file.c_str());
    vector<vector<vector<char> > > all_floors;
    fs.unsetf(ios_base::skipws);
    char symbol;
    for (int x = 0; x < 5; x++){
        vector<vector<char > > all_cells;
        for (int y = 0; y < 25; y++){
            vector<char> row;
            for (int z = 0; z < 79; z++){
                fs >> symbol;
                row.push_back(symbol);
            }
            fs.ignore();
            all_cells.push_back(row);
        }
        all_floors.push_back(all_cells);
    }
    fs.close();
    return all_floors;
}

int ReadFile::convert_to_celltype (char c){
    if (c == '|'){
        return Wall;
    } else if (c == '-'){
        return Wall;
    } else if (c == ' '){
        return Blank;
    } else if (c == '#'){
        return Passage;
    } else if (c == '/'){
        return Stairs;
    } else if (c == '+'){
        return Doorway;
    } else{
        return Floor;
    }
}
