#ifndef __CELL_H__
#define __CELL_H__
#include "readfile.h"
#include "output.h"
#include <iostream>
#include <vector>

class Cell{
    public:
    int type;
    bool p;
    int x;
    int y;
    bool item;
    bool hero;
    bool enemy;
    char rep;
    int num;
    char per;
        Cell(int x, int y, bool c, bool d, bool k, char f, int l, int e);
        Cell(int x, int y, char f, int d);
        void update_output(Output &o);
        char convert_rep(char r);
        char convert_typ(int t);
        bool taken();
        bool gold_item();//remove
        bool po_item();//remove
        void change_info(int n=-1, bool a=false, bool b=false, bool c=false);
        void set_x(int a);//remove
        void set_y(int a);//remove
};

#endif
