#ifndef __BA_H__
#define __BA_H__
#include <iostream>
#include <string>
#include<queue>
#include"potion.h"
#include "goto.h"

class GoTo;

class BA: public Potion{
    public:
    static bool seen;
	BA(int item_number);
	static void show_ba();
	static void hide_ba();
	bool is_seen();
	void take(GoTo &g);
	std::string type_of_item();
};
#endif

	
	
