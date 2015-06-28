#ifndef __VAMPIRE_H__
#define __VAMPIRE_H__
#include"enemies.h"
#include<iostream>

class Vampire: public Enemies{
public:
	~Vampire();
	Vampire(int x,int y,int character_number);
};
#endif
