
#include "WidgBur.h"

using namespace std; 


WidgBur::WidgBur(QRectF rect,QGraphicsItem *parent) :QGraphicsObject(parent)
{

couleur.setRgb(255,255,255,0);
ptr_li=NULL;
ptr_bur_li=NULL;
rect_ini=rect;
rect_eff=rect;
QPolygonF p_pass(rect);
polygon_shape=p_pass;
painting_path.addPolygon(polygon_shape);
entered=false;
cpl_actif=false;
bar_cpl_actif=false;
bar_cpl_oth_actif=false;
drop_accepted=false;
drag_entrant=false;
coupled=false;
setAcceptDrops(true);
setAcceptHoverEvents(true);

angle=0;
//m_lab_index=new QLabel("",this);//ne marche pas widgBur n'est PAS un wigdet c'est un item...
//m_lab_index->setParent(this);
//setAcceptedMouseButtons();

//pt_parent=qobject_cast<WidgBur *>(this->parentWidget());
}

QRectF WidgBur::boundingRect() const
{
return rect_ini;
}

 void WidgBur::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
if(cpl_actif)
{
int a=0;//juste histoire de passer qqchose au drag...
QByteArray data;
QDataStream dataStream(&data, QIODevice::WriteOnly);
dataStream<< a ;

QMimeData *mimeData = new QMimeData;
mimeData->setData("zero",data);

QDrag *drag =new QDrag(event->widget());
drag->setMimeData(mimeData);
drag->exec();

//bar_cpl_actif=true;
//update();
}
}
 void WidgBur::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}
void WidgBur::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
//if(bar_cpl_oth_actif){emit fin_def_cpl();}//TODO
update();
}

 void WidgBur::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
//cout<<"hello we entered me!"<<endl;

if(cpl_actif && (!coupled))
{

//cout<<"hello we entered me!"<<endl;
entered=true;//sert a rien je crois
QColor coul;
coul.setRgb(10,250,250,100);
set_couleur(coul);
update();

}
}

 void WidgBur::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) 
{
//cout<<"leave!!!"<<endl;
if(bar_cpl_actif) emit constr_cpl();
entered=false;
QColor coul;
coul.setRgb(255,255,255);
set_couleur(coul);

update();
}

void WidgBur::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
Q_UNUSED(option);
Q_UNUSED(widget);
//===========contour=============================
    QPen pen;
    QColor coul;
    coul.setRgb(200,100,0,200);  //marron  
    pen.setColor(coul);
   pen.setWidth(3);
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);
/*
    QRectF rect_ajuste(rect_ini);
    rect_ajuste.setWidth(rect_ajuste.width()-1);
    rect_ajuste.setHeight(rect_ajuste.height()-1);

  
      painter->drawRoundedRect(rect_ajuste,4,4);
*/
   //painter->drawRect(rect_ajuste);

    // couleur.setCmyk(0,5,15,0);
    //   couleur.setCmyk(0,0,0,100);
    //     couleur.setRgb(18,13,22);
   //          QPainterPath path_rect;
   //  path_rect.addRect(rect_ajuste);
     QBrush brosse(Qt::SolidPattern);
     brosse.setColor(coul);
   //  painter_fond.fillPath(path_rect,brosse);

//===================================================
//=============================================
 
     QPainterPath path=shape();
    // QBrush brosse(Qt::SolidPattern);
    // brosse.setColor(col);
     QPainterPathStroker pathStroker;
     //pathStroker.setCurveThreshold(0.1);//sert a rien on dirait
     pathStroker.setJoinStyle(Qt::RoundJoin);
     QPainterPath strokedPath=pathStroker.createStroke(path);
     strokedPath.setFillRule(Qt::WindingFill);
     path.setFillRule(Qt::WindingFill);
    // painter->setRenderHint(QPainter::Antialiasing);
     painter->fillPath(strokedPath,brosse);
    // painter->fillPath(path,brosse);


//===================================================
//===========fond=============================

    QPen pen_fond;
    painter->setPen(pen_fond);
    // QRectF rect_fond(rect_ajuste);
    //rect_fond.adjust(1,1,0,0);
    
    // QPainterPath path_rect;
    // path_rect.addRoundedRect(rect_fond,4,4);
     //path_rect.addRect(rect_fond);

   //  QBrush brosse(Qt::SolidPattern);
     brosse.setColor(couleur);
     painter->fillPath(path,brosse);

