#ifndef MES_TYPES_H
#define MES_TYPES_H


#include <cstdlib>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <string>

struct Pos{double x;double y;double largeur;double hauteur;double angle;};
//enum class interType{ras,cpl,bav,gba,mes,gme};
enum class interType{ras,cpl,bav,gba,mes,gme};

enum class indivType{ras,idf,mis,pis,elf,elp,elm};
typedef std::vector<std::vector<interType> > MI;

#endif
