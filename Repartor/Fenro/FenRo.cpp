#include "FenRo.h"




using namespace std; 

FenRo::FenRo() :QWidget()
{

//setFixedSize(800,500);
fenRoDes=new FenRoDes();
/*
graphScene =new QGraphicsScene(fenRoDes->rect(),fenRoDes);
           
graphView = new MaGraphicsView(graphScene,fenRoDes);
graphView->show();
*/

fenRoBut=new FenRoBut();
hLayout=new QHBoxLayout();
 //scroll_area=new QScrollArea();
// scroll_area->setWidget(fenRoDes);

hLayout->addWidget(fenRoDes);
hLayout->addWidget(fenRoBut);

hLayout->setStretchFactor(fenRoDes,80);
hLayout->setStretchFactor(fenRoBut,1);

this->setLayout(hLayout);

connect(fenRoBut,SIGNAL(aj_mode(ViewMode)),fenRoDes,SLOT(setMode(ViewMode)));

connect(fenRoDes,SIGNAL(modif_bur(int,Pos)),this,SLOT(emetre_modif_bur(int,Pos)));
connect(fenRoDes,SIGNAL(supr_bur(int)),this,SLOT(emetre_supr_bur(int)));
connect(fenRoDes,SIGNAL(add_bur(Pos)),this,SLOT(emetre_add_bur(Pos)));
connect(fenRoDes,SIGNAL(add_cpl(int,int)),this,SLOT(emetre_add_cpl(int,int)));
connect(fenRoDes,SIGNAL(supr_cpl(int,int)),this,SLOT(emetre_supr_cpl(int,int)));

}


FenRoDes::FenRoDes() :QWidget()
{
      setMinimumSize(700,400);
container=new QWidget(this);
scroll_area_2=new QScrollArea;
scroll_area_2->setWidget(container);
//scroll_area_2->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff); 
//scroll_area_2->addScrollBarWidget(container,Qt::AlignRight);

//scroll_area_2->setAlignment(Qt::AlignTop);

scroll_area_2->setWidgetResizable(true);
//container->show();
container->setMinimumSize(4000,4000);
//graphScene =new QGraphicsScene(this->rect(),this);
graphScene =new QGraphicsScene(QRectF(0,0,4000,4000),this);
       
graphView = new MaGraphicsView(graphScene,container);
//indispensable: ==============================================
graphView->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
graphView->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
//===============================================================
//graphView->fitInView(container->rect());
//graphView->ensureVisible(container->rect(),0,0);
//graphView->show();
//graphView->setViewport(container);
QHBoxLayout *layout =new QHBoxLayout;
layout->addWidget(graphView);
layout->setContentsMargins(0,0,0,0);
container->setLayout(layout);

QHBoxLayout *layout_2 =new QHBoxLayout;
layout_2->addWidget(scroll_area_2);
this->setLayout(layout_2);
connect(graphView,SIGNAL(resize(qreal)),this,SLOT(resize(qreal)));


connect(graphView,SIGNAL(modif_bur(int,Pos)),this,SLOT(emetre_modif_bur(int,Pos)));
connect(graphView,SIGNAL(supr_bur(int)),this,SLOT(emetre_supr_bur(int)));
connect(graphView,SIGNAL(add_bur(Pos)),this,SLOT(emetre_add_bur(Pos)));
connect(graphView,SIGNAL(add_cpl(int,int)),this,SLOT(emetre_add_cpl(int,int)));
connect(graphView,SIGNAL(supr_cpl(int,int)),this,SLOT(emetre_supr_cpl(int,int)));

}

    void FenRoDes::setMode(ViewMode vm)
{
graphView->setMode(vm);
}


MaGraphicsView::MaGraphicsView(QGraphicsScene * scene,QWidget *parent)
:QGraphicsView(scene,parent)
{
//ptr_fenro=...//TODO
//  setMinimumSize(1000,1000);
setViewportUpdateMode(QGraphicsView::FullViewportUpdate);
wiB_temp=NULL;
wiL_temp=NULL;
ptr_wiB_a=NULL;
ptr_wiB_b=NULL;
ptr_wiB_c=NULL;
ptr_wiB_d=NULL;
ptr_wiB_e=NULL;
ptr_wiB_f=NULL;
ptr_wiB_g=NULL;


ptr_li_a=NULL;
ptr_li_b=NULL;
ptr_li_c=NULL;

MINIMAL_WIDTH=20; 
MINIMAL_HEIGTH=20;
MAXIMAL_WIDTH=300;
MAXIMAL_HEIGTH=300;

deplacement=false;
move_liaison=false;
           mode=ViewMode::NOMODE;
      //setMouseTracking(true);
      //setAcceptDrops(true);//pq pas besoin?
     //setAcceptHoverEvents(true);
connect(this,SIGNAL(rotation(int)),this,SLOT(effectuer_rot(int)));//astuce a la noix
 }

MonBout::MonBout() :QPushButton()
{
setFixedSize(70,60);

m_mode=ViewMode::NOMODE;
connect(this,SIGNAL(clicked()),this,SLOT(envoyer_click()));
}

void MonBout::envoyer_click()
{
emit mon_clicked(this);
}

ViewMode MonBout::mode()
{
return m_mode;
}
 void  MonBout::setMode(ViewMode md)
{
m_mode=md;
}


