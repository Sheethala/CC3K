#include <iostream>
#include <string>
#include "effect.h"
#include "move.h"
#include "character.h"
using namespace std;

Move::Move(Character *c, int x, int y) : c(c), UserEffects(x,y) {}

Character* Move::get_character(){
    return c;
}

Move::~Move(){}
