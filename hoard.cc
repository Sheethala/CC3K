#include <iostream>
#include <string>
#include "hoard.h"
#include "goto.h"
using namespace std;

Hoard::Hoard(int a, int b, char c, bool e): points(b), Item(a,c,e,false) {}

Hoard::~Hoard(){
}

void Hoard::take(GoTo &g){
    g.go_to(this);
}

