#ifndef FENA_H
#define FENA_H



#include <iostream>



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
#include <QLineEdit>




class widgN;
class MaLineEdit;
class FeNa :  public QWidget 
{

    Q_OBJECT

    public:
	FeNa();
    public slots:
void nouvelle_fen_N(QString string_N);
void addN();
void detruire_N(widgN*);
    signals:
    void addNS(QString);
    void aj_list(QList<QString>);
    protected:
        //void showEvent();

    private:
bool N_libre();

//=================ajout N===============
QPushButton * bouton;
MaLineEdit * line;


//========================================
//===============container N===============
QList<widgN*> N_list;
QList<QString> N_str_list;
QWidget * m_w_multi_aff;
QScrollArea * m_scroll_multi_aff;
QVBoxLayout* m_vboxlayout_pr_aff;



//===================================
QHBoxLayout * l;
QHBoxLayout * lay;
     };



class widgN:  public QWidget 
{

    Q_OBJECT

    public:
	widgN();
        ~widgN();
        void paintEvent(QPaintEvent *);
        void setN(QString string_N);
        QString getN();   

       public slots:
void destruction(); 
    signals:
void     detruit_moi(widgN*);
 //void add_cpt_freeze_fenres();

    private:

	QLabel *m_label_N;


};

class MaLineEdit:  public QLineEdit 
{

    Q_OBJECT

    public:
	MaLineEdit();
       
    protected:
       void keyPressEvent(QKeyEvent * event);

       public slots:
    signals:
     void enter();
    private:



};

#endif
