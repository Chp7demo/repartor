#pragma once


#include <cstdlib>
#include <map>
#include <set>

#include"mes_types.h"


struct Elements
{
std::vector<std::string> elem_names;
MI matr_i; // matrice d'interactions triangulaire sans diagonale
};

struct Space
{
std::vector<Pos> cell_pos; // position des cellules
std::multimap<int,int> cell_pair; // cellules liées entre elles pour acceuillir des paires d'éléments
};


struct Combi
{
Elements elements;
Space  space;
std::map<int,int> elem_cell_map;
std::map<int,int> elem_cell_map_old;//stock elem_cell_map apres un placement auto (en cas d'annulation par l'utilisateur)
std::set<int> frozen_cell;// cellules interdites//doit retirer le bureau ds data zone->à faire//peut etre vaux il mieux faire cela en amont?..

};




