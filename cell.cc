#include "cell.h"
#include "output.h"
#include "readfile.h"
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
using namespace std;

//Cell::Cell(): type(0), p(false), x(0), y(0), item(false), hero(false), enemy(false), rep(' '), num(0), per(' ') { }

Cell::Cell(int x, int y, bool c, bool d, bool k, char f, int l, int e): type(l), x(x), y(y), enemy(c), item(d), hero(k), rep(f), num(e) { }

Cell::Cell(int x, int y, char f, int d): type(d), x(x), y(y), enemy(false), item(false), hero(false), rep(f), num(-1) { }

void Cell::update_output(Output &o){
    o.notifyBoard(x, y, convert_rep(rep));
}

char Cell::convert_rep(char r){
    if (r == '0' || r == '1' || r == '2' || r == '3' || r == '4' || r == '5'){
        return 'P';
    } else if (r == '6' || r == '7' || r == '8' || r == '9'){
        return 'G';
    } else {
        return r;
    }
}

char Cell::convert_typ(int t){
    if (t == 0 || t == 1){
        return ' ';
    } else if (t == 2){
        return '+';
    } else if (t == 3){
        return '#';
    } else {
        return '.';
    }
}

bool Cell::taken(){
    if ((hero == true) || (enemy == true) || (item == true)){
        return true;
    } else {
        return false;
    }
}




bool Cell::gold_item(){
    if (rep == '6' || rep == '7' || rep == '8' || rep == '9'){
        if (item == true){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

bool Cell::po_item(){
    if (rep == '0' || rep == '1' || rep == '2' || rep == '3' || rep == '4' || rep == '5'){
        if (item == true){
            return true;
        } else {
            return false;
        }
    } else {
        return false;
    }
}

void Cell::change_info(int n, bool a, bool b, bool c){
    num = n;
    p = c;
    hero = c;
    enemy = a;
    item = b;
}

void Cell::set_x(int a){
    x = a;
}

void Cell::set_y(int a){
    y = a;
}
