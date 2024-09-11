#include "FenRes.h"



using namespace std; 

FenRes::FenRes() :QWidget()
{

    moderes=modeRes::NORMALE;

    fenNaRes=new FeNaRes();
    fenDes=new FenDesRes();
    fenBut=new FenButRes();

    hLayout=new QHBoxLayout();

    hLayout->addWidget(fenNaRes);
    hLayout->addWidget(fenDes);
    hLayout->addWidget(fenBut);

    hLayout->setStretchFactor(fenNaRes,1);
    hLayout->setStretchFactor(fenDes,80);
    hLayout->setStretchFactor(fenBut,1);

    this->setLayout(hLayout);

    connect(fenDes->pt_graphView(),SIGNAL(drop_cached()),fenNaRes,SLOT(set_drop_catched()));
    connect(fenDes->pt_graphView(),SIGNAL(aj_elem_cell_map(QString,int)),this,SLOT(emettre_aj_elem_cell_map(QString,int)));

    connect(fenDes->pt_graphView(),SIGNAL(ad_frozen_cell(int)),this,SLOT(emettre_ad_frozen_cell(int)));
    connect(fenDes->pt_graphView(),SIGNAL(supr_frozen_cell(int)),this,SLOT(emettre_supr_frozen_cell(int)));

    connect(fenDes->pt_graphView(),SIGNAL(enlever_st(QString)),fenNaRes->pt_feResNaAff(),SLOT(enlever_st(QString)));
    connect(fenDes->pt_graphView(),SIGNAL(rapatrier_wNRG(QList<QString>)),fenNaRes,SLOT(rapatrier_wNRG(QList<QString>)));
    connect(fenDes->pt_graphView(),SIGNAL(sous()),this,SLOT(emettre_sous()));

    connect(fenNaRes,SIGNAL(drop_locale_catched()),fenDes,SLOT(drop_locale_catched()));
    connect(fenNaRes,SIGNAL(elem_cell_map_supr(QString)),this,SLOT(emettre_elem_cell_map_supr(QString)));
    connect(fenNaRes,SIGNAL(rapatrier(QString)),fenDes->pt_graphView(),SLOT(rapatrier(QString)));
    connect(fenNaRes,SIGNAL(sous()),this,SLOT(emettre_sous()));


    connect(fenBut,SIGNAL(aj_mode(modeRes)),this,SLOT(aj_mode(modeRes)));

    connect(fenNaRes->pt_feResNaAff(),SIGNAL(desact_frozen_cell()),fenBut,SLOT(desact_frozen_cell()));
    connect(fenNaRes->pt_feResNaAff(),SIGNAL(desact_frozen_cell()),fenDes,SLOT(desact_frozen_cell()));
}


FeResNaAff::FeResNaAff() :QWidget()
{
    m_vboxlayout_pr_aff=new QVBoxLayout();
    m_vboxlayout_pr_aff->setAlignment(Qt::AlignCenter);
    m_vboxlayout_pr_aff->setSizeConstraint(QLayout::SetNoConstraint);//utile?
    this->setLayout(m_vboxlayout_pr_aff);

    setAcceptDrops(true);
    connect(this,SIGNAL(aj_post_drop(QString,int)),this,SLOT(aj_post_drop_sl(QString,int)));
}


FenDesRes::FenDesRes() :QWidget()
{
    setMinimumSize(700,400);
    container=new QWidget();
    scroll_area_2=new QScrollArea;
    scroll_area_2->setWidget(container);
    scroll_area_2->setWidgetResizable(true);

    container->setFixedSize(4000,4000);

    graphScene =new QGraphicsScene(QRectF(0,0,4000,4000),this);
    graphView = new MaGraphicsViewRes(graphScene,container);

    //indispensable: ==============================================
    graphView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    graphView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    //===============================================================

    QHBoxLayout *layout =new QHBoxLayout;
    layout->addWidget(graphView);
    layout->setContentsMargins(0,0,0,0);
    container->setLayout(layout);

    QHBoxLayout *layout_2 =new QHBoxLayout;
    layout_2->addWidget(scroll_area_2);
    this->setLayout(layout_2);

}




MonBoutRes_1::MonBoutRes_1() :QPushButton()
{
    setFixedSize(80,70);
}



FenButRes::FenButRes() :QWidget()
{
    setMinimumSize(90,400);

    vLayout=new QVBoxLayout();

    but1=new MonBoutRes_1();
    but1->setText("Résolution");
    but1->setCheckable(true);

    but2=new MonBoutRes_1();
    but2->setText("Geler \n cellule");
    but2->setCheckable(true);

    connect(but2,SIGNAL(clicked()),this,SLOT(aj_mode_res()));
    connect(but1,SIGNAL(clicked()),this,SLOT(mode_calc()));



    vLayout->addWidget(but1);
    vLayout->addWidget(but2);


    this->setLayout(vLayout);

}



MaGraphicsViewRes::MaGraphicsViewRes(QGraphicsScene * scene,QWidget *parent)
    :QGraphicsView(scene,parent)
{
    pt_w_pass=NULL;
    pt_w_a=NULL;
    pt_w_b=NULL;
    setMouseTracking(true);
    setAcceptDrops(true);
    mode=modeRes::NORMALE;

}



