#include "FenI.h"

//attention bug dans definition des interactions de type couple :on peut mettre en cpl qlqu'un qui l'est deja... a changer

using namespace std; 

FenI::FenI() :QWidget()
{

fenDes=new FenDesI();
fenBut=new FenButI();

hLayout=new QHBoxLayout();
hLayout->addWidget(fenDes);
hLayout->addWidget(fenBut);

hLayout->setStretchFactor(fenDes,80);
hLayout->setStretchFactor(fenBut,1);

this->setLayout(hLayout);

connect(fenBut,SIGNAL(aj_mode(ViewModeI)),fenDes,SLOT(setMode(ViewModeI)));
connect(fenDes,SIGNAL(nouv_inter(QString,QString,interType)),this,SLOT(pass_nouv_inter(QString,QString,interType)));
connect(fenDes->pt_graph_View(),SIGNAL(sous()),this,SLOT(emettre_sous()));

}


FenDesI::FenDesI() :QWidget()
{
setMinimumSize(700,400);
container=new QWidget();
scroll_area_2=new QScrollArea;
scroll_area_2->setWidget(container);
scroll_area_2->setWidgetResizable(true);

container->setFixedSize(800,800);
//container->setAlignment(Qt::AlignCenter);
graphScene =new QGraphicsScene(QRectF(0,0,800,800),this);
graphView = new MaGraphicsViewI(graphScene,container);

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

connect(graphView,SIGNAL(nouv_inter(QString,QString,interType)),this,SLOT(pass_nouv_inter(QString,QString,interType)));


scroll_area_2->ensureWidgetVisible(container);
}

void FenDesI::setMode(ViewModeI vm)
{
graphView->setMode(vm);
}





MonBoutI::MonBoutI() :QPushButton()
{
setFixedSize(100,60);

m_mode=ViewModeI::NOMODE;
connect(this,SIGNAL(clicked()),this,SLOT(envoyer_click()));
}

void MonBoutI::envoyer_click()
{
emit mon_clicked(this);
}

ViewModeI MonBoutI::mode()
{
return m_mode;
}
 void  MonBoutI::setMode(ViewModeI md)
{
m_mode=md;
}


FenButI::FenButI() :QWidget()
{
      setMinimumSize(110,400);

vLayout=new QVBoxLayout();

  MonBoutI *but1=new MonBoutI();
  but1->setText("Couple");
  but1->setMode(ViewModeI::MODE1); 
  but1->setCheckable(true);

  MonBoutI *but2=new MonBoutI();
  but2->setText("Rapprocher");
  but2->setMode(ViewModeI::MODE2); 
  but2->setCheckable(true);

  MonBoutI *but3=new MonBoutI();
  but3->setText("Rapprocher +");
  but3->setMode(ViewModeI::MODE3);
  but3->setCheckable(true);

  MonBoutI *but4=new MonBoutI();
  but4->setText("Eloigner");
  but4->setMode(ViewModeI::MODE4);
  but4->setCheckable(true);


  MonBoutI *but5=new MonBoutI();
  but5->setText("Eloigner +");
  but5->setMode(ViewModeI::MODE5);
  but5->setCheckable(true);

  MonBoutI *but6=new MonBoutI();
  but6->setText("SUPR");
  but6->setMode(ViewModeI::MODE6);
  but6->setCheckable(true);



list_but<<but1<<but2<<but3<<but4<<but5<<but6;

vLayout->addWidget(but1);
vLayout->addWidget(but2);
vLayout->addWidget(but3);
vLayout->addWidget(but4);
vLayout->addWidget(but5);
vLayout->addWidget(but6);


this->setLayout(vLayout);

connect(but1,SIGNAL(mon_clicked(MonBoutI *)),this, SLOT(aj_but(MonBoutI *)));
connect(but2,SIGNAL(mon_clicked(MonBoutI *)),this, SLOT(aj_but(MonBoutI *)));
connect(but3,SIGNAL(mon_clicked(MonBoutI *)),this, SLOT(aj_but(MonBoutI *)));
connect(but4,SIGNAL(mon_clicked(MonBoutI *)),this, SLOT(aj_but(MonBoutI *)));
connect(but5,SIGNAL(mon_clicked(MonBoutI *)),this, SLOT(aj_but(MonBoutI *)));
connect(but6,SIGNAL(mon_clicked(MonBoutI *)),this, SLOT(aj_but(MonBoutI *)));


 }

