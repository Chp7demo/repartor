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
connect(fenDes->pt_graphView(),SIGNAL(aj_dsm(QString,int)),this,SLOT(emettre_aj_dsm(QString,int)));

connect(fenDes->pt_graphView(),SIGNAL(ad_fbs(int)),this,SLOT(emettre_ad_fbs(int)));
connect(fenDes->pt_graphView(),SIGNAL(supr_fbs(int)),this,SLOT(emettre_supr_fbs(int)));

connect(fenDes->pt_graphView(),SIGNAL(enlever_st(QString)),fenNaRes->pt_feResNaAff(),SLOT(enlever_st(QString)));
connect(fenDes->pt_graphView(),SIGNAL(rapatrier_wNRG(QList<QString>)),fenNaRes,SLOT(rapatrier_wNRG(QList<QString>)));
connect(fenDes->pt_graphView(),SIGNAL(sous()),this,SLOT(emettre_sous()));

connect(fenNaRes,SIGNAL(drop_locale_catched()),fenDes,SLOT(drop_locale_catched()));
connect(fenNaRes,SIGNAL(dsm_supr(QString)),this,SLOT(emettre_dsm_supr(QString)));
connect(fenNaRes,SIGNAL(rapatrier(QString)),fenDes->pt_graphView(),SLOT(rapatrier(QString)));
connect(fenNaRes,SIGNAL(sous()),this,SLOT(emettre_sous()));


connect(fenBut,SIGNAL(aj_mode(modeRes)),this,SLOT(aj_mode(modeRes)));

connect(fenNaRes->pt_feResNaAff(),SIGNAL(desact_fbs()),fenBut,SLOT(desact_fbs()));
connect(fenNaRes->pt_feResNaAff(),SIGNAL(desact_fbs()),fenDes,SLOT(desact_fbs()));
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

QRectF rect_drop(event->pos().x()-point_intra.x(),event->pos().y()-point_intra.y(),rect_widg.width(),rect_widg.height());

QPainterPath painter_path;
painter_path.addRect(rect_drop);
WidgBurRes* pt_w=trouve_intersect(painter_path,event->pos());
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
cout<<"drop entred"<<endl;
//emit drop_catched();
QByteArray byte_array=event->mimeData()->data("mon_mime");
QDataStream dataStream(&byte_array,QIODevice::ReadOnly);
QString text_received;
QRectF rect_widg;
QPointF point_intra;
//QPixmap pix;//tout ce qui est lie a cette pixmap stockee semble useless...
dataStream>>text_received>>rect_widg>>point_intra;//>>pix;

QRectF rect_drop(event->pos().x()-point_intra.x(),event->pos().y()-point_intra.y(),rect_widg.width(),rect_widg.height());
//scene()->addRect(rect_drop);

