#include "mutation.h"

using namespace std;

//attention... mal codee...
void mutation(vector<int> &indiv,const DataZone &dZ)//rq: marche que s'il n'y a pas de multipaires de bur...
{
ordo(indiv,dZ.vect_ordo);
//cout<<"indiv.size()"<<indiv.size()<<endl;
//cout<<"N_fix"<<dZ.N_Fix<<endl;
int a=rand_a_b(dZ.N_Fix,indiv.size()-1);
//cout<<"apres_rand"<<endl;
//int b=rand_a_b(dZ.N_Fix,indiv.size()-1);//a refaire! tirer un cellreau pas un indice!!!
int bord= dZ.N_Cpl+dZ.N_Fix;

int cell=rand_a_b(1,dZ.N_Cell);
int idx=index(indiv,cell);
bool ds_indiv;
if(idx==-1){ds_indiv=false;}
else{ds_indiv=true;}

if(ds_indiv)
{
int b=idx;
if(idx >= dZ.N_Fix)//diminue encore le taux de mutation...
{ 
if(a!=b)
{
if ((a >= bord) &( b >= bord))
{
simple_switch(indiv,a,b);
}

if ((a < bord) &( b >= bord))
{
desordo(indiv,dZ.vect_desordo);
if(cell_have_pair_av(indiv[dZ.vect_ordo[b]],dZ.cell_pair_map))//sinon pas de mutation atttention dilue le taux de mut
{
//cout<<"a,b "<<a<<","<<b<<endl; 
//cout<<"rep 1 dZ.vect_ordo"<<endl;
//debug_aff_vect(dZ.vect_ordo);
switch_cell_pair(indiv,dZ.vect_ordo[a],dZ.vect_ordo[b],dZ);
}
ordo(indiv,dZ.vect_ordo);
}

if ((a < bord) &( b < bord))
{
//cout<<"rep 1 ordo"<<endl;
//debug_aff_vect(indiv);
//debug_aff_vect(dZ.vect_ordo);

desordo(indiv,dZ.vect_desordo);
//cout<<"rep 1 desordo"<<endl;
//debug_aff_vect(indiv);
//debug_aff_vect(dZ.vect_desordo);


if(have_cpl(dZ.vect_ordo[a],dZ.vect_ordo[b],dZ))
{
//cout<<"rep 2"<<endl;

simple_switch(indiv,dZ.vect_ordo[a],dZ.vect_ordo[b]);

}
else
{
//cout<<"rep 3"<<endl;


switch_cell_pair(indiv,dZ.vect_ordo[a],dZ.vect_ordo[b],dZ);
}
ordo(indiv,dZ.vect_ordo);
}

if ((b < bord) &( a >= bord))
{
desordo(indiv,dZ.vect_desordo);
if(cell_have_pair_av(indiv[dZ.vect_ordo[a]],dZ.cell_pair_map))//attention au taux de mut
{
//cout<<"a,b "<<a<<","<<b<<endl; 
//cout<<"rep 1 dZ.vect_ordo"<<endl;
//debug_aff_vect(dZ.vect_ordo);
switch_cell_pair(indiv,dZ.vect_ordo[b],dZ.vect_ordo[a],dZ);
}
ordo(indiv,dZ.vect_ordo);
}

}//if(a!=b);
}//if(idx >= dZ.N_Fix)
}//if(ds_indiv);
else///a  faire!!!TODO//cell n'est pas ds indiv
{
if(a >= bord)
{
indiv[a]=cell;
}
if(a < bord)
{
if(cell_have_pair_av(cell,dZ.cell_pair_map))//attention au taux de mut
{
int c_pair=get_cell_pair(cell,dZ.cell_pair_map);
int idx_bis=index(indiv,c_pair);
bool ds_indiv_bis;
if(idx_bis==-1){ds_indiv_bis=false;}
else{ds_indiv_bis=true;}
if(ds_indiv_bis)
{
desordo(indiv,dZ.vect_desordo);
int a_bis=get_elem_pair(dZ.vect_ordo[a],dZ);
int b_bis=dZ.vect_ordo[idx_bis];
switch_cell_pair(indiv,a_bis,b_bis,dZ);//marteau pr mouche;
ordo(indiv,dZ.vect_ordo);
}
else
{
desordo(indiv,dZ.vect_desordo);

indiv[dZ.vect_ordo[a]]=cell;
indiv[get_elem_pair(dZ.vect_ordo[a],dZ)]=c_pair;

ordo(indiv,dZ.vect_ordo);

}
}
}

}//fin else cell pas ds indiv


desordo(indiv,dZ.vect_desordo);

}

void simple_switch(vector<int> &indiv,int a,int b)
{
int n_pass=indiv[a];
indiv[a]=indiv[b];
indiv[b]=n_pass;
}

void switch_cell_pair(vector<int> &indiv,int a,int b,const DataZone &dZ)//indiv desordo
{
int c= get_elem_pair(a,dZ);

int val=get_cell_pair(indiv[b],dZ.cell_pair_map);

int d=index(indiv,val);

simple_switch(indiv,a,b);

if(d==-1)
{indiv[c]=val;}
else
{
simple_switch(indiv,c,d);
}
}



bool have_cpl(int a,int b,const DataZone &dZ)//indiv desordo //seulement si a a un cpl;
{
int n=get_elem_pair(a,dZ);
if(n==b) {return true;}
else {return false;}
}

int get_cell_pair(int bur_ind,const std::multimap<int,int> &cell_pair_map)
{
auto itlow=cell_pair_map.lower_bound(bur_ind);
int ctrk=cell_pair_map.count(bur_ind);
if(ctrk==0)return 0;
int a=rand_a_b(0,ctrk);
for(int i=0;i<a;i++){itlow++;}
int bur_value=itlow->second;
//cout<<"entree eff pair"<<endl;
//eff_pairs(bur_ind,cell_pair_map_av);
//cout<<"sortie eff pair"<<endl;
return bur_value;

}

