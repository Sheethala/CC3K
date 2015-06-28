#ifndef __PH_H__
#define __PH_H__
#include<iostream>
#include<string>
#include<queue>
#include "potion.h"

class GoTo;

class PH: public Potion{
	public:
	static bool seen;
	PH(int item_number);
	static void show_ph();
	static void hide_ph();
	bool is_seen();
	std::string type_of_item();
	void take(GoTo &g);
};
#endif