/*
if(cpl_actif)
{
   // QPainter painter_fond(this);
    QPen pen_fond;
    painter->setPen(pen_fond);
    QRectF rect_fond(rect_ajuste);
    rect_fond.adjust(1,1,0,0);


  
     QColor couleur_fond;
    
if(entered)
{
if(bar_cpl_actif||bar_cpl_oth_actif){couleur_fond.setRgb(150,0,0);if(drop_accepted)couleur_fond.setRgb(0,0,150);}


else{couleur_fond.setRgb(0,150,0);}

}
else
{
if(drag_entrant)couleur_fond.setRgb(150,0,0);
else couleur_fond.setRgb(255,255,255);
}

     QPainterPath path_rect;
     path_rect.addRect(rect_fond);
     QBrush brosse(Qt::SolidPattern);
     brosse.setColor(couleur_fond);
     painter->fillPath(path_rect,brosse);

//===================================================
}*/
//===================indice pr debug====================
/*
QString str,str_2;
QPointF pt=rect_ini.topLeft();
pt.setX(pt.x()+5);
pt.setY(pt.y()+5);
str.append("ind ");
str_2.setNum(index);
str.append(str_2);
str.append("angle ");
 str_2.setNum(get_angle());
str.append(str_2);
painter->drawText(pt,str);
*/
//=======================================================
}

 void WidgBur::aj_cpl_actif(bool cpl_a)
{
cpl_actif=cpl_a;
}

  void WidgBur::bar_oth_en_cour()
{
if(!bar_cpl_actif)//si la bar ne part pas de lui meme
{
bar_cpl_oth_actif=true;
}
}

void WidgBur::dragEnterEvent(QGraphicsSceneDragDropEvent * event)
{
if(event->mimeData()->hasFormat("zero"))
{
event->accept();
bar_cpl_actif=true;
update();
// event->acceptProposedAction();
}
}

void WidgBur::dropEvent(QGraphicsSceneDragDropEvent * event)
{
if(event->mimeData()->hasFormat("zero"))
{
drag_entrant=false;
drop_accepted=true;
 event->accept();
update();
}
}
void WidgBur::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{

if(event->mimeData()->hasFormat("zero"))
{
//cout<<"hello!!"<<endl;

emit clean_others();
drag_entrant=true;
event->accept();
update();
}
}

void WidgBur::clean()
{
drag_entrant=false;
update();
}

  void WidgBur::set_couleur(const QColor & coul)
{
couleur=coul;
update();
}
 
 bool WidgBur::get_coupled()
{
return coupled;
}
void WidgBur::set_coupled(bool cpled)
{
coupled=cpled;
}


WidgLi* WidgBur::get_ptr_li()
{
return ptr_li;
}
void WidgBur::set_ptr_li(WidgLi *ptr)
{
ptr_li=ptr;
}

WidgBur* WidgBur::get_ptr_bur_li()
{
return ptr_bur_li;
}
void WidgBur::set_ptr_bur_li(WidgBur *ptr)
{
ptr_bur_li=ptr;
}

QPainterPath WidgBur::shape() const
{
return painting_path;
}

 void WidgBur::rotation()
{


//====rotation a chaque clic en rad=======
double pi=3.14159265;
double rot_rad=pi/18;//correspond a 10 deg
cout<<"rot_rad"<<rot_rad<<endl;
//=======on ajourne l'angle qui est accessible=======
angle=angle+rot_rad;
//===========================================
//====centre=========
QPointF ctr=get_centre();
//===================
//=========rayon=======
QPointF p=polygon_shape.at(0);
double R=sqrt(pow(p.x()-ctr.x(),2)+pow(p.y()-ctr.y(),2));

double a,b,a_p,b_p;
for(int i=0;i<polygon_shape.size();i++)
{
p=polygon_shape.at(i);

//=========angle par rap a l'horizontale omega=====
a=p.y()-ctr.y();
b=p.x()-ctr.x();
double omega;
if(a>0&&b>0)
{
omega=asin(a/R);
}
if(a>0&&b<0)
{
omega=-asin(a/R)+pi;
}
if(a<0&&b<0)
{
omega=-asin(a/R)-pi;
}
if(a<0&&b>0)
{
omega=asin(a/R);
}


cout<<"ctr.y-p.y()"<<ctr.y()-p.y()<<endl;
cout<<"omega"<<omega<<endl;

//=====nouvel angle alpha=======
double alpha=omega+rot_rad;cout<<"alpha"<<alpha<<endl;
//==========nouveaux points=====
a_p=R*sin(alpha);cout<<"a"<<a<<endl;
b_p=R*cos(alpha);
polygon_shape[i].setY(ctr.y()+a_p);
polygon_shape[i].setX(ctr.x()+b_p);
}
cout<<"coucou"<<endl;
QPainterPath new_path;
new_path.addPolygon(polygon_shape);
painting_path=new_path;
double x_inf,x_sup,y_inf,y_sup;
x_inf=ctr.x();
x_sup=ctr.x();
y_inf=ctr.y();
y_sup=ctr.y();
for(int i=0;i<polygon_shape.size();i++)
{
double x_pass,y_pass;
x_pass=polygon_shape.at(i).x();
y_pass=polygon_shape.at(i).y();

if (x_pass<x_inf) x_inf=x_pass;
if (x_pass>x_sup) x_sup=x_pass;
if (y_pass<y_inf) y_inf=y_pass;
if (y_pass>y_sup) y_sup=y_pass;

}
//QPointF p_1(x_inf,y_inf),p_2(x_inf,y_sup),p_3(x_sup,y_sup),p_4(x_sup,y_inf);
QRectF rect(x_inf,y_inf,x_sup-x_inf,y_sup-y_inf);
rect_ini=rect;
update();
}
 