void MaGraphicsViewRes::dragEnterEvent(QDragEnterEvent * event)
{
    event->accept();
}


void MaGraphicsViewRes::dragMoveEvent(QDragMoveEvent * event)
{
    //TODO verif format
    QByteArray byte_array=event->mimeData()->data("mon_mime");
    QDataStream dataStream(&byte_array,QIODevice::ReadOnly);
    QString text_received;
    QRectF rect_widg;
    QPointF point_intra;
    dataStream>>text_received>>rect_widg>>point_intra;

    QRectF rect_drop(event->position().x()-point_intra.x(),event->position().y()-point_intra.y(),rect_widg.width(),rect_widg.height());

    QPainterPath painter_path;
    painter_path.addRect(rect_drop);
    WidgCellRes* pt_w=trouve_intersect(painter_path,event->position());

    if (pt_w!=NULL)
    {
        QColor coul;
        coul.setRgb(255,255,102,100);
        if(!pt_w->get_occupe()) pt_w->set_couleur(coul);
    }
    if( pt_w_pass != NULL && pt_w_pass != pt_w)
    {
        QColor coul;
        coul.setRgb(255,255,255,0);
        pt_w_pass->set_couleur(coul);

    }
    pt_w_pass=pt_w;
    event->acceptProposedAction();
}


void MaGraphicsViewRes::dropEvent(QDropEvent * event)
{
    //TODO verif format

    QByteArray byte_array=event->mimeData()->data("mon_mime");
    QDataStream dataStream(&byte_array,QIODevice::ReadOnly);
    QString text_received;
    QRectF rect_widg;
    QPointF point_intra;
    dataStream>>text_received>>rect_widg>>point_intra;//>>pix;

    QRectF rect_drop(event->position().x()-point_intra.x(),event->position().y()-point_intra.y(),rect_widg.width(),rect_widg.height());


    QPainterPath painter_path;
    painter_path.addRect(rect_drop);
    WidgCellRes* pt_w=trouve_intersect(painter_path,event->position());
    if (pt_w!=NULL && !pt_w->get_occupe())
    {

        QString str_cpl=trouve_cpl(text_received,elements_copie);
        if(str_cpl=="")//si pas de cpl...
        {
            emit drop_cached();// catched !?
            aj_drop_catched_locale(true);

            QColor coul;
            coul.setRgb(255,255,255,0);
            pt_w->set_couleur(coul);
            pt_w_pass=NULL;
            widgNRG* wn=creer_widgNRG(text_received,pt_w);
            if(wn->boundingRect().contains(event->position()))wn->set_entered(true);//déjà le cas ?
            else wn->set_entered(false);

        }
        else
        {

            int ind_cell_cpl;
            bool cell_a_un_cpl=false;
            if(mm_copie.count(list_widgCellRes.indexOf(pt_w)))/*pas pt_w->get_index?*/
            {
                ind_cell_cpl=mm_copie.find(list_widgCellRes.indexOf(pt_w))->second;cell_a_un_cpl=true;
            }
            if(!cell_a_un_cpl)
            {
                cout<<"erreur utilisateur: "<<endl;
                QColor coul;
                coul.setRgb(255,255,255,0);
                pt_w->set_couleur(coul);

            }
            else
            {
                if(list_widgCellRes.at(ind_cell_cpl)->get_occupe())//si la cell est occupe
                {
                    cout<<"erreur utilisateur: "<<endl;
                    QColor coul;
                    coul.setRgb(255,255,255,0);
                    pt_w->set_couleur(coul);
                }
                else
                {

                    emit drop_cached();//attention cached/catched !
                    aj_drop_catched_locale(true);

                    QColor coul;
                    coul.setRgb(255,255,255,0);
                    pt_w->set_couleur(coul);
                    pt_w_pass=NULL;
                    widgNRG* wn=creer_widgNRG(text_received,pt_w);
                    if(wn->boundingRect().contains(event->position()))wn->set_entered(true);//c'est déjà le cas il vient d'etre construit
                    else wn->set_entered(false);

                    bool deja_ds_cell=false;
                    int ind_NRG_cpl;

                    for(int i=0;i<list_widgNRG.size();i++)
                    {
                        if(list_widgNRG.at(i)->getN()==str_cpl){deja_ds_cell=true;ind_NRG_cpl=i;}
                    }

                    if(deja_ds_cell)
                    {
                        WidgCellRes* pt_w_cpl_anc=list_widgNRG.at(ind_NRG_cpl)->get_pt_WBR();
                        pt_w_cpl_anc->set_occupe(false);
                        delete list_widgNRG.at(ind_NRG_cpl);
                        list_widgNRG.removeAt(ind_NRG_cpl);
                    }
                    else emit enlever_st(str_cpl);

                    widgNRG* wn_cpl=creer_widgNRG(str_cpl,list_widgCellRes.at(ind_cell_cpl));
                    wn_cpl->set_entered(false);

                }
            }
        }
        //=================================
    }
    event->acceptProposedAction();

}


