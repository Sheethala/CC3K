#include "item.h"
#include "goto.h"
#include <iostream>
#include <string>
using namespace std;

int Item::no_of_items = 0;

Item::Item(int a, char b, bool c, bool d, int e, int f): item_number(a), item(b), can_have(c), can_steal(c), can_drink(d), xcoord(e), ycoord(f) {}

Item::~Item(){}

void Item::take(GoTo &g) {}

int Item::create_number(){
    no_of_items = no_of_items + 1;
    return no_of_items;
}



int Item::get_coord(char c){
    if (c == 'x'){
        return xcoord;
    } else {
        return ycoord;
    }
}

string Item::type_of_item(){
    return "Item";
}

bool Item::is_seen(){
    return false;
}
