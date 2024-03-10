#ifndef LII_H
#define LII_H



#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>



#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QObject>
#include <QPaintEvent>
#include <QPainter>
#include <QRect>
#include <QPen>
#include <QVector>
#include <QPointF>
#include <QPoint>
#include <QPolygonF>
#include <QSpinBox>
#include <QString>
#include <QMetaType>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QDragEnterEvent>
#include <QDragMoveEvent>
#include <QDropEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QRectF>
#include <QGraphicsSceneDragDropEvent>
#include <QGraphicsSceneMouseEvent>
#include <QGraphicsSceneHoverEvent>
#include <QGraphicsObject>
#include <QPainterPath>
#include <QPolygon>
#include <QPainterPathStroker>

#include "mes_types.h"

class LiI :  public QGraphicsItem 
{


    public:
	LiI(QPointF,QPointF,QGraphicsItem *parent=0);

       QRectF boundingRect() const;
       QPainterPath shape() const;
	void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=0);
        void set_couleur(const QColor & coul);//obsolete?
      
        QString get_nm_1();
        QString get_nm_2();
 
        void set_nm_1(QString);
        void set_nm_2(QString);
        
        void set_li_mode(interType);
        interType get_li_mode();                  
        void set_nm_bouts(QString,QString);
    protected:
           
   
       
    signals:

    public slots:
      
    private:
   QPolygonF creat_poly_1(const QPointF &pt_1,const QPointF &pt_2,double a);
   QPolygonF creat_poly_2(const QPointF &pt_1,const QPointF &pt_2,double a);



 
   QRectF b_rect;
   QPainterPath painting_path;
   QPointF p_1;
   QPointF p_2;

interType li_mode;

QString nm_1;
QString nm_2;

    QColor col;

QColor coul_1;
QColor coul_2;
QColor coul_3;
QColor coul_4;
QColor coul_5;

  };
#endif
