
#include "GlobF.h"

using namespace std; 

GlobF::GlobF() :QWidget()
{
    mng = new Mng;

    feNa=new FeNa();
    fenI=new FenI();
    fenRo=new FenRo();
    fenRes=new FenRes();

    fenGlobBut=new FenGlobBut();
    gVLayout=new QVBoxLayout();

    gVLayout->addWidget(fenGlobBut);
    gVLayout->addWidget(feNa);


    gVLayout->setStretchFactor(fenGlobBut,1);
    gVLayout->setStretchFactor(feNa,80);

    this->setLayout(gVLayout);

    mode=GlobMode::FENA;
    cpt_freeze_fenres=0;
    connect(fenGlobBut,SIGNAL(aj_mode(GlobMode)),this,SLOT(setMode(GlobMode)));

    //===connections manager====================

    connect(fenRes,SIGNAL(sous_cpt_freeze_fenres()),this,SLOT(sous_cpt_freeze_fenres()));
    connect(fenI,SIGNAL(sous_cpt_freeze_fenres()),this,SLOT(sous_cpt_freeze_fenres()));

    connect(feNa,SIGNAL(aj_list(QList<QString>)),this,SLOT(aj_cl_et_ro(QList<QString>)));
    //connect(feNa,SIGNAL(aj_list(QList<QString>)),mng,SLOT(aj_cl_et_ro(QList<QString>)));

    connect(fenI,SIGNAL(nouv_inter(QString,QString,interType)),this,SLOT(nouv_inter(QString,QString,interType)));
    //connect(fenI,SIGNAL(nouv_inter(QString,QString,interType)),mng,SLOT(nouv_inter(QString,QString,interType)));



    connect(fenRo,SIGNAL(modif_bur(int,Pos)),this,SLOT(modif_bur(int,Pos)));
    connect(fenRo,SIGNAL(supr_bur(int)),this,SLOT(supr_bur(int)));
    connect(fenRo,SIGNAL(add_bur(Pos)),this,SLOT(add_bur(Pos)));
    connect(fenRo,SIGNAL(add_cpl(int,int)),this,SLOT(add_cpl(int,int)));
    connect(fenRo,SIGNAL(supr_cpl(int,int)),this,SLOT(supr_cpl(int,int)));
    /*
connect(fenRo,SIGNAL(modif_bur(int,Pos)),mng,SLOT(modif_bur(int,Pos)));
connect(fenRo,SIGNAL(supr_bur(int)),mng,SLOT(supr_bur(int)));
connect(fenRo,SIGNAL(add_bur(Pos)),mng,SLOT(add_bur(Pos)));
connect(fenRo,SIGNAL(add_cpl(int,int)),mng,SLOT(add_cpl(int,int)));
connect(fenRo,SIGNAL(supr_cpl(int,int)),mng,SLOT(supr_cpl(int,int)));
*/

    connect(fenRes,SIGNAL(aj_elem_cell_map(QString,int)),mng,SLOT(aj_elem_cell_map(QString,int)));
    connect(fenRes,SIGNAL(elem_cell_map_supr(QString)),mng,SLOT(elem_cell_map_supr(QString)));

    connect(fenRes,SIGNAL(ad_frozen_cell(int)),mng,SLOT(ad_frozen_cell(int)));//Slot à faire
    connect(fenRes,SIGNAL(supr_frozen_cell(int)),mng,SLOT(supr_frozen_cell(int)));//Slot à faire

    qRegisterMetaType< Elements >("Elements");
    //qRegisterMetaType< Elements >("Elements");
    //qRegisterMetaType< Elements >("Elements");

    connect(mng,SIGNAL(ajourned(Elements,std::map<int,int>)),this,SLOT(aff_cercle(Elements)));
    connect(mng,SIGNAL(ajourned(Elements,std::map<int,int>)),fenRes,SLOT(ajourner(Elements,std::map<int,int>)));
    connect(mng,SIGNAL(ajourner_sans_reaff_cercle(Elements,std::map<int,int>)),fenRes,SLOT(ajourner(Elements,std::map<int,int>)));
    connect(mng,SIGNAL(cell_pos_ajourned(std::vector<Pos>,std::map<int,int>,std::set<int>)),fenRes,SLOT(ajourner_bu(std::vector<Pos>,std::map<int,int>,std::set<int>)));
    connect(mng,SIGNAL(bmmp_ajourned(std::map<int,int>)),fenRes,SLOT(ajourner_mm(std::map<int,int>)));

    connect(mng,SIGNAL(faire_ajourner(Elements,std::map<int,int>)),this,SLOT(faire_ajourner(Elements,std::map<int,int>)));

    connect(fenRes,SIGNAL(lancer_calc()),mng,SLOT(lancer_calc()));//todo: geler toutes les fenetres


}



