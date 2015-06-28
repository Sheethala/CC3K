#include<iostream>
#include"gotoitem.h"
#include"hoard.h"
#include"playeroption.h"
#include"merchant.h"
#include<queue>
#include"normalhoard.h"
#include<cmath>
#include"attackgoto.h"
#include"character.h"
#include"dragon.h"
#include<cstdlib>

using namespace std;

class WD;
class WA;
class RH;
class PH;
class BD;
class BA;

int AttackGoTo::go_to(Enemies *e){
	double defense = static_cast<double>(e->new_defense);
        double attack = static_cast<double>(c->new_attack);
	int d = static_cast<int>(ceil((100.00/(100.00+defense))*(attack)));
	e->dec_health(d);
	if(!e->new_health_points <= 0){
		Hoard h = NormalHoard(-1);
        GoToItem steal_hoard = GoToItem();
	}
	return d;
}


AttackGoTo::~AttackGoTo(){}

int AttackGoTo::go_to(Merchant *m){
	 double defense = static_cast<double>(m->new_defense);
        double attack = static_cast<double>(c->new_attack);
        int d = static_cast<int>(ceil((100.00/(100.00+defense))*(attack)));
	m->dec_health(d);
	if(m->enemy){
		Merchant::pissed_merchants();
	}
	return d;
}


AttackGoTo::AttackGoTo(Character *c): c(c){}

int AttackGoTo::go_to(Dragon *d){
	double defense = static_cast<double>(d->new_defense);
        double attack = static_cast<double>(c->new_attack);
        int da = static_cast<int>(ceil((100.00/(100.00+defense))*(attack)));
	d->dec_health(da);
	if(d->new_health_points <= 0){
		d->free_hoard();
	}
	return da;
}

int AttackGoTo::go_to(Character *ch){
	double defense = static_cast<double>(ch->new_defense);
	double attack = static_cast<double>(c->new_attack);
	
	int n = (rand() %2);
	int d;
	if(n == 1){
		d = static_cast<int>(ceil((100.00/100.00+defense)) * (attack));
	}
	else{
		d = 0;
	}
	return d;
}