FenRoBut::FenRoBut() :QWidget()
{
      setMinimumSize(90,400);

vLayout=new QVBoxLayout();

  MonBout *butBur=new MonBout();
  butBur->setText("Cellule");
  butBur->setMode(ViewMode::BUR); 
  butBur->setCheckable(true);

  MonBout *butCpl=new MonBout();
  butCpl->setText("Joindre");
  butCpl->setMode(ViewMode::CPL); 
  butCpl->setCheckable(true);

  MonBout *butCopie=new MonBout();
  butCopie->setText("Copier");
  butCopie->setMode(ViewMode::COPIE);
  butCopie->setCheckable(true);

  MonBout *butRot=new MonBout();
  butRot->setText("Rotation");
  butRot->setMode(ViewMode::ROT);
  butRot->setCheckable(true);


  MonBout *butSupr=new MonBout();
  butSupr->setText("Suprimer");
  butSupr->setMode(ViewMode::SUPRR);
  butSupr->setCheckable(true);


list_but<<butBur<<butCpl<<butCopie<<butRot<<butSupr;

vLayout->addWidget(butBur);
vLayout->addWidget(butCpl);
vLayout->addWidget(butCopie);
vLayout->addWidget(butRot);
vLayout->addWidget(butSupr);

this->setLayout(vLayout);

connect(butBur,SIGNAL(mon_clicked(MonBout *)),this, SLOT(aj_but(MonBout *)));
connect(butCpl,SIGNAL(mon_clicked(MonBout *)),this, SLOT(aj_but(MonBout *)));
connect(butRot,SIGNAL(mon_clicked(MonBout *)),this, SLOT(aj_but(MonBout *)));
connect(butSupr,SIGNAL(mon_clicked(MonBout *)),this, SLOT(aj_but(MonBout *)));
connect(butCopie,SIGNAL(mon_clicked(MonBout *)),this, SLOT(aj_but(MonBout *)));

 }

void FenRoBut::aj_but(MonBout *bout) 
{
if(bout->isChecked())
{
uncheck_others(bout);
emit aj_mode(bout->mode());
}
else{emit aj_mode(ViewMode::NOMODE);}
}


 void FenRoBut::uncheck_others(MonBout *bout)
{
for(int i=0;i<list_but.size();i++)
{
if(list_but.at(i)!= bout)list_but.at(i)->setChecked(false);
}

}


 void MaGraphicsView::mousePressEvent(QMouseEvent *event)
{
event->accept();
switch(mode)
{
case ViewMode::NOMODE:mousePressEvent_NOMODE(event);
break;
case ViewMode::BUR:mousePressEvent_BUR(event);
break;
case ViewMode::DES_BUR:mousePressEvent_DES_BUR(event);
break;
case ViewMode::CPL:mousePressEvent_CPL(event);
break;
case ViewMode::BAR_CPL:mousePressEvent_BAR_CPL(event);
break;
case ViewMode::COPIE:mousePressEvent_COPIE(event);
break;
case ViewMode::SUPRR:mousePressEvent_SUPRR(event);
break;
case ViewMode::ROT:mousePressEvent_ROT(event);
break;
}
}
 void MaGraphicsView::mouseMoveEvent(QMouseEvent *event)
{
event->accept();

switch(mode)
{
case ViewMode::NOMODE:mouseMoveEvent_NOMODE(event);
break;
case ViewMode::BUR:mouseMoveEvent_BUR(event);
break;
case ViewMode::DES_BUR:mouseMoveEvent_DES_BUR(event);
break;
case ViewMode::CPL:mouseMoveEvent_CPL(event);
break;
case ViewMode::BAR_CPL:mouseMoveEvent_BAR_CPL(event);
break;
case ViewMode::COPIE:mouseMoveEvent_COPIE(event);
break;
case ViewMode::SUPRR:mouseMoveEvent_SUPRR(event);
break;
case ViewMode::ROT:mouseMoveEvent_ROT(event);
break;
}
}

void MaGraphicsView::mouseReleaseEvent(QMouseEvent *event)
{
event->accept();

switch(mode)
{
case ViewMode::NOMODE:mouseReleaseEvent_NOMODE(event);
break;
case ViewMode::BUR:mouseReleaseEvent_BUR(event);
break;
case ViewMode::DES_BUR:mouseReleaseEvent_DES_BUR(event);
break;
case ViewMode::CPL:mouseReleaseEvent_CPL(event);
break;
case ViewMode::BAR_CPL:mouseReleaseEvent_BAR_CPL(event);
break;
case ViewMode::COPIE:mouseReleaseEvent_COPIE(event);
break;
case ViewMode::SUPRR:mouseReleaseEvent_SUPRR(event);
break;
case ViewMode::ROT:mouseReleaseEvent_ROT(event);
break;
}
}

void  MaGraphicsView::mouseDoubleClickEvent(QMouseEvent *event)
{
event->accept();

switch(mode)
{
case ViewMode::NOMODE:mouseDoubleClickEvent_NOMODE(event);
break;
case ViewMode::BUR:mouseDoubleClickEvent_BUR(event);
break;
case ViewMode::DES_BUR:mouseDoubleClickEvent_DES_BUR(event);
break;
case ViewMode::CPL:mouseDoubleClickEvent_CPL(event);
break;
case ViewMode::BAR_CPL:mouseDoubleClickEvent_BAR_CPL(event);
break;
case ViewMode::COPIE:mouseDoubleClickEvent_COPIE(event);
break;
case ViewMode::SUPRR:mouseDoubleClickEvent_SUPRR(event);
break;
case ViewMode::ROT:mouseDoubleClickEvent_ROT(event);
break;

}
}

//implementer get_polygon et pouvoir mettre le polygon ds set_shape();//ok
// resoudre pb de rotation qui overlap son voisin;//ok
//================================NOMODE==========================================
//PRESS.............................................................................
 void MaGraphicsView::mousePressEvent_NOMODE(QMouseEvent *event)
{
}
//MOVE..................................................................................
 void MaGraphicsView::mouseMoveEvent_NOMODE(QMouseEvent *event)
{
}
//RELEASE.........................................................................
 void MaGraphicsView::mouseReleaseEvent_NOMODE(QMouseEvent *event)
{
}
//DBL CLICK.........................................................................
void  MaGraphicsView::mouseDoubleClickEvent_NOMODE(QMouseEvent *event)
{
}

