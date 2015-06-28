#include "enemiestranslator.h"
#include"werewolf.h"
#include<iostream>
using namespace std;

Werewolf::~Werewolf(){}

Werewolf::Werewolf(int x,int y,int character_number):Enemies(120,30,5,x,y,'W',character_number,new EnemiesTranslator()){}
