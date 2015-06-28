#ifndef __ENEMYCREATOR_H__
#define __ENEMYCREATOR_H__
class Enemies;

class EnemyCreator{
	public:
	EnemyCreator();
	Enemies* new_enemy(char c);
	Enemies* new_enemy();
};

#endif
