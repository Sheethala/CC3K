#ifndef ___RH_H__
#define __RH_H__
#include"potion.h"
#include<iostream>
#include<string>
#include<queue>

class GoTo;

class RH: public Potion{
	public:
    static bool seen;
	RH(int item_number);
	bool is_seen();
	static void show_rh();
	static void hide_rh();
	void take(GoTo &g);
	std::string type_of_item();
};
#endif
