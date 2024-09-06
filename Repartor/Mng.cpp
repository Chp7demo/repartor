#include "Mng.h"

using namespace std; 


Mng::Mng() :QObject()
{
qRegisterMetaType<vector<int>> ("vector<int>");
}

void Mng::aj_list(QList<QString> list_N)//obsolette
{
std::vector<std::string> vect_pass;
for(int i=0;i<list_N.size();i++)
{vect_pass.push_back(list_N.at(i).toStdString());}
sclass.st_nm=vect_pass;
//===aff debug=====
/*
for(int i=0;i<sclass.st_nm.size();i++)
{cout<<sclass.st_nm[i]<<" ";}
cout<<endl;*/
//===================
}

void Mng::aj_cl_et_ro(QList<QString> list_N)//pas et_ro en fait..
{
std::vector<std::string> nouv_list;
for(int i=0;i<list_N.size();i++)
{nouv_list.push_back(list_N.at(i).toStdString());}

if(nouv_list.size()>sclass.st_nm.size())
{
//aj matr_i===
std::string nouv_element=nouv_list[nouv_list.size()-1];

for(int i=0;i<sclass.matr_i.size();i++)
{
sclass.matr_i[i].push_back(interType::ras);
}
std::vector<interType> nouv_vect;
for(int i=0;i<sclass.matr_i.size()+1;i++)
{nouv_vect.push_back(interType::ras);} 
sclass.matr_i.push_back(nouv_vect);
//==============
//aj_st_it=======
sclass.st_it.push_back(indivType::ras);
//=================
//aj_st_nm========
sclass.st_nm=nouv_list;
//==============
}
if(nouv_list.size()<sclass.st_nm.size())
{
//indice du disparu===
int ind_disp;
for(int i=0;i<sclass.st_nm.size();i++)
{
auto it=find(nouv_list.begin(),nouv_list.end(),sclass.st_nm[i]);
if(it == nouv_list.end())
{
ind_disp=i;
break;
}
}
//=========
//aj_matr_i=======
for(int i=0;i<sclass.matr_i.size();i++)
{
sclass.matr_i[i].erase(sclass.matr_i[i].begin()+ind_disp);
}
sclass.matr_i.erase(sclass.matr_i.begin()+ind_disp);
//==================

//aj_st_it=======
sclass.st_it.erase(sclass.st_it.begin()+ind_disp);
//=================

//aj_st_nm========
sclass.st_nm.erase(sclass.st_nm.begin()+ind_disp);
//==============

//====on ajourne dsm ==========
combi.sc_dsm.erase(ind_disp);
map<int,int> new_map;
for(auto &paire: combi.sc_dsm)
{
    if(paire.first>ind_disp)
    {
        pair<int,int> new_paire(paire.first-1,paire.second);
        new_map.insert(new_paire);
    }
        else
        {
            new_map.insert(paire);
        }
}
combi.sc_dsm=new_map;
//=========================
}
emit ajourned(sclass,combi.sc_dsm);
//emit aj_dsm_copies(combi.sc_dsm);
}

