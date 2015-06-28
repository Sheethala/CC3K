#include"enemiestranslator.h"
#include"phoenix.h"
#include<iostream>
using namespace std;

Phoenix::Phoenix(int x,int y,int character_number):
	Enemies(50,35,20,x,y,'X',character_number,new EnemiesTranslator()){
}

Phoenix::~Phoenix(){
}

