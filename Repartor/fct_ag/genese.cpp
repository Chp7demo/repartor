#include "genese.h"


using namespace std;



vector<int> genere_indiv(const DataZone & dZ)
{

    vector<int> indiv(dZ.N_Elem); // index-> un elem , valeur-> une cell ( indice_de_cell=indiv[un_elem] )

    vector<int> Cellindlist;
    for(int i=1;i<=dZ.N_Cell;i++)Cellindlist.push_back(i);

    vector<int> elem_ind_list=dZ.vect_ordo;

    std::map<int,int> cell_pair_map_av=dZ.cell_pair_map;

    for(auto m_p : dZ.elem_cell_map)
    {

        indiv[m_p.first]=m_p.second;
        Cellindlist.erase(find(Cellindlist.begin(),Cellindlist.end(),m_p.second));

        // effacer paire dans cell_pair_map_av si c'est une cell de paire!!!
        if(cell_have_pair_av(m_p.second,cell_pair_map_av))
        {
            auto it=cell_pair_map_av.find(m_p.second);
            int ind_bp=it->second;
            cell_pair_map_av.erase(it);
            it=cell_pair_map_av.find(ind_bp);
            cell_pair_map_av.erase(it);

        }
        elem_ind_list.erase(find(elem_ind_list.begin(),elem_ind_list.end(),m_p.first));
    }


    //les elems avec des cpl seront traités avant car elem_ind est ordo
    while(elem_ind_list.size()!=0)
    {

        int a=rand_a_b(0,Cellindlist.size());
        while(elem_have_pair(elem_ind_list.at(0),dZ)&&(!cell_have_pair_av(Cellindlist.at(a),cell_pair_map_av)))
        {
            a=a+1-(((int) (a+1)/(Cellindlist.size()))*Cellindlist.size());//?? pas optimal!!!
        }

        int Cellind=Cellindlist.at(a);

        Cellindlist.erase(Cellindlist.begin()+a);

        indiv[elem_ind_list.at(0)]=Cellind;


        if(elem_have_pair(elem_ind_list.at(0),dZ))
        {

            int bp=get_a_cell_pair(Cellind,cell_pair_map_av);//efface ds cell_pair_map_av...
            int st_pair=get_elem_pair(elem_ind_list.at(0),dZ);
            indiv[st_pair]=bp;
            Cellindlist.erase(find(Cellindlist.begin(),Cellindlist.end(),bp));
            elem_ind_list.erase(find(elem_ind_list.begin(),elem_ind_list.end(),st_pair));
        }

        elem_ind_list.erase(elem_ind_list.begin());
    }

    return indiv;
}


int get_a_cell_pair(int Cellind,std::map<int,int> &cell_pair_map_av)
{
    auto itlow=cell_pair_map_av.lower_bound(Cellind);
    int ctrk=cell_pair_map_av.count(Cellind);
    if(ctrk==0)return 0;
    int a=rand_a_b(0,ctrk);
    for(int i=0;i<a;i++){itlow++;}
    int cell_value=itlow->second;
    eff_pairs(Cellind,cell_pair_map_av);
    return cell_value;
}


void eff_pairs(int Cellind,std::map<int,int> &cell_pair_map_av)//pas optimal non?
{
    auto p=cell_pair_map_av.begin();
    while(p!=cell_pair_map_av.end())
    {
        if((p->first==Cellind)||(p->second==Cellind)){
            p = cell_pair_map_av.erase(p);
        }
        else{p++;}
    }
}


bool cell_have_pair_av(int Cellind,const std::map<int,int> &cell_pair_map_av)
{
    auto it_pair=cell_pair_map_av.equal_range(Cellind);
    return(!(it_pair.first==it_pair.second));//???
}


bool elem_have_pair(int elem_ind,const DataZone & dZ)
{
    return(!(dZ.cpl_map.find(elem_ind)==dZ.cpl_map.end()));
}


int get_elem_pair(int elem_ind,const DataZone & dZ)
{
    auto it=dZ.cpl_map.find(elem_ind);
    return(it->second);
}


bool cpl_in_elem_cell_map(int elem_ind,const DataZone & dZ)
{
    int fd=get_elem_pair(elem_ind,dZ);
    return(!((dZ.elem_cell_map.find(fd))==(dZ.elem_cell_map.end())));
}