void FenButI::aj_but(MonBoutI *bout) 
{
if(bout->isChecked())
{
uncheck_others(bout);
emit aj_mode(bout->mode());
}
else{emit aj_mode(ViewModeI::NOMODE);}
}


 void FenButI::uncheck_others(MonBoutI *bout)
{
for(int i=0;i<list_but.size();i++)
{
if(list_but.at(i)!= bout)list_but.at(i)->setChecked(false);
}

}

MaGraphicsViewI::MaGraphicsViewI(QGraphicsScene * scene,QWidget *parent)
:QGraphicsView(scene,parent)
{
mode=ViewModeI::NOMODE;
constr=false;
ptr_it_a=NULL;
ptr_it_mouve=NULL;
ptr_it_re=NULL;
li_temp=NULL;

HAUT_ITEM=15;
LARG_ITEM=110;
RAY=250;
RAY_B=150;
center.setX(400);
center.setY(400);
//=====essai=====
/*
QPointF p_t(50,300);
QRectF rect_t(p_t.x(),p_t.y(),LARG_ITEM,HAUT_ITEM);
ItemPersI *item_t=new ItemPersI(rect_t,"hehe hyo c'est l echo ");
scene->addItem(item_t);*/
//================
setMouseTracking(true);

//==============couleurs==============
//col.setRgb(200,20,10,110);
coul_3.setRgb(10,200,80,100);
coul_2.setRgb(50,180,80,100);
coul_1.setRgb(20,200,180,100);
coul_5.setRgb(200,20,10,100);
coul_4.setRgb(200,70,10,100);

ptr_li_a=NULL;
ptr_li_b=NULL;
ptr_li_c=NULL;
ptr_li_d=NULL;
ptr_li_e=NULL;

}

void MaGraphicsViewI::setMode( ViewModeI vM)
{
mode=vM;
}

void MaGraphicsViewI::aff_cercle(SClass scl)
{
//au passage on transmet une copie de la matr (utile ailleurs) =========
matr_copie=scl.matr_i;
str_list_std=scl.st_nm;
//====================================================
//conversion en QString=====
QList<QString> str_list;
for(int i=0;i<scl.st_nm.size();i++)
{str_list.append(QString::fromStdString(scl.st_nm.at(i)));}

//==========================
if(item_list.size()==0)
{
QVector<QPointF> vect_pos=calcul_pos(str_list.size());
for(int i=0;i<str_list.size();i++)
{
QRectF rect(vect_pos.at(i).x(),vect_pos.at(i).y(),LARG_ITEM,HAUT_ITEM);
ItemPersI * nouv_item=new ItemPersI(rect,str_list.at(i));
item_list << nouv_item;
this->scene()->addItem(nouv_item);
}
}
else
{
for(int i=0;i<item_list.size();i++)
{
this->scene()->removeItem(item_list.at(i));
delete item_list.at(i);
}
for(int i=0;i<li_list.size();i++)
{
this->scene()->removeItem(li_list.at(i));
delete li_list.at(i);
}

//QList<ItemPersI *> list_pass;
item_list.clear();
li_list.clear();
QVector<QPointF> vect_pos=calcul_pos(str_list.size());
for(int i=0;i<str_list.size();i++)
{
QRectF rect(vect_pos.at(i).x(),vect_pos.at(i).y(),LARG_ITEM,HAUT_ITEM);
ItemPersI * nouv_item=new ItemPersI(rect,str_list.at(i));
item_list << nouv_item;
/*for(int i=0;i< item_list.size();i++)
{

}*/
this->scene()->addItem(nouv_item);
}
//============liaisons========
for(int i=0;i<scl.st_nm.size();i++)
{
for(int j=0;j<i;j++)
{
if(scl.matr_i.at(i).at(j)!=interType::ras)
{
LiI *liI=new LiI(item_list[i]->boundingRect().center(),item_list[j]->boundingRect().center());
liI->set_li_mode(scl.matr_i.at(i).at(j));
liI->set_nm_bouts(str_list[i],str_list[j]);
li_list << liI;
this->scene()->addItem(liI);

}
}
}
//=============================
}
update();
emit sous();
}

