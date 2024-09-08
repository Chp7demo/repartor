#pragma once


#include <cstdlib>
#include <map>
#include <set>

#include"RepartorTypes.h"


struct Elements
{
std::vector<std::string> elem_names;
MI matr_i; // matrice d'interactions triangulaire sans diagonale
};

struct Space
{
std::vector<Pos> cell_pos; // position des cellules
std::map<int,int> cell_pair; // cellules liées entre elles pour acceuillir des paires d'éléments
};


struct Combi
{
Elements elements;
Space  space;
std::map<int,int> elem_cell_map;
std::set<int> frozen_cell;// cellules interdites
};




