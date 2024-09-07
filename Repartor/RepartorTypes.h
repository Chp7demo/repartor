#pragma once


#include <cstdlib>
#include <map>
#include <set>
#include <utility>
#include <vector>
#include <string>

struct Pos{double x;double y;double largeur;double hauteur;double angle;};

enum class interType{NO_INTER,PARTNERS,BRING_CLOSE,BRING_VERY_CLOSE,SPLIT,SPLIT_FAR};

typedef std::vector<std::vector<interType> > MI;


