#include "cross_over.h"


using namespace std;
void cross_over(vector<int> &vect_1, vector<int> &vect_2,const DataZone & dZ)
{
//debug=====================
/*cout<<"avant cross"<<endl;
cout<<"desordo"<<endl;
for(int i=0;i<vect_1.size();i++){cout<<vect_1.at(i)<<" ";}
cout<<endl;

for(int i=0;i<vect_2.size();i++){cout<<vect_2.at(i)<<" ";}
cout<<endl;*/
//============================

ordo(vect_1,dZ.vect_ordo);
ordo(vect_2,dZ.vect_ordo);

//debug=====================
//cout<<"avant cross"<<endl;
/*cout<<"ordo"<<endl;
for(int i=0;i<vect_1.size();i++){cout<<vect_1.at(i)<<" ";}
cout<<endl;

for(int i=0;i<vect_2.size();i++){cout<<vect_2.at(i)<<" ";}
cout<<endl;*/
//============================
//cout<<"vect ordo avant simple cross"<<endl;
//debug_aff_vect(vect_1);
//debug_aff_vect(vect_2);
int ind=tir_ind_cross(dZ);
simple_cross(ind,vect_1,vect_2);
//cout<<"vect ordo apres simple cross"<<endl;
//debug_aff_vect(vect_1);
//debug_aff_vect(vect_2);

clean_cross(vect_1,vect_2,ind,dZ);
//cout<<"vect ordo apres clean"<<endl;
//debug_aff_vect(vect_1);
//debug_aff_vect(vect_2);
//cout<<endl;

//debug=====================
/*cout<<"après cross"<<endl;
//cout<<"ordo"<<endl;
for(int i=0;i<vect_1.size();i++){cout<<vect_1.at(i)<<" ";}
cout<<endl;

for(int i=0;i<vect_2.size();i++){cout<<vect_2.at(i)<<" ";}
cout<<endl;*/
//============================
desordo(vect_1,dZ.vect_desordo);
desordo(vect_2,dZ.vect_desordo);

//debug=====================
/*
cout<<"desordo"<<endl;
for(int i=0;i<vect_1.size();i++){
    cout<<vect_1.at(i)<<" ";
 for (int j=0;j<i;j++){if(vect_1.at(j)==vect_1.at(i))cout<<"!!!!!!!";}
}

cout<<endl;

for(int i=0;i<vect_2.size();i++){cout<<vect_2.at(i)<<" ";}
cout<<endl;*/
//============================
}

void ordo(vector<int> &vect,const vector<int> &vect_ordo)
{
vector<int> vect_copie=vect;
for(int i=0;i<vect.size();i++)
{
vect[i]=vect_copie[vect_ordo[i]];
}
}

void desordo(vector<int> &vect,const vector<int> &vect_desordo)
{
vector<int> vect_copie=vect;
for(int i=0;i<vect.size();i++)
{
vect[i]=vect_copie[vect_desordo[i]];
}

}

int tir_ind_cross(const DataZone & dZ)
{
int a=rand_a_b(0,dZ.N_Cpl/2+dZ.N_Free-2);
if(a<=dZ.N_Cpl/2-1){return (dZ.N_Fix-1+2*a);}
if(a>dZ.N_Cpl/2-1){return (dZ.N_Fix-1+dZ.N_Cpl/2-1+a);}
}

void simple_cross(int ind,vector<int> &vect_1,vector<int> &vect_2)
{
int c_pass;
for(int i=ind+1;i<vect_1.size();i++)
{
c_pass=vect_1[i];
vect_1[i]=vect_2[i];
vect_2[i]=c_pass;
}
}

void clean_cross(vector<int> &vect_1,vector<int> &vect_2,int ind,const DataZone &dZ)//sur vect ordo!
{
vector<int> vect_pass=vect_1;
if(clean_vect(vect_1,vect_2,ind,dZ)){if(!clean_vect(vect_2,vect_pass,ind,dZ)){vect_1=vect_pass; simple_cross(ind,vect_1,vect_2);}}//on annule le cross...c'est con ...
else simple_cross(ind,vect_1,vect_2);
}

bool clean_vect(vector<int> &v_1,vector<int> &v_2,int ind,const DataZone &dZ)//sur vect ordo!
{
    vector<int> v_1_prov=v_1;
    //vector<int> v_2_prov;
if(ind >= (dZ.N_Fix+dZ.N_Cpl))
{
for(int i=ind+1; i<dZ.N_St;i++)
{
int idx= index(v_1,v_1[i]);//retourne le premier ayant cette valeur...
//cout<<"rep 1 idx"<<idx<<endl;
//PARTIE A REVOIR!!!!======
if(idx<=ind){
    for(int id=ind+1;id<dZ.N_St;id++)
       {
        if(v_1[id]==v_2[i]){/*cout<<"annulation cross"<<endl;*/ return false;} //on annule le cross, c'est pas beau A CHANGER!!!
        //else v_1_prov[idx]=v_2[i];
    }
    if(idx>(dZ.N_Fix+dZ.N_Cpl))v_1_prov[idx]=v_2[i];
    else v_1_prov[i]=v_2[i];
}
}
}
v_1=v_1_prov;
if(ind<(dZ.N_Fix+dZ.N_Cpl))//PAS /2 ?!!!
{//cout<<"cross couple"<<endl;
    //debug
   // return false;
   // cout<<"av clean"<<endl;
    //debug_aff_vect(v_1);
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
//cout<<" idx dZ.N_Fix"<<idx<<dZ.N_Fix<<endl;
if(is_pair(idx-dZ.N_Fix)&&is_pair(i-dZ.N_Fix)){v_1_prov[idx+1]=v_2[i+1];}
if(!is_pair(idx-dZ.N_Fix)&&is_pair(i-dZ.N_Fix)){v_1_prov[idx-1]=v_2[i+1];}
if(is_pair(idx-dZ.N_Fix)&&!is_pair(i-dZ.N_Fix)){v_1_prov[idx+1]=v_2[i-1];}
if(!is_pair(idx-dZ.N_Fix)&&!is_pair(i-dZ.N_Fix)){v_1_prov[idx-1]=v_2[i-1];}
}
else v_1_prov[i]=v_2[i];
}
}
v_1=v_1_prov;
// cout<<"ap clean"<<endl;
 //   debug_aff_vect(v_1);
}
return true;
}


