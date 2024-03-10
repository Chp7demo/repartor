#ifndef MUTATION_H
#define MUTATION_H

#include "cross_over.h"

void mutation(vector<int> &indiv,const DataZone &dZ);
void simple_switch(vector<int> &indiv,int a,int b);
void switch_bur_cpl(vector<int> &indiv,int a,int b,const DataZone &dZ);//indiv desordo
bool en_cpl(int a,int b,const DataZone &dZ);
int get_bur_pair(int bur_ind,const std::multimap<int,int> &bmm);


#endif
