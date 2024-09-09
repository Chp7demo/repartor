#ifndef FENRO_H
#define FENRO_H



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
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsItem>
#include <QGraphicsRectItem>
#include <QRectF>
#include <QEvent>


#include "WidgBur.h"
#include "WidgLi.h"

#include "../RepartorTypes.h"

enum class ViewMode{NOMODE,BUR,DES_BUR,CPL,BAR_CPL,COPIE,SUPRR,ROT};

class WidgBur;
class FenRo;
class MaGraphicsView : public QGraphicsView
{
  Q_OBJECT

  public:
    MaGraphicsView(QGraphicsScene* scene,QWidget *parent=0);
 
 //void peindre();
    protected:
//	void paintEvent(QPaintEvent *event);
        //void drawForeground(QPainter *,const QRectF &);
        void mousePressEvent(QMouseEvent *);

 	void mousePressEvent_NOMODE(QMouseEvent *event);
 	void mousePressEvent_BUR(QMouseEvent *event);
 	void mousePressEvent_DES_BUR(QMouseEvent *event);
 	void mousePressEvent_CPL(QMouseEvent *event);
 	void mousePressEvent_BAR_CPL(QMouseEvent *event);
 	void mousePressEvent_COPIE(QMouseEvent *event);
 	void mousePressEvent_SUPRR(QMouseEvent *event);
	void mousePressEvent_ROT(QMouseEvent *event);


        void mouseMoveEvent(QMouseEvent *);

 	void mouseMoveEvent_NOMODE(QMouseEvent *event);
 	void mouseMoveEvent_BUR(QMouseEvent *event);
 	void mouseMoveEvent_DES_BUR(QMouseEvent *event);
 	void mouseMoveEvent_CPL(QMouseEvent *event);
 	void mouseMoveEvent_BAR_CPL(QMouseEvent *event);
 	void mouseMoveEvent_COPIE(QMouseEvent *event);
 	void mouseMoveEvent_SUPRR(QMouseEvent *event);
	void mouseMoveEvent_ROT(QMouseEvent *event);


        void mouseReleaseEvent(QMouseEvent *);

 	void mouseReleaseEvent_NOMODE(QMouseEvent *event);
 	void mouseReleaseEvent_BUR(QMouseEvent *event);
 	void mouseReleaseEvent_DES_BUR(QMouseEvent *event);
 	void mouseReleaseEvent_CPL(QMouseEvent *event);
 	void mouseReleaseEvent_BAR_CPL(QMouseEvent *event);
 	void mouseReleaseEvent_COPIE(QMouseEvent *event);
 	void mouseReleaseEvent_SUPRR(QMouseEvent *event);
	void mouseReleaseEvent_ROT(QMouseEvent *event);


      	void mouseDoubleClickEvent(QMouseEvent *event);

	void mouseDoubleClickEvent_NOMODE(QMouseEvent *event);
 	void mouseDoubleClickEvent_BUR(QMouseEvent *event);
 	void mouseDoubleClickEvent_DES_BUR(QMouseEvent *event);
 	void mouseDoubleClickEvent_CPL(QMouseEvent *event);
 	void mouseDoubleClickEvent_BAR_CPL(QMouseEvent *event);
 	void mouseDoubleClickEvent_COPIE(QMouseEvent *event);
 	void mouseDoubleClickEvent_SUPRR(QMouseEvent *event);
	void mouseDoubleClickEvent_ROT(QMouseEvent *event);


        void dragMoveEvent(QDragMoveEvent *);
        void dropEvent(QDropEvent * event);
        void dragEnterEvent(QDragEnterEvent *);

     //   void enterEvent(QEvent *);
        void wheelEvent(QWheelEvent *event);

        
        //void resizeEvent(QResizeEvent *);
    signals:

    void modif_cell(int index,Pos pos);
    void supr_cell(int index);
    void add_cell(Pos pos);
    void add_cpl(int,int);
    void supr_cpl(int,int); 
        // void clean_widgbur();
void resize(qreal);
void rotation(int index_du_wiB);//useless?

public slots:
   
     //  void clean_others();

    void setMode(ViewMode vM);
void effectuer_rot(int index_du_wiB);

    private:
    void scaleView(qreal scaleFactor);


    QList<WidgBur *> list_widgBur;
    QList<WidgLi *> list_widgLi; 
    
    WidgBur* trouve_bur(const QPointF & point);
    WidgLi*  trouve_li(const QPointF & point);

