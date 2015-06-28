#include<string>
#include<iostream>
#include<cstdlib>
#include"playeroption.h"
#include"playertranslator.h"
using namespace std;

PlayerOption::PlayerOption(int health_points,int attack,int defense,int x,int y,char option,int character_number):
Character(health_points,attack,defense,x,y,character_number),hoard(0),option(option){
	this->in = new PlayerTranslator();
	this->player_inst = this;
	atexit(cleanup);
}

PlayerOption *PlayerOption::get_inst(){
	return player_inst;
}

PlayerOption::~PlayerOption(){
	delete in;
}

void PlayerOption::cleanup(){
	delete player_inst;
	player_inst = NULL;
}

void PlayerOption::change_info(){
	this->in->translate(this);
}

void PlayerOption::set_hoard(int hd){
	this->hoard = hd;
}

int PlayerOption::get_hoard(){
	return hoard;
}

char PlayerOption::get_option(){
	return option;
}

string PlayerOption::char_to_option(char c){
	if( c == 'o'){
		return "Orc";
	}
	if(c == 'e'){
		return "Elf";
	}
	if(c == 'd'){
		return "Dwarf";
	}
	if(c == 'h'){
		return "Human";
	}
}

PlayerOption* PlayerOption::player_inst = NULL;

Elf::Elf(int x,int y,int character_number):
	PlayerOption(140,30,10,x,y,'e',character_number){}

Elf::~Elf() {}

Dwarf::~Dwarf(){}

Dwarf::Dwarf(int x,int y,int character_number):PlayerOption(100,20,30,x,y,'d',character_number){}

Human::~Human(){}
Human::Human(int x,int y,int character_number):PlayerOption(140,20,20,x,y,'h',character_number){}

Orc::~Orc(){
	}

Orc::Orc(int x,int y,int character_number):
	PlayerOption(180,30,25,x,y,'o',character_number){} 
