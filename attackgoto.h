#ifndef __ATTACKGOTO_H__
#define __ATTACKGOTO_H__
#include"goto.h"
#include<iostream>
#include<queue>

class Character;
class Enemies;
class BD;
class Merchant;
class BA;
class PH;
class RH;
class WD;
class WA;


class AttackGoTo: public GoTo{
	public:
	Character *c;
	int go_to(Merchant *m);
	AttackGoTo(Character *c);
	int go_to(Character *ch);
	int go_to(Enemies *e);
	~AttackGoTo();
	int go_to(Dragon *d);
};
#endif
//THIS CLASS TAKES WHOSE GETTING ATTACKED AND THE ATTACKKER SO THE ACCORDING THINGS CAN GET DEDUCTED.
