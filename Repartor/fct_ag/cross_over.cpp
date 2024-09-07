#include "cross_over.h"


using namespace std;

void cross_over(vector<int> &vect_1, vector<int> &vect_2,const DataZone & dZ)
{

ordo(vect_1,dZ.vect_ordo);
ordo(vect_2,dZ.vect_ordo);

int ind=tir_ind_cross(dZ);

simple_cross(ind,vect_1,vect_2);   // ?? avant clean cross?

clean_cross(vect_1,vect_2,ind,dZ);

desordo(vect_1,dZ.vect_desordo);
desordo(vect_2,dZ.vect_desordo);

}

void ordo(vector<int> &vect,const vector<int> &vect_ordo)
{
vector<int> vect_copie=vect;
for(unsigned int i=0;i<vect.size();i++)
{
vect[i]=vect_copie[vect_ordo[i]];
}
}


void desordo(vector<int> &vect,const vector<int> &vect_desordo)
{
vector<int> vect_copie=vect;
for(unsigned int i=0;i<vect.size();i++)
{
vect[i]=vect_copie[vect_desordo[i]];
}
}


int tir_ind_cross(const DataZone & dZ)
{
int a=rand_a_b(0,dZ.N_Cpl/2+dZ.N_Free-2);
if(a<=dZ.N_Cpl/2-1){return (dZ.N_Fix-1+2*a);}
return (dZ.N_Fix-1+dZ.N_Cpl/2-1+a);
}


void simple_cross(int ind,vector<int> &vect_1,vector<int> &vect_2)
{
int c_pass;
for(unsigned int i=ind+1;i<vect_1.size();i++)
{
c_pass=vect_1[i];
vect_1[i]=vect_2[i];
vect_2[i]=c_pass;
}
}


void clean_cross(vector<int> &vect_1,vector<int> &vect_2,int ind,const DataZone &dZ)//sur vect ordo!
{
vector<int> vect_pass=vect_1;
if(clean_vect(vect_1,vect_2,ind,dZ))
{
    if(!clean_vect(vect_2,vect_pass,ind,dZ))
    {
        vect_1=vect_pass;
        simple_cross(ind,vect_1,vect_2);
    }
}//on annule le cross...c'est dommage
else simple_cross(ind,vect_1,vect_2);
}



bool clean_vect(vector<int> &v_1,vector<int> &v_2,int ind /*indice du crossover*/,const DataZone &dZ)//sur vect ordo!
{
    vector<int> v_1_prov=v_1;

if(ind >= (dZ.N_Fix+dZ.N_Cpl))
{
for(int i=ind+1; i<dZ.N_St;i++)
{  
int idx= index(v_1,v_1[i]); //??//retourne le premier ayant cette valeur
//(donc potentiellement un idx < à ind+1) ...-1 sinon //index c'est le bur?

//PARTIE A REVOIR!!!!======

if(idx<=ind){ // ça veut dire qu'on a trouvé un doublon...
    for(int id=ind+1;id<dZ.N_St;id++)
       {
        if(v_1[id]==v_2[i]){/*cout<<"annulation cross"<<endl;*/ return false;} //on annule le cross, c'est pas beau A CHANGER!!!
        //else v_1_prov[idx]=v_2[i];
    }
    // erreure ci dessous !!!
    if(idx>(dZ.N_Fix+dZ.N_Cpl))v_1_prov[idx]=v_2[i]; // ce cas se présente t'il ?
    else v_1_prov[i]=v_2[i];
}
}
}


v_1=v_1_prov;

if(ind<(dZ.N_Fix+dZ.N_Cpl))//PAS /2 ?!!!
{


for(int i=ind+1;i<(dZ.N_St);i++)
{
int idx= index(v_1_prov,v_1_prov[i]);
//cout<<"rep 2 idx"<<idx<<endl;
if(idx<=ind){
      for(int id=ind+1;id<dZ.N_St;id++) //a changer !!! on reduit considerablement le nb de cross!
       {
        if(v_1_prov[id]==v_2[i]){/*cout<<"annulation cross"<<endl;*/ return false;} //on annule le cross, c'est pas beau A CHANGER!!!
        //else v_1_prov[idx]=v_2[i];
    }
if(i<=ind)
{
v_1_prov[idx]=v_2[i];

if(is_pair(idx-dZ.N_Fix)&&is_pair(i-dZ.N_Fix)){v_1_prov[idx+1]=v_2[i+1];}
if(!is_pair(idx-dZ.N_Fix)&&is_pair(i-dZ.N_Fix)){v_1_prov[idx-1]=v_2[i+1];}
if(is_pair(idx-dZ.N_Fix)&&!is_pair(i-dZ.N_Fix)){v_1_prov[idx+1]=v_2[i-1];}
if(!is_pair(idx-dZ.N_Fix)&&!is_pair(i-dZ.N_Fix)){v_1_prov[idx-1]=v_2[i-1];}
}
else v_1_prov[i]=v_2[i];
}
}
v_1=v_1_prov;

}
return true;
}


