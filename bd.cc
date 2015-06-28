#include"bd.h"
#include<iostream>
#include<string>
#include<queue>

#include"goto.h"

using namespace std;

BD::BD(int item_number):Potion(item_number,5,'2'){}

void BD::show_bd(){
    BD::seen = true;
}

bool BD::is_seen(){
	return BD::seen;
}

void BD::hide_bd(){
    BD::seen = false;
}


string BD::type_of_item(){
	return "BD potion";
}

void BD::take(GoTo &g){
	g.go_to(this);
}

bool BD::seen = false;
