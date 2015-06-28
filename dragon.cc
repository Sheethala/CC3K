#include"dragontranslator.h"
#include"dragon.h"
#include "dragonhoard.h"
#include"goto.h"
#include<iostream>
#include <string>
#include <cstdlib>
using namespace std;

Dragon::~Dragon(){}

int Dragon::take(GoTo &g){
	return g.go_to(this);
}

int Dragon::get_hoard_pos(char c){
	if(c == 'x'){
		return xcoord;
	}
	else{
		return ycoord;
	}
}

void Dragon::free_hoard(){
	if(protected_hoard){
		protected_hoard->can_steal = true;
	}
}

void Dragon::protect(DragonHoard *hoard){
	protected_hoard = hoard;
	protected_hoard->can_steal = false; //Because player can't steal.
}

Dragon::Dragon(int x,int y,int character_number):
	Enemies(150, 20, 20, x, y, 'D', character_number, new DragonTranslator(), true, false){
	this->protected_hoard = false;
}


