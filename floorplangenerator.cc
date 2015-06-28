#include "floorplangenerator.h"
#include "hoard.h"
#include "readfile.h"
#include "cell.h"
#include "chambercells.h"
#include "itemgenerator.h"
#include "enemycreator.h"
#include "dragonhoard.h"
#include "dragon.h"
#include "gotoitem.h"
#include "playeroption.h"
#include "brain.h"
#include <vector>
#include <iostream>
#include <map>
#include <string>
#include <queue>
#include <cstdlib>
using namespace std;

//at it's latest update

FloorPlanGenerator::FloorPlanGenerator(){
    initial_xcoord = 3;
    initial_ycoord = 3;
    i = new GoToItem;
    ot = new Output(79, 25);
}

Cell* FloorPlanGenerator::spawn_cell(int x, int y, char c){
    ReadFile r = ReadFile();
    Cell *checked;
    int ct = 0;
    ct = r.convert_to_celltype(c);
    if (ct == 5){
        int num = -1;
        bool en = false;
        bool it = false;
        bool pl = false;
	if (c == '0' || c == '1' || c == '2' || c == '4' || c == '5'|| c == '6' || c == '7' || c == '8'){
            ItemGenerator gen = ItemGenerator();
            Item *thing = gen.get_item(c);
            thing->xcoord = x;
	    thing->ycoord = y;
	    num = thing->item_number;
	    items[num] = thing;
	    it = true;
	} else if (c == '@'){
		PlayerOption *p = PlayerOption::get_inst();
		p->set_coord(x, y);
		initial_xcoord = x;
		initial_ycoord = y;
		pl = true;
	} else if (c == 'X' || c == 'W' || c == 'V' || c == 'N' || c == 'T' || c == 'M'){
		EnemyCreator gen = EnemyCreator();
		Enemies *e = gen.new_enemy(c);
		e->set_coord(x, y);
		num = e->character_number;
		level_enemies[num] = e;
		enemy_lineup.push(e);
		en = true;
	}
	checked = new Cell(x, y, en, it, pl, c, ct, num);
    } else {
	    checked = new Cell(x, y, c, ct);
    }
    return checked;
}

void FloorPlanGenerator::set_all_cells(vector<vector<char> > v){
	//In this function we set all the cells and initializes them to their basic values
	char cur;
	chamber_cells_fpg.resize(25);
	for (int i = 0; i < 25; i++){
		vector<Cell *> each_row;
		each_row.resize(79);
		for(int j = 0; j < 79; j++){
			cur = v.at(i).at(j);
			Cell *created = spawn_cell(i, j, cur);
			created->update_output(*ot);
			each_row[j] = created;
		}
		chamber_cells_fpg[i] = each_row;
	}
}

void FloorPlanGenerator::spawn_floor(){
	//IN THIS FUNCTION WE CREATE ALL THE ITEMS AND THE ENEMIES.
	make_playerandstairs();
	make_potions();
	make_hoards();
	make_enemies();
	starting_enemy_lineup();
}

void FloorPlanGenerator::make_playerandstairs(){
	//IN THIS FUNCTION WE RANDOMLY CREATE 	PLAYERS AND STAIRS AS MENTIONED IN THE SPECIFICATIONS.
	int x;
	int character;
	Cell *thiscell;
	ChamberCells *thischamber;
	x = (rand()%5);
	character = x;
	thischamber = chambers.at(x);
	thischamber->chamber_cells.size();
	x = (rand()%(thischamber->chamber_cells.size()));
	thiscell = thischamber->chamber_cells.at(x);
	spawn_player(thiscell);
	x = (rand()%5);
	thischamber = chambers.at(x);
	while (x == character){
		x = (rand()%5);
		thischamber = chambers.at(x);
	}
	x = (rand()%(thischamber->chamber_cells.size()));
	thiscell = thischamber->chamber_cells.at(x);
	spawn_stairs(thiscell);
}

Output *FloorPlanGenerator::get_output(){
	return ot;
}