QVector<QPointF>  MaGraphicsViewI::calcul_pos(int taille_liste)
{
//center=this->scene()->rect().center();
double pi=3.14159265;
QVector<QPointF> vect;

//======liste de teta=======================
/*
double teta= i*(2*pi/taille_liste);
double k=0.2;
if(teta < pi/2)
{
}
if(teta > pi/2 && teta < pi)
{
}
if (teta > pi && teta < 3*pi/2)
{
}
if (teta >3*pi/2)
{
}*/
//===============================================
//=======liste de points============================
//TODO si y en a qu 1 ou 2 ou 3..a
int N_bis;

if(taille_liste % 2 ==0)
{
N_bis=taille_liste-2;
}
else
{
N_bis=taille_liste-3;
}
double pas=HAUT_ITEM+5;
RAY=(((N_bis+2)/2)*pas)/2;

QPoint p;
// celui d'en haut
p.setX(center.x()-LARG_ITEM/2);
p.setY(center.y()+RAY);
vect << p;
// le ou les deux du bas
if(taille_liste % 2 ==0)
{
p.setX(center.x()-LARG_ITEM/2);
p.setY(center.y()-RAY);
vect << p;
}
else
{

p.setX(center.x()-(LARG_ITEM+10));
p.setY(center.y()-RAY);
vect << p;

p.setX(center.x()+10);
p.setY(center.y()-RAY);
vect << p;
}
//double hauteur=RAY*2-HAUT_ITEM;
//double pas=hauteur/(N_bis/2);
for(int i=0;i<N_bis;i++)
{
QPointF p_vide;
vect << p_vide;
}
double k=0.2 ;
for(int i=0;i<N_bis/2;i++)
{QPointF pt;
pt.setY(center.y()+RAY-HAUT_ITEM/2-pas/2-i*pas);
double b=(pt.y()-center.y());
//double a=sqrt(pow(RAY,2)-pow(b,2));
double a=RAY_B*sqrt(1-pow(b/RAY,2));
//b=abs(b);
pt.setX(center.x()+a);
vect.replace(i+taille_liste-N_bis,pt);
}
for(int i=N_bis/2;i<N_bis;i++)
{QPointF pt;
pt.setY(center.y()+RAY-HAUT_ITEM/2-pas/2-(i-N_bis/2)*pas);
double b=(pt.y()-center.y());
//double a=sqrt(pow(RAY,2)-pow(b,2));
//b=abs(b);
double a=RAY_B*sqrt(1-pow(b/RAY,2));

pt.setX(center.x()-a-LARG_ITEM);
vect.replace(i+taille_liste-N_bis,pt);

}

/*
for(int i=0;i<N_bis/2;i++)
{
QPointF p;

p.setX(center.x()+RAY*cos(teta));
p.setY(center.y()+RAY*sin(teta));
vect << p;
}*/
return vect;
}

  void FenI::aff_cercle(SClass s)
{
fenDes->aff_cercle(s);
}
  void FenDesI::aff_cercle(SClass s)
{
graphView->aff_cercle(s);
}

 void MaGraphicsViewI::mousePressEvent(QMouseEvent *event)
{
bool cont_fonc=true;
switch(mode)
{
case ViewModeI::NOMODE://mousePressEvent_NOMODE(event);
break;
case ViewModeI::MODE1://mousePressEvent_MODE1(event);
break;
case ViewModeI::MODE2://mousePressEvent_MODE2(event);
break;
case ViewModeI::MODE3://mousePressEvent_MODE3(event);
break;
case ViewModeI::MODE4://mousePressEvent_MODE4(event);
break;
case ViewModeI::MODE5://mousePressEvent_MODE5(event);
break;
case ViewModeI::MODE6:mousePressEvent_SUPR(event);
cont_fonc=false;
break;

}

if(event->button()== Qt::LeftButton && cont_fonc)
{

p_1=event->pos();


ptr_it_a=trouve_it(p_1);
if(ptr_it_a!=NULL )
{
constr=true;
QColor coul;
coul.setRgb(10,250,250,100);
ptr_it_a->set_couleur(coul);
}

}

}

 void MaGraphicsViewI::mouseMoveEvent(QMouseEvent *event)
{
QColor col;
bool cont_fonc=true;

switch(mode)
{
case ViewModeI::NOMODE://mouseMoveEvent_NOMODE(event);
break;
case ViewModeI::MODE1://mouseMoveEvent_MODE1(event);
col=coul_1;
break;
case ViewModeI::MODE2://mouseMoveEvent_MODE2(event);
col=coul_2;
break;
case ViewModeI::MODE3://mouseMoveEvent_MODE3(event);
col=coul_3;
break;
case ViewModeI::MODE4://mouseMoveEvent_MODE4(event);
col=coul_4;
break;
case ViewModeI::MODE5://mouseMoveEvent_MODE5(event);
col=coul_5;
break;
case ViewModeI::MODE6:mouseMoveEvent_SUPR(event);
cont_fonc=false;
break;

}
if(cont_fonc)
{
if(constr==false)
{
  ItemPersI *ptr_it=NULL;
 ptr_it=ptr_it_mouve;;
  ptr_it_mouve=trouve_it(event->pos());

if(ptr_it_mouve!=NULL)
{
//cout<<"dedans"<<endl;

QColor coul;
coul.setRgb(10,250,250,100);
ptr_it_mouve->set_couleur(coul);
}

if( ptr_it != NULL && ptr_it_mouve!=ptr_it )
{
//cout<<"sortie"<<endl;
QColor coul;
coul.setRgb(255,255,255);
ptr_it->set_couleur(coul);
}
}
else{

p_2=event->pos();
 ItemPersI *ptr_it=NULL;

ptr_it=ptr_it_mouve;
ptr_it_mouve=trouve_it(p_2);
if( ptr_it != NULL && ptr_it != ptr_it_a && ptr_it!=ptr_it_mouve)
{
QColor coul;
coul.setRgb(255,255,255);
ptr_it->set_couleur(coul);
}
if(ptr_it_mouve!=NULL && ptr_it_a != ptr_it_mouve )
{
QColor coul;
//coul.setRgb(250,10,220,180);//rose 
//coul.setRgb(10,50,250,100);//bleu fonce pas mal
coul.setRgb(10,250,250,100);
ptr_it_mouve->set_couleur(coul);

}

if(li_temp!=NULL){this->scene()->removeItem(li_temp);delete li_temp;li_temp=NULL;}
li_temp= new LiI(p_1,p_2);
li_temp->set_couleur(col);
this->scene()->addItem(li_temp);

update();//sert a rien semble il...
}
}
}

 void MaGraphicsViewI::mouseReleaseEvent(QMouseEvent *event)
{
bool cont_fonc=true;
QColor col;
interType li_mode;
switch(mode)
{
case ViewModeI::NOMODE://mouseMoveEvent_NOMODE(event);
break;
case ViewModeI::MODE1://mouseMoveEvent_MODE1(event);
col=coul_1;
li_mode=interType::cpl;
break;
case ViewModeI::MODE2://mouseMoveEvent_MODE2(event);
col=coul_2;
li_mode=interType::bav;
break;
case ViewModeI::MODE3://mouseMoveEvent_MODE3(event);
col=coul_3;
li_mode=interType::gba;
break;
case ViewModeI::MODE4://mouseMoveEvent_MODE4(event);
col=coul_4;
li_mode=interType::mes;
break;
case ViewModeI::MODE5://mouseMoveEvent_MODE5(event);
col=coul_5;
li_mode=interType::gme;
break;
case ViewModeI::MODE6:mouseReleaseEvent_SUPR(event);
cont_fonc=false;
break;

}
if(cont_fonc)
{
if(constr==true)
{
if(event->button()== Qt::LeftButton)
{

this->scene()->removeItem(li_temp);
delete li_temp;
li_temp=NULL;
p_2=event->pos();

ptr_it_re=trouve_it(p_2);
if(ptr_it_re!=NULL && ptr_it_a != ptr_it_re )
{
QPointF p_a=ptr_it_a->boundingRect().center();
QPointF p_b=ptr_it_re->boundingRect().center();
QString nm_1=ptr_it_a->get_nm();
QString nm_2=ptr_it_re->get_nm();
//mal codé===============================
int ind_1;
int ind_2;

std::string nm_1_std=nm_1.toStdString();
std::string nm_2_std=nm_2.toStdString();

auto it=std::find(str_list_std.begin(),str_list_std.end(),nm_1_std);
ind_1=it-str_list_std.begin();

it=std::find(str_list_std.begin(),str_list_std.end(),nm_2_std);
ind_2=it-str_list_std.begin();
//=================================
if(matr_copie.at(ind_1).at(ind_2)== interType::ras)
{
LiI *liI;
liI =new LiI(p_a,p_b);
//liI->set_couleur(col);//useless
liI->set_li_mode(li_mode);

liI->set_nm_bouts(nm_1,nm_2);
emit nouv_inter(nm_1,nm_2,li_mode);
matr_copie[ind_1][ind_2]=li_mode;
matr_copie[ind_2][ind_1]=li_mode;

this->scene()->addItem(liI);
li_list << liI;
}
QColor coul;
coul.setRgb(255,255,255);

ptr_it_re->set_couleur(coul);//c'est pas beau comme maniere de programmer...
ptr_it_a->set_couleur(coul);

update();
//creer_wil(p_1,p_2);

}
QColor coul;
coul.setRgb(255,255,255);

ptr_it_a->set_couleur(coul);


constr=false;

}
}

switch(mode)
{
case ViewModeI::NOMODE:mouseReleaseEvent_NOMODE(event);
break;
case ViewModeI::MODE1:mouseReleaseEvent_MODE1(event);
break;
case ViewModeI::MODE2:mouseReleaseEvent_MODE2(event);
break;
case ViewModeI::MODE3:mouseReleaseEvent_MODE3(event);
break;
case ViewModeI::MODE4:mouseReleaseEvent_MODE4(event);
break;
case ViewModeI::MODE5:mouseReleaseEvent_MODE5(event);
break;
case ViewModeI::MODE6:mouseReleaseEvent_MODE6(event);
break;

}
}
}



 void MaGraphicsViewI::mousePressEvent_NOMODE(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseMoveEvent_NOMODE(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseReleaseEvent_NOMODE(QMouseEvent *event)
{
}


 void MaGraphicsViewI::mousePressEvent_MODE1(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseMoveEvent_MODE1(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseReleaseEvent_MODE1(QMouseEvent *event)
{
}


 void MaGraphicsViewI::mousePressEvent_MODE2(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseMoveEvent_MODE2(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseReleaseEvent_MODE2(QMouseEvent *event)
{
}

 void MaGraphicsViewI::mousePressEvent_MODE3(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseMoveEvent_MODE3(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseReleaseEvent_MODE3(QMouseEvent *event)
{
}

 void MaGraphicsViewI::mousePressEvent_MODE4(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseMoveEvent_MODE4(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseReleaseEvent_MODE4(QMouseEvent *event)
{
}

 void MaGraphicsViewI::mousePressEvent_MODE5(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseMoveEvent_MODE5(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseReleaseEvent_MODE5(QMouseEvent *event)
{
}

 void MaGraphicsViewI::mousePressEvent_MODE6(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseMoveEvent_MODE6(QMouseEvent *event)
{
}
 void MaGraphicsViewI::mouseReleaseEvent_MODE6(QMouseEvent *event)
{
}


 void MaGraphicsViewI::mousePressEvent_SUPR(QMouseEvent *event)
{
p_1=event->pos();

ptr_li_a=trouve_li(p_1);
if(ptr_li_a!=NULL)
{

QString nm_1=ptr_li_a->get_nm_1();
QString nm_2=ptr_li_a->get_nm_2();

//mal codé===============================
int ind_1;
int ind_2;

std::string nm_1_std=nm_1.toStdString();
std::string nm_2_std=nm_2.toStdString();

auto it=std::find(str_list_std.begin(),str_list_std.end(),nm_1_std);
ind_1=it-str_list_std.begin();

it=std::find(str_list_std.begin(),str_list_std.end(),nm_2_std);
ind_2=it-str_list_std.begin();

matr_copie[ind_1][ind_2]=interType::ras;
matr_copie[ind_2][ind_1]=interType::ras;
//=================================

emit nouv_inter(nm_1,nm_2,interType::ras);

this->scene()->removeItem(ptr_li_a);
li_list.removeOne(ptr_li_a);
delete ptr_li_a;
ptr_li_a=NULL;
}
/*
else
{
ptr_wiB_a=trouve_bur(p_1);
if(ptr_wiB_a!=NULL)
{
this->scene()->removeItem(ptr_wiB_a);
list_widgBur.removeOne(ptr_wiB_a);//fuite memoire?
if((ptr_wiB_a->get_ptr_li())!=NULL)
{
ptr_li_b=ptr_wiB_a->get_ptr_li();//mal codee faire des maps...
ptr_wiB_b=ptr_wiB_a->get_ptr_bur_li();
ptr_wiB_a->set_ptr_bur_li(NULL);
ptr_wiB_b->set_ptr_bur_li(NULL);
ptr_wiB_b->set_ptr_li(NULL);
ptr_wiB_b->set_coupled(false);


this->scene()->removeItem(ptr_li_b);
list_widgLi.removeOne(ptr_li_b);//fuite memoire?


}
//delete ptr_wiB_a;
}
}*/
}

//TODO resoudre bug passage rapide 
//TODO resoudre bug passage par autre liaison
 void MaGraphicsViewI::mouseMoveEvent_SUPR(QMouseEvent *event)
{
 ptr_li_b=ptr_li_a;
  ptr_li_a=trouve_li(event->pos());
if(ptr_li_a!=NULL )
{
QColor coul;
coul.setRgb(250,10,10,170);
ptr_li_a->set_couleur(coul);

}
if(ptr_li_a==NULL && ptr_li_b != NULL )
{
ptr_li_b->set_li_mode(ptr_li_b->get_li_mode());//astuce pr lui rendre sa couleur
}

if(ptr_li_a==NULL) 
{
/*
 ptr_wiB_f=ptr_wiB_e;
  ptr_wiB_e=trouve_bur(event->pos());
if(ptr_wiB_e!=NULL )
{
QColor coul;
//coul.setRgb(250,10,220,180);//rose 
//coul.setRgb(250,250,10,100);//jaune sobre 
coul.setRgb(250,10,10,100);
ptr_wiB_e->set_couleur(coul);
}
if(ptr_wiB_e==NULL && ptr_wiB_f != NULL )
{
QColor coul;
coul.setRgb(255,255,255);
ptr_wiB_f->set_couleur(coul);
}*/
}

}

 void MaGraphicsViewI::mouseReleaseEvent_SUPR(QMouseEvent *event)
{
}



void MaGraphicsViewI::dragEnterEvent(QDragEnterEvent * event)
{
}
 void MaGraphicsViewI::dragMoveEvent(QDragMoveEvent * event)
{
}
 void MaGraphicsViewI::dropEvent(QDropEvent * event)
{
}



 


void MaGraphicsViewI::wheelEvent(QWheelEvent *event)
{
}

  ItemPersI*  MaGraphicsViewI::trouve_it(const QPointF & point)
{
for(int i=0;i<item_list.size();i++)
{if(item_list.at(i)->boundingRect().contains(point))return(item_list.at(i));}
return(NULL);
}

  LiI*  MaGraphicsViewI::trouve_li(const QPointF & point)
{
for(int i=0;i<li_list.size();i++)
{if(li_list.at(i)->shape().contains(point))return(li_list.at(i));}
return(NULL);
}
 void FenI::pass_nouv_inter(QString st1,QString st2,interType inter)
{
emit nouv_inter(st1,st2,inter);
}
 void FenDesI::pass_nouv_inter(QString st1,QString st2,interType inter)
{
emit nouv_inter(st1,st2,inter);
}

