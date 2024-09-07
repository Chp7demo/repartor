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


//rq: les 3 fonction suivante existe aussi ds genese.h elles sont surchargées...
bool st_have_pair(int st_ind);
int get_st_pair(int st_ind);//st_ind doit avoir une pair
bool cpl_ds_dsm(int st_ind);//st_ind doit avoir une pair
bool ds_dsm(int st_ind);


vector<int> create_ordo();
vector<int> create_desordo();




int N_St;
int N_Bur;

int N_Fix;
int N_Cpl;
int N_Free;

multimap<int,int> bmm;
map<int,int> dsm;
map<int,int> stm;

vector<int> vect_ordo;
vector<int> vect_desordo;

MI mi;
vector<Pos> bp;
double D_max;
double D_min;


private:

//fct du constructeur:
map<int,int>  from_matr_to_stm(const MI &matr);


};