void FloorPlanGenerator::make_hoards(){
	//IN THIS FUNCTION WE MAKE THE GOLD AND SPAWN THEM
	int x = (rand()%5) + 1;
	ChamberCells *thischamber;
	Cell *thiscell;
	for(int i = 0; i < 10; i++){
		x = (rand()%5);
		thischamber = chambers.at(x);
		x = (rand()%(thischamber->chamber_cells.size()));
		thiscell = thischamber->chamber_cells.at(x);
		while((thiscell->taken() == true) || (thiscell->type == 4)){
			x = (rand()%(thischamber->chamber_cells.size()));
			thiscell = thischamber->chamber_cells.at(x);
		}
		spawn_hoard(thiscell);
	}
}

void FloorPlanGenerator::change_info(){
	//WE CALL THIS IF WE WANT TO CHANGE INFORMATION ABOUT THE PLAYER OR ONE OF THE ENEMY.
	for(unsigned int i = 0; i < chamber_cells_fpg.size(); i++){
		for(unsigned int j = 0; j < chamber_cells_fpg.at(i).size(); j++){
			Cell *thiscell = chamber_cells_fpg.at(i).at(j);
			if (thiscell->enemy == true){
				int char_num = thiscell->num;
				Enemies* proch = level_enemies[char_num];
				enemy_lineup.push(proch);
			}
		}
	}
	while (enemy_lineup.size() != 0){
		Enemies *thisenemy = enemy_lineup.front();
		thisenemy->change_info();
		enemy_lineup.pop();
	}
}

void FloorPlanGenerator::starting_enemy_lineup(){
	Cell *thiscell;
	for (int i = 0; i < chamber_cells_fpg.size(); i++){
		for (int j = 0; j < chamber_cells_fpg.at(i).size(); j++){
			thiscell = chamber_cells_fpg.at(i).at(j);
			if (thiscell->enemy == true){
				enemy_lineup.push(level_enemies[thiscell->num]);
			}
		}
	}
}

void FloorPlanGenerator::set_all_chambers(vector<vector<char> > c){
	vector<vector<char> > version = c;

	char thisc;
	vector<vector<char> > all_c = c;
	for (int i = 0; i <version.size(); i++){
		for (int j= 0; j <version.at(i).size(); j++){
			thisc = version[i][j];
			if (thisc == '.'){
				place_all_items(j,i,'!',all_c);
				spawn_chamber(all_c);
				place_all_items(j,i,'!',version);
				place_all_items(j,i,'.',all_c);
			}
		}
	}
}

void FloorPlanGenerator::spawn_chamber(vector<vector<char> > v){
	vector<Cell *> c;
	char ch;

	for(unsigned int i = 0; i < v.size(); i++){
		for(unsigned int j = 0; j < v[i].size(); j++){
			ch = v.at(i).at(j);
			if (ch == '!'){
				c.push_back(chamber_cells_fpg[i][j]);
			}
		}
	}
	ChamberCells *n = new ChamberCells(c);
	chambers.push_back(n);
}

void FloorPlanGenerator::place_all_items(int ix, int iy, char c, vector<vector<char> > &f){
	char ch = f.at(iy).at(ix);
	if ( ch == c || ch == '-' || ch == '|' || ch == '+' || ch == '#'){
		return;
	}
	f.at(iy).at(ix) = c;
	place_all_items(ix-1,iy,c,f);
	place_all_items(ix+1,iy,c,f);
	place_all_items(ix,iy-1,c,f);
	place_all_items(ix,iy+1,c,f);
}

void FloorPlanGenerator::output(){
	cout << *ot;
	ot->clearStatus();
}

void FloorPlanGenerator::make_potions(){
	int gen = (rand()%5);
	ChamberCells *thischamber;
	Cell* thiscell;
	for (int i = 0; i < 10; i++){
		gen = (rand()%5);
		thischamber = chambers.at(gen);
		gen = (rand()%(thischamber->chamber_cells.size()));
		thiscell = thischamber->chamber_cells.at(gen);
		while (thiscell->taken() == true || thiscell->type == 4){
			gen = (rand()%(thischamber->chamber_cells.size()));
			thiscell = thischamber->chamber_cells.at(gen);
		}
		spawn_potion(thiscell);
	}
}

void FloorPlanGenerator::modify_character_points(){
	PlayerOption *thehero = PlayerOption::get_inst();
	thehero->change_attack(-(i->get_change_attack()));
	thehero->change_defense(-(i->get_change_defense()));
}