QPainterPath painter_path;
painter_path.addRect(rect_drop);
WidgBurRes* pt_w=trouve_intersect(painter_path,event->pos());
if (pt_w!=NULL && !pt_w->get_occupe())
{
 //=========le st a-t-il un cpl?===============
/*
auto it=std::find(elements_copie.elem_names.begin(),elements_copie.elem_names.end(),text_received.toStdString());
int ind_st=it-elements_copie.elem_names.begin();
auto it_matr=std::find(elements_copie.matr_i.at(ind_st).begin(),elements_copie.matr_i.at(ind_st).end(),interType::cpl);
bool st_a_un_cpl=false;
int ind_st_cpl;
if(it_matr!=elements_copie.matr_i.at(ind_st).end()){st_a_un_cpl=true,ind_st_cpl=it_matr-elements_copie.matr_i.at(ind_st).begin();}
*/
 QString str_cpl=trouve_cpl(text_received,elements_copie);
if(str_cpl=="")//si pas de cpl...
 {
      emit drop_cached();//attention je l'ai appler catched a d'autres endroits..
    aj_drop_catched_locale(true);

    QColor coul;
 coul.setRgb(255,255,255,0);
pt_w->set_couleur(coul);
pt_w_pass=NULL;
widgNRG* wn=creer_widgNRG(text_received,pt_w);
if(wn->boundingRect().contains(event->pos()))wn->set_entered(true);//c'est dejale cas il viens d'etre construit
else wn->set_entered(false);

}
else
{
cout<<"st a cpl"<<endl;
//le bu choisi a t il un cpl?
int ind_bu_cpl;
bool bu_a_un_cpl=false;
if(mm_copie.count(list_widgBurRes.indexOf(pt_w)))/*pas pt_w->get_index?*/
{ind_bu_cpl=mm_copie.find(list_widgBurRes.indexOf(pt_w))->second;bu_a_un_cpl=true;}
if(!bu_a_un_cpl)
 {
    cout<<"erreur utilisateur: "<<endl;
      QColor coul;
   coul.setRgb(255,255,255,0);
pt_w->set_couleur(coul);

}
else
{
if(list_widgBurRes.at(ind_bu_cpl)->get_occupe())//si le bu cpl est occupe
{
   cout<<"erreur utilisateur: "<<endl;
      QColor coul;
   coul.setRgb(255,255,255,0);
pt_w->set_couleur(coul);
}
else
 {

         emit drop_cached();//attention je l'ai appeler catched à d'autres endroits..
    aj_drop_catched_locale(true);

    QColor coul;
 coul.setRgb(255,255,255,0);
pt_w->set_couleur(coul);
pt_w_pass=NULL;
widgNRG* wn=creer_widgNRG(text_received,pt_w);
if(wn->boundingRect().contains(event->pos()))wn->set_entered(true);//c'est déjà le cas il vient d'etre construit
else wn->set_entered(false);

    //on attribu un widgNRG au bu cpl
cout<<"rep widg cpl"<<endl;
//le st_cpl est il deja ds un bur?
bool deja_ds_bur=false;
int ind_NRG_cpl;
//QString str_cpl=QString::fromStdString(elements_copie.elem_names.at(ind_st_cpl));
for(int i=0;i<list_widgNRG.size();i++)
{if(list_widgNRG.at(i)->getN()==str_cpl){deja_ds_bur=true;ind_NRG_cpl=i;}}
  if(deja_ds_bur)
  {
      WidgBurRes* pt_w_cpl_anc=list_widgNRG.at(ind_NRG_cpl)->get_pt_WBR();
      pt_w_cpl_anc->set_occupe(false);
      delete list_widgNRG.at(ind_NRG_cpl);
      list_widgNRG.removeAt(ind_NRG_cpl);}
 else emit enlever_st(str_cpl);
  widgNRG* wn_cpl=creer_widgNRG(str_cpl,list_widgBurRes.at(ind_bu_cpl));
wn_cpl->set_entered(false);

  } //fin else cpl occupe
 }   //fin else de if !bu_a_un_cpl
}//fin if st_a_un_cpl
//=================================
}
event->acceptProposedAction();

 }


 void MaGraphicsViewRes::mousePressEvent(QMouseEvent * event)
 {   if(mode!=modeRes::FBS)QGraphicsView::mousePressEvent(event);
     else
     {   pt_w_b=NULL;
          pt_w_b=trouve_bur_res(event->pos());

if(pt_w_b!=NULL && !pt_w_b->get_occupe() && (pt_w_b->getModeCroix()==WidgBurRes::CROIXP))
{
pt_w_b->setModeCroix(WidgBurRes::CROIX);
pt_w_b->set_occupe(true);
emit ad_fbs(pt_w_b->get_index());
}
if(pt_w_b!=NULL/* && !pt_w_b->get_occupe()*/ && (pt_w_b->getModeCroix()==WidgBurRes::CROIXR))
{
pt_w_b->setModeCroix(WidgBurRes::NOCROIX);
pt_w_b->set_occupe(false);
emit supr_fbs(pt_w_b->get_index());

}

     }
}
 void MaGraphicsViewRes::mouseMoveEvent(QMouseEvent * event)
 {
     if(mode!=modeRes::FBS)QGraphicsView::mouseMoveEvent(event);
     else

  {


       pt_w_a=pt_w_b;
  pt_w_b=trouve_bur_res(event->pos());

if(pt_w_b!=NULL && pt_w_b!=pt_w_a&& !pt_w_b->get_occupe() && (pt_w_b->getModeCroix()==WidgBurRes::NOCROIX))
{
pt_w_b->setModeCroix(WidgBurRes::CROIXP);
}

if(pt_w_b!=NULL &&pt_w_b!=pt_w_a /*&& !pt_w_b->get_occupe() */&& (pt_w_b->getModeCroix()==WidgBurRes::CROIX))
{
pt_w_b->setModeCroix(WidgBurRes::CROIXR);
}
/*
if(pt_w_b!=NULL && !pt_w_b->get_occupe() && (pt_w_b->getModeCroix()==WidgBurRes::CROIXR))
{
pt_w_b->setModeCroix(WidgBurRes::CROIXR);
}*/

if(pt_w_b==NULL && (pt_w_a != NULL /*&& pt_w_a!=pt_w_b && !pt_w_a->get_occupe()*/)&&(pt_w_a->getModeCroix()==WidgBurRes::CROIXR) )
{
pt_w_a->setModeCroix(WidgBurRes::CROIX);
}

if(pt_w_b==NULL && (pt_w_a != NULL /*&& pt_w_a!=pt_w_b*/&& !pt_w_a->get_occupe())&&(pt_w_a->getModeCroix()==WidgBurRes::CROIXP) )
{
pt_w_a->setModeCroix(WidgBurRes::NOCROIX);
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
//m_w_multi_aff->show();
//m_w_multi_aff->setMinimumSize(300,300);
 m_scroll_multi_aff=new  QScrollArea();
 m_scroll_multi_aff->setWidget(m_w_multi_aff);
//=================================================
//m_scroll_multi_aff->ensureVisible(300,550);
 bl->setAlignment(Qt::AlignCenter);
 bl->setSizeConstraint(QLayout::SetNoConstraint);//utile?

bl->addWidget(m_scroll_multi_aff);
bl->setStretchFactor(m_scroll_multi_aff,1);//faut tout essayer..
this->setLayout(bl);

setAcceptDrops(true);

}



widgNRes::widgNRes() :QWidget()
{
    setFixedSize(150,20);
//cout<<"hehe"<<endl;
    m_label_N = new QLabel("",this);
    m_label_N -> setFixedSize(100,15);
    m_label_N -> move(this->rect().center().x()-m_label_N->width()/2,this->rect().center().y()-m_label_N->height()/2);

    m_label_N->setAlignment(Qt::AlignCenter);
/*
QVBoxLayout *vb=new QVBoxLayout;
vb->addWidget(m_label_N);
vb->setAlignment(Qt::AlignCenter);
this->setLayout(vb);
*/
     QFont font=m_label_N->font();
    font.setPointSize(10);
    
  
    m_label_N->setFont(font);
  



  QPaintEvent paintevent();//???


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

void FenRes::ajourner(Elements elements,std::map<int,int> map_dsm)
{
fenDes->ajourner(elements,map_dsm);
fenNaRes->ajourner(elements,map_dsm);
} 
void FenDesRes::ajourner(Elements elements,std::map<int,int> map_dsm)
{
graphView->ajourner(elements,map_dsm);
}

void MaGraphicsViewRes::ajourner(Elements elements,std::map<int,int> map_dsm)
{
 elements_copie=elements;
/*
matr_copie=elements.matr_i;//utile ici?
dsm_copie=map_dsm;//utile?
*/
//=========================
//ici on retire le stud eventuellment disparu...//si l ajournement provient d'un supression d'un stud...
vector<string> stnm_copie=elements.elem_names;
if(map_dsm.size()<list_widgNRG.size())
{
//si ds la widgNRG le nom correspondant n'est pas ds les dsm on le retire
int ind_widgNRG_to_remove;
for(int i=0;i<list_widgNRG.size();i++)
 {
string str=(list_widgNRG.at(i)->getN()).toStdString();
//std::vector<std::string>::iterator
auto it=std::find(stnm_copie.begin(),stnm_copie.end(),str);
int ind_st=it-stnm_copie.begin();
if(map_dsm.find(ind_st)==map_dsm.end())
{ind_widgNRG_to_remove=i;break;}
}
//on libere le bu
list_widgNRG.at(ind_widgNRG_to_remove)->get_pt_WBR()->set_occupe(false);
//on enleve le widgNRG de la scene
scene()->removeItem(list_widgNRG.at(ind_widgNRG_to_remove));//a mettre direct apres le clic c'est plus sur non?
//on le suprime de la liste et delete
delete list_widgNRG.at(ind_widgNRG_to_remove);
list_widgNRG.removeAt(ind_widgNRG_to_remove);
}
//si l'ajournement provient d'un placement auto===//attention cette partie n'a pas encore été testée
if(map_dsm.size()>list_widgNRG.size())
{
    for(auto paire: map_dsm)
  {
  //on trouve le nom du type
   string str=stnm_copie.at(paire.first);
   cout<<"paire.first "<<paire.first<<" nom du type:"<<str<<endl;
 //on regarde s 'il y a deja un NRG pr ce stud
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
  cout<<"str_q "<<str_q.toStdString()<<endl;
 emit enlever_st(str_q);
  widgNRG* wn=creer_widgNRG(str_q,list_widgBurRes.at(paire.second));
wn->set_entered(false);
       }
    }
}
//=============================
emit sous();
}
void FeNaRes::ajourner(std::map<int,int> map_dsm)
{
   ajourner(elements_copie,map_dsm);

}
void FeNaRes::ajourner(Elements elements,std::map<int,int> map_dsm)
{
//dsm_copie_fenares=map_dsm;//utile?
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
//cout<<m_w_multi_aff->N_list.size()<<endl;
for(int i=0;i<elements.elem_names.size();i++)
{if(map_dsm.find(i)==map_dsm.end())N_str_list.append(QString::fromStdString(elements.elem_names.at(i)));}
//=========ajourner st_map=========================
QMap<QString,int>::iterator i=st_qmap.begin();
while(i!=st_qmap.end())
{
if(N_str_list.contains(i.key()))i++;
else st_qmap.erase(i);//TODO emetre qqchose pour effacer ceux placé qui n'existent plus...//pas besoinen fait
}
//=======================
//TODO gestion de ceux qui sont deja place... !
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

//connect(nouv_fen,SIGNAL(decolle(widgNRes *)),this,SLOT(cacher_widg(widgNRes *)));
//cout<<"yo"<<endl;

    m_w_multi_aff->m_vboxlayout_pr_aff->addWidget(nouv_fen);
       
   
   m_w_multi_aff->resize(nouv_fen->width()+10,m_w_multi_aff->height()+nouv_fen->height()+10);
}
}
//===========on rapatrie ceux palce qui ont perdu le bur de leur cpl======
for(int i=0;i<m_w_multi_aff->N_list.size();i++){rapatrier_cpl_eventuel(m_w_multi_aff->N_list.at(i)->getN());}
//==================================================

//update();
emit sous();
}