    bool creer_bur(const QPointF & pt_1,const QPointF & pt_2);
    void creer_bur_temp(const QPointF & pt_1,const QPointF & pt_2);
    void creer_wil(const QPointF & pt_1,const QPointF & pt_2);
    void creer_wil_temp(const QPointF & pt_1,const QPointF & pt_2);
    bool intersecte_bur(const QRectF & rect);
    bool intersecte_bur(const QPainterPath & shape_path);
    bool intersecte_bur_lui_exclu(const QPainterPath & shape_path,int ind);

    bool taille_bur_acceptable(const QRectF &rect);
    QPointF p_1;
    QPointF p_2;
    QPointF p_3;

    QPointF pos_1;
    QPointF pos_2;
 
    WidgBur *wiB_temp;
    WidgLi  *wiL_temp;
    WidgBur *ptr_wiB_a;
    WidgBur *ptr_wiB_b;
    WidgBur *ptr_wiB_c;
    WidgBur *ptr_wiB_d;
    WidgBur *ptr_wiB_e;
    WidgBur *ptr_wiB_f;
    WidgBur *ptr_wiB_g;


    WidgLi *ptr_li_a;
    WidgLi *ptr_li_b;
    WidgLi *ptr_li_c;

   QPointF ctr;
   QPointF ctr_2;


   
double MINIMAL_WIDTH; 
double MINIMAL_HEIGTH;
double MAXIMAL_WIDTH;
double MAXIMAL_HEIGTH;

bool deplacement;
bool move_liaison;

    ViewMode mode;

std::vector<Pos> vect_pos;//utile?//prle scaling peut etre...
FenRo * ptr_fenro;
};

class FenRoDes :  public QWidget 
{

    Q_OBJECT

    public:
	FenRoDes();
    public slots:
    void setMode(ViewMode);
    void resize(qreal);
    private:
 QGraphicsScene *graphScene;
  MaGraphicsView *graphView;
QWidget * container;
QScrollArea * scroll_area_2;


   signals:
   void modif_cell(int index,Pos pos);
    void supr_cell(int index);
    void add_cell(Pos pos);
    void add_cpl(int i_1,int i_2);
    void supr_cpl(int i_1,int i_2); 

    public slots:
   void emetre_modif_cell(int index,Pos pos){emit modif_cell(index,pos);};
    void emetre_supr_cell(int index){emit supr_cell(index);};
    void emetre_add_cell(Pos pos){emit add_cell(pos);};
    void emetre_add_cpl(int i_1,int i_2){emit add_cpl(i_1,i_2);};
    void emetre_supr_cpl(int i_1,int i_2){emit supr_cpl(i_1,i_2);}; 

     };

class MonBout : public QPushButton
{
Q_OBJECT
  public:
	MonBout();
  ViewMode mode();
  void setMode(ViewMode);
  public slots:
  void envoyer_click();
   signals:
  void mon_clicked(MonBout*);
    private:
  ViewMode m_mode;

};
class FenRoBut :  public QWidget 
{

    Q_OBJECT

    public:
	FenRoBut();

    //enum but {BUR,CPL,ROT,SUPR,COPIE};
    public slots:
    void  aj_but(MonBout *);
   

    signals:
   void aj_mode(ViewMode);

    private:
 
   void uncheck_others(MonBout *);

QList<MonBout *> list_but;
   // QPushButton *butBur;
   // QPushButton *butCpl;
    QVBoxLayout *vLayout;

    


};

class FenRo :  public QWidget 
{

    Q_OBJECT

    public:
	FenRo();
   signals:
   void modif_cell(int index,Pos pos);
    void supr_cell(int index);
    void add_cell(Pos pos);
    void add_cpl(int i_1,int i_2);
    void supr_cpl(int i_1,int i_2); 
  //  void add_cpt_freeze_fenres();
    public slots:
   void emetre_modif_cell(int index,Pos pos){emit modif_cell(index,pos);};
    void emetre_supr_cell(int index){emit supr_cell(index);};
    void emetre_add_cell(Pos pos){emit add_cell(pos);};
    void emetre_add_cpl(int i_1,int i_2){emit add_cpl(i_1,i_2);}//emit add_cpl(i_2,i_1);}//comme c'est vilain...
    void emetre_supr_cpl(int i_1,int i_2){emit supr_cpl(i_1,i_2);}//emit supr_cpl(i_2,i_1);}

  
    private:


    FenRoDes *fenRoDes;
    FenRoBut *fenRoBut;
    QHBoxLayout *hLayout;

QScrollArea * scroll_area;



};



#endif
