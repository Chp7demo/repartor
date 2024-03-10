#include <iostream>
#include <QApplication>
#include "GlobF.h"

int main(int argc, char*argv[])
{

QApplication app(argc,argv);
GlobF globF;
globF.show();
return app.exec();
}