//cette cascade c'est n'importe quoi..; iutiliser des refs..
void FenRes::ajourner_bu(vector<Pos> pos_vect,std::map<int,int> map_dsm,std::set<int> set_fbs)
{
cout<<"entree cascade"<<endl;
//deux travaux
fenDes->ajourner_bu(pos_vect,map_dsm,set_fbs);
fenNaRes->ajourner(map_dsm);
}
void FenRes::ajourner_mm(multimap<int,int> mmp) 
{
fenDes->ajourner_mm(mmp);
}
void FenDesRes::ajourner_bu(vector<Pos> pos_vect,std::map<int,int> map_dsm,std::set<int> set_fbs)
{
graphView->ajourner_bu(pos_vect,map_dsm,set_fbs);
}
void FenDesRes::ajourner_mm(multimap<int,int> mmp) 
{
graphView->ajourner_mm(mmp);
}


void MaGraphicsViewRes::ajourner_bu(vector<Pos> pos_vect,std::map<int,int> map_dsm,std::set<int> set_fbs)
{

//dsm_copie=map_dsm;//utile?
//cout<<"entree ajourner bu"<<endl;
if(list_widgBurRes.size()==0)
{
for(int i=0;i<pos_vect.size();i++)
{
QRectF rect(pos_vect.at(i).x,pos_vect.at(i).y,pos_vect.at(i).largeur,pos_vect.at(i).hauteur);
WidgBurRes * nouv_wbr=new WidgBurRes(rect);
list_widgBurRes << nouv_wbr;
nouv_wbr->set_index(i);//utile?
nouv_wbr->set_angle(pos_vect.at(i).angle);
nouv_wbr->rotation(pos_vect.at(i).angle);//lent?
connect(nouv_wbr,SIGNAL(drop_catched()),this,SLOT(drop_cached_sl()));
this->scene()->addItem(nouv_wbr);
//cout<<"coucou 1"<<endl;
}
}
else
{
for(int i=0;i<list_widgBurRes.size();i++)
{
    this->scene()->removeItem(list_widgBurRes.at(i));

    delete list_widgBurRes.at(i);
}
list_widgBurRes.clear();//methode du feignant;

for(int i=0;i<pos_vect.size();i++)
{
QRectF rect(pos_vect.at(i).x,pos_vect.at(i).y,pos_vect.at(i).largeur,pos_vect.at(i).hauteur);
WidgBurRes * nouv_wbr=new WidgBurRes(rect);
list_widgBurRes << nouv_wbr;
nouv_wbr->set_index(i);//utile?
nouv_wbr->set_angle(pos_vect.at(i).angle);
nouv_wbr->rotation(pos_vect.at(i).angle);//lent?
nouv_wbr->setZValue(1);
connect(nouv_wbr,SIGNAL(drop_catched()),this,SLOT(drop_cached_sl()));
//====fbs
//auto set_it=set_fbs.find(i);
if(set_fbs.count(i)>0){nouv_wbr->set_occupe(true);nouv_wbr->setModeCroix(WidgBurRes::CROIX);}
//======
this->scene()->addItem(nouv_wbr);
//cout<<"coucou 2"<<endl;

}
}//sortie else
//==================widgNRG================
//on recupere les pixmap.................
QMap<QString,QPixmap> map_pix;
for(int i=0;i<list_widgNRG.size();i++){map_pix.insert(list_widgNRG.at(i)->getN(),list_widgNRG.at(i)->get_pixmap());}
//....................................................
for(int i=0;i<list_widgNRG.size();i++){scene()->removeItem(list_widgNRG.at(i));delete list_widgNRG.at(i);}
list_widgNRG.clear();

for(int i=0;i<list_widgBurRes.size();i++)//mal codee peu etre plus rapide...
{
for(auto &paire:map_dsm)
 {
    if(paire.second==list_widgBurRes.at(i)->get_index())
    {
list_widgBurRes.at(i)->set_text(QString::fromStdString(elements_copie.elem_names.at(paire.first)));//useless?
list_widgBurRes.at(i)->set_occupe(true);

QRectF rect(list_widgBurRes.at(i)->get_centre().x(),list_widgBurRes.at(i)->get_centre().y(),150,20);//dimensions calquees sur widgNres//pq pas utiliser rect_widg?
rect.translate(-rect.width()/2,-rect.height()/2);
        widgNRG * nouv_wNRG=new widgNRG(rect);
        nouv_wNRG->setN(QString::fromStdString(elements_copie.elem_names.at(paire.first)));
        nouv_wNRG->set_pixmap(map_pix.value(nouv_wNRG->getN()));//pour stocker l'image en vue d'un futur deplacement
        nouv_wNRG->set_entered(false);
        nouv_wNRG->setZValue(2);
        nouv_wNRG->set_pt_WBR(list_widgBurRes.at(i));
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

void MaGraphicsViewRes::ajourner_mm(multimap<int,int> mmp) 
{
//TODO comportement lorsque des nom sont placé?
mm_copie=mmp;
QList<widgNRG*> list_to_supr;
cout<<"mm rep 1"<<endl;
for(int i=0;i<list_widgNRG.size();i++)
{

    QString str=trouve_cpl(list_widgNRG.at(i)->getN(),elements_copie);
    cout<<str.toStdString()<<endl;
    if(str!=""&&mmp.find(list_widgNRG.at(i)->get_pt_WBR()->get_index())==mmp.end())
    {
        list_to_supr<<list_widgNRG.at(i);
        cout<<str.toStdString()<<endl;
    }
}
cout<<"mm rep 2"<<endl;
QList<QString> list_str_to_supr;
for(int i=0;i<list_to_supr.size();i++){list_str_to_supr<<list_to_supr.at(i)->getN();}
cout<<"mm rep 3"<<endl;

for(int i=0;i<list_to_supr.size();i++)
{
    list_to_supr.at(i)->get_pt_WBR()->set_occupe(false);
    this->scene()->removeItem(list_to_supr.at(i));
    list_widgNRG.removeOne(list_to_supr.at(i));
    delete list_to_supr.at(i);
}
//list_to_supr.clear();
cout<<"mm rep 4"<<endl;

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

/*
widgNRes *child_N=NULL;
if(!((childAt(event->pos())==m_w_multi_aff)||(childAt(event->pos())==0)))//nawak
{
cout<<"hedsif"<<endl;
*/
 widgNRes *child_N=NULL;
// child_N=static_cast<widgNRes*>(childAt(event->pos()));
if(!(child_N=trouve_N(event->pos()))) return;

emit desact_fbs();
/*
}
else {cout<<"hebyebye";return;}
*/
/*
QByteArray byte_array;
QDataStream dataStream(&byte_array,QIODevice::WriteOnly);
dataStream<<this->getN();
*///pas utile prdu text...
int ind_lay=N_list.indexOf(child_N);
QPixmap pixmap=QWidget::grab(child_N->rect());
QString str=child_N->getN();
QRectF rect=child_N->rect();
//cout<<str.toStdString()<<endl;
QByteArray byte_array;
QDataStream dataStream(&byte_array,QIODevice::WriteOnly);
dataStream<<str<<rect<<QPointF(event->pos()-child_N->pos());//<<pixmap;

QMimeData *mimeData=new QMimeData;
mimeData->setData("mon_mime",byte_array);
//mimeData->setText(str);

drop_catched=false;

QDrag *drag=new QDrag(this);
drag->setMimeData(mimeData);
drag->setPixmap(pixmap);
drag->setHotSpot(event->pos()-child_N->pos());
cacher_widg(child_N);

//if(drag->exec(Qt::CopyAction|Qt::MoveAction,Qt::CopyAction)==Qt::CopyAction)
//{recreer_widg(str,ind_lay);}
//else{cout<<"pas copy..."<<endl;}
drag->exec();
emit aj_post_drop(str,ind_lay);//emit apres le signal d'un drop reçu...
} 


void FeResNaAff::aj_post_drop_sl(QString str,int ind_lay)
{
cout<<"entree slot"<<endl;
if(!drop_catched)
{recreer_widg(str,ind_lay);}
drop_catched=false;
}

void FeResNaAff::recreer_widg(QString nm,int ind_lay)
{
cout<<"enter recreer"<<endl;
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
cout<<"drag move 1"<<endl;
//TODO accepter seulement un format specifique
if(event->source()==this)
{
event->setDropAction(Qt::CopyAction);
event->accept();
cout<<"drag move 2"<<endl;

}
else{event->ignore();cout<<"rep 3"<<endl;
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
//emit drop_catched();
   // cout<<"event->source()!=this"<<(event->source()!=this)<<endl;
    if(event->source()!=m_w_multi_aff)
    {
    cout<<"drop event FeNaRes"<<endl;
QByteArray byte_array=event->mimeData()->data("mon_mime");
QDataStream dataStream(&byte_array,QIODevice::ReadOnly);
QString text_received;
QRectF rect_widg;
QPointF point_intra;
//QPixmap pix;
dataStream>>text_received>>rect_widg>>point_intra;//>>pix;
m_w_multi_aff->ajouter_widg(text_received);
emit drop_locale_catched();
emit dsm_supr(text_received);

rapatrier_cpl_eventuel(text_received);
/*
//s'il a un cpl sur un bur
QString str_cpl=trouve_cpl(text_received,elements_copie);
if(str_cpl!="")//si cpl
 {
//est il ds la liste ou sur un bur?
 bool ds_liste;
 for(int i=0;i<m_w_multi_aff->N_list.size();i++){if(m_w_multi_aff->N_list.at(i)->getN()==str_cpl)ds_liste=true;}
 if(!ds_liste)
 {
     emit rapatrier(str_cpl);
   emit dsm_supr(str_cpl);
 m_w_multi_aff->recreer_widg(str_cpl,m_w_multi_aff->N_list.size()-1);
 }
}*/
    }
event->acceptProposedAction();

}
//cette fct n'ext pas appeleé ?!!
void FeResNaAff::dragEnterEvent(QDragEnterEvent * event)
{
cout<<"drag enter 1"<<endl;

//TODO accepter seulement un format specifique
if(event->source()==this)
{
event->setDropAction(Qt::CopyAction);
event->accept();
cout<<"drag enter 2"<<endl;

}
else{event->ignore();cout<<"rep 6"<<endl;}

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
//N_str_list.removeAt(N_str_list.indexOf(wN->getN()));
//emit aj_list(N_str_list);
cout<<"entree cacher"<<endl;
wN->hide();
int hdel=wN->height();
//N_list.removeAt(N_list.indexOf(wN));
//delete wN;
 m_w_multi_aff->resize( m_w_multi_aff->width(),m_w_multi_aff->height()-hdel-10);
update();
}

void FeResNaAff::cacher_widg(widgNRes *wN)
{
//N_str_list.removeAt(N_str_list.indexOf(wN->getN()));
//emit aj_list(N_str_list);
cout<<"entree cacher bis"<<endl;
int hdel=wN->height();
cout<<"cacher rep 1"<<endl;
wN->hide();
cout<<"cacher rep 2"<<endl;
N_list.removeAt(N_list.indexOf(wN));
cout<<"cacher rep 3"<<endl;
delete wN;
cout<<"cacher rep 4"<<endl;
 this->resize( this->width(),this->height()-hdel-10);
cout<<"cacher rep 5"<<endl;
update();
}


 widgNRes*  FeResNaAff::trouve_N(const QPoint & point)
{
for(int i=0;i<N_list.size();i++)
{
QRect rect=N_list.at(i)->rect();
rect.translate(N_list.at(i)->pos().x(),N_list.at(i)->pos().y());
if(rect.contains(point))return(N_list.at(i));}
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
    cout <<"entree drop cached"<<endl;
drop_catched=true;
}



 void MaGraphicsViewRes::drop_cached_sl()//cette fonction n'est pas appelee semble il ...
 {
     emit drop_cached();
 }
 void MaGraphicsViewRes::aj_drop_catched_locale(bool b)
 {
   for(int i=0;i<list_widgNRG.size();i++)
   {list_widgNRG.at(i)->set_drop_catched_locale(b);}
 }
widgNRG::widgNRG( QRectF rect, QGraphicsItem *parent) :QGraphicsObject(parent)
{

//couleur.setRgb(255,255,255);
entered=true;
rect_ini=rect;
  QColor couleur;

     couleur.setRgb(255,255,210,255);// TODO attention pas le meme bege que les widgNresa ...

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
    //  QPainter painter(this);
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
//QPointF pt=rect_ini.center();
//QPointF pt=rect_ini.topLeft();
//pt.setX(pt.x()+5);
//pt.setY(pt.y()+5);
painter->drawText(rect_ini,Qt::AlignCenter,text_N);
//====================pixmap pr le drag drop==============

// QPixmap pix(rect_ini.width(),rect_ini.height());
// QRectF rect_pix(0,0,rect_ini.width(),rect_ini.height());
QPixmap pix(rect_ajuste.width()+1,rect_ajuste.height()+1);
QRectF rect_pix(0,0,rect_ajuste.width(),rect_ajuste.height());
 QPainter painter_pix(&pix);

 //peut on faire une pixmap de forme queconque ?!!
 QColor transp;transp.setRgb(255,255,255,255);//blans pas transparent... ça marche pas sur une pix...
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
 /*
//===========contour=============================
    QPen pen;
    QColor coul;
    coul.setRgb(200,100,0,200);  //marron
    pen.setColor(coul);
    pen.setWidth(3);
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
    QBrush brosse(Qt::SolidPattern);
    brosse.setColor(coul);

//===================================================
//=============================================

     QPainterPath path=shape();
     QPainterPathStroker pathStroker;
     pathStroker.setJoinStyle(Qt::RoundJoin);
     QPainterPath strokedPath=pathStroker.createStroke(path);
     strokedPath.setFillRule(Qt::WindingFill);
     path.setFillRule(Qt::WindingFill);
     painter->fillPath(strokedPath,brosse);

//===================================================
//===========fond=============================

    QPen pen_fond;
    painter->setPen(pen_fond);
    brosse.setColor(couleur);
    painter->fillPath(path,brosse);
//===================indice pr debug====================
QString str;
QPointF pt=rect_ini.topLeft();
pt.setX(pt.x()+5);
pt.setY(pt.y()+5);
str.setNum(index);
painter->drawText(pt,str);
//=======================================================
*/
}
WidgBurRes* MaGraphicsViewRes::trouve_bur_res(QPointF point)
{
    for(int i=0;i<list_widgBurRes.size();i++)
{if(list_widgBurRes.at(i)->shape().contains(point))return(list_widgBurRes.at(i));}
return(NULL);

}

WidgBurRes* MaGraphicsViewRes::trouve_intersect(QPainterPath painter_path,QPointF mouse_pos)
{
 //   cout<<"rep fct 1"<<endl;
 QList<WidgBurRes*> list_inter;
for(int i=0;i<list_widgBurRes.size();i++)
{ //cout<<"rep fct 2"<<endl;

    if(painter_path.intersects(list_widgBurRes.at(i)->shape())){list_inter<<list_widgBurRes.at(i);}
}
if(list_inter.size()==0) return(NULL);

int ind=0;
int i=1;
 //cout<<"rep fct 3"<<endl;
   double d=sqrt(pow(mouse_pos.x()-list_inter.at(0)->get_centre().x(),2)+pow(mouse_pos.y()-list_inter.at(0)->get_centre().y(),2));
   // cout<<"rep fct 3_bis"<<endl;

while(i<list_inter.size())
   {
//cout<<"rep fct 4"<<endl;
     double dbis=sqrt(pow(mouse_pos.x()-list_inter.at(i)->get_centre().x(),2)+pow(mouse_pos.y()-list_inter.at(i)->get_centre().y(),2));
    if(dbis<d){d=dbis;ind=i;}
            i++;
      //      cout<<"rep fct 5"<<endl;
}
    // cout<<"rep fct 6"<<endl;

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
    /*
 QPixmap pix(this->boundingRect().width(),this->boundingRect().height());
 QPainter painter(&pix);
 */
 drop_catched_locale=false;
QByteArray byte_array;
QDataStream dataStream(&byte_array,QIODevice::WriteOnly);
dataStream<<text_N<<this->boundingRect()<<QPointF(event->pos()-this->boundingRect().topLeft())<<m_pixmap;

QMimeData *mimeData=new QMimeData;
mimeData->setData("mon_mime",byte_array);

QDrag *drag=new QDrag(event->widget());
drag->setMimeData(mimeData);
drag->setPixmap(m_pixmap);
//QPixmap pixmap;//=QPixmap::grabWindow(event->widget()->winId(),);
//drag->setPixmap(pixmap);
//cout<<"(int) this->boundingRect().topLeft().x()"<<(int) this->boundingRect().topLeft().x()<<endl;
//cout<<" this->boundingRect().topLeft().x()"<<this->boundingRect().topLeft().x()<<endl;
cout<<"event->pos()"<<event->pos().x()<<endl;
cout<< "this->boundingRect().topLeft().x()"<< this->boundingRect().topLeft().x()<<endl;

QPoint point_arrond((int) this->boundingRect().topLeft().x(),(int) this->boundingRect().topLeft().y());//ro c'est pas beau
QPoint pos_event_arrond((int) event->pos().x(),(int) event->pos().y() );
//QPoint p_test(pos_event_arrond-point_arrond);

//cout<<"p_test.x()"<<p_test.x()<<"p_test.y()"<<p_test.y()<<endl;
//QPoint phot(10,10);
//drag->setHotSpot(phot);
drag->setHotSpot(pos_event_arrond-point_arrond);

QGraphicsScene* pt_scene=this->scene();
pt_scene->removeItem(this);
WidgBurRes* pt_wbr=get_pt_WBR();
pt_wbr->set_occupe(false);

drag->exec();
if(drop_catched_locale)
 {
emit detruit_moi(this);
}
else
{cout<<"coucou drop ds l vide"<<endl;
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


widgNRG* MaGraphicsViewRes::creer_widgNRG(QString text_received,WidgBurRes* pt_w)
{
       emit aj_dsm(text_received,pt_w->get_index());//list_widgBurRes.indexOf(pt_w));
pt_w->set_text(text_received);//useless?
pt_w->set_occupe(true);

QRectF rect(pt_w->get_centre().x(),pt_w->get_centre().y(),150,20);//dimensions calquees sur widgNres//pq pas utiliser rect_widg?
rect.translate(-rect.width()/2,-rect.height()/2);
widgNRG *wn=new widgNRG(rect);
wn->setN(text_received);//useless?
//wn->set_pixmap(event->pixmap());//pour stocker l'image en vue d'un futur deplacement//marche pas
//-----------------------pixmap stockee-----------------------------------
/*
 QRectF rect_pix=rect;//(0,0,rect.width(),rect.height());
 QPixmap pix(rect_pix.width(),rect_pix.height());
 QPainter painter_pix(&pix);

    QPainterPath path_rect_pix;
     path_rect_pix.addRoundedRect(rect_pix,4,4);
     QBrush brosse_pix(Qt::SolidPattern);
     brosse_pix.setColor(color);
     painter_pix.fillPath(path_rect_pix,brosse_pix);
     painter_pix.drawRoundedRect(rect_pix,4,4);

 painter_pix.drawText(rect_pix,Qt::AlignCenter,text_N);*/
//--------------------------------------------------------------------------------------------
//wn->set_pixmap(pix);//pour stocker l'image en vue d'un futur deplacement
//wn->setParent(this);//utile?
wn->set_pt_WBR(pt_w);
wn->setZValue(2);
list_widgNRG<<wn;
connect(wn,SIGNAL(detruit_moi(widgNRG*)),this,SLOT(detruire_wn(widgNRG*)));
scene()->addItem(wn);
return wn;
}
void FeResNaAff::enlever_st(QString str)
{
    cout<<"le nom est : "<<str.toStdString()<<endl;

    widgNRes* wN;
    for(int i=0;i<N_list.size();i++)
{   cout<<"on le compare a :"<<N_list.at(i)->getN().toStdString()<<endl;
               if(N_list.at(i)->getN()==str){cout<<"un nom trouvé!"<<endl;wN=N_list.at(i);break;}
          }
   cacher_widg(wN);
}

QString trouve_cpl(const QString & str ,const Elements & scl)
{
auto it=std::find(scl.elem_names.begin(),scl.elem_names.end(),str.toStdString());
int ind_st=it-scl.elem_names.begin();
auto it_matr=std::find(scl.matr_i.at(ind_st).begin(),scl.matr_i.at(ind_st).end(),interType::cpl);
bool st_a_un_cpl=false;
int ind_st_cpl;
if(it_matr!=scl.matr_i.at(ind_st).end()){st_a_un_cpl=true,ind_st_cpl=it_matr-scl.matr_i.at(ind_st).begin();}
    QString str_cpl="";
    if(st_a_un_cpl)str_cpl=QString::fromStdString(scl.elem_names.at(ind_st_cpl));
    return str_cpl;
 }

 void MaGraphicsViewRes::rapatrier(QString str)
 {
cout<<"rapatrier"<<endl;
int ind_NRG;
for(int i=0;i<list_widgNRG.size();i++)
{if(list_widgNRG.at(i)->getN()==str)ind_NRG=i;}
list_widgNRG.at(ind_NRG)->get_pt_WBR()->set_occupe(false);
detruire_wn(list_widgNRG.at(ind_NRG));
 }

 void FeNaRes::rapatrier_cpl_eventuel(QString text_received)
{
QString str_cpl=trouve_cpl(text_received,elements_copie);
if(str_cpl!="")//si cpl
 {
//est il ds la liste ou sur un bur?
 bool ds_liste;
 for(int i=0;i<m_w_multi_aff->N_list.size();i++){if(m_w_multi_aff->N_list.at(i)->getN()==str_cpl)ds_liste=true;}
 if(!ds_liste)
 {
     emit rapatrier(str_cpl);
   emit dsm_supr(str_cpl);
 m_w_multi_aff->recreer_widg(str_cpl,m_w_multi_aff->N_list.size()-1);
 }
}
 }


 void FeNaRes::rapatrier_wNRG(QList<QString> list)
{
  cout<<"rap enter"<<endl;
 for(int i=0;i<list.size();i++){ m_w_multi_aff->recreer_widg(list.at(i),m_w_multi_aff->N_list.size()-1);emit dsm_supr(list.at(i));}
 cout<<"rap sortie"<<endl;
//emit degeler//TODO
 emit sous();
 }
