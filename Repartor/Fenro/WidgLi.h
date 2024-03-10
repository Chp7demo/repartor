#ifndef WIDGLI_H
#define WIDGLI_H



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

class WidgBur;
class FenRoDes;
class WidgLi :  public QGraphicsObject 
{

    Q_OBJECT

    public:
	WidgLi(QPointF,QPointF,QGraphicsItem *parent=0);

       QRectF boundingRect() const;//useless?
       QPainterPath shape() const;
	void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=0);
        void set_couleur(const QColor & coul);
      
        WidgBur* get_ptr_bout();
        void set_ptr_bout(WidgBur *);
      

    protected:
        void mousePressEvent(QGraphicsSceneMouseEvent *);
        void mouseMoveEvent(QGraphicsSceneMouseEvent *);
        void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    
    virtual   void hoverEnterEvent(QGraphicsSceneHoverEvent *);
       void hoverLeaveEvent(QGraphicsSceneHoverEvent *);  

        void dragEnterEvent(QGraphicsSceneDragDropEvent *);
        //void dragLeaveEvent(QGraphicsSceneDragDropEvent *);
        void dragMoveEvent(QGraphicsSceneDragDropEvent *);
        void dropEvent(QGraphicsSceneDragDropEvent *);

       
    signals:

    public slots:
      
    private:
   QPolygonF creat_poly_1(const QPointF &pt_1,const QPointF &pt_2,double a);
   QPolygonF creat_poly_2(const QPointF &pt_1,const QPointF &pt_2,double a);



 
   QRectF b_rect;
   QPainterPath painting_path;
   QPointF p_1;
   QPointF p_2;


   bool entered;//util?
   QColor col;

  WidgBur* ptr_bout;
 
  };
#endif
