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
int get_a_cell_pair(int cell_ind,std::map<int,int> &cell_pair_map_av);
void eff_pairs(int cell_ind,std::map<int,int> &cell_pair_map_av);
bool cell_have_pair_av(int cell_ind,const std::map<int,int> &cell_pair_map_av);
bool elem_have_pair(int elem_ind,const DataZone & dZ);
int get_elem_pair(int elem_ind,const DataZone & dZ);//elem_ind doit avoir une pair
bool cpl_in_elem_cell_map(int elem_ind,const DataZone & dZ);//elem_ind doit avoir une pair





