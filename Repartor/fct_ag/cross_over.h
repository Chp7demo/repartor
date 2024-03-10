#ifndef CROSS_OVER_H
#define CROSS_OVER_H

#include "genese.h"

void cross_over(vector<int> &vect_1, vector<int> &vect_2,const DataZone & dZ);
void ordo(vector<int> &vect,const vector<int> &vect_ordo);
void desordo(vector<int> &vect,const vector<int> &vect_desordo);
int tir_ind_cross(const DataZone & dZ);
void simple_cross(int ind,vector<int> &vect_1,vector<int> &vect_2);
void clean_cross(vector<int> &vect_1,vector<int> &vect_2,int ind,const DataZone &dZ);
bool clean_vect(vector<int> &v_1,vector<int> &v_2,int ind,const DataZone &dZ);


#endif
