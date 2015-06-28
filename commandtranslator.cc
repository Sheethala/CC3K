#include "effect.h"
#include "commandtranslator.h"
#include "character.h"
#include <string>
#include <iostream>
#include <cmath>
using namespace std;

CommandTranslator::CommandTranslator(): status("") {}

CommandTranslator::~CommandTranslator(){}

bool CommandTranslator::next_to(Character *person, UserEffects &e){
    int thisx = person->get_coord('x');
    int thisy = person->get_coord('y');
    int thatx = e.get_x_coord();
    int thaty = e.get_y_coord();
    if ((abs(thisx - thatx)<=1) && (abs(thisy-thaty)<=1)){
        return true;
    } else {
        return false;
    }
}

void CommandTranslator::translate(Character *person) {}
