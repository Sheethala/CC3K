#include"goto.h"
#include<iostream>
#include"character.h"
#include "enemies.h"
#include"hoard.h"
#include"wd.h"
#include"wa.h"
#include"rh.h"
#include"ph.h"
#include"bd.h"
#include"ba.h"
#include"merchant.h"
#include<string>
#include<queue>
using namespace std;

GoTo::~GoTo(){}

GoTo::GoTo(){}

int GoTo::go_to(Dragon *d){
	return 0;
}

void GoTo::go_to(WD *p){
}

void GoTo::go_to(WA *p){
}

int GoTo::go_to(Enemies *e){
	return 0; //this is a visitor pattern.
}

void GoTo::go_to(PH *p){
}

int GoTo::go_to(Merchant *m){
	return 0;
}

void GoTo::go_to(RH *p){
}

int GoTo::go_to(Character *c){
	return 0;
}

void GoTo::go_to(BA *p){
}         

void GoTo::go_to(Potion *p){}

void GoTo::go_to(Hoard *h){}

void GoTo::go_to(BD *p){
}
