
#include "WidgCell.h"

using namespace std; 


WidgCell::WidgCell(QRectF rect,QGraphicsItem *parent) :QGraphicsObject(parent)
{

    couleur.setRgb(255,255,255,0);
    ptr_li=NULL;
    ptr_cell_li=NULL;
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
    havecpl=false;
    setAcceptDrops(true);
    setAcceptHoverEvents(true);

    angle=0;

}


QRectF WidgCell::boundingRect() const
{
    return rect_ini;
}


void WidgCell::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(cpl_actif)
    {
        int a=0;//pour passer qqchose au drag...
        QByteArray data;
        QDataStream dataStream(&data, QIODevice::WriteOnly);
        dataStream<< a ;

        QMimeData *mimeData = new QMimeData;
        mimeData->setData("zero",data);

        QDrag *drag =new QDrag(event->widget());
        drag->setMimeData(mimeData);
        drag->exec();

    }
}


void WidgCell::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
}


void WidgCell::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    update();
}


void WidgCell::hoverEnterEvent(QGraphicsSceneHoverEvent *event)
{


    if(cpl_actif && (!havecpl))
    {

        entered=true;//utile?
        QColor coul;
        coul.setRgb(10,250,250,100);
        set_couleur(coul);
        update();

    }
}



void WidgCell::hoverLeaveEvent(QGraphicsSceneHoverEvent *event)
{
    if(bar_cpl_actif) emit constr_cpl();
    entered=false;
    QColor coul;
    coul.setRgb(255,255,255);
    set_couleur(coul);

    update();
}



void WidgCell::paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget)
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


    //===================================================

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

}



void WidgCell::aj_cpl_actif(bool cpl_a)
{
    cpl_actif=cpl_a;
}


void WidgCell::bar_oth_en_cour()
{
    if(!bar_cpl_actif)//si la bar ne part pas d'elle meme
    {
        bar_cpl_oth_actif=true;
    }
}


void WidgCell::dragEnterEvent(QGraphicsSceneDragDropEvent * event)
{
    if(event->mimeData()->hasFormat("zero"))
    {
        event->accept();
        bar_cpl_actif=true;
        update();
    }
}


void WidgCell::dropEvent(QGraphicsSceneDragDropEvent * event)
{
    if(event->mimeData()->hasFormat("zero"))
    {
        drag_entrant=false;
        drop_accepted=true;
        event->accept();
        update();
    }
}


void WidgCell::dragMoveEvent(QGraphicsSceneDragDropEvent *event)
{

    if(event->mimeData()->hasFormat("zero"))
    {

        emit clean_others();
        drag_entrant=true;
        event->accept();
        update();
    }
}


void WidgCell::clean()
{
    drag_entrant=false;
    update();
}


void WidgCell::set_couleur(const QColor & coul)
{
    couleur=coul;
    update();
}


bool WidgCell::have_cpl()
{
    return havecpl;
}


void WidgCell::set_have_cpl(bool cpled)
{
    havecpl=cpled;
}


WidgLi* WidgCell::get_ptr_li()
{
    return ptr_li;
}


void WidgCell::set_ptr_li(WidgLi *ptr)
{
    ptr_li=ptr;
}


WidgCell* WidgCell::get_ptr_cell_li()
{
    return ptr_cell_li;
}


void WidgCell::set_ptr_cell_li(WidgCell *ptr)
{
    ptr_cell_li=ptr;
}

QPainterPath WidgCell::shape() const
{
    return painting_path;
}

void WidgCell::rotation()
{


    //====rotation a chaque clic en rad=======
    double pi=3.14159265;
    double rot_rad=pi/18;//correspond à 10 deg

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


QPointF WidgCell::get_centre()
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
void WidgCell::set_shape(QPainterPath path_shape,QPolygonF poly_shape)
{
    painting_path=path_shape;
    polygon_shape=poly_shape;

}


QPolygonF WidgCell::get_polygon()
{
    return polygon_shape;
}

QPainterPath WidgCell::rotated_shape()
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

void WidgCell::set_index(int ind)
{
    index=ind;
}


int WidgCell::get_index()
{
    return index;
}


void WidgCell::set_angle(double ang)
{
    angle=ang;
}


double WidgCell::get_angle()
{
    return angle;
}

QRectF WidgCell::get_rect_eff()
{
    return rect_eff;
}

