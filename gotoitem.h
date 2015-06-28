#ifndef __GOTOITEM_H__
#define __GOTOITEM_H__
#include<iostream>
#include"goto.h"
#include<queue>

class PlayerOption;
class Hoard;
class WD;
class RH;
class PH;
class WA;
class BA;
class BD;

class GoToItem: public GoTo{
	public:
	PlayerOption *p;
	int change_attack;
	int change_defense;
	~GoToItem();
	GoToItem();
	void go_to(Hoard *h);
	void go_to(WD *p);
	void go_to(WA *p);
	void go_to(RH *p);
	void go_to(PH *p);
	void go_to(BA *p);
	void go_to(BD *p);
	int get_change_attack();
	int get_change_defense();
};
#endif



