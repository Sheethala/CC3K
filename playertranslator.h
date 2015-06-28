#ifndef __PLAYERTRANSLATOR_H__
#define __PLAYERTRANSLATOR_H__
#include "commandtranslator.h"
#include <string>
#include <iostream>
#include <utility>
#include "useitem.h"

class PlayerOption;
class Output;
class Brain;
class Move;
class Attack;
class UseItems;

class PlayerTranslator: public CommandTranslator{
    public:
    std::string status;
    Brain *b;
    PlayerTranslator();
    bool possible_m(Move &m);
    bool possible_a(Attack &a);
    bool possible_i(UseItem &i);
    void move(Move &m);
    void attack(Attack &a);
    void use(UseItem &i);
    void tell_output(Output &o, std::string s);
    std::string get_status(std::string s);
    void translate(PlayerOption* p);
    std::pair<int, int> get_placement(std::string s);
    ~PlayerTranslator();
};
#endif