void MaGraphicsViewRes::mousePressEvent(QMouseEvent * event)
{
    if(mode!=modeRes::FREEZ_CELL)QGraphicsView::mousePressEvent(event);
    else
    {   pt_w_b=NULL;
        pt_w_b=trouve_cell_res(event->pos());

        if(pt_w_b!=NULL && !pt_w_b->get_occupe() && (pt_w_b->getModeCroix()==WidgCellRes::CROIXP))
        {
            pt_w_b->setModeCroix(WidgCellRes::CROIX);
            pt_w_b->set_occupe(true);
            emit ad_frozen_cell(pt_w_b->get_index());
        }
        if(pt_w_b!=NULL/* && !pt_w_b->get_occupe()*/ && (pt_w_b->getModeCroix()==WidgCellRes::CROIXR))
        {
            pt_w_b->setModeCroix(WidgCellRes::NOCROIX);
            pt_w_b->set_occupe(false);
            emit supr_frozen_cell(pt_w_b->get_index());
        }
    }
}


void MaGraphicsViewRes::mouseMoveEvent(QMouseEvent * event)
{
    if(mode!=modeRes::FREEZ_CELL)QGraphicsView::mouseMoveEvent(event);
    else

    {

        pt_w_a=pt_w_b;
        pt_w_b=trouve_cell_res(event->pos());

        if(pt_w_b!=NULL && pt_w_b!=pt_w_a&& !pt_w_b->get_occupe() && (pt_w_b->getModeCroix()==WidgCellRes::NOCROIX))
        {
            pt_w_b->setModeCroix(WidgCellRes::CROIXP);
        }

        if(pt_w_b!=NULL &&pt_w_b!=pt_w_a /*&& !pt_w_b->get_occupe() */&& (pt_w_b->getModeCroix()==WidgCellRes::CROIX))
        {
            pt_w_b->setModeCroix(WidgCellRes::CROIXR);
        }


        if(pt_w_b==NULL && (pt_w_a != NULL /*&& pt_w_a!=pt_w_b && !pt_w_a->get_occupe()*/)&&(pt_w_a->getModeCroix()==WidgCellRes::CROIXR) )
        {
            pt_w_a->setModeCroix(WidgCellRes::CROIX);
        }

        if(pt_w_b==NULL && (pt_w_a != NULL /*&& pt_w_a!=pt_w_b*/&& !pt_w_a->get_occupe())&&(pt_w_a->getModeCroix()==WidgCellRes::CROIXP) )
        {
            pt_w_a->setModeCroix(WidgCellRes::NOCROIX);
        }
    }
}



void MaGraphicsViewRes::mouseReleaseEvent(QMouseEvent *event)
{
    QGraphicsView::mouseReleaseEvent(event);
}


FeNaRes::FeNaRes() :QWidget()
{

    QPalette palette;
    QColor coul;
    coul.setRgb(255,255,255,255);
    palette.setColor(QPalette::Window,coul);
    setPalette(palette);
    setMinimumSize(350,550);

    bl=new QVBoxLayout();

    //=========container N==========================
    m_w_multi_aff=new FeResNaAff();
    m_w_multi_aff->setParent(this);
    m_scroll_multi_aff=new  QScrollArea();
    m_scroll_multi_aff->setWidget(m_w_multi_aff);

    //=================================================
    bl->setAlignment(Qt::AlignCenter);
    bl->setSizeConstraint(QLayout::SetNoConstraint);//utile?
    bl->addWidget(m_scroll_multi_aff);
    bl->setStretchFactor(m_scroll_multi_aff,1);//utile?
    this->setLayout(bl);

    setAcceptDrops(true);

}



widgNRes::widgNRes() :QWidget()
{
    setFixedSize(150,20);
    m_label_N = new QLabel("",this);
    m_label_N -> setFixedSize(100,15);
    m_label_N -> move(this->rect().center().x()-m_label_N->width()/2,this->rect().center().y()-m_label_N->height()/2);
    m_label_N->setAlignment(Qt::AlignCenter);

    QFont font=m_label_N->font();
    font.setPointSize(10);
    
    m_label_N->setFont(font);

}



widgNRes::~widgNRes() 
{
}

void widgNRes::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    QPen pen;
    painter.setPen(pen);
    QRect rect_ajuste(this->rect());
    rect_ajuste.setWidth(rect_ajuste.width()-1);
    rect_ajuste.setHeight(rect_ajuste.height()-1);

    
    QPainterPath path_rect;
    path_rect.addRoundedRect(rect_ajuste,4,4);
    QBrush brosse(Qt::SolidPattern);
    brosse.setColor(color);
    painter.fillPath(path_rect,brosse);
    painter.drawRoundedRect(rect_ajuste,4,4);

}


void widgNRes::setN(QString string_N)
{
    m_label_N->setText(string_N);

    QColor couleur;

    couleur.setRgb(255,255,255,255);

    default_color=couleur;
    color=default_color;
}


void widgNRG::setN(QString string_N)
{
    text_N=string_N;
}


QString widgNRes::getN()
{
    return m_label_N->text();
}


QString widgNRG::getN()
{
    return text_N;
}


