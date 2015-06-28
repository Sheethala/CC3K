#ifndef __ENEMIESTRANSLATOR_H__
#define __ENEMIESTRANSLATOR_H__
#include<string>
#include"commandtranslator.h"

class Brain;
class Enemies;
class Output;
class Move;
class Attack;

class EnemiesTranslator: public CommandTranslator{
	Brain *b;
	std::string status;
	public:
	std::pair<int,int> get_pos(int n);
	void move_enemy_random(Enemies* e);
	bool valid(Move &m);
	bool is_mobile(Enemies *e);
	void move_enemy(Move &m);
	~EnemiesTranslator();
	virtual void translate(Enemies *e);
	virtual bool adjacent(Enemies *e);
	void attack(Attack &a);
	void update_output(Output &o,std::string s);
	EnemiesTranslator();
};
#endif