//================================BUR=======================================================
//PRESS.................................................................................
 void MaGraphicsView::mousePressEvent_BUR(QMouseEvent *event)
{
if(event->button()== Qt::LeftButton)
{

p_1=event->pos();
cout<<"x: "<<p_1.x()<<"y: "<<p_1.y()<<endl;
p_3=p_1;
ptr_wiB_g=trouve_bur(p_1);
if(ptr_wiB_g!=NULL)
{
pos_1=ptr_wiB_g->pos();
ptr_wiB_g->setZValue(1);
QColor coul;
coul.setRgb(255,236,139);

ptr_wiB_g->set_couleur(coul);

setCursor(Qt::ClosedHandCursor);
deplacement=true;
//si liaison////
ptr_li_c=ptr_wiB_g->get_ptr_li();
if(ptr_li_c!=NULL)
{
move_liaison=true;
//ctr=ptr_wiB_g->boundingRect().center();
ctr=ptr_wiB_g->get_centre();
//point autre bout////
ptr_wiB_e=ptr_wiB_g->get_ptr_bur_li();
ptr_wiB_e->set_ptr_li(NULL);
ctr_2=ptr_wiB_e->get_centre();

this->scene()->removeItem(ptr_li_c);
list_widgLi.removeOne(ptr_li_c);
wiL_temp=new WidgLi(ctr,ctr_2);
wiL_temp->setZValue(2);
this->scene()->addItem(wiL_temp);
/////////
}

} 
else
{setMode(ViewMode::DES_BUR);}
}
}
//MOVE........................................................................................
 void MaGraphicsView::mouseMoveEvent_BUR(QMouseEvent *event)
{

p_2=event->pos();
if(deplacement)
{


setCursor(Qt::ClosedHandCursor);
pos_1.setX(pos_1.x()+(p_2.x()-p_1.x()));
pos_1.setY(pos_1.y()+(p_2.y()-p_1.y()));
//prepareGeometryChange();
//ptr_wiB_g->setPos(pos_1);
//?

//si liasion
if(move_liaison)
{
//le nouveau:
ctr.setX(ctr.x()+(p_2.x()-p_1.x()));
ctr.setY(ctr.y()+(p_2.y()-p_1.y()));

this->scene()->removeItem(wiL_temp);
wiL_temp=new WidgLi(ctr,ctr_2);
wiL_temp->setZValue(2);
this->scene()->addItem(wiL_temp);

}
//////
ptr_wiB_g->setPos(pos_1);
QColor coul;
coul.setRgb(255,236,139);

ptr_wiB_g->set_couleur(coul);

p_1=p_2;
update();

}
else
{//si bouton pas presse et seulemnt entree et sortie pr pas gaspiller de la memoire TODO
ptr_wiB_g=trouve_bur(p_2);

if (ptr_wiB_g!=NULL)
{setCursor(Qt::OpenHandCursor);}
else
{setCursor(Qt::ArrowCursor);}


}
}

//RELEASE..................................................................................
 void MaGraphicsView::mouseReleaseEvent_BUR(QMouseEvent *event)
{
if(deplacement)
{//tout ça est mal codee..
p_2=event->pos();
pos_1.setX(pos_1.x()+(p_2.x()-p_1.x()));
pos_1.setY(pos_1.y()+(p_2.y()-p_1.y()));

//prepareGeometryChange();//marche pas..
ptr_wiB_g->setPos(pos_1);
QRectF rectf=ptr_wiB_g->get_rect_eff();//de l'ancienne pos 
QPainterPath path_shape=ptr_wiB_g->shape();
QPolygonF poly_shape=ptr_wiB_g->get_polygon();
QPointF pp_1=rectf.topLeft();
QPointF pp_2=rectf.bottomRight();
rectf.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());
QPainterPath path_shape_2=path_shape;
QPolygonF poly_shape_2=poly_shape;
path_shape_2.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());
poly_shape_2.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());

this->scene()->removeItem(ptr_wiB_g);//astuce a la noix
list_widgBur.removeOne(ptr_wiB_g);


QColor coul;
coul.setRgb(255,255,255,0);

ptr_wiB_g->set_couleur(coul);
int index=ptr_wiB_g->get_index();
double angle=ptr_wiB_g->get_angle();

delete ptr_wiB_g;
ptr_wiB_g=NULL;



//->sortir intersecte de creerbur et l'implementer avec les shapes//ok
//->faire une fct get_polygon_shape//pasbesoin en fait
//->faire un translation du polygon et voire si 'il intersecte ac les autre ac la fct intersect//ok
//->faire une fct set_shape(//ok)
//->creer le nouveau bur en utilisant la fct//ok
if(intersecte_bur(path_shape_2))
{
if(creer_bur(pp_1,pp_2))//creation du bur
{
list_widgBur[list_widgBur.size()-1]->set_shape(path_shape,poly_shape);//pas terrible comme maniere de prog...
list_widgBur[list_widgBur.size()-1]->set_index(index);
list_widgBur[list_widgBur.size()-1]->set_angle(angle);
}
}
else
{
if(creer_bur(rectf.topLeft(),rectf.bottomRight()))
{
list_widgBur[list_widgBur.size()-1]->set_shape(path_shape_2,poly_shape_2);

list_widgBur[list_widgBur.size()-1]->set_index(index);
list_widgBur[list_widgBur.size()-1]->set_angle(angle);

double x,y,w,h;
x=list_widgBur[list_widgBur.size()-1]->get_rect_eff().topLeft().x();
y=list_widgBur[list_widgBur.size()-1]->get_rect_eff().topLeft().y();
w=list_widgBur[list_widgBur.size()-1]->get_rect_eff().width();
h=list_widgBur[list_widgBur.size()-1]->get_rect_eff().height();

Pos pos={x,y,w,h,angle};
emit modif_bur(index,pos);
}

}

