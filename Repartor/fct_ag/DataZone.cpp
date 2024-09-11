#include "DataZone.h"

DataZone::DataZone(const Combi &combi)
{
    N_Elem=combi.elements.elem_names.size();
    N_Cell=combi.space.cell_pos.size()-1;//0 -> useless
    cell_pair_map=combi.space.cell_pair;
    elem_cell_map=combi.elem_cell_map;
    cpl_map=from_matr_to_cpl_map(combi.elements.matr_i);

    vect_ordo=create_ordo();
    vect_desordo=create_desordo();

    //pour evaluation======
    mi=combi.elements.matr_i;


    cell_pos=combi.space.cell_pos;


    //distance max et min

    double d_max=0;
    double d_min=0;

    for(unsigned int i=0;i<cell_pos.size();i++)
    {
        for(unsigned int j=i+1;j<cell_pos.size();j++)
        {

            double a_x = cell_pos.at(i).x;
            double b_x = cell_pos.at(j).x;
            double a_y = cell_pos.at(i).y;
            double b_y = cell_pos.at(j).y;

            double dist=sqrt(pow(a_x-b_x,2)+pow(a_y-b_y,2));

            if(dist>d_max){d_max=dist;}
            if(dist<d_min || d_min==0){d_min=dist;}

        }
    }

    D_max=d_max;
    D_min=d_min;
    //===============
}


std::map<int,int>   DataZone::from_matr_to_cpl_map(const MI &matr)
{
    std::map<int,int>  cpl_map;

    for(unsigned int i=1;i<matr.size();i++)
    {
        for(unsigned int j=0;j<matr.at(i).size();j++)
        {
            if(matr.at(i).at(j)==interType::PARTNERS)
            {
                cpl_map[i]=j;
                cpl_map[j]=i;
            }
        }

    }
    return cpl_map;
}


bool DataZone::elem_have_pair(int cell_ind)
{
    return(!(cpl_map.find(cell_ind)==cpl_map.end()));
}


int DataZone::get_elem_pair(int cell_ind)
{
    auto it=cpl_map.find(cell_ind);
    return(it->second);
}

bool DataZone::cpl_in_elem_cell_map(int cell_ind)
{
    int fd=get_elem_pair(cell_ind);
    return(!((elem_cell_map.find(fd))==(elem_cell_map.end())));
}

bool DataZone::in_elem_cell_map(int cell_ind)
{
    return(!((elem_cell_map.find(cell_ind))==(elem_cell_map.end())));
}


vector<int> DataZone::create_ordo()
{
    vector<int> vect_fix;
    vector<int> vect_cpl;
    vector<int> vect_free;

    vector<int> ind_list;
    for(int i=0;i<N_Elem;i++){ind_list.push_back(i);}

    while(ind_list.size()>0)
    {
        if(in_elem_cell_map(ind_list[0]))
        {
            vect_fix.push_back(ind_list[0]);
            if(elem_have_pair(ind_list[0]))
            {
                int nb=get_elem_pair(ind_list[0]);
                vect_fix.push_back(nb);
                ind_list.erase(find(ind_list.begin(),ind_list.end(),nb));
            }
            ind_list.erase(ind_list.begin());
        }
        else
        {
            if((elem_have_pair(ind_list[0]))&&(in_elem_cell_map(get_elem_pair(ind_list[0]))))
            {
                vect_fix.push_back(ind_list[0]);
                int nb=get_elem_pair(ind_list[0]);
                vect_fix.push_back(nb);
                ind_list.erase(find(ind_list.begin(),ind_list.end(),nb));
                ind_list.erase(ind_list.begin());
            }
            if((elem_have_pair(ind_list[0]))&&!(in_elem_cell_map(get_elem_pair(ind_list[0]))))
            {
                vect_cpl.push_back(ind_list[0]);
                int nb=get_elem_pair(ind_list[0]);
                vect_cpl.push_back(nb);
                ind_list.erase(find(ind_list.begin(),ind_list.end(),nb));
                ind_list.erase(ind_list.begin());
            }
            if(!elem_have_pair(ind_list[0]))
            {
                vect_free.push_back(ind_list[0]);
                ind_list.erase(ind_list.begin());
            }

        }
    }//fin while

    N_Fix=vect_fix.size();
    N_Cpl=vect_cpl.size();
    N_Free= vect_free.size();

    vector<int> vect_ord;

    for(auto el:vect_fix){vect_ord.push_back(el);}//merge!!!
    for(auto el:vect_cpl){vect_ord.push_back(el);}
    for(auto el:vect_free){vect_ord.push_back(el);}

    return vect_ord;

}


vector<int> DataZone::create_desordo() // à appeler après create ordo
{
    vector<int> vect_des;
    for(int i=0;i<N_Elem;i++)
    //{vect_des.push_back(i);}
    {
        vect_des.push_back((int) (find(vect_ordo.begin(),vect_ordo.end(),i)-vect_ordo.begin()));// ??
    }
    cout<<"vect_des"<<endl;for(auto el:vect_des){cout<<el<<" ";}cout<<endl;
    return vect_des;
}

