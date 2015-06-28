#ifndef __DRAGONTRANSLATOR_H__
#define __DRAGONTRANSLATOR_H__
#include "enemiestranslator.h"

class Brain;

class Enemies;

class DragonTranslator: public EnemiesTranslator{
	public:
	bool adjacent(Enemies *e);
	~DragonTranslator();
	DragonTranslator();
	};
#endif
