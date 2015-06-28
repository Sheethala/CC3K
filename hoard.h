#ifndef __HOARD_H__
#define __HOARD_H__ 
#include <string>
#include <iostream>
#include "item.h"

class GoTo;

class Hoard: public Item{
    public: 
    int points;
    Hoard(int a, int b, char c, bool d = true);
    ~Hoard();
    virtual void take(GoTo &v);
};

#endif
