#pragma once

#include "DataZone.h"


double evaluation(const vector<int> & vect,const DataZone & dZ);
double distance(Pos pos_1,Pos pos_2);
double formule_score_moins(double C1, Pos p1,Pos p2);
double formule_score_plus(double C1, Pos p1,Pos p2);


