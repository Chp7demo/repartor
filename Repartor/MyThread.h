#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include "fct_ag/evaluation.h"
#include "fct_ag/cross_over.h"
#include "fct_ag/genese.h"
#include "fct_ag/mutation.h"
#include "fct_ag/petites_fonctions.h"
#include "fct_ag/DataZone.h"
#include <QFileDialog>
#include<QTextStream>

class MyThread : public QThread
{
 Q_OBJECT

public:
    MyThread(const DataZone & dz) : QThread () {SCcombi combi_vide;dZ=new DataZone(combi_vide);*dZ=dz;}//nawak
 public slots:
    void run();
 signals:
    void record_ag(double,double,int,vector<int>);
    void fin_ag(vector<int>);
    void aff_graph();
    private :


    DataZone *dZ;
};


#endif // MYTHREAD_H