void FloorPlanGenerator::make_enemies(){
	int x = (rand()%5);
	Cell *thiscell;
	ChamberCells *thischamber;
	for(int i = 0; i < 20; i++){
		x = (rand()%5);
		thischamber = chambers.at(x);
		x = (rand() % (thischamber->chamber_cells.size()));
		thiscell = thischamber->chamber_cells.at(x);
		while (thiscell->type == 4 || thiscell->taken() == true){
			x = (rand() % (thischamber->chamber_cells.size()));
			thiscell = thischamber->chamber_cells.at(x);
		}
		spawn_enemy(thiscell);
	}
}



FloorPlanGenerator::~FloorPlanGenerator(){
	for(int p = 0;p<chamber_cells_fpg.size();++p){
		while(chamber_cells_fpg[p].size() != 0){
			delete chamber_cells_fpg[p].back();
			chamber_cells_fpg[p].pop_back();
		}
	}
	delete ot;
	delete i;
	while(!chambers.empty()){
		delete chambers.back();
		chambers.pop_back();
	}
	for(map<int,Item*>::iterator j = items.begin();j != items.end();++j){
		delete j->second;
		items.erase(j);
	}

	for(map<int, Enemies*>::iterator k = level_enemies.begin();k != level_enemies.end();++k){
		delete k->second;
		level_enemies.erase(k);
	}
}



Cell* FloorPlanGenerator::get_cell(int x,int y){
	return chamber_cells_fpg.at(x).at(y);
}

void FloorPlanGenerator::spawn_player(Cell *c){
	PlayerOption *p = PlayerOption::get_inst();
	if(!(c->taken())){
		c->change_info(p->character_number,false,false,true);
		c->rep = ('@');
		c->update_output(*ot);
		p->set_coord(c->x,c->y);
		initial_xcoord = c->x;
		initial_ycoord = c->y;
	}
}

void FloorPlanGenerator::spawn_hoard(Cell *c){
	if(!c->taken()){
		ItemGenerator it = ItemGenerator();
		Item *newit = it.get_hoard();
		newit->xcoord = c->x;
                newit->ycoord = c->y;
                c->change_info(newit->item_number, false,true,false);
                c->rep = (newit->item);
                c->update_output(*ot);
                items[newit->item_number] = newit;
        }
}


void FloorPlanGenerator::spawn_enemy(Cell *c){
        if(!c->taken()){
                EnemyCreator egen = EnemyCreator();
                Enemies *newen = egen.new_enemy();
                int character_number = newen->character_number;
                newen->set_coord(c->x,c->y);
                c->change_info(character_number,true,false,false);
                c->rep = (newen->type);
                c->update_output(*ot);
                level_enemies[character_number] = newen;
        }
}

Enemies* FloorPlanGenerator::get_enemy(int n){
    return level_enemies.at(n);
}

void FloorPlanGenerator::delete_enemy(int character_number){        
        delete level_enemies[character_number];
        level_enemies.erase(character_number);
}

void FloorPlanGenerator::spawn_potion(Cell *c){
        if(!c->taken()){
                ItemGenerator ig = ItemGenerator();
                Item *newit = ig.get_potion();
                int number = newit->item_number;
                newit->xcoord = c->x;
		        newit->ycoord = c->y;
                c->change_info(number,false,true,false);
                c->rep = (newit->item);
                c->update_output(*ot);
                items[number] = newit;
        }
}

void FloorPlanGenerator::spawn_stairs(Cell *c){
        if(!c->taken()){
                c->change_info(false,false,false);
                c->type = 4;
                c->rep = ('/');
                c->update_output(*ot);
        }
}

void FloorPlanGenerator::delete_item(int item_number){
        delete items[item_number];
        items.erase(item_number);
}

void FloorPlanGenerator::spawn_item(int x,int y,char c){
        ItemGenerator itg = ItemGenerator();
        Item *it = itg.get_item(c);
        Cell *ce = chamber_cells_fpg.at(x).at(y);
        ce->change_info(it->item_number,false,true,false);
        ce->rep = (c);
        it->xcoord = x;
        it->ycoord = y;
        items[it->item_number] = it;
        ce->update_output(*ot);
}


