#ifndef __FLOORPLANGENERATOR_H__
#define __FLOORPLANGENERATOR_H__
#include "cell.h"
#include "enemies.h"
#include "item.h"
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <cstdlib>

class GoToItem;
class Output;
class ChamberCells;
class PlayerOption;
class Hoard;

class FloorPlanGenerator{
    public:
    //To help track movement among the floors
    	FloorPlanGenerator();
   	 ~FloorPlanGenerator(); 
	int initial_xcoord;
	int initial_ycoord;
    	std::vector<std::vector<Cell*> > chamber_cells_fpg; 
	std::vector<ChamberCells*> chambers; //An array of vectors that point to each chamber;
    	std::map<int, Item*> items; 
	Output *ot;
	GoToItem *i;
    	Cell* spawn_cell(int x, int y, char c); 
    	Cell* get_cell(int x, int y);
    	void set_all_cells(std::vector<std::vector<char > > v); 
    	void spawn_player(Cell* c); 
    	void spawn_hoard(Cell *c); 
    	void spawn_enemy(Cell* c);
    	Enemies* get_enemy(int n);
    	void delete_enemy(int character_number); 
	void spawn_floor(); 
    	void make_playerandstairs();
    	std::map<int, Enemies*> level_enemies; 
    	std::queue<Enemies*> enemy_lineup;
    	void spawn_potion(Cell* c); 
    	void spawn_stairs(Cell* c); 
    	void delete_item(int character_number); 
    	void spawn_item(int x, int y, char c); 
    	Output * get_output(); 
    	void modify_character_points(); 
    	void make_hoards(); 
   	 void make_enemies(); 
    	void change_info(); 
    	void make_potions();
    	void starting_enemy_lineup(); 
    	void set_all_chambers(std::vector<std::vector<char> > c); 
    	void spawn_chamber(std::vector<std::vector<char> > v);
    	void place_all_items(int ix, int iy, char c, std::vector<std::vector<char> > &f); 
    	void output(); 
};
#endif
