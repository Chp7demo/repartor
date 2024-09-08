#pragma once

#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <map>
#include <set>
#include <utility>
#include <algorithm>
#include <iterator>


#include "petites_fonctions.h"
#include "DataZone.h"


std::vector<int> genere_indiv(const DataZone & dZ);
int get_a_cell_pair(int bur_ind,std::multimap<int,int> &cell_pair_map_av);
void eff_pairs(int bur_ind,std::multimap<int,int> &cell_pair_map_av);
bool cell_have_pair_av(int bur_ind,const std::multimap<int,int> &cell_pair_map_av);
bool elem_have_pair(int cell_ind,const DataZone & dZ);
int get_elem_pair(int cell_ind,const DataZone & dZ);//cell_ind doit avoir une pair
bool cpl_in_elem_cell_map(int cell_ind,const DataZone & dZ);//cell_ind doit avoir une pair





