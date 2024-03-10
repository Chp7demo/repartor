#ifndef DATAZONE_H
#define DATAZONE_H

#include <iostream>
#include <math.h>
#include <cstdlib>
#include <map>
#include "sclass_et_room.h"

#include <utility>
#include <vector>
#include <set>
#include <algorithm>
#include <iterator>

#include <QString>
#include <QFile>
#include<QTextStream>

using namespace std;
class DataZone
{

friend vector<int> genere_indiv(const DataZone & dZ);
friend bool st_have_pair(int st_ind,const DataZone & dZ);
friend int get_st_pair(int st_ind,const DataZone & dZ);
friend bool cpl_ds_dsm(int st_ind,const DataZone & dZ);
friend void cross_over(vector<int> &vect_1, vector<int> &vect_2,const DataZone & dZ);
friend int tir_ind_cross(const DataZone & dZ);
friend void clean_cross(vector<int> &vect_1,vector<int> &vect_2,int ind,const DataZone &dZ);
friend bool clean_vect(vector<int> &v_1,vector<int> &v_2,int ind,const DataZone &dZ);
friend void mutation(vector<int> &indiv,const DataZone &dZ);
friend void switch_bur_cpl(vector<int> &indiv,int a,int b,const DataZone &dZ);//indiv desordo
friend bool en_cpl(int a,int b,const DataZone &dZ);
friend double evaluation(const vector<int> & vect,const DataZone & dZ);
friend void check_pop(vector<vector<int>> pop,QString lieu,const DataZone & dZ);
friend void check_indiv(vector<int> indiv,QString lieu,const DataZone & dZ);

public:

DataZone(const SCcombi &combi);

private:

//fct du constructeur:
std::map<int,int>  from_matr_to_stm(const MI &matr);

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
};



#endif
