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
void placer_stud(vector<int>);
void record_ag(double,double,int,vector<int>);
void aff_graph();

//=============fcts en rapport avec liste d'elements=========
void aj_list(QList<QString>);//pas tres optimal...//non utilisee
void aj_cl_et_ro(QList<QString>);
void nouv_inter(QString,QString,interType);

//====fcts en rapport avec liste de bu===================
void modif_bur(int index,Pos);
void supr_bur(int index);
void supr_bur(int index,Combi &comb);//surchage utile dans crea_combi_ready;
void add_bur(Pos pos);
void add_cpl(int,int);
void supr_cpl(int,int); 

//================fcts en rapport avec elem_cell_map=========================
void aj_elem_cell_map(QString,int);//rajoute ou remplace une paire elem_cell_map
void elem_cell_map_supr(QString);

//======================frozen_cell=========================
void ad_frozen_cell(int);
void supr_frozen_cell(int);



    signals:
void ajourned(Elements,std::map<int,int>);
void ajourner_sans_reaff_cercle(Elements,std::map<int,int>);
void cell_pos_ajourned(std::vector<Pos>,std::map<int,int>,std::set<int>);
void bmmp_ajourned(std::map<int,int>);
void faire_ajourner(Elements,std::map<int,int>);


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