//liaison===============

if(move_liaison)
{move_liaison=false;

ptr_wiB_g=list_widgBur[list_widgBur.size()-1];
ptr_wiB_g->setZValue(0);


this->scene()->removeItem(wiL_temp);
delete wiL_temp;
wiL_temp=NULL;

WidgLi *wiL;
wiL =new WidgLi(ptr_wiB_g->boundingRect().center(),ctr_2);
this->scene()->addItem(wiL);


ptr_wiB_g->set_ptr_bur_li(ptr_wiB_e);
ptr_wiB_e->set_ptr_bur_li(ptr_wiB_g);
ptr_wiB_g->set_coupled(true);
ptr_wiB_e->set_coupled(true);
ptr_wiB_g->set_ptr_li(wiL);
ptr_wiB_e->set_ptr_li(wiL);
wiL->set_ptr_bout(ptr_wiB_g);
list_widgLi << wiL;

ptr_wiB_g->stackBefore(list_widgLi.at(0));//list_widgLi.at(0)) et lepremier stacker a priori...


}

update();


deplacement=false;
setCursor(Qt::OpenHandCursor);
}
}
//============================================DES BUR==========================================
//PRESS....................................................................................... 
void MaGraphicsView::mousePressEvent_DES_BUR(QMouseEvent *event)
{
}

//MOVE.........................................................................................
 void MaGraphicsView::mouseMoveEvent_DES_BUR(QMouseEvent *event)
{

p_2=event->pos();

if(wiB_temp!=NULL){this->scene()->removeItem(wiB_temp);}

creer_bur_temp(p_1,p_2);//fuite memoire??
//TODO faire des item plutot que obj pr gaspiller moins de memoire
update();//sert a rien semble il...
//peindre();

}


//RELEASE...................................................................................
 void MaGraphicsView::mouseReleaseEvent_DES_BUR(QMouseEvent *event)
{
if(event->button()== Qt::LeftButton)
{
//cout<<"hoho"<<endl;
this->scene()->removeItem(wiB_temp);
delete wiB_temp;
wiB_temp=NULL;
//cout<<"héhé"<<endl;
p_2=event->pos();
//this->scene()->removeItem(wiB_temp);//TODO la premier fois ça remove ds le vide...
//if(wiB_temp!=NULL)
//{this->scene()->removeItem(wiB_temp);//TODO la premier fois ça remove ds le vide...
//{
//delete wiB_temp;}

QRectF r(p_2,p_1);
QPainterPath path;
path.addRect(r);

if(!intersecte_bur(path))
{
if(creer_bur(p_1,p_2))
{
int index=list_widgBur.size()-1;
list_widgBur[list_widgBur.size()-1]->set_index(index);
double x,y,w,h;
x=list_widgBur[list_widgBur.size()-1]->get_rect_eff().topLeft().x();
y=list_widgBur[list_widgBur.size()-1]->get_rect_eff().topLeft().y();
w=list_widgBur[list_widgBur.size()-1]->get_rect_eff().width();
h=list_widgBur[list_widgBur.size()-1]->get_rect_eff().height();

Pos pos={x,y,w,h,0};//l'angle est nul lors de la creation...
emit add_bur(pos);

}

}
//cout<<"list_widgBur.size() "<<list_widgBur.size()<<endl;
setMode(ViewMode::BUR);

update();
//peindre();
}
}
//===========================================CPL================================================
 
//PRESS........................................................................................

void MaGraphicsView::mousePressEvent_CPL(QMouseEvent *event)
{
if(event->button()== Qt::LeftButton)
{

p_1=event->pos();


ptr_wiB_a=trouve_bur(p_1);
if(ptr_wiB_a!=NULL && (!ptr_wiB_a->get_coupled()))
{
setMode(ViewMode::BAR_CPL);
QColor coul;
coul.setRgb(10,250,250,100);
ptr_wiB_a->set_couleur(coul);

}

}
}

//...............................................MOVE............................................

 void MaGraphicsView::mouseMoveEvent_CPL(QMouseEvent *event)
{
//QGraphicsView::mouseMoveEvent(event);
  WidgBur *ptr_wiB_zou=NULL;
 ptr_wiB_zou=ptr_wiB_e;
  ptr_wiB_e=trouve_bur(event->pos());
//cout<<"hihihaha"<<endl;
if(ptr_wiB_e!=NULL && !ptr_wiB_e->get_coupled())
{
QColor coul;
//coul.setRgb(250,10,220,180);//rose 
coul.setRgb(10,250,250,100);

ptr_wiB_e->set_couleur(coul);
}
if(ptr_wiB_e==NULL && ptr_wiB_zou != NULL )
{
QColor coul;
coul.setRgb(255,255,255,0);
//cout<<"he non pointeur pas null.."<<endl;
ptr_wiB_zou->set_couleur(coul);//pb lorsque 2 fenetre;
}

}

//..............................................RELEASE.........................................

 void MaGraphicsView::mouseReleaseEvent_CPL(QMouseEvent *event)
{
QGraphicsView::mouseReleaseEvent(event);
}

//==========================================BAR CPL============================================

//.............................................PRESS............................................

 void MaGraphicsView::mousePressEvent_BAR_CPL(QMouseEvent *event)
{
}

//..............................................MOUVE..........................................

