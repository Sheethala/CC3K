#ifndef __GOBLIN_H__
#define __GOBLIN_H__
#include"enemies.h"
#include<iostream>
#include<vector>

class Goblin:public Enemies{
	public:
	Goblin(int x,int y,int character_number);
	~Goblin();
};
#endif	
