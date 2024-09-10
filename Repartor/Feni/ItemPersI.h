#ifndef ITEMPERSI_H
#define ITEMPERSI_H



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

class ItemPersI :  public QGraphicsItem
{

    
public:

    ItemPersI(QRectF rect,QString string_N,QGraphicsItem *parent=0);

    QRectF boundingRect() const;
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=0);
    void set_couleur(const QColor & coul);
    QString get_nm();

    
protected:

signals:

public slots:

private:

    QRectF rect_ini;
    QColor couleur;//fond
    QString str;

};
#endif
