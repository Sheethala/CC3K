#include <string>
#include <iostream>
#include "attack.h"
#include "effect.h"

//this is our constructor.
Attack::Attack(Character *at, int x, int y): at(at), UserEffects(x, y) {}

//this returns an instance of an enemy we should attack
Character *Attack::get_at(){
    return at;
}

//this is our destructor
Attack::~Attack(){}
