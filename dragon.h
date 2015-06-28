#ifndef __DRAGON_H__
#define __DRAGON_H__
#include "enemies.h"
#include "dragonhoard.h"
#include <iostream>
#include <string>
#include <vector>

class GoTo;
class Hoard;

class Dragon:public Enemies{
	DragonHoard *protected_hoard;
	public:
	~Dragon();
	int take(GoTo &g);
	int get_hoard_pos(char c);
	void free_hoard();
	void protect(DragonHoard *hoard);
	Dragon(int x,int y,int character_number);
};

#endif
	
