#ifndef __USEITEM_H__
#define __USEITEM_H__
#include "effect.h"

class Character;
class UseItem: public UserEffects{
    public:
    Character *player;
    UseItem(Character *player, int x, int y);
    ~UseItem();
    Character *get_player();
};

#endif
