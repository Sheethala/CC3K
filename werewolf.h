#ifndef __WEREWOLF_H__
#define __WEREWOLF_H__
#include "enemies.h"

class Werewolf: public Enemies{
	public:
		Werewolf(int x,int y,int character_number);
		~Werewolf();
};
#endif
