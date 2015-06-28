#ifndef __BD_H__
#define __BD_H__
#include<iostream>
#include<string>
#include"potion.h"

class GoTo;

class BD: public Potion{
	public:
	static bool seen;
	BD(int item_number);
	static void show_bd();
	static void hide_bd();
	void take(GoTo &g);
    bool is_seen();
	std::string type_of_item();
};
#endif
	
