#include "output.h"
#include "playeroption.h"
#include "brain.h"
#include <vector>
#include <iostream>
#include <sstream>
#include <string>
#include <cstring>
#include <cstdlib>
using namespace std;

void Output::setStatus(string s){
    status = status + s;
}

Output::Output(int x, int y){
    for (int i = 0; i < 25; i++){
        vector<char> v;
        for (int j = 0; j < 79; j++){
            v.push_back(' ');
        }
        board.push_back(v);
    }
    status = "Player character has spawned.\n";
}

void Output::notifyBoard(int x, int y, char c){
    board[x][y] = c;
}

void Output::clearStatus(){
    status = "";
}

ostream &operator<<(ostream &out, const Output &o){
    for (int i = 0; i < o.board.size(); i++){
        for (int j = 0; j < o.board[i].size(); j++){
            char c = o.board[i][j];
            out << c;
        }
        out << endl;
    }
    PlayerOption *p = PlayerOption::get_inst();
    Brain *b = Brain::getBrain();
    string ptype = PlayerOption::char_to_option(p->option);
    int hp = p->new_health_points;
    int gold = p->get_hoard();
    int atk = p->new_attack;
    int def = p->new_defense;
    int fl = 1+b->brain_curfloor();
    out << "Race: " << ptype;
    out << " Gold: " << gold;
    out << "                                                 Floor: " << fl;
    out << endl;
    out << "HP: " << hp << endl;
    out << "Atk: " << atk << endl;
    out << "Def: " << def << endl;
    out << "Action: " << o.status;
    return out;
}