void GlobF::setMode( GlobMode gM)
{
    GlobMode anc_mode=mode;
    mode=gM;
    fermer_anc_mode(anc_mode);

    switch(mode)
    {
    case GlobMode::FENA:
        gVLayout->addWidget(feNa);
        gVLayout->setStretchFactor(fenGlobBut,1);
        gVLayout->setStretchFactor(feNa,80);
        feNa->show();//utile?
        break;
    case GlobMode::FENI:
        gVLayout->addWidget(fenI);
        gVLayout->setStretchFactor(fenGlobBut,1);
        gVLayout->setStretchFactor(fenI,80);
        fenI->show();//utile?
        break;
    case GlobMode::FENRO:
        gVLayout->addWidget(fenRo);
        gVLayout->setStretchFactor(fenGlobBut,1);
        gVLayout->setStretchFactor(fenRo,80);
        fenRo->show();//utile?
        break;
    case GlobMode::FENRES:
        gVLayout->addWidget(fenRes);
        gVLayout->setStretchFactor(fenGlobBut,1);
        gVLayout->setStretchFactor(fenRes,80);
        fenRes->show();//utile?
        break;

    }
}

void GlobF::fermer_anc_mode(GlobMode anc_mode)
{
    switch(anc_mode)
    {
    case GlobMode::FENA:
        gVLayout->removeWidget(feNa);
        feNa->hide();
        break;
    case GlobMode::FENI:
        gVLayout->removeWidget(fenI);
        fenI->hide();
        break;
    case GlobMode::FENRO:
        gVLayout->removeWidget(fenRo);
        fenRo->hide();
        break;
    case GlobMode::FENRES:
        gVLayout->removeWidget(fenRes);
        fenRes->hide();
        break;

    }
}



MonBoutGlob::MonBoutGlob() :QPushButton()
{
    setFixedSize(100,50);
    this->setFocusPolicy(Qt::NoFocus);
    m_mode=GlobMode::FENA;//c'est pas top comme maniere de programmer...
    connect(this,SIGNAL(clicked()),this,SLOT(envoyer_click()));
}

void MonBoutGlob::envoyer_click()
{
    emit mon_clicked(this);
}

GlobMode MonBoutGlob::mode()
{
    return m_mode;
}
void  MonBoutGlob::setMode(GlobMode md)
{
    m_mode=md;
}

FenGlobBut::FenGlobBut() :QWidget()
{
    // setMinimumSize(100,400);

    vLayout=new QHBoxLayout();

    MonBoutGlob *butFena=new MonBoutGlob();
    butFena->setText("Liste");
    butFena->setMode(GlobMode::FENA);
    butFena->setCheckable(true);//mode actif à l'ouverture
    butFena->setChecked(true);//mode actif à l'ouverture


    MonBoutGlob *butFeni=new MonBoutGlob();
    butFeni->setText("Interactions");
    butFeni->setMode(GlobMode::FENI);
    butFeni->setCheckable(true);//mode actif à l'ouverture

    MonBoutGlob *butFenro=new MonBoutGlob();
    butFenro->setText("Espace");
    butFenro->setMode(GlobMode::FENRO);
    butFenro->setCheckable(true);


    MonBoutGlob *butFenres=new MonBoutGlob();
    butFenres->setText("Résolution");
    butFenres->setMode(GlobMode::FENRES);
    butFenres->setCheckable(true);


    list_but<<butFena<<butFeni<<butFenro<<butFenres;

    vLayout->addWidget(butFena);
    vLayout->addWidget(butFeni);
    vLayout->addWidget(butFenro);
    vLayout->addWidget(butFenres);

    this->setLayout(vLayout);

    connect(butFena,SIGNAL(mon_clicked(MonBoutGlob*)),this, SLOT(aj_but(MonBoutGlob*)));
    connect(butFeni,SIGNAL(mon_clicked(MonBoutGlob*)),this, SLOT(aj_but(MonBoutGlob*)));
    connect(butFenro,SIGNAL(mon_clicked(MonBoutGlob*)),this, SLOT(aj_but(MonBoutGlob*)));
    connect(butFenres,SIGNAL(mon_clicked(MonBoutGlob*)),this, SLOT(aj_but(MonBoutGlob*)));

}

void FenGlobBut::aj_but(MonBoutGlob *bout) 
{
    if(bout->isChecked())
    {
        bout->setChecked(true);//ça fait bizarre ça
        //bout->setDown(true);
        //bout->setAutoDefault(false);
        uncheck_others(bout);
        emit aj_mode(bout->mode());
    }
}

void FenGlobBut::freeze_fenres()//pas que fenres en fait
{
    for(int i=0;i<list_but.size();i++)
    {
        list_but.at(i)->setCheckable(false);
    }
}



void FenGlobBut::unfreeze()
{
    for(int i=0;i<list_but.size();i++)
    {
        list_but.at(i)->setCheckable(true);
    }
    cout<<"unfreezed"<<endl;
}


void FenGlobBut::uncheck_others(MonBoutGlob *bout)
{
    for(int i=0;i<list_but.size();i++)
    {
        if(list_but.at(i)!= bout)
        {
            list_but.at(i)->setChecked(false);
            list_but.at(i)->update();
        }
    }

}