void MaGraphicsView::mouseMoveEvent_BAR_CPL(QMouseEvent *event)
{

//cout<<"here we are moved"<<endl;

p_2=event->pos();

ptr_wiB_d=ptr_wiB_c;
ptr_wiB_c=trouve_bur(p_2);
if(ptr_wiB_c==NULL && ptr_wiB_d != NULL && ptr_wiB_d != ptr_wiB_a )
{
QColor coul;
coul.setRgb(255,255,255,0);
ptr_wiB_d->set_couleur(coul);
}
if(ptr_wiB_c!=NULL && ptr_wiB_a != ptr_wiB_c && (! ptr_wiB_c->get_coupled()))
{
QColor coul;
//coul.setRgb(250,10,220,180);//rose 
coul.setRgb(10,250,250,100);

ptr_wiB_c->set_couleur(coul);

}
//delete wiL_temp;
//wiL_temp =new WidgLi(pt_1,pt_2);
if(wiL_temp!=NULL){this->scene()->removeItem(wiL_temp);}
wiL_temp= new WidgLi(p_1,p_2);
this->scene()->addItem(wiL_temp);
//cout<<"hello"<<endl;
//creer_wil_temp(p_1,p_2);//TODO//fuite memoire??
//TODO faire des item plutot que obj pr gaspiller moins de memoire
update();//sert a rien semble il...

}

//..........................................RELEASE.............................................

 void MaGraphicsView::mouseReleaseEvent_BAR_CPL(QMouseEvent *event)
{
if(event->button()== Qt::LeftButton)
{

this->scene()->removeItem(wiL_temp);
    delete wiL_temp;
wiL_temp=NULL;
p_2=event->pos();

ptr_wiB_b=trouve_bur(p_2);
if(ptr_wiB_b!=NULL && ptr_wiB_a != ptr_wiB_b &&(! ptr_wiB_b->get_coupled()))
{
//cout<<"on est entré"<<endl;
QPointF p_a=ptr_wiB_a->get_centre();
QPointF p_b=ptr_wiB_b->get_centre();

WidgLi *wiL;
wiL =new WidgLi(p_a,p_b);
this->scene()->addItem(wiL);

ptr_wiB_b->set_ptr_bur_li(ptr_wiB_a);
ptr_wiB_a->set_ptr_bur_li(ptr_wiB_b);
ptr_wiB_b->set_coupled(true);
ptr_wiB_a->set_coupled(true);
ptr_wiB_b->set_ptr_li(wiL);
ptr_wiB_a->set_ptr_li(wiL);
wiL->set_ptr_bout(ptr_wiB_a);
list_widgLi << wiL;

emit add_cpl(ptr_wiB_a->get_index(),ptr_wiB_b->get_index());

QColor coul;
coul.setRgb(255,255,255,0);

ptr_wiB_b->set_couleur(coul);//c'est pas beau comme maniere de programmer...
ptr_wiB_a->set_couleur(coul);

update();
//creer_wil(p_1,p_2);

}
QColor coul;
coul.setRgb(255,255,255,0);

ptr_wiB_a->set_couleur(coul);


setMode(ViewMode::CPL);


}
}
//===============================================COPIE========================================

//.........................................PRESS............................................

 void MaGraphicsView::mousePressEvent_COPIE(QMouseEvent *event)
{
if(event->button()== Qt::LeftButton)
{

p_1=event->pos();
p_3=p_1;//?
ptr_wiB_d=trouve_bur(p_1);

if(ptr_wiB_d!=NULL)
{
ptr_wiB_g=new WidgBur(ptr_wiB_d->get_rect_eff());
ptr_wiB_g->set_shape(ptr_wiB_d->shape(),ptr_wiB_d->get_polygon());
this->scene()->addItem(ptr_wiB_g);
pos_1=ptr_wiB_g->pos();
ptr_wiB_g->setZValue(1);
QColor coul;
coul.setRgb(100,255,100);
ptr_wiB_g->set_couleur(coul);
coul.setRgb(255,255,255,0);
ptr_wiB_d->set_couleur(coul);

setCursor(Qt::ClosedHandCursor);
deplacement=true;
}

}
}

//...............................................MOVE..........................................

 void MaGraphicsView::mouseMoveEvent_COPIE(QMouseEvent *event)
{

p_2=event->pos();
if(deplacement)
{


setCursor(Qt::ClosedHandCursor);
pos_1.setX(pos_1.x()+(p_2.x()-p_1.x()));
pos_1.setY(pos_1.y()+(p_2.y()-p_1.y()));
//prepareGeometryChange();
//ptr_wiB_g->setPos(pos_1);
//?

ptr_wiB_g->setPos(pos_1);
QColor coul;
coul.setRgb(100,255,100);

ptr_wiB_g->set_couleur(coul);

p_1=p_2;
update();

}
else
{//si bouton pas presse et seulemnt entree et sortie pr pas gaspiller de la memoire TODO
ptr_wiB_g=trouve_bur(p_2);

if (ptr_wiB_g!=NULL)
{setCursor(Qt::OpenHandCursor);
QColor coul;
coul.setRgb(100,255,100);

ptr_wiB_g->set_couleur(coul);
ptr_wiB_a=ptr_wiB_g;
}
else
{setCursor(Qt::ArrowCursor);
if(ptr_wiB_a!=0)
{QColor coul;
coul.setRgb(255,255,255,0);

ptr_wiB_a->set_couleur(coul);
}
}


}

}

//............................................RELEASE........................................

 void MaGraphicsView::mouseReleaseEvent_COPIE(QMouseEvent *event)
{
if(deplacement)
{//tout ça est mal codee..
p_2=event->pos();
pos_1.setX(pos_1.x()+(p_2.x()-p_1.x()));
pos_1.setY(pos_1.y()+(p_2.y()-p_1.y()));

//prepareGeometryChange();//marche pas..
ptr_wiB_g->setPos(pos_1);
QRectF rectf=ptr_wiB_g->get_rect_eff();//de l'ancienne pos va savoir pq!
QPainterPath path_shape=ptr_wiB_g->shape();
QPolygonF poly_shape=ptr_wiB_g->get_polygon();

QPointF pp_1=rectf.topLeft();
QPointF pp_2=rectf.bottomRight();
QPainterPath path_shape_2=path_shape;
QPolygonF poly_shape_2=poly_shape;

path_shape_2.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());
poly_shape_2.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());

