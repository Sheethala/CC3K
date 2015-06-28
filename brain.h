#ifndef __BRAIN_H__
#define __BRAIN_H__
#include "playeroption.h"
#include "floorplangenerator.h"
#include <iostream>
#include <sstream>
#include <string>
#include <fstream>

class Brain{
    Brain();
    PlayerOption* pl;
    bool done;
    FloorPlanGenerator **fl;
    bool file;
    bool won;
    static void delBrain();
    ~Brain();

    public:
    std::string fname;
    static Brain* b;
    int curfl;
    PlayerOption* get_player();
    void set_board(std::string str);
    void set_allfloors(std::vector<std::vector<std::vector<char> > > fls);
    void set_all();
    void output_allfloors();
    static Brain* getBrain();
    void choose_playertype(char type);
    void set_curfloor(int f);
    void user_command();
    void set_player(PlayerOption* p);
    void update();
    FloorPlanGenerator** get_allfloors();
    int brain_curfloor();
    void restart();
    bool brain_done();
    void given_file(std::string s);
    void endgame(bool result);
    void make_fls();
};

#endif