void FenRes::ajourner(Elements elements,std::map<int,int> map_elem_cell_map)
{
    fenDes->ajourner(elements,map_elem_cell_map);
    fenNaRes->ajourner(elements,map_elem_cell_map);
} 

void FenDesRes::ajourner(Elements elements,std::map<int,int> map_elem_cell_map)
{
    graphView->ajourner(elements,map_elem_cell_map);
}

void MaGraphicsViewRes::ajourner(Elements elements,std::map<int,int> map_elem_cell_map)
{
    elements_copie=elements;

    //=========================
    //ici on retire l'element eventuellment disparu...//si l ajournement provient d'un supression...
    vector<string> stnm_copie=elements.elem_names;
    if(map_elem_cell_map.size()<list_widgNRG.size())
    {
        //si ds la widgNRG le nom correspondant n'est pas ds les elem_cell_map on le retire
        int ind_widgNRG_to_remove;
        for(int i=0;i<list_widgNRG.size();i++)
        {
            string str=(list_widgNRG.at(i)->getN()).toStdString();

            auto it=std::find(stnm_copie.begin(),stnm_copie.end(),str);
            int ind_st=it-stnm_copie.begin();
            if(map_elem_cell_map.find(ind_st)==map_elem_cell_map.end())
            {
                ind_widgNRG_to_remove=i;break;
            }
        }
        //on libere la cell
        list_widgNRG.at(ind_widgNRG_to_remove)->get_pt_WBR()->set_occupe(false);
        //on enleve le widgNRG de la scene
        scene()->removeItem(list_widgNRG.at(ind_widgNRG_to_remove));//a mettre direct apres le clic c'est plus sur non?
        //on le suprime de la liste et delete
        delete list_widgNRG.at(ind_widgNRG_to_remove);
        list_widgNRG.removeAt(ind_widgNRG_to_remove);
    }

    //si l'ajournement provient d'un placement auto===//attention cette partie n'a pas encore été testée
    if(map_elem_cell_map.size()>list_widgNRG.size())
    {
        for(auto paire: map_elem_cell_map)
        {
            //on trouve le nom du type
            string str=stnm_copie.at(paire.first);

            //on regarde s 'il y a deja un NRG pr cet elem
            bool deja_place=false;
            for(int i=0;i<list_widgNRG.size();i++)
            {
                string str_bis=(list_widgNRG.at(i)->getN()).toStdString();
                if(str==str_bis){deja_place=true;break;}
            }
            if(!deja_place)
            {
                QString str_q;
                str_q=QString::fromStdString(str);

                emit enlever_st(str_q);
                widgNRG* wn=creer_widgNRG(str_q,list_widgCellRes.at(paire.second));
                wn->set_entered(false);
            }
        }
    }
    //=============================
    emit sous();
}


void FeNaRes::ajourner(std::map<int,int> map_elem_cell_map)
{
    ajourner(elements_copie,map_elem_cell_map);

}


void FeNaRes::ajourner(Elements elements,std::map<int,int> map_elem_cell_map)
{
    //elem_cell_map_copie_fenares=map_elem_cell_map;//utile?
    elements_copie=elements;
    int s=N_str_list.size();
    while((m_w_multi_aff->N_list.size())>0)
    {
        int hdel=m_w_multi_aff->N_list.at(0)->height();
        widgNRes *wN=m_w_multi_aff->N_list.last();
        m_w_multi_aff->N_list.removeLast();
        delete wN;
        m_w_multi_aff->resize( m_w_multi_aff->width(),m_w_multi_aff->height()-hdel-10);
    }

    N_str_list.clear();

    //nouvelle liste========
    for(int i=0;i<elements.elem_names.size();i++)
    {
        if(map_elem_cell_map.find(i)==map_elem_cell_map.end())N_str_list.append(QString::fromStdString(elements.elem_names.at(i)));
    }

    //=========ajourner st_map=========================
    QMap<QString,int>::iterator i=st_qmap.begin();
    while(i!=st_qmap.end())
    {
        if(N_str_list.contains(i.key()))i++;
        else st_qmap.erase(i);
    }
    //=======================


    //affichage=============
    for(int i=0;i<N_str_list.size();i++)
    {
        if(!st_qmap.contains(N_str_list.at(i)))//s'il n'est pas deja placé...
        {
            widgNRes *nouv_fen;
            nouv_fen = new widgNRes();
            nouv_fen->setParent(m_w_multi_aff);
            nouv_fen->setN(N_str_list[i]);
            m_w_multi_aff->N_list.push_back(nouv_fen);
            m_w_multi_aff->m_vboxlayout_pr_aff->addWidget(nouv_fen);
            m_w_multi_aff->resize(nouv_fen->width()+10,m_w_multi_aff->height()+nouv_fen->height()+10);
        }
    }

    //===========on rapatrie ceux placé qui ont perdu la cell de leur cpl======
    for(int i=0;i<m_w_multi_aff->N_list.size();i++){rapatrier_cpl_eventuel(m_w_multi_aff->N_list.at(i)->getN());}
    //==================================================

    //update();
    emit sous();
}

