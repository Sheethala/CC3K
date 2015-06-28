#ifndef __POTION_H__
#define __POTION_H__
#include "item.h"

class GoTo;

class Potion: public Item{
	//in this class we create a potion and this is a parent class for all other potions we create(eg:rh,ph etc etc)
	public:
	int size;
	Potion(int item_number,int size,char c);
	int get_size();
	virtual bool is_seen();
	virtual void take(GoTo &g);
};
#endif


