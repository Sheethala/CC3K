#include"vampire.h"
#include"enemiestranslator.h"
#include<iostream>
using namespace std;

Vampire::Vampire(int x,int y,int character_number):Enemies(50,25,25,x,y,'V',character_number,new EnemiesTranslator()){}

Vampire::~Vampire(){}
