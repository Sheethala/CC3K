#ifndef __WA_H__
#define __WA_H__

#include"potion.h"
#include<iostream>
#include<string>

class GoTo;

class WA: public Potion{
	public:
	static bool seen;
	WA(int item_number);
	bool is_seen();
	static void show_wa();
	static void hide_wa();
	std::string type_of_item();
	void take(GoTo &g);
};
#endif
