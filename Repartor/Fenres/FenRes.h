#ifndef FENRES_H
#define FENRES_H



#include <iostream>
#include <math.h>
#include <string.h>
#include <cstdlib>
#include <utility>
#include <algorithm>

#include <string.h>



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
#include <QSplitter>




#include "../sclass_et_room.h"

#include "WidgBurRes.h"


QString trouve_cpl(const QString &,const SClass &);

enum class modeRes{NORMALE,CALCUL,FBS};

class widgNRes;
class widgNRG;
class FeNaRes;
class FeResNaAff; 
class MaGraphicsViewRes : public QGraphicsView
{
  Q_OBJECT

  public:
    MaGraphicsViewRes(QGraphicsScene* scene,QWidget *parent=0);
   void ajourner(SClass,std::map<int,int>);
   void setModeRes(modeRes moderes){mode=moderes;}
    protected:
           
        void dragMoveEvent(QDragMoveEvent *);
        void dropEvent(QDropEvent *);
        void dragEnterEvent(QDragEnterEvent *);

        void mousePressEvent(QMouseEvent *);
        void mouseMoveEvent(QMouseEvent *);
        void mouseReleaseEvent(QMouseEvent *);

   
    signals:

        void drop_cached();
        void aj_dsm(QString,int);
        void enlever_st(QString);
        void rapatrier_wNRG(QList<QString>);
        void sous();

        void ad_fbs(int);
        void supr_fbs(int);
        public slots:

        void drop_cached_sl();

        void ajourner_bu(std::vector<Pos>,std::map<int,int>,std::set<int> set_fbs);
        void ajourner_mm(std::multimap<int,int>);
        void aj_drop_catched_locale(bool b);
        void detruire_wn(widgNRG* pt_wn);
       widgNRG* creer_widgNRG(QString,WidgBurRes*);
       void rapatrier(QString);//en fait detruit seulement...
    private:
      SClass sclass_copie;
    // MI matr_copie;//TODO a faire ajourner par ajourned...
    //std::map<int,int> dsm_copie;
     std::multimap<int,int> mm_copie;

    QList<WidgBurRes *> list_widgBurRes;
   QList<widgNRG*> list_widgNRG;
    WidgBurRes*  trouve_intersect(QPainterPath painter_path, QPointF mouse_pos);
    WidgBurRes*  trouve_bur_res(QPointF mouse_pos);
   // QPointF pos_move_1;
   // QPointF pos_move_2;
     WidgBurRes * pt_w_pass;
     WidgBurRes *pt_w_a;
     WidgBurRes *pt_w_b;

     modeRes mode;
 };



class FenDesRes :  public QWidget 
{

    Q_OBJECT

    public:
	FenDesRes();
    MaGraphicsViewRes *pt_graphView(){return graphView;}
    public slots:
void ajourner(SClass,std::map<int,int>);

void ajourner_bu(std::vector<Pos>,std::map<int,int>,std::set<int> set_fbs);
void ajourner_mm(std::multimap<int,int>); 
void drop_locale_catched(){graphView->aj_drop_catched_locale(true);}

void desact_fbs(){pt_graphView()->setModeRes(modeRes::NORMALE);}
         signals:
     private:
 QGraphicsScene *graphScene;
  MaGraphicsViewRes *graphView;
QWidget * container;
QScrollArea * scroll_area_2;


     };

class MonBoutRes_1 : public QPushButton
{
Q_OBJECT
  public:
	MonBoutRes_1();
   public slots:
   signals:
     private:
 
};


class FenButRes :  public QWidget 
{

    Q_OBJECT

    public:
	FenButRes();

     public slots:
    void aj_mode_res(){if(but2->isChecked())emit aj_mode(modeRes::FBS);else emit aj_mode(modeRes::NORMALE);}
    void mode_calc(){desact_fbs();emit aj_mode(modeRes::CALCUL);}
    void desact_fbs(){but2->setChecked(false);}
    signals:
 void aj_mode(modeRes);
    private:
 
     QVBoxLayout *vLayout;

    MonBoutRes_1 *but1;
    MonBoutRes_1 *but2;


};

class FenRes :  public QWidget 
{

    Q_OBJECT

    public:
	FenRes();
   // FenDesRes * pt_fenDes(){return fenDes;}

    public slots:
void ajourner(SClass,std::map<int,int>);

void ajourner_bu(std::vector<Pos>,std::map<int,int>,std::set<int>);
void ajourner_mm(std::multimap<int,int>); 


void set_drop_catched();
void emettre_aj_dsm(QString s,int i){emit aj_dsm(s,i);}
void emettre_dsm_supr(QString s){emit dsm_supr(s);}
void emettre_sous(){emit sous_cpt_freeze_fenres();}

void emettre_ad_fbs(int i){emit ad_fbs(i);}
void emettre_supr_fbs(int i){emit supr_fbs(i);}


void aj_mode(modeRes mode){moderes=mode;fenDes->pt_graphView()->setModeRes(mode);if(moderes==modeRes::CALCUL)emit lancer_calc();}
    signals:
 void aj_dsm(QString,int);
 void ad_fbs(int);
 void supr_fbs(int);
 void dsm_supr(QString);
 void sous_cpt_freeze_fenres();
 void  lancer_calc();
    private:

