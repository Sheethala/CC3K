#include "gotoitem.h"
#include<iostream>
#include"playeroption.h"
#include"hoard.h"
#include"wd.h"
#include"wa.h"
#include<cstdlib>
#include"rh.h"
#include"ph.h"
#include<string>
#include"bd.h"
#include"ba.h"
#include<queue>

using namespace std;

GoToItem::~GoToItem(){}

void GoToItem::go_to(WD *pn){
	int size = pn->get_size();
	if(p->get_option() == 'e'){
		p->change_defense(abs(size));
		change_defense += (abs(size));
	}
	else{
		p->change_defense(size);
		change_defense += size;
	}
        //p->change_defense(size);
        //change_defense += size;
        WD::show_wd();
}

void GoToItem::go_to(BD *pn){
        int size = pn->get_size();
        p->change_defense(size);
        change_defense += size;
        BD::show_bd();
}

void GoToItem::go_to(WA *pn){
        int size = pn->get_size();
	if(p->get_option() == 'e'){
		p->change_attack(abs(size));
		change_attack += size;
	}
	else{
		p->change_attack(size);
		change_attack += size;
	}
        //p->change_attack(size);
        //change_attack += size;
        WA::show_wa();
}


GoToItem::GoToItem(){
	this->change_attack = 0;
	this->change_defense = 0;
	this->p = PlayerOption::get_inst();
}

void GoToItem::go_to(PH *pn){
        int size = pn->get_size();
	if(p->get_option() == 'e'){
        	p->change_health(abs(size));
	}
	else{
		p->change_health(size);
	}
        //change_attack += size;
        PH::show_ph();
}

int GoToItem::get_change_defense(){
	return change_defense;
}

void GoToItem::go_to(BA *pn){
	int size = pn->get_size();
	p->change_attack(size);
	change_attack += size;
	BA::show_ba();
}

int GoToItem::get_change_attack(){
	return change_attack;
}


void GoToItem::go_to(RH *pn){
        int size = pn->get_size();
        p->change_health(size);
   	if(size < -30){}
        RH::show_rh();
}


void GoToItem::go_to(Hoard *h){
	int d = h->points;
	if(p->get_option() == 'o'){
		d = d/2;
	}
	if(p->get_option() == 'd'){
		d = d*2;
	}
	int dd = p->get_hoard();
	p->set_hoard(dd + d);
}


