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




#include "../Elements_and_space.h"

#include "WidgCellRes.h"


QString trouve_cpl(const QString &,const Elements &);

enum class modeRes{NORMALE,CALCUL,FREEZ_CELL};

class widgNRes;
class widgNRG;
class FeNaRes;
class FeResNaAff; 

class MaGraphicsViewRes : public QGraphicsView
{
    Q_OBJECT

public:
    MaGraphicsViewRes(QGraphicsScene* scene,QWidget *parent=0);
    void ajourner(Elements,std::map<int,int>);
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
    void aj_elem_cell_map(QString,int);
    void enlever_st(QString);
    void rapatrier_wNRG(QList<QString>);
    void sous();
    void ad_frozen_cell(int);
    void supr_frozen_cell(int);

public slots:
    void drop_cached_sl();
    void ajourner_cell(std::vector<Pos>,std::map<int,int>,std::set<int> set_frozen_cell);
    void ajourner_mm(std::map<int,int>);
    void aj_drop_catched_locale(bool b);
    void detruire_wn(widgNRG* pt_wn);
    widgNRG* creer_widgNRG(QString,WidgCellRes*);
    void rapatrier(QString);//en fait detruit seulement...

private:
    Elements elements_copie;
    std::map<int,int> mm_copie;
    QList<WidgCellRes *> list_widgCellRes;
    QList<widgNRG*> list_widgNRG;
    WidgCellRes*  trouve_intersect(QPainterPath painter_path, QPointF mouse_pos);
    WidgCellRes*  trouve_cell_res(QPointF mouse_pos);
    WidgCellRes * pt_w_pass;
    WidgCellRes *pt_w_a;
    WidgCellRes *pt_w_b;

    modeRes mode;
};



class FenDesRes :  public QWidget 
{

    Q_OBJECT

public:
    FenDesRes();
    MaGraphicsViewRes *pt_graphView(){return graphView;}

public slots:
    void ajourner(Elements,std::map<int,int>);
    void ajourner_cell(std::vector<Pos>,std::map<int,int>,std::set<int> set_frozen_cell);
    void ajourner_mm(std::map<int,int>);
    void drop_locale_catched(){graphView->aj_drop_catched_locale(true);}
    void desact_frozen_cell(){pt_graphView()->setModeRes(modeRes::NORMALE);}

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
    void aj_mode_res(){if(but2->isChecked())emit aj_mode(modeRes::FREEZ_CELL);else emit aj_mode(modeRes::NORMALE);}
    void mode_calc(){desact_frozen_cell();emit aj_mode(modeRes::CALCUL);}
    void desact_frozen_cell(){but2->setChecked(false);}

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


public slots:
    void ajourner(Elements,std::map<int,int>);

    void ajourner_cell(std::vector<Pos>,std::map<int,int>,std::set<int>);
    void ajourner_mm(std::map<int,int>);

    void set_drop_catched();
    void emettre_aj_elem_cell_map(QString s,int i){emit aj_elem_cell_map(s,i);}
    void emettre_elem_cell_map_supr(QString s){emit elem_cell_map_supr(s);}
    void emettre_sous(){emit sub_cpt_freeze_fenres();}

    void emettre_ad_frozen_cell(int i){emit ad_frozen_cell(i);}
    void emettre_supr_frozen_cell(int i){emit supr_frozen_cell(i);}
    void aj_mode(modeRes mode){moderes=mode;fenDes->pt_graphView()->setModeRes(mode);if(moderes==modeRes::CALCUL)emit lancer_calc();}

signals:
    void aj_elem_cell_map(QString,int);
    void ad_frozen_cell(int);
    void supr_frozen_cell(int);
    void elem_cell_map_supr(QString);
    void sub_cpt_freeze_fenres();
    void lancer_calc();

private:

    modeRes moderes;
    FeNaRes *fenNaRes;
    FenDesRes *fenDes;
    FenButRes *fenBut;

    QHBoxLayout *hLayout;

    QScrollArea *scroll_area;



};

class widgNRes;
class FeNaRes :  public QWidget 
{

    Q_OBJECT

public:
    FeNaRes();
    void ajourner(Elements,std::map<int,int>);// TODO const ref?
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
    void elem_cell_map_supr(QString);
    void rapatrier(QString);
    void sous();
private:
    void rapatrier_cpl_eventuel(QString text_received);

    //===============container N===============
    QList<QString> N_str_list;
    FeResNaAff * m_w_multi_aff;
    QScrollArea * m_scroll_multi_aff;

    //===================================
    QMap<QString,int> st_qmap;
    Elements elements_copie;
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
    void paint(QPainter *painter,const QStyleOptionGraphicsItem *option,QWidget *widget=0);
    void setN(QString string_N);
    QString getN();

    void set_color(QColor);
    void set_default_color();

    void set_entered(bool b){entered=b;}
    void set_pixmap(QPixmap p){m_pixmap=p;}
    QPixmap get_pixmap(){return m_pixmap;}
    void set_drop_catched_locale(bool b){drop_catched_locale=b;}
    void set_pt_WBR(WidgCellRes * pt){pt_WBR=pt;}
    WidgCellRes* get_pt_WBR(){return pt_WBR;}

public slots:

signals:
    void detruit_moi(widgNRG*);
    void decolle(widgNRes *);

protected:
    void hoverEnterEvent(QGraphicsSceneHoverEvent *);
    void hoverLeaveEvent(QGraphicsSceneHoverEvent *);
    void mousePressEvent(QGraphicsSceneMouseEvent*);


private:
    bool entered;
    QString text_N;
    QColor default_color;
    QColor color;
    QRectF rect_ini;//bounding rect
    QPixmap m_pixmap;
    bool drop_catched_locale;
    WidgCellRes *pt_WBR;

};


class FeResNaAff :  public QWidget 
{

    Q_OBJECT

public:
    FeResNaAff();
    QList<widgNRes*> N_list;// mettre en private
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
    void sub_cpt_freeze_fenres();
    void desact_frozen_cell();

protected:
    void mousePressEvent(QMouseEvent *);
    void dragMoveEvent(QDragMoveEvent *);
    void dropEvent(QDropEvent * event);
    void dragEnterEvent(QDragEnterEvent *);

private:
    bool drop_catched;

};

#endif
