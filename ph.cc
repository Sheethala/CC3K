#include"ph.h"
#include"potion.h"
#include<iostream>
#include<string>
#include<queue>
#include"goto.h"
using namespace std;

PH::PH(int item_number):Potion(item_number,-10,'3'){}

bool PH::is_seen(){
	return PH::seen;
}

void PH::show_ph(){
    PH::seen = true;
}

void PH::hide_ph(){
    PH::seen = false;
}

void PH::take(GoTo &g){
	g.go_to(this);
}

string PH::type_of_item(){
	return "PH potion";
}

bool PH::seen = false;