void Mng::nouv_inter(QString s1 ,QString s2 ,interType inter_type)
{
std::string str1=s1.toStdString();
std::string str2=s2.toStdString();

int ind_1;
int ind_2;

auto it=find(sclass.st_nm.begin(),sclass.st_nm.end(),str1);
ind_1=it-sclass.st_nm.begin();

it=find(sclass.st_nm.begin(),sclass.st_nm.end(),str2);
ind_2=it-sclass.st_nm.begin();

sclass.matr_i[ind_1][ind_2]=inter_type;
sclass.matr_i[ind_2][ind_1]=inter_type;
//DEBUG===aff matrice

//  cout<<"dZ.N_st : "<<dZ.N_St<<endl;
for(int i=0;i<sclass.st_nm.size();i++)
{
  //  cout<<"pilipili"<<endl;
    //cout<<endl;
    for(int j=0;j<sclass.st_nm.size();j++)
    {

 switch (sclass.matr_i.at(i).at(j)) {
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
//fin debug======
emit ajourner_sans_reaff_cercle(sclass,combi.sc_dsm);

}

//fcts pr burs====================================================

//le code ici c'est nawak  avec les paires...
void Mng::modif_bur(int index,Pos pos)
{
ro.cell_pair[index]=pos;
emit cell_pair_ajourned(ro.cell_pair,combi.sc_dsm,combi.fbs);
}
void Mng::supr_bur(int index)
{
ro.cell_pair.erase(ro.cell_pair.begin()+index);
//on ajourne les cpl======
//----------------------------------------------------------------------------------------
ro.r_bmmp.erase(index);
pair<int,int> paire_to_remove;//en pratique un bur n'a qu'un paire (meme si multimap...)  
bool remove_paire=false;
for(auto &paire: ro.r_bmmp)
{
if(paire.second==index)
{
paire_to_remove=paire;
remove_paire=true;
}
}//sortie for
if(remove_paire)
{
ro.r_bmmp.erase(paire_to_remove.first);
}

//----------------------------------------------------------------------------------------
multimap<int,int> mm_copie;
for(auto &paire: ro.r_bmmp)
{
if(paire.first>index&&paire.second<index)
{
pair<int,int> new_paire(paire.first-1,paire.second);
mm_copie.insert(new_paire);
}
else
{
if(paire.second>index&&paire.first<index)
{
pair<int,int> new_paire(paire.first,paire.second-1);
mm_copie.insert(new_paire);
}
else
{
if(paire.second>index&&paire.first>index)
{
pair<int,int> new_paire(paire.first-1,paire.second-1);
mm_copie.insert(new_paire);
}
else
{
mm_copie.insert(paire);
}
}
}
}//sortie for
ro.r_bmmp=mm_copie;
//====on ajourne dsm =======
int  ind_st_to_erase;
bool is_there_ind=false;
for(auto &paire:combi.sc_dsm)
 {
    if(paire.second==index){ind_st_to_erase=paire.first;is_there_ind=true;}
}

if(is_there_ind)combi.sc_dsm.erase(ind_st_to_erase);

map<int,int> new_map;
for(auto &paire: combi.sc_dsm)
{
    if(paire.second>index)
    {
        pair<int,int> new_paire(paire.first,paire.second-1);
        new_map.insert(new_paire);
    }
        else
        {
            new_map.insert(paire);
        }
}
combi.sc_dsm=new_map;
//======on ajourne fbs==========
set<int> new_set;

for(auto b:combi.fbs)
{
    if(b>index) new_set.insert(b-1);
    if(b<index) new_set.insert(b);
    //if egale on s'en fiche ...
}
combi.fbs=new_set;
//=========================
emit cell_pair_ajourned(ro.cell_pair,combi.sc_dsm,combi.fbs);
//emit aj_dsm_copies(combi.sc_dsm);
emit bmmp_ajourned(ro.r_bmmp);
}


void Mng::add_bur(Pos pos)
{
cout<<"entree add_bur"<<endl;
ro.cell_pair.push_back(pos);
cout<<"ro.cell_pair.size()"<<ro.cell_pair.size()<<endl;
emit cell_pair_ajourned(ro.cell_pair,combi.sc_dsm,combi.fbs);
cout<<"sortie add_bur"<<endl;
}


void Mng::add_cpl(int i_1,int i_2)
{
pair<int,int> p(i_1,i_2);
pair<int,int> p_2(i_2,i_1);

ro.r_bmmp.insert(p);
ro.r_bmmp.insert(p_2);

emit bmmp_ajourned(ro.r_bmmp);
}
void Mng::supr_cpl(int i_1,int i_2) 
{
pair<int,int> paire_to_remove;
pair<int,int> paire_to_remove_2;

for(auto &paire: ro.r_bmmp)
{
if(paire.first==i_1&&paire.second==i_2)
{
paire_to_remove=paire;
}
if(paire.first==i_2&&paire.second==i_1)
{
paire_to_remove_2=paire;
}

}
ro.r_bmmp.erase(paire_to_remove.first);
ro.r_bmmp.erase(paire_to_remove_2.first);

emit bmmp_ajourned(ro.r_bmmp);

}

void Mng::aj_dsm(QString qstr_n,int ind_bu)//rajoute ou remplace une paire dsm
{

auto it=find(sclass.st_nm.begin(),sclass.st_nm.end(),qstr_n.toStdString());
int ind_n=it-sclass.st_nm.begin();

pair<int,int>  new_pair(ind_n,ind_bu);
combi.sc_dsm.erase(ind_n);//pas grave s'il ny en a pas ?
combi.sc_dsm.insert(new_pair);
}
void Mng::dsm_supr(QString qstr_n)
{
auto it=find(sclass.st_nm.begin(),sclass.st_nm.end(),qstr_n.toStdString());
int ind_n=it-sclass.st_nm.begin();
combi.sc_dsm.erase(ind_n);
}

void Mng::ad_fbs(int i)
{
combi.fbs.insert(i);
}

void Mng::supr_fbs(int i)
{
combi.fbs.erase(i);
}

void Mng::lancer_calc()
{
//crea_combi_ready
SCcombi cr;
cr=crea_combi_ready();
//crea datazone
DataZone Dz(cr);
//fichier analise ag
creer_fichier();//cette fct nettoie aussi le fichier recird indiv debug
//lancer thread
MyThread * myThread=new MyThread(Dz);
connect(myThread,SIGNAL(fin_ag(vector<int>)),this,SLOT(placer_stud(vector<int>)));
//connect(myThread,SIGNAL(record_ag(double,double,int,vector<int>)),this,SLOT(record_ag(double,double,int,vector<int>)));
//connect(myThread,SIGNAL(aff_graph()),this,SLOT(aff_graph()));
myThread->start();
}

SCcombi Mng::crea_combi_ready()
{
 SCcombi combi_r;
 combi_r.sclass=sclass;
 combi_r.room=ro;
 combi_r.sc_dsm=combi.sc_dsm;
 //DEBUG=========
for(auto m_p : combi_r.sc_dsm){cout<<"st: "<<m_p.first<<"bu: "<<m_p.second<<endl;}
//===============

// for(int )
  //supression des fbs

 int cpt_bur_spr=0;
 for(auto ind: combi.fbs)
 {
     cout<<ind<<endl;
     supr_bur(ind-cpt_bur_spr,combi_r);
     cpt_bur_spr++;
 }
 //DEBUG=========
for(auto m_p : combi_r.sc_dsm){cout<<"st: "<<m_p.first<<"bu: "<<m_p.second<<endl;}
//===============

 //decalage des ind bur (l ag les traites a partir de l ind 1( c'est con mais bon ))
 Pos p_vide;
 combi_r.room.cell_pair.insert(combi_r.room.cell_pair.begin(),p_vide);
//...........
 multimap<int,int> new_map;
for(auto &paire: combi_r.room.r_bmmp)
{
         pair<int,int> new_paire(paire.first+1,paire.second+1);
        new_map.insert(new_paire);
 }
combi_r.room.r_bmmp=new_map;
//..........

map<int,int> new_map_dsm;
for(auto &paire: combi_r.sc_dsm)
{
         pair<int,int> new_paire(paire.first,paire.second+1);
        new_map_dsm.insert(new_paire);
 }
combi_r.sc_dsm=new_map_dsm;
 //====
 return combi_r;
}

void Mng::supr_bur(int index,SCcombi &comb)
{
comb.room.cell_pair.erase(comb.room.cell_pair.begin()+index);
//on ajourne les cpl======
//----------------------------------------------------------------------------------------
comb.room.r_bmmp.erase(index);
pair<int,int> paire_to_remove;//en pratique un bur n'a qu'un paire (meme si multimap...)
bool remove_paire=false;
for(auto &paire: comb.room.r_bmmp)
{
if(paire.second==index)
{
paire_to_remove=paire;
remove_paire=true;
}
}//sortie for
if(remove_paire)
{
comb.room.r_bmmp.erase(paire_to_remove.first);
}

//----------------------------------------------------------------------------------------
multimap<int,int> mm_copie;
for(auto &paire: comb.room.r_bmmp)
{
if(paire.first>index&&paire.second<index)
{
pair<int,int> new_paire(paire.first-1,paire.second);
mm_copie.insert(new_paire);
}
else
{
if(paire.second>index&&paire.first<index)
{
pair<int,int> new_paire(paire.first,paire.second-1);
mm_copie.insert(new_paire);
}
else
{
if(paire.second>index&&paire.first>index)
{
pair<int,int> new_paire(paire.first-1,paire.second-1);
mm_copie.insert(new_paire);
}
else
{
mm_copie.insert(paire);
}
}
}
}//sortie for
comb.room.r_bmmp=mm_copie;
//====on ajourne dsm =======
/*vient de l autre surcharge
int  ind_st_to_erase;
for(auto &paire:comb.sc_dsm)
 {
    if(paire.second==index)ind_st_to_erase=paire.first;
}
comb.sc_dsm.erase(ind_st_to_erase);
*/
map<int,int> new_map;
for(auto &paire: comb.sc_dsm)
{
    if(paire.second>index)
    {
        pair<int,int> new_paire(paire.first,paire.second-1);
        new_map.insert(new_paire);
    }
        else
        {
            new_map.insert(paire);
        }
}
comb.sc_dsm=new_map;
//======on ajourne fbs==========

//ça on s' en fiche pour l'utilisation de cette fct====
/*
set<int> new_set;
for(auto b:combi.fbs)
{
    if(b>index) new_set.insert(b-1);
    if(b<index) new_set.insert(b);
    //if egale on s'en fiche ...
}
combi.fbs=new_set;*/
//=========================
//emit cell_pair_ajourned(ro.cell_pair,combi.sc_dsm,combi.fbs);
//emit aj_dsm_copies(combi.sc_dsm);
//emit bmmp_ajourned(ro.r_bmmp);
}

void Mng::placer_stud(vector<int> gen)
{
   //redecaler les indices des burs
   for(int i=0;i<gen.size();i++){gen[i]--;}

    //remapper les resultats en rajoutant les bur manquants
    for(auto ind: combi.fbs)
    {
     for (int i=0;i<gen.size();i++){if(gen[i]>=ind)gen[i]++;}
    }
    //remplir un dsm_2 à fabrique(qui contient l 'ancien dsm)
    combi.sc_dsm_old=combi.sc_dsm;
    combi.sc_dsm.clear();
     for (int i=0;i<gen.size();i++){
         pair<int,int> newpair(i,gen[i]);
         combi.sc_dsm.insert(newpair);
     cout<< gen[i]<<" ";
     }
           cout<<endl;
     cout<<"taille dsm: "<<combi.sc_dsm.size()<<endl;
    //emmetre un ajourned // faire les modif ds fenro pr prendre en cpt le dsm_2 //faire un bout annuler calc...
     emit faire_ajourner(sclass,combi.sc_dsm);//pb a l affichage , à voir...
}

void Mng::record_ag(double fit_moy,double fit_max,int ng,vector<int> best_g)
{

    /*
    //enregistrer les donnee dans un fichier (a definir)

QFile file(fileName);
// file.open(QFile::WriteOnly|QFile::Text);
//cout<<"heho"<<endl;
if(ng==0)file.open(QFile::WriteOnly|QFile::Text|QFile::Truncate);
else file.open(QFile::WriteOnly|QFile::Text|QFile::Append);
QTextStream out_text(&file);
out_text<<ng<<" "<<fit_moy<<" "<<fit_max<<"   ";
for(int i=0;i<best_g.size();i++){out_text<<best_g.at(i)<<" ";}
out_text << Qt::endl;
file.close();

    //faire une boite de dial demandant le nom du fich en debut d'ag?
    */
}
void Mng::aff_graph()
{
    //afficher une fenetre avec le graphdu ficheir enregistré
    //passer le nom de fichier en arg? ou bien le nom est un menbre?
    //pr l'instant on va voir avec gnuplot...
}
void Mng::creer_fichier()//faire tout ça dans mng avant le slot ... imbecile!
{
   // fileName=QFileDialog::getSaveFileName();
   // cout<<"nom fichier"<<fileName.toStdString()<<endl;
    fileName="/home/remi/reugq/fich_debug/essai";//attention que faire pr exporte le logiciel!!
   // QFile file(fileName);

    //on nettoie le fichier record_indiv_err

QFile file("/home/remi/reugq/fich_debug/record_indiv_err");
file.open(QFile::WriteOnly|QFile::Text|QFile::Truncate);
QTextStream out_text(&file);
out_text<< Qt::endl;
file.close();
}
