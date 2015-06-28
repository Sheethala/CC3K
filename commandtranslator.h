#ifndef __COMMANDTRANSLATOR_H__
#define __COMMANDTRANSLATOR_H__
#include <string>
#include <iostream>
#include "character.h"
#include "useitem.h"

class UserEffects;
class Character;

class CommandTranslator{
    public:
    CommandTranslator();
    std::string status;
    virtual bool next_to(Character *person, UserEffects &e);
    virtual void translate(Character *person);
    virtual ~CommandTranslator() = 0;
};
#endif
