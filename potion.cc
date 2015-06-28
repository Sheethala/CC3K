#include<iostream>
#include<string>
#include"potion.h"
#include"goto.h"
#include<queue>

using namespace std;

void Potion::take(GoTo &g){
	g.go_to(this);
}

bool Potion::is_seen(){
	return false;
}

Potion::Potion(int item_number,int size,char c):Item(item_number,c,false,true){
	//This is a constructor for the potion.
	this->size = size;
}

int Potion::get_size(){
	return size;
}


