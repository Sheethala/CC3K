#ifndef __GOTO_H__
#define __GOTO_H__
#include<iostream>
#include<cstdlib>
#include<string>

class Potion;
class WD;
class WA;
class RH;
class PH;
class BA;
class BD;
class Dragon;
class Merchant;
class Enemies;
class Character;
class Hoard;

class GoTo{
	public:
	GoTo();
	virtual int go_to(Enemies *e);
	virtual ~GoTo() = 0;
	virtual int go_to(Merchant *m);
	virtual void go_to(RH *p);
	virtual void go_to(WD *p);
	virtual void go_to(WA *p);
	virtual void go_to(PH *p);
	virtual int go_to(Character *c);
	virtual void go_to(BD *p);
	virtual int go_to(Dragon *d);
	virtual void go_to(BA *p);
	virtual void go_to(Potion *p);	
	virtual void go_to(Hoard *h);
};
#endif