//code ci dessous à revoir, utiliser des refs
void FenRes::ajourner_cell(vector<Pos> pos_vect,std::map<int,int> map_elem_cell_map,std::set<int> set_frozen_cell)
{
    fenDes->ajourner_cell(pos_vect,map_elem_cell_map,set_frozen_cell);
    fenNaRes->ajourner(map_elem_cell_map);
}

void FenRes::ajourner_mm(map<int,int> mmp) 
{
    fenDes->ajourner_mm(mmp);
}

void FenDesRes::ajourner_cell(vector<Pos> pos_vect,std::map<int,int> map_elem_cell_map,std::set<int> set_frozen_cell)
{
    graphView->ajourner_cell(pos_vect,map_elem_cell_map,set_frozen_cell);
}

void FenDesRes::ajourner_mm(map<int,int> mmp) 
{
    graphView->ajourner_mm(mmp);
}


void MaGraphicsViewRes::ajourner_cell(vector<Pos> pos_vect,std::map<int,int> map_elem_cell_map,std::set<int> set_frozen_cell)
{

    if(list_widgCellRes.size()==0)
    {
        for(unsigned int i=0;i<pos_vect.size();i++)
        {
            QRectF rect(pos_vect.at(i).x,pos_vect.at(i).y,pos_vect.at(i).largeur,pos_vect.at(i).hauteur);
            WidgCellRes * nouv_wbr=new WidgCellRes(rect);
            list_widgCellRes << nouv_wbr;
            nouv_wbr->set_index(i);//utile?
            nouv_wbr->set_angle(pos_vect.at(i).angle);
            nouv_wbr->rotation(pos_vect.at(i).angle);//lent?
            connect(nouv_wbr,SIGNAL(drop_catched()),this,SLOT(drop_cached_sl()));
            this->scene()->addItem(nouv_wbr);
        }
    }
    else
    {
        for(int i=0;i<list_widgCellRes.size();i++)
        {
            this->scene()->removeItem(list_widgCellRes.at(i));

            delete list_widgCellRes.at(i);
        }
        list_widgCellRes.clear();//??;

        for(int i=0;i<pos_vect.size();i++)
        {
            QRectF rect(pos_vect.at(i).x,pos_vect.at(i).y,pos_vect.at(i).largeur,pos_vect.at(i).hauteur);
            WidgCellRes * nouv_wbr=new WidgCellRes(rect);
            list_widgCellRes << nouv_wbr;
            nouv_wbr->set_index(i);//utile?
            nouv_wbr->set_angle(pos_vect.at(i).angle);
            nouv_wbr->rotation(pos_vect.at(i).angle);//lent?
            nouv_wbr->setZValue(1);
            connect(nouv_wbr,SIGNAL(drop_catched()),this,SLOT(drop_cached_sl()));

            //====frozen_cell
            if(set_frozen_cell.count(i)>0){nouv_wbr->set_occupe(true);nouv_wbr->setModeCroix(WidgCellRes::CROIX);}

            //======
            this->scene()->addItem(nouv_wbr);
        }
    }

    //==================widgNRG================
    //on recupere les pixmap.................
    QMap<QString,QPixmap> map_pix;
    for(int i=0;i<list_widgNRG.size();i++){map_pix.insert(list_widgNRG.at(i)->getN(),list_widgNRG.at(i)->get_pixmap());}
    //....................................................

    for(int i=0;i<list_widgNRG.size();i++){scene()->removeItem(list_widgNRG.at(i));delete list_widgNRG.at(i);}
    list_widgNRG.clear();

    for(int i=0;i<list_widgCellRes.size();i++)//mal codé, peu être plus rapide...
    {
        for(auto &paire:map_elem_cell_map)
        {
            if(paire.second==list_widgCellRes.at(i)->get_index())
            {
                list_widgCellRes.at(i)->set_text(QString::fromStdString(elements_copie.elem_names.at(paire.first)));//useless?
                list_widgCellRes.at(i)->set_occupe(true);

                QRectF rect(list_widgCellRes.at(i)->get_centre().x(),list_widgCellRes.at(i)->get_centre().y(),150,20);//dimensions calquees sur widgNres//pq pas utiliser rect_widg?
                rect.translate(-rect.width()/2,-rect.height()/2);
                widgNRG * nouv_wNRG=new widgNRG(rect);
                nouv_wNRG->setN(QString::fromStdString(elements_copie.elem_names.at(paire.first)));
                nouv_wNRG->set_pixmap(map_pix.value(nouv_wNRG->getN()));//pour stocker l'image en vue d'un futur deplacement
                nouv_wNRG->set_entered(false);
                nouv_wNRG->setZValue(2);
                nouv_wNRG->set_pt_WBR(list_widgCellRes.at(i));
                list_widgNRG<<nouv_wNRG;
                connect(nouv_wNRG,SIGNAL(detruit_moi(widgNRG*)),this,SLOT(detruire_wn(widgNRG*)));
                scene()->addItem(nouv_wNRG);

            }
        }
    }
    //=======================================
    update();
    emit sous();
}

