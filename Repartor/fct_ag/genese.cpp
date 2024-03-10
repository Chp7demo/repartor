#include "genese.h"


using namespace std;

vector<int> genere_indiv(const DataZone & dZ)
{
//srand(time(NULL));//voir lib standard
vector<int> indiv(dZ.N_St);
vector<int> bur_ind_list;//pourquoi des vect et pas des set?ou list c'est mieux pr les erase...
//cout<<"rep G1"<<endl;
for(int i=1;i<=dZ.N_Bur;i++)bur_ind_list.push_back(i);
vector<int> st_ind_list=dZ.vect_ordo;
//cout<<"rep G2"<<endl;

//for(int i=0;i<dZ.N_St;i++)st_ind_list.push_back(i);
//auto bmm_av=dZ.bmm;//marche pas!
std::multimap<int,int> bmm_av=dZ.bmm;
//cout<<"rep G3"<<endl;

//cout<<"placement des direct s"<<endl;
//cout<<"dsm:"<<endl;
//DEBUG=========
//for(auto m_p : dZ.dsm){cout<<"st: "<<m_p.first<<"bu: "<<m_p.second<<endl;}
//===============
for(auto m_p : dZ.dsm)
{
/*//DEBUG==========
cout<<"rep G4"<<endl;
cout<<"st av :"<<endl;
debug_aff_vect(st_ind_list);
cout<<"bu av: "<<endl;
debug_aff_vect(bur_ind_list);
//=============*/
indiv[m_p.first]=m_p.second;
bur_ind_list.erase(find(bur_ind_list.begin(),bur_ind_list.end(),m_p.second));
// effacer pair ds bmm_av si c'est un bur de paire!!!
if(bur_have_pair_av(m_p.second,bmm_av))
{
    auto it=bmm_av.find(m_p.second);
    //auto it_2=bmm_av.find(it->second);
    int ind_bp=it->second;
    bmm_av.erase(it);
    it=bmm_av.find(ind_bp);
    bmm_av.erase(it);

}
st_ind_list.erase(find(st_ind_list.begin(),st_ind_list.end(),m_p.first));
//DEBUG===========
/*
cout<<"st ap :"<<endl;
debug_aff_vect(st_ind_list);
cout<<"bu ap: "<<endl;
debug_aff_vect(bur_ind_list);
//================
*/
}
//cout<<"fin placement"<<endl;
//debug_aff_vect(indiv);
//cout<<"rep_1"<<endl;
//cout<<"placement des cpl des direct s"<<endl;
//useless c'est fait manuellement...*
/*
for(auto m_p : dZ.dsm)
{
if((st_have_pair(m_p.first,dZ))&&(!cpl_ds_dsm(m_p.first,dZ)))
{
//cout<<"entree if"<<endl;
int bp=get_a_bur_pair(m_p.second,bmm_av);
//cout<<"sortie get_a_bur pair"<<endl;
int st_pair=get_st_pair(m_p.first,dZ);
//cout<<"sortie_fct"<<endl;
indiv[st_pair]=bp;
bur_ind_list.erase(find(bur_ind_list.begin(),bur_ind_list.end(),bp));
st_ind_list.erase(find(st_ind_list.begin(),st_ind_list.end(),st_pair));

}
}
*/
//cout<<"fin placement"<<endl;
//debug_aff_vect(indiv);
//cout<<"rep_2"<<endl;

//les stud ac des cpl seront traité avant car st_ind est ordo
while(st_ind_list.size()!=0)
{
//cout<<"entree while,choix d'un indice de bur"<<endl;
//cout<<"rep G5"<<endl;
int a=rand_a_b(0,bur_ind_list.size());//voir lib std si il ya une fct implementée
while(st_have_pair(st_ind_list.at(0),dZ)&&(!bur_have_pair_av(bur_ind_list.at(a),bmm_av)))
{//cout<<"rep g5 while"<<endl;
//cout<<"a= "<<a<<endl;
//cout<<"(int) a/(bur_ind_list.size())"<<(int) a/(bur_ind_list.size())<<endl;
a=a+1-(((int) (a+1)/(bur_ind_list.size()))*bur_ind_list.size());//?? pas optimal!!!
//cout<<"a= "<<a<<endl;

}
//cout<<"rep G6"<<endl;
int bur_ind=bur_ind_list.at(a);
//cout<<"bur_ind_list: "<<endl;
//debug_aff_vect(bur_ind_list);

bur_ind_list.erase(bur_ind_list.begin()+a);
//cout<<"bur_ind_list: "<<endl;
//debug_aff_vect(bur_ind_list);

indiv[st_ind_list.at(0)]=bur_ind;

//cout<<"fin choix"<<endl;
//debug_aff_vect(indiv);
//cout<<"si paire choix du bur du st paire"<<endl;
if(st_have_pair(st_ind_list.at(0),dZ))
{
//cout<<"rep G7"<<endl;
int bp=get_a_bur_pair(bur_ind,bmm_av);//efface ds bmm_av...
//cout<<"rep G7_2"<<endl;
int st_pair=get_st_pair(st_ind_list.at(0),dZ);
//cout<<"rep G7_3"<<endl;
indiv[st_pair]=bp;
//cout<<"rep G7_4"<<endl;
//cout<<"bur_ind_list: "<<endl;
//debug_aff_vect(bur_ind_list);
//cout<<"bp: "<<bp<<endl;
bur_ind_list.erase(find(bur_ind_list.begin(),bur_ind_list.end(),bp));
//cout<<"rep G7_5"<<endl;
//debug_aff_vect(bur_ind_list);
st_ind_list.erase(find(st_ind_list.begin(),st_ind_list.end(),st_pair));
//cout<<"rep G8"<<endl;
}
//cout<<"fin choix"<<endl;
//debug_aff_vect(indiv);
//debug_aff_vect(bur_ind_list);

st_ind_list.erase(st_ind_list.begin());
}
//cout<<"rep G9"<<endl;
return indiv;
}


