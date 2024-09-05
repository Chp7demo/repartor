#ifndef SCLASS_ET_ROOM_H
#define SCLASS_ET_ROOM_H


#include <cstdlib>
#include <map>
#include <set>

#include"mes_types.h"


class SClass
{
public:
//SClass();
std::string sc_n;
std::vector<std::string> st_nm;
std::vector<indivType> st_it;
MI matr_i;//matrice triangulaire sans diagonale


};

class Room
{
public:
//Room();
std::string r_n;
std::vector<Pos> cell_pair;//Pos à definir.
Pos at_pt;

std::multimap<int,int> r_bmmp;//comment est il rempli?!

};


class SCcombi
{
public:
//SCcombi();

SClass sclass;
Room  room;
std::map<int,int> sc_dsm;//el-b
std::map<int,int>sc_dsm_old;//stock sc_dsm apres un placement auto en cas d 'annulation
std::set<int> fbs;//doit retirer le bureau ds data zone->à faire//peut etre vaux il mieux faire cela en amont?..

};



#endif
