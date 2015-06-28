#include"wd.h"
#include"potion.h"
#include"item.h"
#include"goto.h"
#include<iostream>
#include<string>
using namespace std;

WD::WD(int item_number): Potion(item_number,-5,'5'){
	}

void WD::show_wd(){
    WD::seen = true;
}

void WD::hide_wd(){
    WD::seen = false;
}

bool WD::is_seen(){
	return WD::seen;
}

string WD::type_of_item(){
	return "WD Potion";
}

void WD::take(GoTo &g){
	g.go_to(this);
}

bool WD::seen = false;