void MaGraphicsViewRes::ajourner_mm(map<int,int> mmp) 
{

    mm_copie=mmp;
    QList<widgNRG*> list_to_supr;

    for(int i=0;i<list_widgNRG.size();i++)
    {

        QString str=trouve_cpl(list_widgNRG.at(i)->getN(),elements_copie);

        if(str!=""&&mmp.find(list_widgNRG.at(i)->get_pt_WBR()->get_index())==mmp.end())
        {
            list_to_supr<<list_widgNRG.at(i);
        }
    }

    QList<QString> list_str_to_supr;
    for(int i=0;i<list_to_supr.size();i++){list_str_to_supr<<list_to_supr.at(i)->getN();}


    for(int i=0;i<list_to_supr.size();i++)
    {
        list_to_supr.at(i)->get_pt_WBR()->set_occupe(false);
        this->scene()->removeItem(list_to_supr.at(i));
        list_widgNRG.removeOne(list_to_supr.at(i));
        delete list_to_supr.at(i);
    }

    emit rapatrier_wNRG(list_str_to_supr);
}


void widgNRes::enterEvent(QEvent * event)
{
    QColor col;
    col.setRgb(255,255,102,100);
    this->set_color(col);
}


void widgNRes::leaveEvent(QEvent * event)
{
    this->set_default_color();
}


void FeResNaAff::mousePressEvent(QMouseEvent * event)
{

    widgNRes *child_N=NULL;

    if(!(child_N=trouve_N(event->pos()))) return;

    emit desact_frozen_cell();

    int ind_lay=N_list.indexOf(child_N);
    QPixmap pixmap=QWidget::grab(child_N->rect());
    QString str=child_N->getN();
    QRectF rect=child_N->rect();

    QByteArray byte_array;
    QDataStream dataStream(&byte_array,QIODevice::WriteOnly);
    dataStream<<str<<rect<<QPointF(event->pos()-child_N->pos());//<<pixmap;

    QMimeData *mimeData=new QMimeData;
    mimeData->setData("mon_mime",byte_array);

    drop_catched=false;

    QDrag *drag=new QDrag(this);
    drag->setMimeData(mimeData);
    drag->setPixmap(pixmap);
    drag->setHotSpot(event->pos()-child_N->pos());
    cacher_widg(child_N);

    drag->exec();
    emit aj_post_drop(str,ind_lay);//emit apres le signal d'un drop reçu...
} 


void FeResNaAff::aj_post_drop_sl(QString str,int ind_lay)
{
    if(!drop_catched)
    {recreer_widg(str,ind_lay);}
    drop_catched=false;
}


void FeResNaAff::recreer_widg(QString nm,int ind_lay)
{

    widgNRes *nouv_fen;
    nouv_fen = new widgNRes();
    nouv_fen->setParent(this);
    nouv_fen->setN(nm);
    N_list.insert(ind_lay,nouv_fen);
    m_vboxlayout_pr_aff->insertWidget(ind_lay,nouv_fen);


    this->resize(nouv_fen->width()+10,this->height()+nouv_fen->height()+10);

}


void FeResNaAff::ajouter_widg(QString nm)
{
    widgNRes *nouv_fen;
    nouv_fen = new widgNRes();
    nouv_fen->setParent(this);
    nouv_fen->setN(nm);
    N_list<<nouv_fen;
    m_vboxlayout_pr_aff->addWidget(nouv_fen);

    this->resize(nouv_fen->width()+10,this->height()+nouv_fen->height()+10);

}


void FeResNaAff::dragMoveEvent(QDragMoveEvent * event)
{

    //TODO accepter seulement un format spécifique
    if(event->source()==this)
    {
        event->setDropAction(Qt::CopyAction);
        event->accept();

    }
    else{event->ignore();
    }
}


void FeNaRes::dragMoveEvent(QDragMoveEvent * event)
{
    event->acceptProposedAction();
}


void FeResNaAff::dropEvent(QDropEvent * event)
{
    event->acceptProposedAction();
}


void FeNaRes::dropEvent(QDropEvent *event)
{
    //TODO verif format

    if(event->source()!=m_w_multi_aff)
    {

        QByteArray byte_array=event->mimeData()->data("mon_mime");
        QDataStream dataStream(&byte_array,QIODevice::ReadOnly);
        QString text_received;
        QRectF rect_widg;
        QPointF point_intra;

        dataStream>>text_received>>rect_widg>>point_intra;//>>pix;
        m_w_multi_aff->ajouter_widg(text_received);
        emit drop_locale_catched();
        emit elem_cell_map_supr(text_received);

        rapatrier_cpl_eventuel(text_received);

    }
    event->acceptProposedAction();

}


//cette fct n'est pas appeleé ?!!
void FeResNaAff::dragEnterEvent(QDragEnterEvent * event)
{

    //TODO accepter seulement un format specifique
    if(event->source()==this)
    {
        event->setDropAction(Qt::CopyAction);
        event->accept();

    }
    else{event->ignore();}

}


void FeNaRes::dragEnterEvent(QDragEnterEvent * event)
{
    event->acceptProposedAction();
}


void widgNRes::set_color(QColor col)
{
    color=col;
    update();
}


void widgNRes::set_default_color()
{
    color=default_color;
    update();
}


void widgNRG::set_color(QColor col)
{
    color=col;
    update();
}

void widgNRG::set_default_color()
{
    color=default_color;
    update();
}


