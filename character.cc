#include"goto.h"
#include"character.h"
#include <iostream>
#include <string>
using namespace std;

Character::~Character(){}

Character::Character(int health,int attack,int defense,int xcoord,int ycoord,int character_number){
	this->health_points = health;
	this->attack = attack;
	this->defense = defense;
	this->xcoord = xcoord;
	this->ycoord = ycoord;
	this->character_number = character_number;
	this->new_health_points = health;
	this->new_attack = attack;
	this->new_defense = defense;
}

int Character::no_of_characters = 0;

void Character::dec_health(int n){
	new_health_points -= n;
}

void Character::set_coord(int x,int y){
	this->xcoord = x;
	this->ycoord = y;
}

int Character::take(GoTo &g){
	return g.go_to(this);
}


int Character::get_coord(char c){
	if(c == 'x'){
		return xcoord;
	}
	else{
		return ycoord;
	}
}

void Character::change_defense(int change){
	new_defense += change;
	if(new_defense <= 0){
		new_defense = 0;
	}
}

void Character::change_attack(int change){
	new_attack += change;
	if(new_attack <= 0){
		new_attack = 0;
	}
}

void Character::change_health(int change){
	new_health_points = change + new_health_points;
	if(new_health_points > health_points){
		new_health_points = health_points;
	}
	if(new_health_points <= 0){
		new_health_points = 1;
	}
}



int Character::generate_character_number(){
	++no_of_characters;
	return no_of_characters;
}	

	
