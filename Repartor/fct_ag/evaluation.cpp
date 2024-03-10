#include "evaluation.h"

using namespace std;


double evaluation(const vector<int> & vect,const DataZone & dZ)
{
    //debug===

    cout<<"damx"<<dZ.D_max<<endl;
    //   for(int i=0;i<dZ.bp.size();i++){cout<<dZ.bp[i].x<<" ";}
    //=======
    double score=0;


    double C2=0;//d_min  // variable inutile->à nettoyer
//DEBUG===aff matrice
/*
  cout<<"dZ.N_st : "<<dZ.N_St<<endl;
for(int i=0;i<dZ.N_St;i++)
{
  //  cout<<"pilipili"<<endl;
    cout<<endl;
    for(int j=0;j<dZ.N_St;j++)
    {

 switch (dZ.mi.at(i).at(j)) {
        case (interType::cpl):
                  cout<<"cpl ";
     break;
        case (interType::bav):
                  cout<<"bav ";
     break;
       case (interType::ras):
                  cout<<"--- ";
     break;

        case(interType::gba):
            cout<<"gba ";
                        break;
        case(interType::mes):
               cout<<"mes";
             break;
        case(interType::gme):
             cout<<"gme";
            break;
        default:
       cout<<"???";

            break;
   }
 }
}*/
//==============
for(int i=0;i<dZ.N_St;i++)
{
    for(int j=i+1;j<dZ.N_St;j++)
    {
        switch (dZ.mi[i][j]) {
        case (interType::bav):

            score+=formule_score_moins(dZ.D_max,C2,dZ.bp.at(vect.at(i)),dZ.bp.at(vect.at(j)));

            break;
        case(interType::gba):
                 score+=2*formule_score_moins(dZ.D_max,C2,dZ.bp.at(vect.at(i)),dZ.bp.at(vect.at(j)));
            break;
        case(interType::mes):
                 score+=formule_score_plus(dZ.D_max,C2,dZ.bp.at(vect.at(i)),dZ.bp.at(vect.at(j)));
             break;
        case(interType::gme):
                 score+=2*formule_score_plus(dZ.D_max,C2,dZ.bp.at(vect.at(i)),dZ.bp.at(vect.at(j)));
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

double formule_score_plus(double d_max, double d_min,Pos p1,Pos p2)
{
   // cout<<"dist plus"<< "dmax "<<distance(p1,p2)<<(d_max)<<endl;
    return distance(p1,p2)/(d_max);
}
double formule_score_moins(double d_max, double d_min,Pos p1,Pos p2)
{
   // cout<<"dist moins"<<"d_max"<<distance(p1,p2)<<(d_max)<<endl;
    return (1-distance(p1,p2)/(d_max));
}




