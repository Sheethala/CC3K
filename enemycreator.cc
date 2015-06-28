#include "enemycreator.h"
#include "phoenix.h"
#include"dragon.h"
#include"merchant.h"
#include"goblin.h"
#include"troll.h"
#include"werewolf.h"
#include"vampire.h"
#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;

EnemyCreator::EnemyCreator(){}

Enemies *EnemyCreator::new_enemy(char c){
	Enemies *create_enemy;
	if(c == 'X'){
		create_enemy = new Phoenix(0,0,Character::generate_character_number());
    }
	//else if(c == 'D'){
	//	create_enemy = new Dragon(0,0,Character::generate_character_number());
//    }
	else if(c == 'M'){
		create_enemy = new Merchant(0,0,Character::generate_character_number());
	}
	else if(c == 'N'){
		create_enemy = new Goblin(0,0,Character::generate_character_number());
	}
	else if(c == 'T'){
		create_enemy = new Troll(0,0,Character::generate_character_number());
	}
	else if(c == 'W'){
		create_enemy = new Werewolf(0,0,Character::generate_character_number());
    }
	else{
		create_enemy = new Vampire(0,0,Character::generate_character_number());
	}
	return create_enemy;
}

Enemies *EnemyCreator::new_enemy(){
	int n;
	n = (rand() % 18) + 1; //Generates numbers;
	Enemies *create_enemy;
	if(n >= 17 && n <=18){
		create_enemy = new Merchant(0,0,Character::generate_character_number());
		}

	else if(n >= 15 && n <= 16){
		create_enemy = new Troll(0,0,Character::generate_character_number());
		}
	else if(n >= 13 && n <= 14){
		create_enemy = new Phoenix(0,0,Character::generate_character_number());
		}
	else if(n >= 8 && n <=12){
		create_enemy = new Goblin(0,0,Character::generate_character_number());
		}
	else if(n >= 5 && n <= 7){
		create_enemy = new Vampire(0,0,Character::generate_character_number());
		}
	else{
		create_enemy =new Werewolf(0,0,Character::generate_character_number());
		}
		
		
	return create_enemy;
}