rectf.translate(p_2.x()-p_3.x(),p_2.y()-p_3.y());
this->scene()->removeItem(ptr_wiB_g);//astuce a la noix
list_widgBur.removeOne(ptr_wiB_g);


QColor coul;
coul.setRgb(255,255,255,0);

ptr_wiB_g->set_couleur(coul);

delete ptr_wiB_g;
ptr_wiB_g=NULL;

if(intersecte_bur(path_shape_2))
{
//rien du tout...
//creer_bur(pp_1,pp_2);
//list_widgBur[list_widgBur.size()-1]->set_shape(path_shape);//pas terrible comme maniere de prog...
}
else
{
if(creer_bur(rectf.topLeft(),rectf.bottomRight()))
{
list_widgBur[list_widgBur.size()-1]->set_shape(path_shape_2,poly_shape_2);

int index=list_widgBur.size()-1;
double angle=ptr_wiB_d->get_angle();

list_widgBur[list_widgBur.size()-1]->set_index(index);
list_widgBur[list_widgBur.size()-1]->set_angle(angle);

double x,y,w,h;
x=list_widgBur[list_widgBur.size()-1]->get_rect_eff().topLeft().x();
y=list_widgBur[list_widgBur.size()-1]->get_rect_eff().topLeft().y();
w=list_widgBur[list_widgBur.size()-1]->get_rect_eff().width();
h=list_widgBur[list_widgBur.size()-1]->get_rect_eff().height();

Pos pos={x,y,w,h,angle};
emit add_bur(pos);
}
}

/*
if(!creer_bur(rectf.topLeft(),rectf.bottomRight()))
{creer_bur(pp_1,pp_2);
}
*/

update();


deplacement=false;
setCursor(Qt::OpenHandCursor);
}
}

//===============================================SUPR==========================================

//...............................................PRESS.........................................

 void MaGraphicsView::mousePressEvent_SUPRR(QMouseEvent *event)
{
p_1=event->pos();

ptr_li_a=trouve_li(p_1);
if(ptr_li_a!=NULL)
{
ptr_wiB_d=ptr_li_a->get_ptr_bout();
ptr_wiB_e=ptr_wiB_d->get_ptr_bur_li();
ptr_wiB_d->set_ptr_bur_li(NULL);
ptr_wiB_e->set_ptr_bur_li(NULL);
ptr_wiB_d->set_ptr_li(NULL);
ptr_wiB_e->set_ptr_li(NULL);
ptr_wiB_d->set_coupled(false);
ptr_wiB_e->set_coupled(false);

emit supr_cpl(ptr_wiB_d->get_index(),ptr_wiB_e->get_index());


this->scene()->removeItem(ptr_li_a);
list_widgLi.removeOne(ptr_li_a);//fuite memoire?
//delete ptr_wiB_a;

}
else
{
ptr_wiB_a=trouve_bur(p_1);
if(ptr_wiB_a!=NULL)
{
int index=ptr_wiB_a->get_index();
emit supr_bur(index);
this->scene()->removeItem(ptr_wiB_a);
list_widgBur.removeOne(ptr_wiB_a);//fuite memoire?
//========aj post supr==================
for(int i=0;i<list_widgBur.size();i++)
{
if((list_widgBur[i]->get_index())>index)
{
list_widgBur[i]->set_index((list_widgBur[i]->get_index())-1);
}
}
//======================================
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
}
}

//..............................................MOVE.............................................

//TODO resoudre bug passage rapide 
 void MaGraphicsView::mouseMoveEvent_SUPRR(QMouseEvent *event)
{
 ptr_li_b=ptr_li_a;
  ptr_li_a=trouve_li(event->pos());
if(ptr_li_a!=NULL )
{
if(ptr_wiB_e!=NULL)
{
QColor coul;
//coul.setRgb(250,10,220,180);//rose 
//coul.setRgb(250,250,10,100);//jaune sobre 
coul.setRgb(255,255,255,0);
ptr_wiB_e->set_couleur(coul);
}
QColor coul;
//coul.setRgb(250,10,220,180);//rose 
//coul.setRgb(250,250,10,100);//jaune sobre 
coul.setRgb(250,10,10,100);
ptr_li_a->set_couleur(coul);

}
if(ptr_li_a==NULL && ptr_li_b != NULL )
{
QColor coul;
coul.setRgb(90,5,200,130);
ptr_li_b->set_couleur(coul);
}

if(ptr_li_a==NULL) 
{
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
coul.setRgb(255,255,255,0);
ptr_wiB_f->set_couleur(coul);
}
}

}

//................................................RELEASE.......................................

 void MaGraphicsView::mouseReleaseEvent_SUPRR(QMouseEvent *event)
{
}


//===============================================ROTATION=======================================

//PRESS.............................................................................
 void MaGraphicsView::mousePressEvent_ROT(QMouseEvent *event)
{

p_1=event->pos();
cout<<"p_1: "<<p_1.x()<<" "<<p_1.y()<<endl;
ptr_wiB_g=trouve_bur(p_1);
//ptr_wiB_g->setTransformOriginPoint(ptr_wiB_g->boundingRect().center());
//ptr_wiB_g->setRotation(45);
if(ptr_wiB_g!=NULL)
{

if(!intersecte_bur_lui_exclu(ptr_wiB_g->rotated_shape(),list_widgBur.indexOf(ptr_wiB_g)))
{
//cout<<"yo"<<endl;
ptr_wiB_g->rotation();
int index;
index=ptr_wiB_g->get_index();
double x,y,l,h,ang;
QRectF rect=ptr_wiB_g->get_rect_eff();
x=rect.topLeft().x();
y=rect.topLeft().y();
l=rect.width();
h=rect.height();
ang=ptr_wiB_g->get_angle();
Pos pos{x,y,l,h,ang};
emit modif_bur(index,pos);
}
//pb de rapidite...(de clic oubliés...)
//emit rotation(list_widgBur.indexOf(ptr_wiB_g));//tentative pr resoudre pb des clics mais ne marche pas mieux...des clics sont perdus pq?
//->en fait ce pb est general au clic rapide ds la graphview il ne sont pastous  detectés semble il
//serais a cause du double clic?->oui pb resolu en implementant mouseDoubleClickEvent


}
update();
}
//MOVE..................................................................................
 void MaGraphicsView::mouseMoveEvent_ROT(QMouseEvent *event)
{
}
//RELEASE.........................................................................
 void MaGraphicsView::mouseReleaseEvent_ROT(QMouseEvent *event)
{
}
void  MaGraphicsView::mouseDoubleClickEvent_ROT(QMouseEvent *event)
{
//le test de la rotation est ici pr l'instant
mousePressEvent_ROT(event);

}

 



