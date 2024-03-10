#ifndef WIDGBUR_H
#define WIDGBUR_H



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
#include "FenRo.h"
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
#include <QMimeData>
#include <QDrag>


#include "WidgLi.h"

class WidgLi;
class FenRoDes;
class WidgBur :  public QGraphicsObject 
{

    Q_OBJECT

    public:
        WidgLi* get_ptr_li();
        void set_ptr_li(WidgLi *);
        WidgBur* get_ptr_bur_li();
        void set_ptr_bur_li(WidgBur *);

	WidgBur(QRectF rect,QGraphicsItem *parent=0);

        QRectF boundingRect() const;
        QPainterPath shape() const;


	void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=0);
       void set_couleur(const QColor & coul);
       bool get_coupled();
       void set_coupled(bool);
     
       QPolygonF get_polygon(); 
       void set_shape(QPainterPath,QPolygonF);
      
      QPainterPath rotated_shape();

      QPointF get_centre();


       void set_index(int);
       int get_index();
       void set_angle(double);//useless
       double get_angle();
       QRectF get_rect_eff();



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
    void constr_cpl();
    void clean_others();

    public slots:
     void aj_cpl_actif(bool);
     void bar_oth_en_cour();
     void clean();

     void rotation();

     private:
   
     bool entered; 
     bool cpl_actif;
     bool bar_cpl_actif;
     bool bar_cpl_oth_actif;
     bool drop_accepted;
     bool drag_entrant;

     bool coupled;

     QRectF rect_ini;
     QRectF rect_eff;

     QColor couleur;

     WidgLi * ptr_li;
     WidgBur * ptr_bur_li;


    QPainterPath painting_path;
    QPolygonF polygon_shape;


    int index;
    double angle;

 // QLabel *m_lab_index;//pr le debug (ou pr mettre des indice sur l'image a voir...)
};
#endif
