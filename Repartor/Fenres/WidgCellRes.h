#ifndef WIDGCELLRES_H
#define WIDGCELLRES_H



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

#include "Fenro/FenRo.h"



class WidgCellRes :  public QGraphicsObject 
{

    Q_OBJECT

public:

    WidgCellRes(QRectF rect,QGraphicsItem *parent=0);

    QRectF boundingRect() const;
    QPainterPath shape() const;
    enum ModeCroix{NOCROIX,CROIX,CROIXP,CROIXR};

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=0);
    void set_couleur(const QColor & coul);

    void setModeCroix(ModeCroix mc){modeCroix=mc;update();}
    ModeCroix getModeCroix(){return modeCroix;}

    QPolygonF get_polygon();
    void set_shape(QPainterPath,QPolygonF);

    QPainterPath rotated_shape();

    QPointF get_centre();


    void set_index(int);
    int get_index();
    void set_angle(double);
    double get_angle();
    QRectF get_rect_eff();

    void set_text(QString);

    void set_occupe(bool b){occupe=b;}
    bool get_occupe(){return occupe;}

protected:
    void mousePressEvent(QGraphicsSceneMouseEvent *);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *);
    
    virtual  void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);

    void dragEnterEvent(QGraphicsSceneDragDropEvent *);
    void dragMoveEvent(QGraphicsSceneDragDropEvent *);
    void dropEvent(QGraphicsSceneDragDropEvent *);


signals:

    void drop_catched();

public slots:

    void rotation();
    void rotation(double ang_rad);

private:
    
    QRectF rect_ini;//bounding rect
    QRectF rect_eff;

    QColor couleur;

    QPainterPath painting_path;
    QPolygonF polygon_shape;


    int index;
    double angle;
    
    QString N_text;
    bool occupe;
    ModeCroix modeCroix;
};
#endif
