#ifndef __ITEM_H__
#define __ITEM_H__
#include <iostream>
#include <string>
#include <vector>
#include "goto.h"

class GoTo;

class Item{
    public:
    int xcoord;
    int ycoord;
    int item_number;
    char item;
    bool can_have;
    bool can_steal;
    bool can_drink;
    static int no_of_items;
    Item();
    Item(int a, char b, bool c = false, bool d = false, int e = 0, int f = 0);
    virtual ~Item() = 0;
    virtual void take(GoTo &g);
    static int create_number();
    int get_coord(char c);
    virtual std::string type_of_item();
    virtual bool is_seen();
};

#endif
