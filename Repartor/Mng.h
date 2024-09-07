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



#include "MyThread.h"
   
class Mng : public QObject
{
Q_OBJECT
  public:
	Mng();
   public slots:
void lancer_calc();
void placer_stud(vector<int>);
//void creer_fichier();
void record_ag(double,double,int,vector<int>);
void aff_graph();
//=============fct en raport avce liste de na=========
void aj_list(QList<QString>);//pas tres optimal...//non utilisee
void aj_cl_et_ro(QList<QString>);
void nouv_inter(QString,QString,interType);
//====fcts en rapport avec liste de bu===================
void modif_bur(int index,Pos);
void supr_bur(int index);
void supr_bur(int index,SCcombi &comb);//surchage utile dans crea_combi_ready;
void add_bur(Pos pos);
void add_cpl(int,int);
void supr_cpl(int,int); 
//================fcts en rapport avec dsm=========================
void aj_dsm(QString,int);//rajoute ou remplace une paire dsm
void dsm_supr(QString);
//======================fbs=========================
void ad_fbs(int);
void supr_fbs(int);
    signals:
void ajourned(SClass,std::map<int,int>);
void ajourner_sans_reaff_cercle(SClass,std::map<int,int>);
void cell_pos_ajourned(std::vector<Pos>,std::map<int,int>,std::set<int>);
void bmmp_ajourned(std::multimap<int,int>);
void faire_ajourner(SClass,std::map<int,int>);
//void aj_dsm_copies(std::map<int,int>);//TODO fusionner avec les signaux existants
    private:
void creer_fichier();
SCcombi crea_combi_ready();

SClass sclass;
Room ro;


SCcombi combi;

//pr debug
QString fileName;
};

#endif