void FeNaRes::cacher_widg(widgNRes *wN)//???
{

    wN->hide();
    int hdel=wN->height();
    m_w_multi_aff->resize( m_w_multi_aff->width(),m_w_multi_aff->height()-hdel-10);
    update();
}


void FeResNaAff::cacher_widg(widgNRes *wN)
{

    int hdel=wN->height();
    wN->hide();
    N_list.removeAt(N_list.indexOf(wN));
    delete wN;
    this->resize( this->width(),this->height()-hdel-10);

    update();
}


widgNRes*  FeResNaAff::trouve_N(const QPoint & point)
{
    for(int i=0;i<N_list.size();i++)
    {
        QRect rect=N_list.at(i)->rect();
        rect.translate(N_list.at(i)->pos().x(),N_list.at(i)->pos().y());
        if(rect.contains(point))return(N_list.at(i));
    }
    return(NULL);
}


void FenRes::set_drop_catched()
{
    fenNaRes->set_drop_catched();
}


void FeNaRes::set_drop_catched()
{
    m_w_multi_aff->set_drop_catched();
}


void FeResNaAff::set_drop_catched()
{
    drop_catched=true;
}


void MaGraphicsViewRes::drop_cached_sl()//cette fonction n'est pas appelee semble il ...
{
    emit drop_cached();
}


void MaGraphicsViewRes::aj_drop_catched_locale(bool b)
{
    for(int i=0;i<list_widgNRG.size();i++)
    {
        list_widgNRG.at(i)->set_drop_catched_locale(b);
    }
}


widgNRG::widgNRG( QRectF rect, QGraphicsItem *parent) :QGraphicsObject(parent)
{

    entered=true;
    rect_ini=rect;
    QColor couleur;

    couleur.setRgb(255,255,210,255);// TODO attention pas le meme bège que les widgNresa ...

    default_color=couleur;
    color=default_color;
    setAcceptHoverEvents(true);

}



QRectF widgNRG::boundingRect() const
{
    return rect_ini;
}



void widgNRG::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    //===============================================
    QPen pen;
    painter->setPen(pen);
    QRectF rect_ajuste(rect_ini);
    rect_ajuste.setWidth(rect_ajuste.width()-1);
    rect_ajuste.setHeight(rect_ajuste.height()-1);

    if(entered)
    {
        QPainterPath path_rect;
        path_rect.addRoundedRect(rect_ajuste,4,4);
        QBrush brosse(Qt::SolidPattern);
        brosse.setColor(color);
        painter->fillPath(path_rect,brosse);
        painter->drawRoundedRect(rect_ajuste,4,4);
    }

    painter->drawText(rect_ini,Qt::AlignCenter,text_N);

    //====================pixmap pr le drag drop==============
    QPixmap pix(rect_ajuste.width()+1,rect_ajuste.height()+1);
    QRectF rect_pix(0,0,rect_ajuste.width(),rect_ajuste.height());
    QPainter painter_pix(&pix);

    //peut on faire une pixmap de forme queconque ?!!
    QColor transp;transp.setRgb(255,255,255,255);//blanc pas transparent... ça marche ne pas sur une pix...
    QBrush brosse_transp(Qt::SolidPattern);
    brosse_transp.setColor(transp);
    painter_pix.fillRect(pix.rect(),brosse_transp);


    QPainterPath path_rect_pix;
    path_rect_pix.addRoundedRect(rect_pix,4,4);
    QBrush brosse_pix(Qt::SolidPattern);
    brosse_pix.setColor(color);

    painter_pix.fillPath(path_rect_pix,brosse_pix);
    painter_pix.drawRoundedRect(rect_pix,4,4);

    painter_pix.drawText(rect_pix,Qt::AlignCenter,text_N);

    m_pixmap=pix;
    //================================================

}


WidgCellRes* MaGraphicsViewRes::trouve_cell_res(QPointF point)
{
    for(int i=0;i<list_widgCellRes.size();i++)
    {
        if(list_widgCellRes.at(i)->shape().contains(point))return(list_widgCellRes.at(i));
    }
    return(NULL);

}


WidgCellRes* MaGraphicsViewRes::trouve_intersect(QPainterPath painter_path,QPointF mouse_pos)
{

    QList<WidgCellRes*> list_inter;
    for(int i=0;i<list_widgCellRes.size();i++)
    {
        if(painter_path.intersects(list_widgCellRes.at(i)->shape())){list_inter<<list_widgCellRes.at(i);}
    }
    if(list_inter.size()==0) return(NULL);

    int ind=0;
    int i=1;

    double d=sqrt(pow(mouse_pos.x()-list_inter.at(0)->get_centre().x(),2)+pow(mouse_pos.y()-list_inter.at(0)->get_centre().y(),2));

    while(i<list_inter.size())
    {

        double dbis=sqrt(pow(mouse_pos.x()-list_inter.at(i)->get_centre().x(),2)+pow(mouse_pos.y()-list_inter.at(i)->get_centre().y(),2));
        if(dbis<d){d=dbis;ind=i;}
        i++;

    }

    return list_inter.at(ind);
}


void widgNRG::hoverEnterEvent(QGraphicsSceneHoverEvent *)
{
    entered=true;
    update();
}


