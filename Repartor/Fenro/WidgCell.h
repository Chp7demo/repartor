#ifndef WIDGCELL_H
#define WIDGCELL_H



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
class WidgCell :  public QGraphicsObject
{

    Q_OBJECT

public:
    WidgLi* get_ptr_li();
    void set_ptr_li(WidgLi *);
    WidgCell* get_ptr_cell_li();
    void set_ptr_cell_li(WidgCell *);

    WidgCell(QRectF rect,QGraphicsItem *parent=0);

    QRectF boundingRect() const;
    QPainterPath shape() const;

    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=0);
    void set_couleur(const QColor & coul);
    bool have_cpl();
    void set_have_cpl(bool);

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

    bool havecpl;

    QRectF rect_ini;
    QRectF rect_eff;

    QColor couleur;

    WidgLi * ptr_li;
    WidgCell * ptr_cell_li;


    QPainterPath painting_path;
    QPolygonF polygon_shape;


    int index;
    double angle;


};
#endif
