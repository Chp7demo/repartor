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

    QList<MonBoutGlob *> list_but;    // checker gestion mémoire
    QHBoxLayout *vLayout;

};


class GlobF :  public QWidget 
{

    Q_OBJECT

public:
    GlobF();


public slots:
    void setMode(GlobMode);
    void aff_cercle(Elements sc){fenI->aff_cercle(sc);}
    void add_cpt_freeze_fenres(){cpt_freeze_fenres++;fenGlobBut->freeze_fenres();}//en fait on freeze tout les boutons...pas que fenres.../useless
    void sub_cpt_freeze_fenres(){cpt_freeze_fenres--;std::cout<<"cpt_freeze: "<<cpt_freeze_fenres<<std::endl;if(cpt_freeze_fenres==0)fenGlobBut->unfreeze();}

    //slot mng en 2 etapes.
    void rfsh_elem_space(QList<QString> l){cpt_freeze_fenres+=3;fenGlobBut->freeze_fenres();mng->rfsh_elem_space(l);}
    void new_inter(QString s,QString s2,interType it){cpt_freeze_fenres+=2;fenGlobBut->freeze_fenres();mng->new_inter(s,s2,it);}
    void modif_cell(int i,Pos p){cpt_freeze_fenres+=2;fenGlobBut->freeze_fenres();mng->modif_cell(i,p);}
    void supr_cell(int i){cpt_freeze_fenres+=3;fenGlobBut->freeze_fenres();mng->supr_cell(i);}
    void add_cell(Pos p){cpt_freeze_fenres+=2;fenGlobBut->freeze_fenres();mng->add_cell(p);}
    void add_cpl(int i,int i2){cpt_freeze_fenres++;fenGlobBut->freeze_fenres();mng->add_cpl(i,i2);}
    void supr_cpl(int i,int i2){cpt_freeze_fenres++;fenGlobBut->freeze_fenres();mng->supr_cpl(i,i2);}
    //....

    void make_refresh(Elements sc,std::map<int,int> mp){cpt_freeze_fenres+=2/*pas sur */;fenRes->ajourner(sc,mp);}

private:
    void close_old_mode(GlobMode);
    
    FeNa *feNa;
    FenI *fenI;
    FenRo *fenRo;
    FenRes *fenRes;

    int cpt_freeze_fenres;

    FenGlobBut *fenGlobBut;
    QVBoxLayout *gVLayout;

    QScrollArea * scroll_area;

    GlobMode mode;

    Mng *mng;


};



#endif
