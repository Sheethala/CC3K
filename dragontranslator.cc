#include<string>
#include<queue>
#include "dragontranslator.h"
#include "enemies.h"
#include "playeroption.h"
#include "dragon.h"
#include<cmath>
#include<cstdlib>

using namespace std;

DragonTranslator::DragonTranslator():EnemiesTranslator(){}

DragonTranslator::~DragonTranslator(){}

bool DragonTranslator::adjacent(Enemies *e){
	Dragon *d = static_cast<Dragon*>(e);
	PlayerOption *p = PlayerOption::get_inst();
	int px = p->get_coord('x');
	int py = p->get_coord('y');
	int ex = d->get_coord('x');
	int ey = d->get_coord('y'); 
	int hy = d->get_hoard_pos('y');
	int hx = d->get_hoard_pos('x');

	if(((abs(px-ex) <= 1) && (abs(py - ey) <= 1)) && ((abs(px-hx) <= 1))){
		return true;
	}
	else{
		return false;
	}

}
