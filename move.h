#ifndef __MOVE_H__
#define __MOVE_H__
#include <iostream>
#include <string>
#include "effect.h"

class Character;

class Move: public UserEffects{
    public:
    Character* c;
    Move(Character* c, int x, int y);
    Character *get_character();
    ~Move();
};

#endif
