#include "DataZone.h"

DataZone::DataZone(const Combi &combi)
{
N_St=combi.elements.elem_names.size();
N_Bur=combi.space.cell_pos.size()-1;//le 0 est useless
bmm=combi.space.cell_pair;
dsm=combi.elem_cell_map;
stm=from_matr_to_stm(combi.elements.matr_i);
vect_ordo=create_ordo();
vect_desordo=create_desordo();
//pour evaluation======
mi=combi.elements.matr_i;
//DEBUG===aff matrice
//cout<<"matrice lors de la creation de data zone"<<endl;
//  cout<<"dZ.N_st : "<<dZ.N_St<<endl;
for(int i=0;i<N_St;i++)
{


    for(int j=0;j<N_St;j++)
    {

 switch (mi.at(i).at(j)) {
        case (interType::cpl):
                  cout<<"cpl   ";
     break;
        case (interType::bav):
                  cout<<"bav  ";
     break;
       case (interType::ras):
                  cout<<"---    ";
     break;

        case(interType::gba):
            cout<<"gba  ";
                        break;
        case(interType::mes):
               cout<<"mes  ";
             break;
        case(interType::gme):
             cout<<"gme  ";
            break;
        default:
       cout<<"???  ";

            break;
   }
 }
}
//fin debug===
bp=combi.space.cell_pos;


//distance max et min

double d_max=0;
double d_min=0;
for(int i=0;i<bp.size();i++)
{
    for(int j=i+1;j<bp.size();j++)
    {

            double a_x = bp.at(i).x;
            double b_x = bp.at(j).x;
            double a_y = bp.at(i).y;
            double b_y = bp.at(j).y;

             double dist=sqrt(pow(a_x-b_x,2)+pow(a_y-b_y,2));

             if(dist>d_max){d_max=dist;}
             if(dist<d_min || d_min==0){d_min=dist;}

    }
}

D_max=d_max;
D_min=d_min;
//===============
}

std::map<int,int>   DataZone::from_matr_to_stm(const MI &matr)
{
 std::map<int,int>  stm;

for(int i=1;i<matr.size();i++)
{
for(int j=0;j<matr.at(i).size();j++)
{
if(matr.at(i).at(j)==interType::cpl)
{
stm[i]=j;
stm[j]=i;
}
}

}
return stm;
}

bool DataZone::st_have_pair(int st_ind)
{
//cout<<"entree st_have_pair"<<endl;
return(!(stm.find(st_ind)==stm.end()));
}

int DataZone::get_st_pair(int st_ind)
{//cout<<"entree_fct"<<endl;
// cout<<"dZ.stm.find(st_ind)->second"<<dZ.stm.find(st_ind)->second<<endl;
auto it=stm.find(st_ind);
//cout<<"hello"<<endl;
return(it->second);
//return dZ.stm[st_ind];
}

bool DataZone::cpl_ds_dsm(int st_ind)
{
int fd=get_st_pair(st_ind);
//cout<<"fd"<<fd<<endl;
//bool ess=!((dZ.dsm.find(fd))==(dZ.dsm.end()));
//cout<<"ess"<<ess<<endl;
return(!((dsm.find(fd))==(dsm.end())));
}

bool DataZone::ds_dsm(int st_ind)
{
return(!((dsm.find(st_ind))==(dsm.end())));
}


vector<int> DataZone::create_ordo()
{
vector<int> vect_fix;
vector<int> vect_cpl;
vector<int> vect_free;

vector<int> ind_list;
for(int i=0;i<N_St;i++){ind_list.push_back(i);}

while(ind_list.size()>0)
{
if(ds_dsm(ind_list[0]))
{
vect_fix.push_back(ind_list[0]);
if(st_have_pair(ind_list[0]))
{
int nb=get_st_pair(ind_list[0]);
vect_fix.push_back(nb);
ind_list.erase(find(ind_list.begin(),ind_list.end(),nb));
}
ind_list.erase(ind_list.begin());
}
else
{
if((st_have_pair(ind_list[0]))&&(ds_dsm(get_st_pair(ind_list[0]))))
{
vect_fix.push_back(ind_list[0]);
int nb=get_st_pair(ind_list[0]);
vect_fix.push_back(nb);
ind_list.erase(find(ind_list.begin(),ind_list.end(),nb));
ind_list.erase(ind_list.begin());
}
if((st_have_pair(ind_list[0]))&&!(ds_dsm(get_st_pair(ind_list[0]))))
{
vect_cpl.push_back(ind_list[0]);
int nb=get_st_pair(ind_list[0]);
vect_cpl.push_back(nb);
ind_list.erase(find(ind_list.begin(),ind_list.end(),nb));
ind_list.erase(ind_list.begin());
}
if(!st_have_pair(ind_list[0]))
{
vect_free.push_back(ind_list[0]);
ind_list.erase(ind_list.begin());
}

}//fin else
}//fin while

N_Fix=vect_fix.size();
N_Cpl=vect_cpl.size();
N_Free= vect_free.size();

vector<int> vect_ord;

for(auto el:vect_fix){vect_ord.push_back(el);}//merge!!!
for(auto el:vect_cpl){vect_ord.push_back(el);}
for(auto el:vect_free){vect_ord.push_back(el);}

return vect_ord;

}//fin fct

vector<int> DataZone::create_desordo()
{
vector<int> vect_des;
for(int i=0;i<N_St;i++)
{
vect_des.push_back((int) (find(vect_ordo.begin(),vect_ordo.end(),i)-vect_ordo.begin()));
}
return vect_des;
}

