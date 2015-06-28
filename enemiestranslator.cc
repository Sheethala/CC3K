#include<cstdlib>
#include<sstream>
#include "playeroption.h"
#include"brain.h"
#include<utility>
#include<string>
#include<cmath>
#include"enemiestranslator.h"
#include"enemies.h"
#include"move.h"
#include"attack.h"
#include"attackgoto.h"
#include<queue>
#include<cstring>
using namespace std;

std::pair<int,int> EnemiesTranslator::get_pos(int n){
	int a;
	int b;
	if(n == 1){//These are the coordinates and controls
		a = -1;
		b = 0;//This makes the person move left
	}
	if(n == 2){//This makes the person move right
		a = 1;
		b = 0;
	}
	if(n == 3){
		a = 0;
		b = -1; //This makes the person move down
	}
	if(n == 4){
		a = 0;
		b = 1;//This makes the person move up
	}
	if(n == 5){
		a = -1;
		b = -1; //Makes the person move diagonnaly
	}
	if(n == 6){
		a = -1;
		b - 1;//makes the person move diagonally
	}
	if(n == 7){
		a = 1;
		b = -1;//Makes the person move diagonally
    }   	
	else{
		a = 1;
		b = 1;//Makes the person move diagonally
	}
	std::pair<int,int> p(a,b);
	return p;
}

EnemiesTranslator::~EnemiesTranslator(){}

void EnemiesTranslator::move_enemy_random(Enemies *e){
	int n;
	n = (rand()%8)+1;
	int the_x_coordinate = e->get_coord('x');
	int the_y_coordinate = e->get_coord('y');
	int change_x_coordinate;
	int change_y_coordinate;
	std::pair<int,int> change = get_pos(n);
	change_y_coordinate = the_y_coordinate + change.second;
	change_x_coordinate = the_x_coordinate + change.first;
	Move m = Move(e,change_x_coordinate,change_y_coordinate);
	if(valid(m)){
		move_enemy(m);
	}
	else{
		translate(e);
	}
}
	

bool EnemiesTranslator::valid(Move &m){
	Character *e = m.get_character();
	int x = m.xcoord;
	int y = m.ycoord;
	FloorPlanGenerator* f = (b->get_allfloors())[b->brain_curfloor()];
	Cell *c = f->get_cell(x,y);
	if(next_to(e,m)){
		if((c->type == 5) && (!c->taken())){
			return true;
		}
	}
	return false;
}


	
//***************************************//
 
EnemiesTranslator::EnemiesTranslator(): status(""){
	b = Brain::getBrain();
}


void EnemiesTranslator::translate(Enemies *e){
	if(e->enemy == true){
		PlayerOption *p = PlayerOption::get_inst();
	    if(adjacent(e)){
		    Attack a = Attack(e,p->get_coord('x'),p->get_coord('y'));
		    attack(a);//We attack at this position
	    }
	    else if((e->can_move()) && (is_mobile(e))){
		    move_enemy_random(e);
	    }
    } else  if((e->can_move()) && (is_mobile(e))){
		move_enemy_random(e);
	}
}

bool EnemiesTranslator::is_mobile(Enemies *e){
	Cell *c;
	FloorPlanGenerator  *f = (b->get_allfloors())[b->brain_curfloor()];
	bool free = false;
	int ex = e->get_coord('x');
	int ey = e->get_coord('y');
	for(int j = -1;j<=1;++j){
		for(int k = -1;k<=1;++k){
			c = f->get_cell(ex+j,ey+k);
			if((c->type==5) && (!c->taken())){
				free = true;
			}
		}
	}
		return free;
}
	



void EnemiesTranslator::move_enemy(Move &m){
	Character *c = m.get_character(); 
	int x = c->get_coord('x');
	int y = c->get_coord('y');
	int nx = m.get_x_coord();
	int ny = m.get_x_coord();
    FloorPlanGenerator  *thisfloor = (b->get_allfloors())[b->brain_curfloor()];
    Cell *thiscell = thisfloor->get_cell(x,y);
    Cell *possible = thisfloor->get_cell(nx,ny);
    c->set_coord(nx,ny);
    possible->change_info(c->character_number,true,false,false);
    possible->rep = 'h';
    thiscell->change_info(false,false,false);
    thiscell->rep = ('.');
    possible->update_output(*thisfloor->get_output());
    thiscell->update_output(*thisfloor->get_output());
}

bool EnemiesTranslator::adjacent(Enemies *e){
	PlayerOption *p = PlayerOption::get_inst();
	int px,py,ex,ey;
	px = p->get_coord('x');
	py = p->get_coord('y');
	ex = e->get_coord('x');
	ey= e->get_coord('y');
	if((abs(px-ex) <= 1) && ((abs(py-ey))<=1)){
		return true;
	}
	else{
		return false;
	}
}

void EnemiesTranslator::update_output(Output &o,string s){
	o.setStatus(s);
}

void EnemiesTranslator::attack(Attack &a){
	PlayerOption *p = PlayerOption::get_inst();
	FloorPlanGenerator *f = (b->get_allfloors())[b->brain_curfloor()];
	Character *c = a.get_at();
	Output *o = f->get_output();	
	AttackGoTo ag = AttackGoTo(c);
	int dec_health = p->take(ag);
	char char_name = 'h';
    if (dec_health < 0){
        status = char_name + " misses its attack on PC";
    } else {
        status = char_name + " deals damage to PC";
    }
    if (p->new_health_points <= 0){
        b->endgame(false);
    }
    update_output(*o,status);
}

