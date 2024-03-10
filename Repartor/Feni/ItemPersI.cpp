
#include "ItemPersI.h"

using namespace std; 


ItemPersI::ItemPersI(QRectF rect,QString string_N,QGraphicsItem *parent) :QGraphicsItem(parent)
{

couleur.setRgb(255,255,255);//fond 
rect_ini=rect;
str=string_N;
}

QRectF ItemPersI::boundingRect() const
{
return rect_ini;
}

 
void  ItemPersI::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
{
Q_UNUSED(option);
Q_UNUSED(widget);
//===========contour=============================
    QPen pen;
    QColor coul;
   // coul.setRgb(0,0,0,200);  //noir c'est noir  
    coul.setRgb(131,139,131); //gris
    pen.setColor(coul);
   pen.setWidth(3);
    painter->setPen(pen);
    painter->setRenderHint(QPainter::Antialiasing);

    QRectF rect_ajuste(rect_ini);
    rect_ajuste.setWidth(rect_ajuste.width()-1);
    rect_ajuste.setHeight(rect_ajuste.height()-1);

  
      painter->drawRoundedRect(rect_ajuste,4,4);

//===================================================

//===========fond=============================

    QPen pen_fond;
    painter->setPen(pen_fond);
    QRectF rect_fond(rect_ajuste);
      
     QPainterPath path_rect;
     path_rect.addRoundedRect(rect_fond,4,4);
     //path_rect.addRect(rect_fond);

     QBrush brosse(Qt::SolidPattern);
     brosse.setColor(couleur);
     painter->fillPath(path_rect,brosse);

//====================== text=============================

     QPen pen_text;
     pen_text.setColor(coul);//le gris du contour
    // pen_text.setWidth(20);
     painter->setPen(pen_text);
     painter->drawText(this->boundingRect(),Qt::AlignCenter,str);


//=========================================================

}

 void ItemPersI::set_couleur(const QColor & coul)
{
couleur=coul;
update();
}

QString  ItemPersI::get_nm()
{
return str;
}

