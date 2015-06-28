#ifndef __ENEMIES_H__
#define __ENEMIES_H__
#include<iostream>
#include<string>
#include "character.h"

class GoTo;
class EnemiesTranslator;

class Enemies:public Character{
	public:
	void injured(int injury);
	EnemiesTranslator *input;
	char type;
	bool enemy;
	bool move;
	Enemies(int health,int attack,int defense,int x,int y,char type,int character_number,EnemiesTranslator *input,bool enemy = true,bool move = true);
	bool can_move();
	int take(GoTo &g);
	virtual void change_info();
	virtual ~Enemies();
	virtual bool is_enemy();
};

#endif
