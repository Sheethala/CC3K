#include "effect.h"

UserEffects::UserEffects(int x, int y): xcoord(x), ycoord(y) {}

int UserEffects::get_x_coord(){
    return xcoord;
}

int UserEffects::get_y_coord(){
    return ycoord;
}

UserEffects::~UserEffects(){}
