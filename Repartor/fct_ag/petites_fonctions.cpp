

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

//ce check fait confiance au data zone , si celui ci est faut le check ne le verra pas...
void check_pop(vector<vector<int>> pop,const DataZone & dZ)//sur vect non ordo uniquement (vect normal)
{
    for(unsigned int i=0;i<pop.size();i++){check_indiv(pop.at(i),dZ);}
}

void check_indiv(vector<int> indiv,const DataZone & dZ)//sur vect non ordo uniquement (vect normal)
{
string type_erreur;
bool err_pres=false;

//check redondance
for(unsigned int i=0;i<indiv.size();i++)
{for(unsigned int j=0;j<indiv.size();j++)
    {
        if(i!=j&&indiv.at(i)==indiv.at(j)){err_pres=true;type_erreur="redondance";break;}
    }
}
//check dsm
if(!err_pres)
{
for(auto m_p: dZ.dsm)
{
    if(indiv.at(m_p.first)!=m_p.second){err_pres=true;type_erreur="erreur dsm";break;}
}
}
//check cpls

if(!err_pres)
{
for(auto m_p: dZ.stm)
{
    auto it=dZ.bmm.find(indiv.at(m_p.first));
    if(indiv.at(m_p.second)!=it->second){err_pres=true;type_erreur="erreur cpl";break;}
}
}
//affichage erreur (seulement un type, par priorité);
if(err_pres)
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

/*void check_indiv(vector<int> indiv, QString fileName )
{
    //enregistrer les donnee dans un fichier (a definir)
QFile file(fileName);
// file.open(QFile::WriteOnly|QFile::Text);
//cout<<"heho"<<endl;
if(ng==0)file.open(QFile::WriteOnly|QFile::Text|QFile::Truncate);
else file.open(QFile::WriteOnly|QFile::Text|QFile::Append);
QTextStream out_text(&file);
out_text<<ng<<" "<<fit_moy<<" "<<fit_max<<"   ";
for(int i=0;i<best_g.size();i++){out_text<<best_g.at(i)<<" ";}
out_text<<endl;
file.close();

    //faire une boite de dial demandant le nom du fich en debut d'ag?
}*/
