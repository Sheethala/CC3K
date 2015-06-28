#ifndef __ITEMGENERATOR_H__
#define __ITEMGENERATOR_H__
#include "item.h"
#include "potion.h"
#include <iostream>

class ItemGenerator{
	public:
	ItemGenerator();
	Item* get_item(char c);
	Item* get_potion();
	Item* get_hoard();
};
#endif