    modeRes moderes;
    FeNaRes *fenNaRes;
    FenDesRes *fenDes;
    FenButRes *fenBut;

    QHBoxLayout *hLayout;

QScrollArea * scroll_area;



};

class widgNRes;
class FeNaRes :  public QWidget 
{

    Q_OBJECT

    public:
	FeNaRes();
   void ajourner(SClass,std::map<int,int>);// TODO const ref?
   void ajourner(std::map<int,int>);// TODO const ref?
     public slots:
 void cacher_widg(widgNRes *wn);
 void set_drop_catched();
 void rapatrier_wNRG(QList<QString>);

 FeResNaAff* pt_feResNaAff(){return m_w_multi_aff;}//useless?
    protected:
        void dragMoveEvent(QDragMoveEvent *);
        void dropEvent(QDropEvent * event);
        void dragEnterEvent(QDragEnterEvent *);

    signals:
        void drop_locale_catched();
        void dsm_supr(QString);
        void rapatrier(QString);
        void sous();
    private:
        void rapatrier_cpl_eventuel(QString text_received);
//===============container N===============
   QList<QString> N_str_list;
FeResNaAff * m_w_multi_aff;
QScrollArea * m_scroll_multi_aff;
//===================================
//std::map<int,int> dsm_copie_fenares;//utile?
QMap<QString,int> st_qmap;
SClass sclass_copie;
QVBoxLayout *bl;
     };

class widgNRes:  public QWidget 
{

    Q_OBJECT

    public:
	widgNRes();
        ~widgNRes();
        void paintEvent(QPaintEvent *);
      void setN(QString string_N);
        QString getN();  

   void set_color(QColor);
   void set_default_color();
 
    public slots:
    signals:
            void decolle(widgNRes *);
 protected:
        
        void enterEvent(QEvent *);
        void leaveEvent(QEvent *);

   
    private:

	QLabel *m_label_N;
QColor default_color;
QColor color;

};
class widgNRG:  public QGraphicsObject
{

    Q_OBJECT

    public:
        widgNRG( QRectF rect,QGraphicsItem *parent=0);

        QRectF boundingRect() const;
    //    QPainterPath shape() const;

        void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=0);
      void setN(QString string_N);
        QString getN();

   void set_color(QColor);
   void set_default_color();

   void set_entered(bool b){entered=b;}
   void set_pixmap(QPixmap p){m_pixmap=p;}
   QPixmap get_pixmap(){return m_pixmap;}
   void set_drop_catched_locale(bool b){drop_catched_locale=b;}
   void set_pt_WBR(WidgBurRes * pt){pt_WBR=pt;}
   WidgBurRes* get_pt_WBR(){return pt_WBR;}
    public slots:
    signals:
       void detruit_moi(widgNRG*);
        void decolle(widgNRes *);
 protected:

        void hoverEnterEvent(QGraphicsSceneHoverEvent *);
        void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
       // void dragEnterEvent(QGraphicsSceneDragDropEvent*);
        //void dragMoveEvent(QGraphicsSceneDragDropEvent*);
       // void dropEvent(QGraphicsSceneDragDropEvent*);
        void mousePressEvent(QGraphicsSceneMouseEvent*);


    private:
bool entered;
  //  QLabel *m_label_N;
        QString text_N;
QColor default_color;
QColor color;
  QRectF rect_ini;//bounding rect

  QPixmap m_pixmap;
  bool drop_catched_locale;
  WidgBurRes *pt_WBR;

};

class FeResNaAff :  public QWidget 
{

    Q_OBJECT

 public:
     FeResNaAff();
     QList<widgNRes*> N_list;//il ne faudrait ppas le mettre e public ... je sais..
     QVBoxLayout* m_vboxlayout_pr_aff;
      widgNRes * trouve_N(const QPoint & point);
     void cacher_widg(widgNRes *wN);
     void recreer_widg(QString nm,int ind_lay);
     void set_drop_catched();
     void ajouter_widg(QString nm);


   public slots:
   void aj_post_drop_sl(QString nm,int ind_lay);
  void enlever_st(QString);
  signals:
   void aj_post_drop(QString,int);
   void sous_cpt_freeze_fenres();
   void desact_fbs();
  protected: 
     void mousePressEvent(QMouseEvent *);
   
        void dragMoveEvent(QDragMoveEvent *);
        void dropEvent(QDropEvent * event);
        void dragEnterEvent(QDragEnterEvent *);
 private:
 bool drop_catched;

};

#endif
