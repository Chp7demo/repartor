#include "evaluation.h"

using namespace std;


double evaluation(const vector<int> & vect,const DataZone & dZ)
{

    double score=0;

    //==============
    for(int i=0;i<dZ.N_Elem;i++)
    {
        for(int j=i+1;j<dZ.N_Elem;j++)
        {
            switch (dZ.mi[i][j]) {
            case (interType::BRING_CLOSE):
                score+=formule_score_moins(dZ.D_max,dZ.cell_pos.at(vect.at(i)),dZ.cell_pos.at(vect.at(j)));
                break;
            case(interType::BRING_VERY_CLOSE):
                score+=2*formule_score_moins(dZ.D_max,dZ.cell_pos.at(vect.at(i)),dZ.cell_pos.at(vect.at(j)));
                break;
            case(interType::SPLIT):
                score+=formule_score_plus(dZ.D_max,dZ.cell_pos.at(vect.at(i)),dZ.cell_pos.at(vect.at(j)));
                break;
            case(interType::SPLIT_FAR):
                score+=2*formule_score_plus(dZ.D_max,dZ.cell_pos.at(vect.at(i)),dZ.cell_pos.at(vect.at(j)));
                break;
            default:
                break;
            }
        }
    }

    //fitness:
    return score;


}


double distance(Pos pos_1,Pos pos_2)
{
    return sqrt(pow(pos_1.x-pos_2.x,2)+pow(pos_1.y-pos_2.y,2));
}


double formule_score_plus(double d_max,Pos p1,Pos p2)
{
    return distance(p1,p2)/(d_max);
}


double formule_score_moins(double d_max,Pos p1,Pos p2)
{
    return (1-distance(p1,p2)/(d_max));
}




