#include "genese.h"


using namespace std;


//attention confusion dans ce fichier entre cell et elem due à un search and replace raté-> à revoir
vector<int> genere_indiv(const DataZone & dZ)
{

    vector<int> indiv(dZ.N_Elem);
    vector<int> Cellindlist; // cell ok

    for(int i=1;i<=dZ.N_Cell;i++)Cellindlist.push_back(i);
    vector<int> cell_ind_list=dZ.vect_ordo; // elem ?

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
        cell_ind_list.erase(find(cell_ind_list.begin(),cell_ind_list.end(),m_p.first));
    }


    //les elems avec des cpl seront traités avant car cell_ind est ordo
    while(cell_ind_list.size()!=0)
    {

        int a=rand_a_b(0,Cellindlist.size());
        while(elem_have_pair(cell_ind_list.at(0),dZ)&&(!cell_have_pair_av(Cellindlist.at(a),cell_pair_map_av)))
        {
            a=a+1-(((int) (a+1)/(Cellindlist.size()))*Cellindlist.size());//?? pas optimal!!!
        }

        int bur_ind=Cellindlist.at(a);

        Cellindlist.erase(Cellindlist.begin()+a);

        indiv[cell_ind_list.at(0)]=bur_ind;


        if(elem_have_pair(cell_ind_list.at(0),dZ))
        {

            int bp=get_a_cell_pair(bur_ind,cell_pair_map_av);//efface ds cell_pair_map_av...
            int st_pair=get_elem_pair(cell_ind_list.at(0),dZ);
            indiv[st_pair]=bp;
            Cellindlist.erase(find(Cellindlist.begin(),Cellindlist.end(),bp));
            cell_ind_list.erase(find(cell_ind_list.begin(),cell_ind_list.end(),st_pair));
        }

        cell_ind_list.erase(cell_ind_list.begin());
    }

    return indiv;
}


int get_a_cell_pair(int bur_ind,std::map<int,int> &cell_pair_map_av)
{
    auto itlow=cell_pair_map_av.lower_bound(bur_ind);
    int ctrk=cell_pair_map_av.count(bur_ind);
    if(ctrk==0)return 0;
    int a=rand_a_b(0,ctrk);
    for(int i=0;i<a;i++){itlow++;}
    int bur_value=itlow->second;
    eff_pairs(bur_ind,cell_pair_map_av);
    return bur_value;
}


void eff_pairs(int bur_ind,std::map<int,int> &cell_pair_map_av)//pas optimal non?
{
    auto p=cell_pair_map_av.begin();
    while(p!=cell_pair_map_av.end())
    {
        if((p->first==bur_ind)||(p->second==bur_ind)){
            p = cell_pair_map_av.erase(p);
        }
        else{p++;}
    }
}


bool cell_have_pair_av(int bur_ind,const std::map<int,int> &cell_pair_map_av)
{
    auto it_pair=cell_pair_map_av.equal_range(bur_ind);
    return(!(it_pair.first==it_pair.second));//???
}


bool elem_have_pair(int cell_ind,const DataZone & dZ)
{
    return(!(dZ.cpl_map.find(cell_ind)==dZ.cpl_map.end()));
}


int get_elem_pair(int cell_ind,const DataZone & dZ)
{
    auto it=dZ.cpl_map.find(cell_ind);
    return(it->second);
}


bool cpl_in_elem_cell_map(int cell_ind,const DataZone & dZ)
{
    int fd=get_elem_pair(cell_ind,dZ);
    return(!((dZ.elem_cell_map.find(fd))==(dZ.elem_cell_map.end())));
}