QPointF WidgBur::get_centre()
{
QPointF p_1;
QPointF p_2;

p_1=polygon_shape.at(0);
p_2=polygon_shape.at(2);

double Dx=(p_2.x()-p_1.x())/2;
double Dy=(p_2.y()-p_1.y())/2;

QPointF centre(p_1.x()+Dx,p_1.y()+Dy);
cout<<"centre.x()"<<centre.x()<<"centre.y()"<<centre.y();
return(centre);
}

//mal code pas besoin du painterpath...
void WidgBur::set_shape(QPainterPath path_shape,QPolygonF poly_shape)
{
painting_path=path_shape;
polygon_shape=poly_shape;

}

 QPolygonF WidgBur::get_polygon() 
{
return polygon_shape;
}

QPainterPath WidgBur::rotated_shape()
{
//copie à partir de la rotation
//====rotation a chaque clic en rad=======
double pi=3.14159265;
double rot_rad=pi/18;//correspond a 10 deg
cout<<"rot_rad"<<rot_rad<<endl;
//===========================================
//====centre=========
QPointF ctr=get_centre();
//===================
//=========rayon=======
QPointF p=polygon_shape.at(0);
double R=sqrt(pow(p.x()-ctr.x(),2)+pow(p.y()-ctr.y(),2));

QPolygonF polygon_shape_cp;
polygon_shape_cp=polygon_shape;

double a,b,a_p,b_p;
for(int i=0;i<polygon_shape.size();i++)
{
p=polygon_shape.at(i);

//=========angle par rap a l'horizontale omega=====
a=p.y()-ctr.y();
b=p.x()-ctr.x();
double omega;
if(a>0&&b>0)
{
omega=asin(a/R);
}
if(a>0&&b<0)
{
omega=-asin(a/R)+pi;
}
if(a<0&&b<0)
{
omega=-asin(a/R)-pi;
}
if(a<0&&b>0)
{
omega=asin(a/R);
}


cout<<"ctr.y-p.y()"<<ctr.y()-p.y()<<endl;
cout<<"omega"<<omega<<endl;

//=====nouvel angle alpha=======
double alpha=omega+rot_rad;cout<<"alpha"<<alpha<<endl;
//==========nouveaux points=====
a_p=R*sin(alpha);cout<<"a"<<a<<endl;
b_p=R*cos(alpha);
polygon_shape_cp[i].setY(ctr.y()+a_p);
polygon_shape_cp[i].setX(ctr.x()+b_p);
}
cout<<"coucou_bis"<<endl;
QPainterPath new_path;
new_path.addPolygon(polygon_shape_cp);
return new_path;
/*
double x_inf,x_sup,y_inf,y_sup;
x_inf=ctr.x();
x_sup=ctr.x();
y_inf=ctr.y();
y_sup=ctr.y();
for(int i=0;i<polygon_shape.size();i++)
{
double x_pass,y_pass;
x_pass=polygon_shape.at(i).x();
y_pass=polygon_shape.at(i).y();

if (x_pass<x_inf) x_inf=x_pass;
if (x_pass>x_sup) x_sup=x_pass;
if (y_pass<y_inf) y_inf=y_pass;
if (y_pass>y_sup) y_sup=y_pass;

}*/
//QPointF p_1(x_inf,y_inf),p_2(x_inf,y_sup),p_3(x_sup,y_sup),p_4(x_sup,y_inf);
//QRectF rect(x_inf,y_inf,x_sup-x_inf,y_sup-y_inf);
//rect_ini=rect;
//update();

}

  void WidgBur::set_index(int ind)
{
index=ind;
//pr debug
//QString str;
//str.setNum(ind);
//m_lab_index->setText(str);
}
int WidgBur::get_index()
{
return index;
}
void WidgBur::set_angle(double ang)
{
angle=ang;
}
double WidgBur::get_angle()
{
return angle;
}

 QRectF WidgBur::get_rect_eff()
{
return rect_eff;
}

