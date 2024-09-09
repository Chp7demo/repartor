#pragma once

#include <QThread>
#include "fct_ag/evaluation.h"
#include "fct_ag/cross_over.h"
#include "fct_ag/genese.h"
#include "fct_ag/mutation.h"
#include "fct_ag/petites_fonctions.h"
#include "fct_ag/DataZone.h"
#include <QFileDialog>
#include<QTextStream>

class CalculThread : public QThread
{
 Q_OBJECT

 public:
    CalculThread(const DataZone & dz) : QThread() , dZ{dz}  {}

 public slots:
    void run();

 signals:
    void fin_ag(vector<int>);

 private :

    DataZone dZ;
};


