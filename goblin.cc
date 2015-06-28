#include"goblin.h"
#include"enemies.h"
#include"character.h"
#include<iostream>
#include<string.h>
#include"enemiestranslator.h"
using namespace std;

Goblin::~Goblin(){}

Goblin::Goblin(int x,int y,int character_number):Enemies(70,5,10,x,y,'N',character_number,new EnemiesTranslator()){}

