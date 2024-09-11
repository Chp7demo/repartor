#include "Mng.h"

using namespace std; 


Mng::Mng() :QObject()
{
    qRegisterMetaType<vector<int>> ("vector<int>");
}



void Mng::rfsh_elem_space(QList<QString> list_N)// and space ?
{
    std::vector<std::string> nouv_list;
    for(int i=0;i<list_N.size();i++) {nouv_list.push_back(list_N.at(i).toStdString());}

    if(nouv_list.size()>elements.elem_names.size())
    {
        //aj matr
        std::string nouv_element=nouv_list[nouv_list.size()-1];

        for(unsigned int i=0;i<elements.matr_i.size();i++)
        {
            elements.matr_i[i].push_back(interType::NO_INTER);
        }

        std::vector<interType> nouv_vect;
        for(unsigned int i=0;i<elements.matr_i.size()+1;i++){nouv_vect.push_back(interType::NO_INTER);}

        elements.matr_i.push_back(nouv_vect);
        elements.elem_names=nouv_list;
        //==============
    }
    if(nouv_list.size()<elements.elem_names.size())
    {
        //indice du disparu
        int ind_disp;
        for(unsigned int i=0;i<elements.elem_names.size();i++)
        {
            auto it=find(nouv_list.begin(),nouv_list.end(),elements.elem_names[i]);
            if(it == nouv_list.end())
            {
                ind_disp=i;
                break;
            }
        }

        //=========
        //aj_matr_i=======
        for(unsigned int i=0;i<elements.matr_i.size();i++)
        {
            elements.matr_i[i].erase(elements.matr_i[i].begin()+ind_disp);
        }
        elements.matr_i.erase(elements.matr_i.begin()+ind_disp);
        //==================


        //aj_elem_names========
        elements.elem_names.erase(elements.elem_names.begin()+ind_disp);
        //==============

        //====on ajourne elem_cell_map ==========
        combi.elem_cell_map.erase(ind_disp);
        map<int,int> new_map;
        for(auto &paire: combi.elem_cell_map)
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
        combi.elem_cell_map=new_map;
        //=========================
    }
    emit refreshed(elements,combi.elem_cell_map);

}

void Mng::new_inter(QString s1 ,QString s2 ,interType inter_type)
{
    std::string str1=s1.toStdString();
    std::string str2=s2.toStdString();

    int ind_1;
    int ind_2;

    auto it=find(elements.elem_names.begin(),elements.elem_names.end(),str1);
    ind_1=it-elements.elem_names.begin();

    it=find(elements.elem_names.begin(),elements.elem_names.end(),str2);
    ind_2=it-elements.elem_names.begin();

    elements.matr_i[ind_1][ind_2]=inter_type;
    elements.matr_i[ind_2][ind_1]=inter_type;


    emit refresh_without_circle_disp(elements,combi.elem_cell_map);

}

//===========cell fcts=====================================

//code à revoir ici au niveau de la gestion des paires (la multimap est devenue une map)

void Mng::modif_cell(int index,Pos pos)
{
    ro.cell_pos[index]=pos;
    emit cell_pos_refreshed(ro.cell_pos,combi.elem_cell_map,combi.frozen_cell);
}

void Mng::supr_cell(int index)
{
    ro.cell_pos.erase(ro.cell_pos.begin()+index);

    //on ajourne les cpl======
    //----------------------------------------------------------------------------------------
    ro.cell_pair.erase(index);
    pair<int,int> paire_to_remove;
    bool remove_paire=false;
    for(auto &paire: ro.cell_pair)
    {
        if(paire.second==index)
        {
            paire_to_remove=paire;
            remove_paire=true;
        }
    }
    if(remove_paire)
    {
        ro.cell_pair.erase(paire_to_remove.first);
    }

    //----------------------------------------------------------------------------------------
    map<int,int> mm_copie;
    for(auto &paire: ro.cell_pair)
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
    }
    ro.cell_pair=mm_copie;


    //====on ajourne elem_cell_map =======
    int  ind_st_to_erase;
    bool is_there_ind=false;
    for(auto &paire:combi.elem_cell_map)
    {
        if(paire.second==index){ind_st_to_erase=paire.first;is_there_ind=true;}
    }

    if(is_there_ind)combi.elem_cell_map.erase(ind_st_to_erase);

    map<int,int> new_map;
    for(auto &paire: combi.elem_cell_map)
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
    combi.elem_cell_map=new_map;


    //======on ajourne frozen_cell==========
    set<int> new_set;

    for(auto b:combi.frozen_cell)
    {
        if(b>index) new_set.insert(b-1);
        if(b<index) new_set.insert(b);
        //if egale -> rien ...
    }
    combi.frozen_cell=new_set;


    //=========================
    emit cell_pos_refreshed(ro.cell_pos,combi.elem_cell_map,combi.frozen_cell);
    emit cell_map_refreshed(ro.cell_pair);
}


void Mng::add_cell(Pos pos)
{

    ro.cell_pos.push_back(pos);
    emit cell_pos_refreshed(ro.cell_pos,combi.elem_cell_map,combi.frozen_cell);

}


void Mng::add_cpl(int i_1,int i_2)
{
    pair<int,int> p(i_1,i_2);
    pair<int,int> p_2(i_2,i_1);

    ro.cell_pair.insert(p);
    ro.cell_pair.insert(p_2);

    emit cell_map_refreshed(ro.cell_pair);
}




