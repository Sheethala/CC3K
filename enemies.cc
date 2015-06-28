#include"enemies.h"
#include"enemiestranslator.h"
#include"goto.h"
#include<iostream>
#include<string>
using namespace std;

Enemies::Enemies(int health,int attack,int defense,int x,int y,char type,int character_number,EnemiesTranslator *input,bool enemy,bool move):
	Character(health,attack,defense,x,y,character_number){
	this->input = input;
	this->type = type;
	this->enemy = enemy;
	this->move = move;
}

bool Enemies::can_move(){
	return move;
}

bool Enemies::is_enemy(){
	return enemy;
}

int Enemies::take(GoTo &g){
	return g.go_to(this);
}

void Enemies::change_info(){
	input->translate(this);
}

Enemies::~Enemies(){
    delete input;
}

void Enemies::injured(int injury){
	new_health_points = new_health_points - injury;
}
