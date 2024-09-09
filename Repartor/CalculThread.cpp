#include "CalculThread.h"

void CalculThread::run()
{

   double fit_max;

   //==============
   //param de l'ag
   int N=502;// N nombre fixe d'individu à chaque générations./doit être pair
   int N_g=1000;// N_g nombre de générations fixe
   int N_el=1;// nombre de meilleurs individus directements transmits  d'un gene à l'autre//1? //impair<-?
   double P_crois=0.6;// probabilité de croisement lors de reproduction d'un couple//0.6?
   double P_mut=0.005;// proba de mutation sur un indiv
   double K_roul=0.15;//coeff rang-largeur roulette //largeur additionelle en fait//à equilibrer en fct de N...

   double d_roul_tot=0;
   for(int i=0;i<N;i++) {d_roul_tot+=1+K_roul*i;}

   int  ng=0;//generation en cours
   vector<int> best_g;//pr stocker le meilleur indiv de chaque g

   //genese
   vector<vector<int>> pop={};


   for (int i=0;i<N;i++)
   {
       pop.push_back(genere_indiv(dZ));
   }

   //check_pop(pop,dZ);


   //debut boucle
   //...........................................................................
   for(int i=0;i<N_g;i++)
   {
       //cout<<"ng : "<<ng<<endl;

       //evaluation
       vector<double> eval_pop={};
       for(int j=0;j<N;j++) eval_pop.push_back(evaluation(pop.at(j),dZ));

       //evaluation de la fitness moyenne, et du meilleur sore
       fit_max=0;

       for(int j=0;j<N;j++) {if(eval_pop.at(j)>fit_max){fit_max=eval_pop.at(j);};}


       // on ordonne la population
       vector<vector<int>> pop_ordo={};

       //boucle suivante à optimiser voir les fct c++
       while(pop_ordo.size()<pop.size())
       {
           int ind_fit_max=0;
           for(int j=0;j<N;j++)
           {
               if(eval_pop.at(j)>eval_pop.at(ind_fit_max)){ind_fit_max=j;}
           }
               pop_ordo.push_back(pop.at(ind_fit_max));
               eval_pop[ind_fit_max]=-1;//on a plus besoin des fitness on fait un classement par rang...
       }

       // selection de N_el indiv pour elitisme //on garde le genome //1 seul en fait
       best_g=pop_ordo.at(0);


       //...........................................................................
       // selection par rang-roulette//selection de N/2-Nel individus
       pop.clear();


       for (int id=0;id<N/2-N_el;id++)//50
       {
           int ind_rd=rand_a_b(0,1000);
           double d_roul_tire=d_roul_tot*(((double) ind_rd)/( (double) 1000));
           int ind_choisi=0;
           double seuil=1+(N-1)*K_roul;
           for(int jd=0;jd<N;jd++){if (d_roul_tire<seuil){ind_choisi=jd;break;}else{seuil+=1+(N-(jd+2))*K_roul;}}
           pop.push_back(pop_ordo.at(ind_choisi));
       }
       //formation de (N/2-N_el)/2 couples
       // cout<<"formation N/2 cpl"<<endl;

       vector<vector<int>> pop_couples={};
       while(pop.size()>1){int ind_pif=rand_a_b(0,pop.size()-1); pop_couples.push_back(pop.at(ind_pif));pop.erase(pop.begin()+ind_pif);
           //cout<<"pop.size()"<<pop.size()<<endl;
       }
       pop_couples.push_back(pop.at(0));
       pop.clear();
       //croisement //  naissance de deux fils avec proba de croisement de P_crois// N/2-N_el nouv indiv crées...
       // cout<<"croisements"<<endl;

       // pop.clear();//normalemnent c'est deja le cas !?
       for(unsigned int id=0;id<pop_couples.size();id+=2)
       {
           pop.push_back(pop_couples.at(id));
           pop.push_back(pop_couples.at(id+1));
           if(((double) (rand_a_b(0,1000)/1000))<=P_crois){cross_over(pop.at(id),pop.at(id+1),dZ);}
       }
       //DEBUG======
       //check_pop(pop,dZ);
       //==========

       //reunion des deux ensembles
       // cout<<"reunion"<<endl;

       for(unsigned int id=0;id<pop_couples.size();id++)
       {
           pop.push_back(pop_couples.at(id));
       }
       //mutations  sur chaque indiv avec proba P_mut  comprise entre 0.001 et 0.01//attention les parent mutent aussi  c'est pas ressemnblant à la nature
       // cout<<"mutations"<<endl;

       for(unsigned int id=0;id<pop.size();id++)
       {
           //cout<< ((double) rand_a_b(0,1000))/1000<<endl;
           if((((double) rand_a_b(0,1000))/1000)<=P_mut){mutation(pop.at(id),dZ);/*cout<<"mutation"<<endl;*/}
       }
       // cout<<"ap_mutation"<<endl;

       //DEBUG======
       //check_pop(pop,dZ);
       //==========
       //reintroduction des N_el
       //  cout<<"on remet best g"<<endl;

       pop.push_back(best_g);
       // introduction de N_int nouveau indiv aux hasard//un seul pr l'instant
       //  cout<<"on reintroduit un type"<<endl;

       pop.push_back(genere_indiv(dZ));
       ng++;
   }
   //............................................................................
   //sortie boucle AG // critere d 'arret : nb de geneartion fixe

   // best_g=;
   emit fin_ag(best_g);
}

