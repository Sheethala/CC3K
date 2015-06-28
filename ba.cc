#include<iostream>
#include<string>
#include<queue>
#include"ba.h"

using namespace std;

BA::BA(int item_number): Potion(item_number,5,'1'){
}

bool BA::is_seen(){
	return BA::seen;
}

void BA::hide_ba(){
    BA::seen = false;
}

void BA::show_ba(){
    BA::seen = true;
}

string BA::type_of_item(){
	return "BA potion";
}

void BA::take(GoTo &g){
	g.go_to(this);
}

bool BA::seen = false;

