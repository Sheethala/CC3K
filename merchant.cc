#include"enemiestranslator.h"
#include"goto.h"
#include"enemies.h"
#include"merchant.h"
#include<iostream>
#include<queue>
using namespace std;

Merchant::~Merchant(){
}

Merchant::Merchant(int x,int y,int character_number):
	Enemies(30,70,5,x,y,'M',character_number,new EnemiesTranslator(),false,true){
}

int Merchant::take(GoTo &g){
	return g.go_to(this);
}

void Merchant::pissed_merchants(bool pissed){
    Merchant::enemy = pissed;
}

bool Merchant::is_enemy(){
    return Merchant::enemy;
}

bool Merchant::enemy = false;

