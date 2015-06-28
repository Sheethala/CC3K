#include <string>
#include <iostream>
#include "character.h"
#include "useitem.h"
using namespace std;

UseItem::UseItem(Character *player, int x, int y): player(player), UserEffects(x, y) {}

Character* UseItem::get_player(){
    return player;
}

UseItem::~UseItem() {}
