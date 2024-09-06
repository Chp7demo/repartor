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

//ces fonction doivent avoir un  acces direct au menbres de data zone...(friends?)
std::vector<int> genere_indiv(const DataZone & dZ);
int get_a_bur_pair(int bur_ind,std::multimap<int,int> &bmm_av);
void eff_pairs(int bur_ind,std::multimap<int,int> &bmm_av);
bool bur_have_pair_av(int bur_ind,const std::multimap<int,int> &bmm_av);
bool st_have_pair(int st_ind,const DataZone & dZ);
int get_st_pair(int st_ind,const DataZone & dZ);//st_ind doit avoir une pair
bool cpl_ds_dsm(int st_ind,const DataZone & dZ);//st_ind doit avoir une pair