//===============================================================================================
void MaGraphicsView::creer_bur_temp(const QPointF & pt_1,const QPointF & pt_2)
{
QRectF rect;
if((pt_1.x()<pt_2.x())&&(pt_1.y()<pt_2.y())) 
{
QRectF r(pt_1,pt_2);
rect=r;
//rect.adjust(0,0,1,1);
}
if((pt_1.x()<pt_2.x())&&(pt_1.y()>=pt_2.y())) 
{
QPointF pt_1_bis;
QPointF pt_2_bis;
pt_1_bis.setX(pt_1.x());
pt_1_bis.setY(pt_2.y());
pt_2_bis.setX(pt_2.x());
pt_2_bis.setY(pt_1.y());
QRectF r(pt_1_bis,pt_2_bis);
rect=r;
//rect.adjust(0,1,1,0);

}
if((pt_1.x()>=pt_2.x())&&(pt_1.y()<pt_2.y())) 
{
QPointF pt_1_bis;
QPointF pt_2_bis;
pt_1_bis.setX(pt_2.x());
pt_1_bis.setY(pt_1.y());
pt_2_bis.setX(pt_1.x());
pt_2_bis.setY(pt_2.y());
QRectF r(pt_1_bis,pt_2_bis);
rect=r;
//rect.adjust(1,0,0,1);
}

if((pt_1.x()>=pt_2.x())&&(pt_1.y()>=pt_2.y()))
{
QRectF r(pt_2,pt_1);
rect=r;
//rect.adjust(1,1,0,0);
}

QRectF rect_f(rect);

wiB_temp =new WidgBur(rect_f);

this->scene()->addItem(wiB_temp);
if(list_widgLi.size()>0)
{wiB_temp->stackBefore(list_widgLi.at(0));}//list_widgLi.at(0)) et lepremier stacker a priori...


}
bool MaGraphicsView::creer_bur(const QPointF & pt_1,const QPointF & pt_2)
{
QRectF rect;
if((pt_1.x()<pt_2.x())&&(pt_1.y()<pt_2.y())) 
{
QRectF r(pt_1,pt_2);
rect=r;
//rect.adjust(0,0,1,1);
}
if((pt_1.x()<pt_2.x())&&(pt_1.y()>=pt_2.y())) 
{
QPointF pt_1_bis;
QPointF pt_2_bis;
pt_1_bis.setX(pt_1.x());
pt_1_bis.setY(pt_2.y());
pt_2_bis.setX(pt_2.x());
pt_2_bis.setY(pt_1.y());
QRectF r(pt_1_bis,pt_2_bis);
rect=r;
//rect.adjust(0,1,1,0);

}
if((pt_1.x()>=pt_2.x())&&(pt_1.y()<pt_2.y())) 
{
QPointF pt_1_bis;
QPointF pt_2_bis;
pt_1_bis.setX(pt_2.x());
pt_1_bis.setY(pt_1.y());
pt_2_bis.setX(pt_1.x());
pt_2_bis.setY(pt_2.y());
QRectF r(pt_1_bis,pt_2_bis);
rect=r;
//rect.adjust(1,0,0,1);
}

if((pt_1.x()>=pt_2.x())&&(pt_1.y()>=pt_2.y()))
{
QRectF r(pt_2,pt_1);
rect=r;
//rect.adjust(1,1,0,0);
}

QRectF rect_f(rect);
if(taille_bur_acceptable(rect))//sinon on cree rien du tout ds creer bur....no coment 
{
WidgBur *wiB;
wiB =new WidgBur(rect_f);

this->scene()->addItem(wiB);
if(list_widgLi.size()>0)
{wiB->stackBefore(list_widgLi.at(0));}//list_widgLi.at(0)) et lepremier stacker a priori...


list_widgBur << wiB;
return true;
//connect(this,SIGNAL(clean_widgbur()),wiB,SLOT(clean()));
//connect(wiB,SIGNAL(clean_others()),this,SLOT(clean_others()));
}
else
{return false;}
}