int get_a_bur_pair(int bur_ind,std::multimap<int,int> &bmm_av)
{
//cout<<"rep bur_1"<<endl;
auto itlow=bmm_av.lower_bound(bur_ind);
//cout<<"rep bur_2"<<endl;
int ctrk=bmm_av.count(bur_ind);
//cout<<"rep bur_3"<<endl;
if(ctrk==0)return 0;
//cout<<"rep bur_4"<<endl;
int a=rand_a_b(0,ctrk);
//cout<<"rep bur_5"<<endl;
for(int i=0;i<a;i++){itlow++;}
//cout<<"rep bur_6"<<endl;
int bur_value=itlow->second;
//cout<<"entree eff pair"<<endl;
eff_pairs(bur_ind,bmm_av);
//cout<<"sortie eff pair"<<endl;
return bur_value;
}

void eff_pairs(int bur_ind,std::multimap<int,int> &bmm_av)//pas optimal non?
{
auto p=bmm_av.begin();
while(p!=bmm_av.end())
{
//cout<<"hello you"<<endl;
//debug//
//for(auto pt:bmm_av){cout<<pt.first<<" "<<pt.second<<endl;}
//cout<<endl;
//cout<<p->first<<" "<<p->second<<endl;
//cout<<endl;
//
if((p->first==bur_ind)||(p->second==bur_ind)){
//cout<<"ça va effacer une paire"<<endl;
p = bmm_av.erase(p);
//cout<<"paire effacee.."<<endl;

}
else{p++;}
}
}


bool bur_have_pair_av(int bur_ind,const std::multimap<int,int> &bmm_av)
{
//cout<<"entree bur have pair"<<endl;
auto it_pair=bmm_av.equal_range(bur_ind);
return(!(it_pair.first==it_pair.second));//???
}

bool st_have_pair(int st_ind,const DataZone & dZ)
{
//cout<<"entree st_have_pair"<<endl;
return(!(dZ.stm.find(st_ind)==dZ.stm.end()));
}



int get_st_pair(int st_ind,const DataZone & dZ)
{//cout<<"entree_fct"<<endl;
// cout<<"dZ.stm.find(st_ind)->second"<<dZ.stm.find(st_ind)->second<<endl;
auto it=dZ.stm.find(st_ind);
//cout<<"hello"<<endl;
return(it->second);
//return dZ.stm[st_ind];
}

bool cpl_ds_dsm(int st_ind,const DataZone & dZ)
{
int fd=get_st_pair(st_ind,dZ);
//cout<<"fd"<<fd<<endl;
//bool ess=!((dZ.dsm.find(fd))==(dZ.dsm.end()));
//cout<<"ess"<<ess<<endl;
return(!((dZ.dsm.find(fd))==(dZ.dsm.end())));
}

