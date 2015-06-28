#ifndef __ATTACK_H__
#define __ATTACK_H__
#include "effect.h"

class Character;
//This is the class which helps us attack an enmy and vice versa.
class Attack: public UserEffects{
    public:
    Character *at;
    Attack(Character *at, int x, int y);
    Character *get_at();
    ~Attack();
};

#endif
