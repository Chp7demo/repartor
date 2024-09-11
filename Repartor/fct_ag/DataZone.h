#pragma once

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <map>
#include "Elements_and_space.h"

#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

#include <QString>
#include <QFile>
#include<QTextStream>

using namespace std;
struct DataZone
{


DataZone(const Combi &combi);


//Les 3 fonctions suivantes existent aussi ds genese.h elles sont surchargées...
bool elem_have_pair(int cell_ind);
int get_elem_pair(int cell_ind); //cell_ind doit avoir une pair
bool cpl_in_elem_cell_map(int cell_ind); //cell_ind doit avoir une pair
bool in_elem_cell_map(int cell_ind);


vector<int> create_ordo();
vector<int> create_desordo();



int N_Elem;
int N_Cell;

int N_Fix;
int N_Cpl; // partners (elements can be partners) = couple = cpl
int N_Free;


map<int,int> cell_pair_map;
map<int,int> elem_cell_map;
map<int,int> cpl_map;


vector<int> vect_ordo;  // separated/ordered elements index vector fix/havecpl/free to make crossover
                        // "combi" have a list of elements name, here we work with vectors of the index
                        // of this names
vector<int> vect_desordo;

MI mi;
vector<Pos> cell_pos;
double D_max;  // max found distance between cells
double D_min;  // min found distance between cells


private:

//fct du constructeur:
map<int,int>  from_matr_to_cpl_map(const MI &matr);


};




