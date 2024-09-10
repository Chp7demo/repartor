#include "LiI.h"

using namespace std; 


LiI::LiI(QPointF p1,QPointF p2,QGraphicsItem *parent) :QGraphicsItem(parent)
{
    col.setRgb(90,5,200,130); //un bleu
    coul_3.setRgb(10,200,80,100);
    coul_2.setRgb(50,180,80,100);
    coul_1.setRgb(20,200,180,100);
    coul_5.setRgb(200,20,10,100);
    coul_4.setRgb(200,70,10,100);

    li_mode=interType::NO_INTER;

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
        rect.adjust(0,0,1,1);//utile?
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
        rect.adjust(0,1,1,0);//utile?

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

    b_rect=rect;
    b_rect.adjust(-a,-a,a,a);

}

QPainterPath LiI::shape() const
{
    return painting_path;
}

QRectF LiI::boundingRect() const
{
    return b_rect;
}


void LiI::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
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
    QPainterPath strokedPath=pathStroker.createStroke(path);
    strokedPath.setFillRule(Qt::WindingFill);
    path.setFillRule(Qt::WindingFill);
    painter->setRenderHint(QPainter::Antialiasing);
    painter->fillPath(path,brosse);

    //===================================================

}




QPolygonF LiI::creat_poly_1(const QPointF &pt_1,const QPointF &pt_2,double a)
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



QPolygonF LiI::creat_poly_2(const QPointF &pt_1,const QPointF &pt_2,double a)
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

void LiI::set_couleur(const QColor & coul)
{
    col=coul;
    update();
}

QString LiI::get_nm_1()
{
    return nm_1;
}

QString LiI::get_nm_2()
{
    return nm_2;
}

void LiI::set_nm_1(QString str)
{
    nm_1=str;
}

void LiI::set_nm_2(QString str)
{
    nm_2=str;
}

void LiI::set_li_mode(interType inter_type)
{
    li_mode=inter_type;
    switch(li_mode)
    {
    case interType::NO_INTER:
        break;
    case interType::PARTNERS:col=coul_1;
        break;
    case interType::BRING_CLOSE:col=coul_2;
        break;
    case interType::BRING_VERY_CLOSE:col=coul_3;
        break;
    case interType::SPLIT:col=coul_4;
        break;
    case interType::SPLIT_FAR:col=coul_5;
        break;
    }
    update();

}

interType LiI::get_li_mode()
{
    return li_mode;
}   

void LiI::set_nm_bouts(QString str_1,QString str_2)
{
    nm_1=str_1;
    nm_2=str_2;
}

