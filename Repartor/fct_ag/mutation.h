#pragma once

#include "cross_over.h"

void mutation(vector<int> &indiv,const DataZone &dZ);
void simple_switch(vector<int> &indiv,int a,int b);
void switch_cell_pair(vector<int> &indiv,int a,int b,const DataZone &dZ);//indiv desordo
bool are_cpl(int a,int b,const DataZone &dZ);
int get_cell_pair(int cell_ind,const std::map<int,int> &cell_pair_map);


