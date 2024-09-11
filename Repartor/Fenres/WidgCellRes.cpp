
#include "WidgCellRes.h"
#include "FenRes.h"

using namespace std; 


WidgCellRes::WidgCellRes(QRectF rect,QGraphicsItem *parent) :QGraphicsObject(parent)
{

    modeCroix=NOCROIX;
    occupe=false;
    couleur.setRgb(255,255,255,0);
    rect_ini=rect;
    rect_eff=rect;
    QPolygonF p_pass(rect);
    polygon_shape=p_pass;
    painting_path.addPolygon(polygon_shape);

    setAcceptDrops(true);

}


QRectF WidgCellRes::boundingRect() const
{
    return rect_ini;
}


void WidgCellRes::mousePressEvent(QGraphicsSceneMouseEvent *event)
{   
}

void WidgCellRes::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}

void WidgCellRes::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
}

void WidgCellRes::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{
}

void WidgCellRes::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
}

void WidgCellRes::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
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
    QBrush brosse(Qt::SolidPattern);
    brosse.setColor(coul);

    //=============================================
    QPainterPath path=shape();
    QPainterPathStroker pathStroker;
    pathStroker.setJoinStyle(Qt::RoundJoin);
    QPainterPath strokedPath=pathStroker.createStroke(path);
    strokedPath.setFillRule(Qt::WindingFill);
    path.setFillRule(Qt::WindingFill);
    painter->fillPath(strokedPath,brosse);


    //===========fond=============================
    QPen pen_fond;
    painter->setPen(pen_fond);
    brosse.setColor(couleur);
    painter->fillPath(path,brosse);

    //===================Croix========================
    QColor  gris_croix;
    gris_croix.setRgb(200,200,200,180);
    QColor  rouge_croix;
    rouge_croix.setRgb(200,10,10,180);

    //======bebug========
    QColor  autre;
    autre.setRgb(2,150,5,180);

    //=====================
    QPointF p_1=polygon_shape.at(0);
    QPointF p_2=polygon_shape.at(2);
    QPointF p_3=polygon_shape.at(1);
    QPointF p_4=polygon_shape.at(3);

    QLineF line_1(p_1,p_2);
    QLineF line_2(p_3,p_4);

    switch(modeCroix)
    {
    case NOCROIX:
        break;
    case CROIX:
        pen.setColor(gris_croix);
        painter->setPen(pen);
        painter->drawLine(line_1);
        painter->drawLine(line_2);
        break;
    case CROIXR:
        pen.setColor(rouge_croix);
        painter->setPen(pen);
        painter->drawLine(line_1);
        painter->drawLine(line_2);
        break;
    case CROIXP:
        pen.setColor(gris_croix);
        pen.setStyle(Qt::DashLine);
        painter->setPen(pen);
        painter->drawLine(line_1);
        painter->drawLine(line_2);

        break;
    }

}


void WidgCellRes::dragEnterEvent(QGraphicsSceneDragDropEvent * event)
{//TODO verif format
    event->accept();
}

void WidgCellRes::dropEvent(QGraphicsSceneDragDropEvent * event)
{
    event->acceptProposedAction();
}


void WidgCellRes::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{
    //TODO verif format
    event->accept();
}


void WidgCellRes::set_couleur(const QColor & coul)
{
    couleur=coul;
    update();
}



QPainterPath WidgCellRes::shape() const
{
    return painting_path;
}


void WidgCellRes::rotation()
{
    double pi=3.14159265;

    //rotation de 10 deg
    rotation(pi/18);
}



void WidgCellRes::rotation(double ang_rad)
{


    //====rotation a chaque clic en rad=======
    double pi=3.14159265;
    double rot_rad=ang_rad;//pi/18;//correspond a 10 deg

    //=======on ajourne l'angle qui est accessible=======
    angle=angle+rot_rad;

    //====centre=========
    QPointF ctr=get_centre();

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
        double omega=0;
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


        //=====nouvel angle alpha=======
        double alpha=omega+rot_rad;

        //==========nouveaux points=====
        a_p=R*sin(alpha);
        b_p=R*cos(alpha);
        polygon_shape[i].setY(ctr.y()+a_p);
        polygon_shape[i].setX(ctr.x()+b_p);
    }

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

    QRectF rect(x_inf,y_inf,x_sup-x_inf,y_sup-y_inf);
    rect_ini=rect;
    update();
}


QPointF WidgCellRes::get_centre()
{
    QPointF p_1;
    QPointF p_2;

    p_1=polygon_shape.at(0);
    p_2=polygon_shape.at(2);

    double Dx=(p_2.x()-p_1.x())/2;
    double Dy=(p_2.y()-p_1.y())/2;

    QPointF centre(p_1.x()+Dx,p_1.y()+Dy);
    return(centre);
}


//mal codé pas besoin du painterpath...
void WidgCellRes::set_shape(QPainterPath path_shape,QPolygonF poly_shape)
{
    painting_path=path_shape;
    polygon_shape=poly_shape;
}

QPolygonF WidgCellRes::get_polygon()
{
    return polygon_shape;
}

QPainterPath WidgCellRes::rotated_shape()
{
    //copie à partir de la rotation
    //====rotation a chaque clic en rad=======
    double pi=3.14159265;
    double rot_rad=pi/18;//correspond a 10 deg

    //====centre=========
    QPointF ctr=get_centre();

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
        double omega=0;
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



        //=====nouvel angle alpha=======
        double alpha=omega+rot_rad;

        //==========nouveaux points=====
        a_p=R*sin(alpha);
        b_p=R*cos(alpha);
        polygon_shape_cp[i].setY(ctr.y()+a_p);
        polygon_shape_cp[i].setX(ctr.x()+b_p);
    }

    QPainterPath new_path;
    new_path.addPolygon(polygon_shape_cp);
    return new_path;
}

void WidgCellRes::set_index(int ind)
{
    index=ind;
}


int WidgCellRes::get_index()
{
    return index;
}


void WidgCellRes::set_angle(double ang)
{
    angle=ang;
}


double WidgCellRes::get_angle()
{
    return angle;
}

QRectF WidgCellRes::get_rect_eff()
{
    return rect_eff;
}


void WidgCellRes::set_text(QString str)
{
    N_text=str;
    update();
}