void widgNRG::hoverLeaveEvent(QGraphicsSceneHoverEvent *)
{
    entered=false;
    update();
}


void widgNRG::mousePressEvent(QGraphicsSceneMouseEvent * event)
{

    drop_catched_locale=false;
    QByteArray byte_array;
    QDataStream dataStream(&byte_array,QIODevice::WriteOnly);
    dataStream<<text_N<<this->boundingRect()<<QPointF(event->pos()-this->boundingRect().topLeft())<<m_pixmap;

    QMimeData *mimeData=new QMimeData;
    mimeData->setData("mon_mime",byte_array);

    QDrag *drag=new QDrag(event->widget());
    drag->setMimeData(mimeData);
    drag->setPixmap(m_pixmap);


    QPoint point_arrond((int) this->boundingRect().topLeft().x(),(int) this->boundingRect().topLeft().y());//ro c'est pas beau
    QPoint pos_event_arrond((int) event->pos().x(),(int) event->pos().y() );

    drag->setHotSpot(pos_event_arrond-point_arrond);

    QGraphicsScene* pt_scene=this->scene();
    pt_scene->removeItem(this);
    WidgCellRes* pt_wbr=get_pt_WBR();
    pt_wbr->set_occupe(false);

    drag->exec();
    if(drop_catched_locale)
    {
        emit detruit_moi(this);
    }
    else
    {
        pt_scene->addItem(this);
        pt_wbr->set_occupe(true);
        this->set_entered(false);
    }
}


void MaGraphicsViewRes::detruire_wn(widgNRG* pt_wn)
{
    list_widgNRG.removeAt(list_widgNRG.indexOf(pt_wn));
    delete pt_wn;
}


widgNRG* MaGraphicsViewRes::creer_widgNRG(QString text_received,WidgCellRes* pt_w)
{
    emit aj_elem_cell_map(text_received,pt_w->get_index());//list_widgCellRes.indexOf(pt_w));
    pt_w->set_text(text_received);//useless?
    pt_w->set_occupe(true);

    QRectF rect(pt_w->get_centre().x(),pt_w->get_centre().y(),150,20);//dimensions calquees sur widgNres//pq pas utiliser rect_widg?
    rect.translate(-rect.width()/2,-rect.height()/2);
    widgNRG *wn=new widgNRG(rect);
    wn->setN(text_received);//useless?

    wn->set_pt_WBR(pt_w);
    wn->setZValue(2);
    list_widgNRG<<wn;
    connect(wn,SIGNAL(detruit_moi(widgNRG*)),this,SLOT(detruire_wn(widgNRG*)));
    scene()->addItem(wn);
    return wn;
}


void FeResNaAff::enlever_st(QString str)
{

    widgNRes* wN;
    for(int i=0;i<N_list.size();i++)
    {
        if(N_list.at(i)->getN()==str){;wN=N_list.at(i);break;}
    }
    cacher_widg(wN);
}


QString trouve_cpl(const QString & str ,const Elements & scl)
{
    auto it=std::find(scl.elem_names.begin(),scl.elem_names.end(),str.toStdString());
    int ind_st=it-scl.elem_names.begin();
    auto it_matr=std::find(scl.matr_i.at(ind_st).begin(),scl.matr_i.at(ind_st).end(),interType::PARTNERS);
    bool st_a_un_cpl=false;
    int ind_st_cpl;
    if(it_matr!=scl.matr_i.at(ind_st).end()){st_a_un_cpl=true,ind_st_cpl=it_matr-scl.matr_i.at(ind_st).begin();}
    QString str_cpl="";
    if(st_a_un_cpl)str_cpl=QString::fromStdString(scl.elem_names.at(ind_st_cpl));
    return str_cpl;
}



void MaGraphicsViewRes::rapatrier(QString str)
{

    int ind_NRG;
    for(int i=0;i<list_widgNRG.size();i++)
    {
        if(list_widgNRG.at(i)->getN()==str)ind_NRG=i;
    }
    list_widgNRG.at(ind_NRG)->get_pt_WBR()->set_occupe(false);
    detruire_wn(list_widgNRG.at(ind_NRG));
}



void FeNaRes::rapatrier_cpl_eventuel(QString text_received)
{
    QString str_cpl=trouve_cpl(text_received,elements_copie);
    if(str_cpl!="")//si cpl
    {
        //est il ds la liste ou dans une cell?
        bool ds_liste;
        for(int i=0;i<m_w_multi_aff->N_list.size();i++){if(m_w_multi_aff->N_list.at(i)->getN()==str_cpl)ds_liste=true;}
        if(!ds_liste)
        {
            emit rapatrier(str_cpl);
            emit elem_cell_map_supr(str_cpl);
            m_w_multi_aff->recreer_widg(str_cpl,m_w_multi_aff->N_list.size()-1);
        }
    }
}


void FeNaRes::rapatrier_wNRG(QList<QString> list)
{
    for(int i=0;i<list.size();i++){ m_w_multi_aff->recreer_widg(list.at(i),m_w_multi_aff->N_list.size()-1);emit elem_cell_map_supr(list.at(i));}
    emit sous();
}
