#ifndef GLOBF_H
#define GLOBF_H


#include "Fena/FeNa.h"
#include "Feni/FenI.h"
#include "Fenres/FenRes.h"

#include  "Mng.h"

enum class GlobMode{FENA,FENI,FENRO,FENRES};

   
class MonBoutGlob : public QPushButton
{
Q_OBJECT
  public:
	MonBoutGlob();
  GlobMode mode();
  void setMode(GlobMode);
  public slots:
  void envoyer_click();
   signals:
  void mon_clicked(MonBoutGlob*);
    private:
  GlobMode m_mode;
 };

class FenGlobBut :  public QWidget 
{

    Q_OBJECT

    public:
	FenGlobBut();
    void freeze_fenres();
    void unfreeze();
     public slots:
    void  aj_but(MonBoutGlob *);
      signals:
   void aj_mode(GlobMode);

    private:
 
   void uncheck_others(MonBoutGlob *);

QList<MonBoutGlob *> list_but;
   // QPushButton *butBur;
   // QPushButton *butCpl;
    QHBoxLayout *vLayout;//avnat c'estat une Vbox...

  

};

class GlobF :  public QWidget 
{

    Q_OBJECT

    public:
	GlobF();


    public slots:
  void setMode(GlobMode);
    void aff_cercle(Elements sc,std::map<int,int> mp){fenI->aff_cercle(sc);}
    void add_cpt_freeze_fenres(){cpt_freeze_fenres++;fenGlobBut->freeze_fenres();}//en fait on freeze tout les boutons...pas que fenres.../useless
    void sous_cpt_freeze_fenres(){cpt_freeze_fenres--;std::cout<<"cpt_freeze: "<<cpt_freeze_fenres<<std::endl;if(cpt_freeze_fenres==0)fenGlobBut->unfreeze();}///*debug*/lab_cpt_1->setValue(cpt_freeze_fenres);}

  //slot mng en 2 etapes.
    void aj_cl_et_ro(QList<QString> l){cpt_freeze_fenres+=3;fenGlobBut->freeze_fenres();mng->aj_cl_et_ro(l);}///*debug*/cpt_freeze_bis+=3;lab_cpt_1->setValue(cpt_freeze_fenres);lab_cpt_2->setValue(cpt_freeze_bis);}
    void nouv_inter(QString s,QString s2,interType it){cpt_freeze_fenres+=2;fenGlobBut->freeze_fenres();mng->nouv_inter(s,s2,it);}///*debug*/cpt_freeze_bis+=2;lab_cpt_1->setValue(cpt_freeze_fenres);lab_cpt_2->setValue(cpt_freeze_bis);}
    void modif_bur(int i,Pos p){cpt_freeze_fenres+=2;fenGlobBut->freeze_fenres();mng->modif_bur(i,p);}///*debug*/cpt_freeze_bis+=2;lab_cpt_1->setValue(cpt_freeze_fenres);lab_cpt_2->setValue(cpt_freeze_bis);}
    void supr_bur(int i){cpt_freeze_fenres+=3;fenGlobBut->freeze_fenres();mng->supr_bur(i);}///*debug*/cpt_freeze_bis+=3;lab_cpt_1->setValue(cpt_freeze_fenres);lab_cpt_2->setValue(cpt_freeze_bis);}
    void add_bur(Pos p){cpt_freeze_fenres+=2;fenGlobBut->freeze_fenres();mng->add_bur(p);}///*debug*/cpt_freeze_bis+=2;lab_cpt_1->setValue(cpt_freeze_fenres);lab_cpt_2->setValue(cpt_freeze_bis);}
    void add_cpl(int i,int i2){cpt_freeze_fenres++;fenGlobBut->freeze_fenres();mng->add_cpl(i,i2);}///*debug*/cpt_freeze_bis+=1;lab_cpt_1->setValue(cpt_freeze_fenres);lab_cpt_2->setValue(cpt_freeze_bis);}
    void supr_cpl(int i,int i2){cpt_freeze_fenres++;fenGlobBut->freeze_fenres();mng->supr_cpl(i,i2);}///*debug*/cpt_freeze_bis+=1;lab_cpt_1->setValue(cpt_freeze_fenres);lab_cpt_2->setValue(cpt_freeze_bis);}
   //....
   void faire_ajourner(Elements sc,std::map<int,int> mp){cpt_freeze_fenres+=2/*pas sur */;fenRes->ajourner(sc,mp);}
    private:
  void fermer_anc_mode(GlobMode);
    
    FeNa *feNa;
    FenI *fenI;
    FenRo *fenRo;
    FenRes *fenRes;

 int cpt_freeze_fenres;

//======debug===============
 /*
 int cpt_freeze_bis;
QSpinBox *lab_cpt_1;
QSpinBox *lab_cpt_2;
*/
//=========================
    FenGlobBut *fenGlobBut;
    QVBoxLayout *hLayout;//avant c'etait unQHboxlayout d'où le nom!

QScrollArea * scroll_area;

 GlobMode mode; 

 Mng *mng;


};



#endif
