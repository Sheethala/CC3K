#ifndef __MERCHANT_H__
#define __MERCHANT_H__
#include"character.h"
#include"enemies.h"

class GoTo;

class Merchant:public Enemies{
	public:
    static bool enemy;
	~Merchant();
	int take(GoTo &g);
	bool is_enemy();
	Merchant(int x,int y,int character_number);
	static void pissed_merchants(bool pissed = true);
};

#endif
