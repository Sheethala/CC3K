#include "brain.h"
#include "readfile.h"
#include "floorplangenerator.h"
#include "cell.h"
//#include "human.h"
//#include "dwarf.h"
//#include "elf.h"
//#include "orc.h"
#include "playeroption.h"
#include "merchant.h"
#include "ba.h"
#include "bd.h"
#include "ph.h"
#include "wa.h"
#include "wd.h"
#include "rh.h"
#include <iostream>
#include <string>
#include <vector>
using namespace std;

Brain::Brain(): pl(0), fname(""), done(false), fl(0), file(false), won(false), curfl(0) {
this->fl = new FloorPlanGenerator*[5];
}

Brain* Brain::b = NULL;

void Brain::delBrain(){
    delete b;
    b = NULL;
}

Brain::~Brain(){
    for (int q = 0; q < 5; q++){
	delete fl[q];
    }
    delete fl;
}

Brain* Brain::getBrain(){
    if (!b){
        b = new Brain();
        atexit(delBrain);
    }
    return b;
}

void Brain::set_board(string str){
    fname = str;
    file = true;
}

void Brain::set_allfloors(vector<vector<vector<char > > > fls){
    for (int x = 0; x < 5; x++){
        FloorPlanGenerator *f = new FloorPlanGenerator;
        f->set_all_cells(fls.at(x));
        f->set_all_chambers(fls.at(x));
        fl[x] = f;
    }
}

void Brain::set_all(){
    ReadFile r = ReadFile();
    if (file == false){
        fname = "t1.txt";
    }
    r.filename = fname;
    vector<vector<vector<char > > > a = r.read_layouts(fname);
    if (file == true){
        set_allfloors(a);
	    //make_fls();
    } else {
        set_allfloors(a);
        make_fls();
    }
    pl->set_coord(fl[0]->initial_xcoord, fl[0]->initial_ycoord);
}

void Brain::output_allfloors(){
    fl[curfl]->output();
}

PlayerOption* Brain::get_player(){
    return pl;
}

int Brain::brain_curfloor(){
    return curfl;
}

void Brain::choose_playertype(char type){
    if (type == 'h'){
        Human *h = new Human(0, 0, Character::generate_character_number());
        set_player(h);
    } else if (type == 'o'){
        Orc *o = new Orc(0, 0, Character::generate_character_number());
        set_player(o);
    } else if (type == 'e'){
        Elf *e = new Elf(0, 0, Character::generate_character_number());
        set_player(e);
    } else if (type == 'd'){
        Dwarf *d = new Dwarf(0, 0, Character::generate_character_number());
        set_player(d);
    } else {
        cout << "Invalid player choice." << endl;
    }
}

void Brain::set_curfloor(int f){
    pl->set_coord(fl[f]->initial_xcoord, fl[f]->initial_ycoord);
    curfl = f;
}

void Brain::user_command(){
    pl->change_info();
}

void Brain::set_player(PlayerOption* p){
    pl = p;
}

void Brain::update(){
    fl[curfl]->change_info();
}

FloorPlanGenerator**  Brain::get_allfloors(){
    return fl;
}

void Brain::restart(){
    done = false;
    file = false;
    won = false;
    curfl = 0;
    PH::hide_ph();
    WA::hide_wa();
    BA::hide_ba();
    BD::hide_bd();
    WD::hide_wd();
    RH::hide_rh();
    Merchant::pissed_merchants(false);
    for (int q = 0; q < 5; q ++){
	delete fl[q];
    }
    delete fl;
    set_all();
}

bool Brain::brain_done(){
    return done;
}

void Brain::given_file(string s){
    file = true;
    fname = s;
}

void Brain::endgame(bool result){
    won = result;
    done = true;
}

void Brain::make_fls(){
    FloorPlanGenerator *cur;
    for (int q = 0; q < 5; q++){
        cur = fl[q];
        cur->spawn_floor();
    }
}
