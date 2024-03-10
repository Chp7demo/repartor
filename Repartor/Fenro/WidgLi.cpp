#include "WidgLi.h"

using namespace std; 


WidgLi::WidgLi(QPointF p1,QPointF p2,QGraphicsItem *parent) :QGraphicsObject(parent)
{
 col.setRgb(90,5,200,130);    

entered=false;

p_1=p1;
p_2=p2;

QRectF rect;
QPolygonF poly;
double a=4;// demi epaisseur liaison
if((p_1.x()<p_2.x())&&(p_1.y()<p_2.y())) 
{
poly=creat_poly_2(p_1,p_2,a);
QRectF r(p_1,p_2);
rect=r;
rect.adjust(0,0,1,1);
}
if((p_1.x()<p_2.x())&&(p_1.y()>=p_2.y())) 
{
poly=creat_poly_1(p_1,p_2,a);

QPoint pt_1_bis;
QPoint pt_2_bis;
pt_1_bis.setX(p_1.x());
pt_1_bis.setY(p_2.y());
pt_2_bis.setX(p_2.x());
pt_2_bis.setY(p_1.y());
QRect r(pt_1_bis,pt_2_bis);
rect=r;
rect.adjust(0,1,1,0);

}
if((p_1.x()>=p_2.x())&&(p_1.y()<p_2.y())) 
{
poly=creat_poly_2(p_2,p_1,a);

QPoint pt_1_bis;
QPoint pt_2_bis;
pt_1_bis.setX(p_2.x());
pt_1_bis.setY(p_1.y());
pt_2_bis.setX(p_1.x());
pt_2_bis.setY(p_2.y());
QRectF r(pt_1_bis,pt_2_bis);
rect=r;
rect.adjust(1,0,0,1);
}

if((p_1.x()>=p_2.x())&&(p_1.y()>=p_2.y()))
{
poly=creat_poly_1(p_2,p_1,a);

QRectF r(p_2,p_1);
rect=r;
rect.adjust(1,1,0,0);
}

//painting path==========================================

painting_path.addPolygon(poly);
painting_path.addEllipse(p_1,a,a);
painting_path.addEllipse(p_2,a,a);

//bounding rect=================================================
//pas sur que ce soit bien le bounding rect... mais bon...
b_rect=rect;
b_rect.adjust(-a,-a,a,a);

setAcceptHoverEvents(true);
//setAcceptedMouseButtons();

//pt_parent=qobject_cast<WidgLi *>(this->parentWidget());
}

QPainterPath WidgLi::shape() const
{
/*
QPainterPath path;
QPolygonF polygon;


//TODO faire calculs trigo pour faire une belle liaison...
QPointF p_1_a=p_1;
QPointF p_1_b=p_1;
QPointF p_2_a=p_2;
QPointF p_2_b=p_2;
//trigo...a faire
p_1_a.setX(p_1.x()+5);
p_2_a.setY(p_2.y()+5);
polygon<<p_1_a<<p_1_b<<p_2_a<<p_2_b;
path.addPolygon(polygon);
*/
return painting_path;
}

QRectF WidgLi::boundingRect() const
{
return b_rect;
}

 void WidgLi::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
}
 void WidgLi::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}
void WidgLi::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

 void WidgLi::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
entered=true;
update();//utile?
}

 void WidgLi::hoverLeaveEvent(QGraphicsSceneHoverEvent *event) 
{
entered=false;
update();//utile?

}

void WidgLi::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
Q_UNUSED(option);
Q_UNUSED(widget);
//=============================================
    QPen pen;
      pen.setColor(col);
    painter->setPen(pen);

     QPainterPath path=shape();
     QBrush brosse(Qt::SolidPattern);
     brosse.setColor(col);
     QPainterPathStroker pathStroker;
     //pathStroker.setCurveThreshold(0.1);//sert a rien on dirait
     //pathStroker.setJoinStyle(Qt::RoundJoin);
     QPainterPath strokedPath=pathStroker.createStroke(path);
     strokedPath.setFillRule(Qt::WindingFill);
     path.setFillRule(Qt::WindingFill);
     painter->setRenderHint(QPainter::Antialiasing);
    // painter->fillPath(strokedPath,brosse);
     painter->fillPath(path,brosse);


//===================================================

}


void WidgLi::dragEnterEvent(QGraphicsSceneDragDropEvent * event)
{
}

void WidgLi::dropEvent(QGraphicsSceneDragDropEvent * event)
{
}
void WidgLi::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
}


QPolygonF WidgLi::creat_poly_1(const QPointF &pt_1,const QPointF &pt_2,double a)
{
double teta=atan( double((pt_1.y()-pt_2.y())/(pt_2.x()-pt_1.x())));
double a_cos=a*cos(teta);
double a_sin=a*sin(teta);

QPointF pt_1_a;
QPointF pt_1_b;
QPointF pt_2_a;
QPointF pt_2_b;

pt_1_a.setY(pt_1.y()-a_cos);
pt_1_a.setX(pt_1.x()-a_sin);
pt_1_b.setY(pt_1.y()+a_cos);
pt_1_b.setX(pt_1.x()+a_sin);

pt_2_a.setY(pt_2.y()-a_cos);
pt_2_a.setX(pt_2.x()-a_sin);
pt_2_b.setY(pt_2.y()+a_cos);
pt_2_b.setX(pt_2.x()+a_sin);

QPolygonF poly;
poly<<pt_1_a<<pt_2_a<<pt_2_b<<pt_1_b;
return poly;
}



QPolygonF WidgLi::creat_poly_2(const QPointF &pt_1,const QPointF &pt_2,double a)
{
double teta=atan( double((pt_2.y()-pt_1.y())/(pt_2.x()-pt_1.x())));
double a_cos=a*cos(teta);
double a_sin=a*sin(teta);

QPointF pt_1_a;
QPointF pt_1_b;
QPointF pt_2_a;
QPointF pt_2_b;

pt_1_a.setY(pt_1.y()-a_cos);
pt_1_a.setX(pt_1.x()+a_sin);
pt_1_b.setY(pt_1.y()+a_cos);
pt_1_b.setX(pt_1.x()-a_sin);

pt_2_a.setY(pt_2.y()-a_cos);
pt_2_a.setX(pt_2.x()+a_sin);
pt_2_b.setY(pt_2.y()+a_cos);
pt_2_b.setX(pt_2.x()-a_sin);

QPolygonF poly;
poly<<pt_1_a<<pt_2_a<<pt_2_b<<pt_1_b;
return poly;

}

  void WidgLi::set_couleur(const QColor & coul)
{
col=coul;
update();
}

WidgBur* WidgLi::get_ptr_bout()
{
return ptr_bout;
}
void WidgLi::set_ptr_bout(WidgBur *ptr)
{
ptr_bout=ptr;
}

