#ifndef __CHAMBERCELLS_H__
#define __CHAMBERCELLS_H__
#include <iostream>
#include <vector>
#include "cell.h"

class ChamberCells{
    public:
    std::vector <Cell*> chamber_cells;
    ChamberCells(std::vector <Cell*> c);
};

#endif