void MaGraphicsView::creer_wil_temp(const QPointF & pt_1,const QPointF & pt_2)
{
/*
//cout<<"creation wil temp"<<endl;
wiL_temp =new WidgLi(pt_1,pt_2);

this->scene()->addItem(wiL_temp);

*/
}
void MaGraphicsView::creer_wil(const QPointF & pt_1,const QPointF & pt_2)
{
/*
WidgLi *wiL;
wiL =new WidgLi(pt_1,pt_2);
this->scene()->addItem(wiL);
list_widgLi << wiL;
*/

//this->show();

}
//void  MaGraphicsView::drawForeground(QPainter * painter,const QRectF &rectf)
//void  MaGraphicsView::paintEvent(QPaintEvent *event)
/*void MaGraphicsView::peindre()
{
cout<<"paint event!"<<endl;

//===========fond=============================
    QPainter painter(viewport());
    QPen pen_fond;
    painter.setPen(pen_fond);
    QRect rect_ajuste(this->rect());
    rect_ajuste.setWidth(rect_ajuste.width()-1);
    rect_ajuste.setHeight(rect_ajuste.height()-1);

  
     QColor couleur;
    
    // couleur.setCmyk(0,5,15,0);
    //   couleur.setCmyk(0,0,0,100);
    //     couleur.setRgb(18,13,22);
          couleur.setRgb(255,255,255);
     QPainterPath path_rect;
     path_rect.addRect(rect_ajuste);
     QBrush brosse(Qt::SolidPattern);
     brosse.setColor(couleur);
     painter.fillPath(path_rect,brosse);

//===================================================

//===================rectangle des futurs bur=========
if(des_en_cour)
{
    //QPainter painter_rect_bur(this);
    
     QColor couleur_bur;
     couleur_bur.setRgb(0,0,0);


    QPen pen_rect_bur;
    pen_rect_bur.setColor(couleur_bur);
    painter.setPen(pen_rect_bur);
    QRect rect_bur(p_1,p_2);
  
    
    painter.drawRect(rect_bur);
}
//============================================================
}*/


void MaGraphicsView::dragEnterEvent(QDragEnterEvent * event)
{
event->accept();

/*
if(cpl_actif){QGraphicsView::dragEnterEvent(event);}
else
{

if(event->mimeData()->hasFormat("zero"))
{
event->accept();
// event->acceptProposedAction();
}
}*/
}

 void MaGraphicsView::dragMoveEvent(QDragMoveEvent * event)
{event->accept();

/*
if(cpl_actif){QGraphicsView::dragMoveEvent(event);}
else
{

if(event->mimeData()->hasFormat("zero"))
{
//cout<<"hello!!"<<endl;
emit clean_widgbur();

event->accept();

}
}*/
}
 void MaGraphicsView::dropEvent(QDropEvent * event)
{event->accept();

/*
if(cpl_actif){QGraphicsView::dropEvent(event);}
else
{

if(event->mimeData()->hasFormat("zero"))
{
 event->accept();

}
}*/
}
/* void MaGraphicsView::clean_others()
{
emit clean_widgbur();

}*/

 /*    void MaGraphicsView::enterEvent(QEvent *event)
{
cout<<"graph view entered"<<endl;
}*/

  WidgBur*  MaGraphicsView::trouve_bur(const QPointF & point)
{
for(int i=0;i<list_widgBur.size();i++)
{if(list_widgBur.at(i)->shape().contains(point))return(list_widgBur.at(i));}
return(NULL);
}

  WidgLi*  MaGraphicsView::trouve_li(const QPointF & point)
{
for(int i=0;i<list_widgLi.size();i++)
{if(list_widgLi.at(i)->shape().contains(point))return(list_widgLi.at(i));}
return(NULL);
}

bool  MaGraphicsView::intersecte_bur(const QRectF & rect)
{

for(int i=0;i<list_widgBur.size();i++)
{
if(rect.intersects(list_widgBur.at(i)->boundingRect()))return true;
}
return false;
}

bool  MaGraphicsView::intersecte_bur(const QPainterPath & shape_path)
{

for(int i=0;i<list_widgBur.size();i++)
{
if(shape_path.intersects(list_widgBur.at(i)->shape()))return true;
}
return false;
}

 bool  MaGraphicsView::intersecte_bur_lui_exclu(const QPainterPath & shape_path,int ind)
{

for(int i=0;i<list_widgBur.size();i++)
{

if((i!=ind)&&shape_path.intersects(list_widgBur.at(i)->shape()))return true;
}
return false;
}


void MaGraphicsView::setMode( ViewMode vM)
{
mode=vM;
}

bool MaGraphicsView::taille_bur_acceptable(const QRectF &rect)
{
if((rect.width()<MINIMAL_WIDTH)||(rect.height()<MINIMAL_HEIGTH)||(rect.width()>MAXIMAL_WIDTH)||(rect.height()>MAXIMAL_HEIGTH))
{return false;}
else
{return true;}
}

void MaGraphicsView::wheelEvent(QWheelEvent *event)
{
event->accept();

if(mode==ViewMode::NOMODE)
{
//scaleView(pow((double)2,-event->delta()/ 240.0));
scaleView(pow((double)2,-event->angleDelta().y()/ 500.0));

}
else
{QGraphicsView::wheelEvent(event);}
}
void MaGraphicsView::scaleView(qreal scaleFactor)
{

qreal factor = transform().scale(scaleFactor,scaleFactor).mapRect(QRectF(0,0,1,1)).width();
if(factor <0.07 || factor > 100)
 return;
//scale(scaleFactor, scaleFactor);
emit resize(scaleFactor);
//this->parent()->resize(scaleFactor*this->parent()->width(),scaleFactor*this->parent()->height());
}
  void FenRoDes::resize(qreal sf_r)
{//pas operationel...
/*
int sf_mil=(int) sf_r*1000;
double sf_d=(double) sf_mil/1000;
cout<<"heheo"<< sf_d<<endl;
int anc_w=container->width();
int anc_h=container->height();
container->setFixedWidth(sf_d*anc_w);
container->setFixedHeight(sf_d*anc_h);
int nv_w=container->width();
int nv_h=container->height();

graphView->scale(sf_d,sf_d);
*/
//container->resize( sf*container->width(), sf*container->height());
}

void MaGraphicsView::effectuer_rot(int ind)
{
list_widgBur[ind]->rotation();
}


void  MaGraphicsView::mouseDoubleClickEvent_BUR(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_DES_BUR(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_CPL(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_BAR_CPL(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_COPIE(QMouseEvent *event)
{

}
void  MaGraphicsView::mouseDoubleClickEvent_SUPRR(QMouseEvent *event)
{

}



