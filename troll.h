#ifndef __TROLL_H__
#define __TROLL_H__
#include "enemies.h"

class Troll:public Enemies{
	public:
	~Troll();
	Troll(int x,int y,int character_number);
};
#endif
