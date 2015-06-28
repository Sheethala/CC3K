#ifndef __WD_H__
#define __WD_H__
#include<iostream>
#include"potion.h"
#include<string>
#include<queue>
class GoTo;

class WD: public Potion{
	public:
	static bool seen;
	WD(int item_number);
	bool is_seen();
	static void hide_wd();
	static void show_wd();
	std::string type_of_item();
	void take(GoTo &g);
};
#endif
