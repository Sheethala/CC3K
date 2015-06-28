#ifndef __USEREFFECTS_H__
#define __USEREFFECTS_H__

class UserEffects{
    public:
    int xcoord;
    int ycoord;
    UserEffects(int x, int y);
    virtual int get_x_coord();
    virtual int get_y_coord();
    virtual ~UserEffects() = 0;
};
#endif
