#include "wa.h"
#include"potion.h"
#include"goto.h"
#include<iostream>
#include<string>
using namespace std;

WA::WA(int item_number): Potion(item_number,-5,'4'){}

bool WA::is_seen(){
	return seen;
}

void WA::show_wa(){
	seen = true;
}

void WA::hide_wa(){
	seen = false;
}
 
string WA::type_of_item(){
	return "WA Potion";
}

void WA::take(GoTo &g){
	g.go_to(this);
}

bool WA::seen = false;