void Mng::supr_cpl(int i_1,int i_2) 
{
    pair<int,int> paire_to_remove;
    pair<int,int> paire_to_remove_2;

    for(auto &paire: ro.cell_pair)
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
    ro.cell_pair.erase(paire_to_remove.first);
    ro.cell_pair.erase(paire_to_remove_2.first);

    emit cell_map_refreshed(ro.cell_pair);
}



void Mng::aj_elem_cell_map(QString qstr_n,int ind_cell)//rajoute ou remplace une paire elem_cell_map
{

    auto it=find(elements.elem_names.begin(),elements.elem_names.end(),qstr_n.toStdString());
    int ind_n=it-elements.elem_names.begin();

    pair<int,int>  new_pair(ind_n,ind_cell);
    combi.elem_cell_map.erase(ind_n);//et s'il n'y en a pas ?
    combi.elem_cell_map.insert(new_pair);
}



void Mng::elem_cell_map_supr(QString qstr_n)
{
    auto it=find(elements.elem_names.begin(),elements.elem_names.end(),qstr_n.toStdString());
    int ind_n=it-elements.elem_names.begin();
    combi.elem_cell_map.erase(ind_n);
}


void Mng::ad_frozen_cell(int i)
{
    combi.frozen_cell.insert(i);
}


void Mng::supr_frozen_cell(int i)
{
    combi.frozen_cell.erase(i);
}



void Mng::lancer_calc()
{

    //crea_combi_ready
    Combi cr;
    cr=crea_combi_ready();

    //crea datazone
    DataZone Dz(cr);

    //lancer thread
    CalculThread * myThread=new CalculThread(Dz);
    connect(myThread,SIGNAL(fin_ag(vector<int>)),this,SLOT(place_elem(vector<int>)));
    connect(myThread, &QThread::finished, myThread, &QObject::deleteLater); // is it correct ?
    myThread->start();

}



Combi Mng::crea_combi_ready()
{
    Combi combi_r;
    combi_r.elements=elements;
    combi_r.space=ro;
    combi_r.elem_cell_map=combi.elem_cell_map;



    //supression des frozen_cell

    int cpt_bur_spr=0;
    for(auto ind: combi.frozen_cell)
    {
        cout<<ind<<endl;
        supr_cell(ind-cpt_bur_spr,combi_r);
        cpt_bur_spr++;
    }


    //decalage des ind cell (l'ag les traites à partir de l'ind 1) // pas top
    Pos p_vide;
    combi_r.space.cell_pos.insert(combi_r.space.cell_pos.begin(),p_vide);
    //...........
    map<int,int> new_map;
    for(auto &paire: combi_r.space.cell_pair)
    {
        pair<int,int> new_paire(paire.first+1,paire.second+1);
        new_map.insert(new_paire);
    }
    combi_r.space.cell_pair=new_map;
    //..........

    map<int,int> new_map_elem_cell_map;
    for(auto &paire: combi_r.elem_cell_map)
    {
        pair<int,int> new_paire(paire.first,paire.second+1);
        new_map_elem_cell_map.insert(new_paire);
    }
    combi_r.elem_cell_map=new_map_elem_cell_map;
    //====
    return combi_r;
}


void Mng::supr_cell(int index,Combi &comb)
{
    comb.space.cell_pos.erase(comb.space.cell_pos.begin()+index);

    //on ajourne les cpl======
    //----------------------------------------------------------------------------------------
    comb.space.cell_pair.erase(index);
    pair<int,int> paire_to_remove;//en pratique une cell n'a qu'une paire...
    bool remove_paire=false;
    for(auto &paire: comb.space.cell_pair)
    {
        if(paire.second==index)
        {
            paire_to_remove=paire;
            remove_paire=true;
        }
    }//sortie for
    if(remove_paire)
    {
        comb.space.cell_pair.erase(paire_to_remove.first);
    }

    //----------------------------------------------------------------------------------------
    map<int,int> mm_copie;
    for(auto &paire: comb.space.cell_pair)
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
    }
    comb.space.cell_pair=mm_copie;


    map<int,int> new_map;
    for(auto &paire: comb.elem_cell_map)
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
    comb.elem_cell_map=new_map;

}



void Mng::place_elem(vector<int> gen)
{
    //redecaler les indices des cells
    for(unsigned int i=0;i<gen.size();i++){gen[i]--;}

    //remapper les resultats en rajoutant les cells manquantes
    for(auto ind: combi.frozen_cell)
    {
        for (unsigned int i=0;i<gen.size();i++){if(gen[i]>=ind)gen[i]++;}
    }

    combi.elem_cell_map.clear();
    for (unsigned int i=0;i<gen.size();i++)
    {
        pair<int,int> newpair(i,gen[i]);
        combi.elem_cell_map.insert(newpair);

    }

    emit make_refresh(elements,combi.elem_cell_map);
}



void Mng::creer_fichier()//faire tout ça dans mng avant le slot serait mieux
{

    fileName="/home/remi/reugq/fich_debug/essai";


    //on nettoie le fichier record_indiv_err

    QFile file("/home/remi/reugq/fich_debug/record_indiv_err");
    file.open(QFile::WriteOnly|QFile::Text|QFile::Truncate);
    QTextStream out_text(&file);
    out_text<< Qt::endl;
    file.close();
}
