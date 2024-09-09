
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

    connect(fenRes,SIGNAL(sub_cpt_freeze_fenres()),this,SLOT(sub_cpt_freeze_fenres()));
    connect(fenI,SIGNAL(sub_cpt_freeze_fenres()),this,SLOT(sub_cpt_freeze_fenres()));

    connect(feNa,SIGNAL(aj_list(QList<QString>)),this,SLOT(rfsh_elem_space(QList<QString>)));

    connect(fenI,SIGNAL(new_inter(QString,QString,interType)),this,SLOT(new_inter(QString,QString,interType)));


    connect(fenRo,SIGNAL(modif_cell(int,Pos)),this,SLOT(modif_cell(int,Pos)));
    connect(fenRo,SIGNAL(supr_cell(int)),this,SLOT(supr_cell(int)));
    connect(fenRo,SIGNAL(add_cell(Pos)),this,SLOT(add_cell(Pos)));
    connect(fenRo,SIGNAL(add_cpl(int,int)),this,SLOT(add_cpl(int,int)));
    connect(fenRo,SIGNAL(supr_cpl(int,int)),this,SLOT(supr_cpl(int,int)));

    connect(fenRes,SIGNAL(aj_elem_cell_map(QString,int)),mng,SLOT(aj_elem_cell_map(QString,int)));
    connect(fenRes,SIGNAL(elem_cell_map_supr(QString)),mng,SLOT(elem_cell_map_supr(QString)));

    connect(fenRes,SIGNAL(ad_frozen_cell(int)),mng,SLOT(ad_frozen_cell(int)));//Slot à faire
    connect(fenRes,SIGNAL(supr_frozen_cell(int)),mng,SLOT(supr_frozen_cell(int)));//Slot à faire


    qRegisterMetaType< Elements >("Elements");

    connect(mng,SIGNAL(ajourned(Elements,std::map<int,int>)),this,SLOT(aff_cercle(Elements)));
    connect(mng,SIGNAL(ajourned(Elements,std::map<int,int>)),fenRes,SLOT(ajourner(Elements,std::map<int,int>)));
    connect(mng,SIGNAL(ajourner_sans_reaff_cercle(Elements,std::map<int,int>)),fenRes,SLOT(ajourner(Elements,std::map<int,int>)));
    connect(mng,SIGNAL(cell_pos_ajourned(std::vector<Pos>,std::map<int,int>,std::set<int>)),fenRes,SLOT(ajourner_bu(std::vector<Pos>,std::map<int,int>,std::set<int>)));
    connect(mng,SIGNAL(bmmp_ajourned(std::map<int,int>)),fenRes,SLOT(ajourner_mm(std::map<int,int>)));

    connect(mng,SIGNAL(make_refresh(Elements,std::map<int,int>)),this,SLOT(make_refresh(Elements,std::map<int,int>)));

    connect(fenRes,SIGNAL(lancer_calc()),mng,SLOT(lancer_calc()));//todo: geler toutes les fenetres


}



void GlobF::setMode( GlobMode gM)
{
    GlobMode old_mode=mode;
    mode=gM;
    close_old_mode(old_mode);

    switch(mode)
    {
    case GlobMode::FENA:
        gVLayout->addWidget(feNa);
        gVLayout->setStretchFactor(fenGlobBut,1);
        gVLayout->setStretchFactor(feNa,80);
        feNa->show();
        break;
    case GlobMode::FENI:
        gVLayout->addWidget(fenI);
        gVLayout->setStretchFactor(fenGlobBut,1);
        gVLayout->setStretchFactor(fenI,80);
        fenI->show();
        break;
    case GlobMode::FENRO:
        gVLayout->addWidget(fenRo);
        gVLayout->setStretchFactor(fenGlobBut,1);
        gVLayout->setStretchFactor(fenRo,80);
        fenRo->show();
        break;
    case GlobMode::FENRES:
        gVLayout->addWidget(fenRes);
        gVLayout->setStretchFactor(fenGlobBut,1);
        gVLayout->setStretchFactor(fenRes,80);
        fenRes->show();
        break;

    }
}

void GlobF::close_old_mode(GlobMode old_mode)
{
    switch(old_mode)
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
    m_mode=GlobMode::FENA;
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
        bout->setChecked(true);
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

