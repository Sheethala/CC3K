#ifndef __READFILE_H__
#define __READFILE_H__
#include <vector>
#include <fstream>
#include <iostream>

class ReadFile{
    public:
        ReadFile();
        std::string filename;
        std::vector<std::vector<std::vector<char> > > read_layouts(std::string file);
        int convert_to_celltype (char c);
};

#endif
