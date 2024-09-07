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
std::string sc_n; // nom de la classe ?
std::vector<std::string> st_nm; // les nom des elèves
std::vector<indivType> st_it; // ??
MI matr_i;//matrice triangulaire sans diagonale // matrice d'interaction


};

class Room
{
public:
//Room();
std::string r_n; // nom de la salle classe ? utile ?
std::vector<Pos> cell_pos;//Pos à definir.// position des cellules (nom "cell pair erreure)
//Pos at_pt; // ??

std::multimap<int,int> r_bmmp;//comment est il rempli?! // multimap ? paire de bureau ??

};


class SCcombi
{
public:
//SCcombi();

SClass sclass;
Room  room;
std::map<int,int> sc_dsm;//el-b  // eleve -bureau , si j'ai bien compris !!!
std::map<int,int>sc_dsm_old;//stock sc_dsm apres un placement auto en cas d 'annulation
std::set<int> fbs;// place interdites//doit retirer le bureau ds data zone->à faire//peut etre vaux il mieux faire cela en amont?..

};



#endif
