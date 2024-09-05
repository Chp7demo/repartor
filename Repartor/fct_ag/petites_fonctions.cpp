

#include "petites_fonctions.h"

using namespace std;






int rand_a_b(int a, int b){
if(b>a)return rand()%(b-a) +a;
else return a;
}

bool is_pair(int val)
{
return ((val % 2 )==0);
}

int index(const std::vector<int> &vect, int val) // version cpp ?
{
for(unsigned int i=0;i<vect.size();i++)
{
if(vect[i]==val)return i;
}
return -1;
}

void debug_aff_vect(const std::vector<int> &vect)
{
for(auto el:vect){cout<< el << " ";}
cout<<endl;
}

//ce check fait confiance au datazone, si celui ci est faut le check ne le verra pas...
void check_pop(vector<vector<int>> pop,const DataZone & dZ)//sur vect non ordo uniquement (vect normal)
{

    for(unsigned int i=0;i<pop.size();i++){check_indiv(pop.at(i),dZ);}

}

void check_indiv(vector<int> indiv,const DataZone & dZ)//sur vect non ordo uniquement (vect normal)
{
string type_erreur;
bool err_found=false;

//check redondance
for(unsigned int i=0;i<indiv.size();i++)
{for(unsigned int j=0;j<indiv.size();j++)
    {
        if(i!=j&&indiv.at(i)==indiv.at(j)){err_found=true;type_erreur="redondance";break;}
    }
}
//check elem_cell_map
if(!err_found)
{
for(auto m_p: dZ.elem_cell_map)
{
    if(indiv.at(m_p.first)!=m_p.second){err_found=true;type_erreur="erreur elem_cell_map";break;}
}
}
//check cpls

if(!err_found)
{
for(auto m_p: dZ.cpl_map)
{
    auto it=dZ.cell_pair_map.find(indiv.at(m_p.first));
    if(indiv.at(m_p.second)!=it->second){err_found=true;type_erreur="erreur cpl";break;}
}
}
//affichage erreur (seulement un type, par priorité);
if(err_found)
{
    /*
QFile file("/home/remi/reugq/fich_debug/record_indiv_err");
file.open(QFile::WriteOnly|QFile::Text|QFile::Append);
QTextStream out_text(&file);
out_text<<"lieu"<<"     "<<"type_erreur"<<endl;
for(int i=0;i<indiv.size();i++){out_text<<indiv.at(i)<<" ";}
out_text<<endl;
file.close();*/
}
  }
