#include "cell.h"
#include "attack.h"
#include "attackgoto.h"
#include "goto.h"
#include "brain.h"
#include "playertranslator.h"
#include "gotoitem.h"
#include "move.h"
#include <iostream>
#include <string>
#include <utility>
#include <cstdlib>
#include<sstream>
using namespace std;

PlayerTranslator::PlayerTranslator(){
    status = "";
    b = Brain::getBrain();
}

bool PlayerTranslator::possible_m(Move &m){
    Character *p = PlayerOption::get_inst();
    FloorPlanGenerator* thisfloor = (b->get_allfloors())[b->brain_curfloor()];
    int possiblex = m.get_x_coord();
    int possibley = m.get_y_coord();
    Cell* possibility = thisfloor->get_cell(possiblex,possibley);
    if (next_to(p,m) == true){
        if ((possibility->type != 1) && (possibility->type != 0) && (possibility->enemy == false)){
            if (possibility->item == false){
                return true;
            } else {
                if(thisfloor->items[possibility->num]->can_steal){
                    return true;
                }
            }
         }
     } else {
         return false;
     }
}


bool PlayerTranslator::possible_a(Attack &a){
    PlayerOption *p = PlayerOption::get_inst();
    FloorPlanGenerator* thisfloor = (b->get_allfloors())[b->brain_curfloor()];
    int possiblex = a.get_x_coord();
    int possibley = a.get_y_coord();
    Cell* possibility = thisfloor->get_cell(possiblex,possibley);
    if (next_to(p,a)){
        if (possibility->type == 5 && possibility->enemy == true){
            return true;
        }
    } else {
        return false;
    }
}

bool PlayerTranslator::possible_i(UseItem &i){
    PlayerOption *p = PlayerOption::get_inst();
    FloorPlanGenerator* thisfloor = (b->get_allfloors())[b->brain_curfloor()];
    int possiblex = i.get_x_coord();
    int possibley = i.get_y_coord();
    Cell* possibility = thisfloor->get_cell(possiblex,possibley);
    if (next_to(p,i)){
        if (possibility->type == 5 && possibility->item == true){
                cout << thisfloor->get_cell(possiblex,possibley)->po_item() << endl;
                return true;
        }
    } else {
        return false;
    }
}

void PlayerTranslator::move(Move &m){
    int possiblex = m.get_x_coord();
    int possibley = m.get_y_coord();
    PlayerOption *p = PlayerOption::get_inst();
    int thisx = p->get_coord('x');
    int thisy = p->get_coord('y');
    FloorPlanGenerator* thisfloor = (b->get_allfloors())[b->brain_curfloor()];
    Output *out = thisfloor->get_output();
    Cell* possibility = thisfloor->get_cell(possiblex,possibley);
    Cell* thiscell = thisfloor->get_cell(thisx,thisy);
    p->set_coord(possiblex, possibley);
    if (possibility->type == 4){
        if (b->curfl == 4){
            b->endgame(true);
            return;
        }
        thisfloor->modify_character_points();
        b->set_curfloor(1+b->brain_curfloor());
        FloorPlanGenerator* proch = (b->get_allfloors())[b->brain_curfloor()];
        Output *out = proch->get_output();
        out->clearStatus();
        out->setStatus("PC advances to the next floor.\n");
   }
   if (possibility->gold_item()){
       Item *i = thisfloor->items[possibility->num];
       int before = p->get_hoard();
       GoToItem g = GoToItem();
       i->take(g);
       int amount = p->get_hoard() - before;
	ostringstream n;
	n << amount;
       status +=  " and picks up ";
	status += n.str(); 
	status += " gold";
       thisfloor->delete_item(possibility->num);
   }
   Cell* next = NULL;
   int k = 0;
   for (int w=-1; w<=1; w++){
       for (int q=-1; q<=1; q++){
           next = thisfloor->get_cell(possiblex+w, possibley+q);
           if (next->po_item()){
                Item *i = thisfloor->items[next->num];
                if (i->is_seen()){
                    status = status + " and sees a " + i->type_of_item();
                } else {
                    k++;
                }
            }
        }
   }
   if (k >= 1){
        status = status + " and sees ";
        if (k > 1){
		ostringstream p;
		p << k;
            status = status + p.str() + " unknown potions";
        } else {
            status = status + "an unknown potion";
        }
   }
    possibility->change_info(p->character_number, false, false, true);
    possibility->rep = ('@');
    thiscell->change_info(false,false,false);
    thiscell->rep = (thiscell->convert_typ(thiscell->type));
    thiscell->update_output(*out);
    possibility->update_output(*out);
    status = status + "\n";
    tell_output(*out, status);
    status = "";
}

