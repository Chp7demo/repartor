#pragma once


#include <cstdlib>
#include <map>
#include <set>

#include"mes_types.h"


struct Elements
{
std::vector<std::string> elem_names;
MI matr_i;//matrice d'interactions triangulaire sans diagonale
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

Elements elements;
Room  room;
std::map<int,int> sc_dsm;//el-b  // eleve -bureau , si j'ai bien compris !!!
std::map<int,int>sc_dsm_old;//stock sc_dsm apres un placement auto en cas d 'annulation
std::set<int> fbs;// place interdites//doit retirer le bureau ds data zone->à faire//peut etre vaux il mieux faire cela en amont?..

};




