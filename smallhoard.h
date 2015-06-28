#ifndef __SMALLHOARD_H__
#define __SMALLHOARD_H__
#include "hoard.h"
#include <iostream>
#include <string>

class SmallHoard: public Hoard{
    public:
        SmallHoard(int n);
        ~SmallHoard();
};
#endif
