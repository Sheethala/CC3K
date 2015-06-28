#include"rh.h"
#include<iostream>
#include<string>
#include<queue>
#include"potion.h"
#include"item.h"

using namespace std;

RH::RH(int item_number): Potion(item_number,10,'0'){}

bool RH::is_seen(){
	return seen;
}

void RH::show_rh(){
	seen = true;
}

void RH::hide_rh(){
	seen = false;
}


string RH::type_of_item(){
	return "RH Potion";
}

void RH::take(GoTo &g){
	g.go_to(this);
}

bool RH::seen = false;

