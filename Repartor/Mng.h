#ifndef MNG_H
#define MNG_H



#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <utility>

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
#include <QFileDialog>
#include<QTextStream>



#include "CalculThread.h"

class Mng : public QObject
{
    Q_OBJECT

public:
    Mng();

public slots:

    void lancer_calc();
    void place_elem(vector<int>);

    //=============elements fcts=========
    void rfsh_elem_space(QList<QString>);
    void new_inter(QString,QString,interType);

    //==============cell fcts===================
    void modif_cell(int index,Pos);
    void supr_cell(int index);
    void supr_cell(int index,Combi &comb);//surchage utile dans crea_combi_ready;
    void add_cell(Pos pos);
    void add_cpl(int,int);
    void supr_cpl(int,int);

    //================elem_cell_map fcts=========================
    void aj_elem_cell_map(QString,int);//rajoute ou remplace une paire elem_cell_map
    void elem_cell_map_supr(QString);

    //======================frozen_cell=========================
    void ad_frozen_cell(int);
    void supr_frozen_cell(int);



signals:
    void refreshed(Elements,std::map<int,int>);
    void refresh_without_circle_disp(Elements,std::map<int,int>);
    void cell_pos_refreshed(std::vector<Pos>,std::map<int,int>,std::set<int>);
    void cell_map_refreshed(std::map<int,int>);
    void make_refresh(Elements,std::map<int,int>);


private:
    void creer_fichier();
    Combi crea_combi_ready();

    Elements elements;
    Space ro;

    Combi combi;

    //pour debug
    QString fileName;

};

#endif

