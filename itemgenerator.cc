#include "itemgenerator.h"
#include<iostream>
#include "rh.h"
#include "bd.h"
#include "ph.h"
#include "wa.h"
#include "ba.h"
#include "wd.h"
#include "smallhoard.h"
#include "normalhoard.h"
#include "dragonhoard.h"
#include<cstdlib>
#include<string>

using namespace std;

ItemGenerator::ItemGenerator(){
	}

Item* ItemGenerator::get_item(char c){
	Item *newit;
	if(c == '2'){
		newit = new BD(Item::create_number());
	}
	if(c == '3'){
		newit = new PH(Item::create_number());
	}
	if(c == '4'){
		newit = new WA(Item::create_number());
	}
    if (c == '1'){
        newit = new BA(Item::create_number());
    }
	if(c == '0'){
		newit = new RH(Item::create_number());
	}	
	if(c == '7'){
		newit = new SmallHoard(Item::create_number());
	}

	if(c == '8'){
		newit = new Hoard(Item::create_number(),4,'8');
	}
	
	if(c == '5'){
		newit = new WD(Item::create_number());
	}
	
	if(c == '6'){
		newit = new NormalHoard(Item::create_number());
	}
	
	else{
		newit = new DragonHoard(Item::create_number());
	}
	
	return newit;
}


Item* ItemGenerator::get_potion(){
	Item *newit;
	int n = (rand() % 6) + 1;

	if(n == 1) newit = new RH(Item::create_number());
	if(n == 2) newit = new PH(Item::create_number());
	if(n == 3) newit = new BA(Item::create_number());
	if(n == 4) newit = new BD(Item::create_number());
	if(n == 5) newit = new WA(Item::create_number());
	if(n == 6) newit = new WD(Item::create_number());
	return newit;
}
	
	
Item* ItemGenerator::get_hoard(){
    Item *newit;
    int n = 1+(rand()%8);
    if (n == 1){
        newit = new DragonHoard(Item::create_number());
    } else if ( n > 3 && n < 7){
        newit = new NormalHoard(Item::create_number());
    } else {
        newit = new SmallHoard(Item::create_number());
    } 
    return newit;
}
