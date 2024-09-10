#ifndef FENI_H
#define FENI_H



#include <iostream>
#include <math.h>
#include <string>
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
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QRectF>
#include <QEvent>

#include <string.h>

#include "ItemPersI.h"
#include "LiI.h"
#include "Elements_and_space.h"


enum class ViewModeI{NOMODE,MODE1,MODE2,MODE3,MODE4,MODE5,MODE6};

class MaGraphicsViewI : public QGraphicsView
{
    Q_OBJECT

public:
    MaGraphicsViewI(QGraphicsScene* scene,QWidget *parent=0);

protected:

    void mousePressEvent(QMouseEvent *);

    void mousePressEvent_NOMODE(QMouseEvent *event);
    void mousePressEvent_MODE1(QMouseEvent *event);
    void mousePressEvent_MODE2(QMouseEvent *event);
    void mousePressEvent_MODE3(QMouseEvent *event);
    void mousePressEvent_MODE4(QMouseEvent *event);
    void mousePressEvent_MODE5(QMouseEvent *event);
    void mousePressEvent_MODE6(QMouseEvent *event);


    void mouseMoveEvent(QMouseEvent *);

    void mouseMoveEvent_NOMODE(QMouseEvent *event);
    void mouseMoveEvent_MODE1(QMouseEvent *event);
    void mouseMoveEvent_MODE2(QMouseEvent *event);
    void mouseMoveEvent_MODE3(QMouseEvent *event);
    void mouseMoveEvent_MODE4(QMouseEvent *event);
    void mouseMoveEvent_MODE5(QMouseEvent *event);
    void mouseMoveEvent_MODE6(QMouseEvent *event);


    void mouseReleaseEvent(QMouseEvent *);

    void mouseReleaseEvent_NOMODE(QMouseEvent *event);
    void mouseReleaseEvent_MODE1(QMouseEvent *event);
    void mouseReleaseEvent_MODE2(QMouseEvent *event);
    void mouseReleaseEvent_MODE3(QMouseEvent *event);
    void mouseReleaseEvent_MODE4(QMouseEvent *event);
    void mouseReleaseEvent_MODE5(QMouseEvent *event);
    void mouseReleaseEvent_MODE6(QMouseEvent *event);

    void mousePressEvent_SUPR(QMouseEvent *event);
    void mouseMoveEvent_SUPR(QMouseEvent *event);
    void mouseReleaseEvent_SUPR(QMouseEvent *event);


    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent * event);
    void dragEnterEvent(QDragEnterEvent *);


    void wheelEvent(QWheelEvent *event);


signals:
    void new_inter(QString,QString,interType);
    void sous();

public slots:
    void aff_cercle(Elements);
    void setMode(ViewModeI vM);

private:
    ItemPersI*  trouve_it(const QPointF & point);
    LiI*  trouve_li(const QPointF & point);

    QVector<QPointF> calcul_pos(int taille_liste);

    QList<ItemPersI *> item_list;
    QList<LiI *> li_list;
       
    ViewModeI mode;

    int HAUT_ITEM;
    int LARG_ITEM;
    double RAY;
    double RAY_B;
    QPointF center;

    bool constr;

    ItemPersI  * ptr_it_a;
    ItemPersI  * ptr_it_mouve;
    ItemPersI  * ptr_it_re;


    LiI  * li_temp;

    LiI  * ptr_li_a;
    LiI  * ptr_li_b;
    LiI  * ptr_li_c;
    LiI  * ptr_li_d;
    LiI  * ptr_li_e;



    MI matr_copie;
    std::vector<std::string> str_list_std;


    QPointF p_1;
    QPointF p_2;
    QPointF p_3;

    QColor coul_1;
    QColor coul_2;
    QColor coul_3;
    QColor coul_4;
    QColor coul_5;




};

class FenDesI :  public QWidget 
{

    Q_OBJECT

public:
    FenDesI();
    QGraphicsView *pt_graph_View(){return graphView;}

public slots:
    void setMode(ViewModeI);
    void aff_cercle(Elements);
    void pass_new_inter(QString,QString,interType);

signals:
    void new_inter(QString,QString,interType);

private:
    QGraphicsScene *graphScene;
    MaGraphicsViewI *graphView;
    QWidget * container;
    QScrollArea * scroll_area_2;


};

class MonBoutI : public QPushButton
{
    Q_OBJECT
public:
    MonBoutI();
    ViewModeI mode();
    void setMode(ViewModeI);
public slots:
    void envoyer_click();
signals:
    void mon_clicked(MonBoutI*);
private:
    ViewModeI m_mode;

};


class FenButI :  public QWidget 
{

    Q_OBJECT

public:
    FenButI();

public slots:
    void  aj_but(MonBoutI *);

signals:
    void aj_mode(ViewModeI);

private:
    void uncheck_others(MonBoutI *);

    QList<MonBoutI *> list_but;
    QVBoxLayout *vLayout;

    


};

class FenI :  public QWidget 
{

    Q_OBJECT

public:
    FenI();

public slots:
    void aff_cercle(Elements);
    void pass_new_inter(QString,QString,interType);
    void emettre_sous(){emit sub_cpt_freeze_fenres();}

signals:
    void new_inter(QString,QString,interType);
    void sub_cpt_freeze_fenres();

private:
    FenDesI *fenDes;
    FenButI *fenBut;
    QHBoxLayout *hLayout;
    QScrollArea * scroll_area;

};



#endif
