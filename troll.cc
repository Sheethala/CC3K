#include "troll.h"
#include<iostream>
#include"enemiestranslator.h"
using namespace std;

Troll::~Troll(){}
Troll::Troll(int x,int y,int character_number):Enemies(120,25,15,x,y,'T',character_number,new EnemiesTranslator()){}



