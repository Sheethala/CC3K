#ifndef __OUTPUT_H__
#define __OUTPUT_H__
#include <iostream>
#include <vector>
#include <string>
#include <cstring>

class Output{
    std::vector<std::vector<char> > board;
    std::string status;
    public:
        void setStatus(std::string s);
        Output(int x, int y);
        void notifyBoard(int x, int y, char c);
        void clearStatus();
        friend std::ostream &operator<<(std::ostream &out, const Output &o);
};
#endif