void PlayerTranslator::attack(Attack &a){
    int possiblex = a.get_x_coord();
    int possibley = a.get_y_coord();
    PlayerOption *p = PlayerOption::get_inst();
    FloorPlanGenerator* thisfloor = (b->get_allfloors())[b->brain_curfloor()];
    Cell* possibility = thisfloor->get_cell(possiblex,possibley);
    Enemies *e = thisfloor->get_enemy(possibility->num);
    Output *out = thisfloor->get_output();
	AttackGoTo at = AttackGoTo(p);
    int res = e->take(at);
    int before = e->new_health_points;
    if (before <= 0){
        before = 0;
    }
    ostringstream ss;
    ss<< before;
    if (before != 0){
    	status = status + " deals damage to " + e->type + " (" + ss.str() + " HP)";
    }
    if (before == 0){
        if (e->type != 'M'){
            possibility->change_info(false,false,false);
            possibility->rep = ('.');
            p->hoard++;
        } else {
            thisfloor->spawn_item(possiblex,possibley,'8');
        }
        cout << "Enemy killed!" << endl;
        thisfloor->delete_enemy(possibility->num);
    }
    possibility->update_output(*out);
    status = status + "\n";
    tell_output(*out, status);
    status = "";
}

void PlayerTranslator::use(UseItem &i){
    cout << "in use" << endl;
    int possiblex = i.get_x_coord();
    int possibley = i.get_y_coord();
    FloorPlanGenerator* thisfloor =(b->get_allfloors())[b->brain_curfloor()];
    Cell* possibility = thisfloor->get_cell(possiblex,possibley);
    Item *it = thisfloor->items[possibility->num];
    GoTo *g = thisfloor->i;
    Output *out = thisfloor->get_output();
    it->take(*g);
    status = status + " uses " + it->type_of_item();
    possibility->change_info(false,false,false);
    possibility->rep = ('.');
    thisfloor->delete_item(possibility->num);
    possibility->update_output(*out);
    status = status + "\n";
    tell_output(*out, status);
    status = "";
}

void PlayerTranslator::tell_output(Output &o, std::string s){
    o.setStatus(status);
}

string PlayerTranslator::get_status(string s){
    if (s == "no"){
        return "North";
    } else if (s == "so"){
        return "South";
    } else if (s == "ea"){
        return "East";
    } else if (s == "we"){
        return "West";
    } else if (s == "se"){
        return "South East";
    } else if (s == "ne"){
        return "North East";
    } else if (s == "sw"){
        return "South West";
    } else {
        return "North West";
    }
}

void PlayerTranslator::translate(PlayerOption* p){
    int x = p->get_coord('x');
    int y = p->get_coord('y');
    string s;
    cin >> s;
    status = "PC";
    int xdiff;
    int ydiff;
    int xchange;
    int ychange;
    if (s == "no" || s == "so" || s == "we" || s == "ea" || s == "se" || s == "ne" || s == "nw" || s == "sw" ){
        std::pair<int, int> place = get_placement(s);
        xdiff = place.first;
        ydiff = place.second;
        xchange = xdiff + x;
        ychange = ydiff + y;
        Move mov = Move(p,xchange,ychange);
        if (possible_m(mov)){
            status = status + " moves " + get_status(s);
            move(mov);
        } else {
            translate(p);
        }
    } else if (s == "a"){
        cin >> s;
        if (s == "no" || s == "so" || s == "we" || s == "ea" || s == "se" || s == "ne" || s == "nw" || s == "sw" ){
            std::pair<int, int> place = get_placement(s);
            xdiff = place.first;
            ydiff = place.second;
            xchange = xdiff + x;
            ychange = ydiff + y;
            Attack at = Attack(p,xchange,ychange);
            if (possible_a(at)){
                attack(at);
            } else {
                translate(p);
            }
        } else {
            translate(p);
        }
   } else if (s == "u"){
       cin >> s;
       if (s == "no" || s == "so" || s == "we" || s == "ea" || s == "se" || s == "ne" || s == "nw" || s == "sw" ){
           std::pair<int, int> place = get_placement(s);
           xdiff = place.first;
           ydiff = place.second;
           xchange = xdiff + x;
           ychange = ydiff + y;
           UseItem us = UseItem(p,xchange,ychange);
           if (possible_i(us)){
               cout << "ugh" << endl;
               use(us);
           } else {
               translate(p);
           }
        } else {
           translate(p);
        }
    } else if (s == "r"){
        b->restart();
        b->output_allfloors();
        b->user_command();
        return;
    } else if (s == "q"){
        b->endgame(true);
        return;
    } else {
        translate(p);
    }
}

PlayerTranslator::~PlayerTranslator(){}




std::pair<int, int> PlayerTranslator::get_placement(string s){
   int x;
   int y;
   if (s == "no"){
       x = -1;
       y = 0;
   } else if (s == "so"){
       x = 1;
       y = 0;
   } else if (s == "we"){
       x = 0;
       y = -1;
   } else if (s == "ea"){
       x = 0;
       y = 1;
   } else if (s == "se"){
       x = 1;
       y = 1;
   } else if (s == "ne"){
       x = -1;
       y = 1;
   } else if (s == "sw"){
       x = 1;
       y = -1;
   } else if (s == "nw"){
       x = -1;
       y = -1;
   }
   std::pair<int, int> placement(x,y);
   return placement;
}


