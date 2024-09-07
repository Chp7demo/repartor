
#pragma once

#include <iostream>
#include <math.h>
#include <ctime>
#include <cstdlib>
#include <vector>
#include <utility>


#include <QString>
#include <QFile>
#include<QTextStream>

#include"DataZone.h"



int rand_a_b(int a, int b);
bool is_pair(int val);
int index(const vector<int> &vect, int val); // existe peut être une version std
void debug_aff_vect(const std::vector<int> &vect);
void check_pop(vector<vector<int>> pop,const DataZone & dZ);
void check_indiv(vector<int> indiv,const DataZone & dZ);




