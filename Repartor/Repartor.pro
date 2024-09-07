QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    Fena/FeNa.cpp \
    Feni/FenI.cpp \
    Feni/ItemPersI.cpp \
    Feni/LiI.cpp \
    Fenres/FenRes.cpp \
    Fenres/WidgBurRes.cpp \
    Fenro/FenRo.cpp \
    Fenro/WidgBur.cpp \
    Fenro/WidgLi.cpp \
    GlobF.cpp \
    Mng.cpp \
    MyThread.cpp \
    fct_ag/DataZone.cpp \
    fct_ag/cross_over.cpp \
    fct_ag/evaluation.cpp \
    fct_ag/genese.cpp \
    fct_ag/mutation.cpp \
    fct_ag/petites_fonctions.cpp \
    main.cpp \
    mainwindow.cpp

HEADERS += \
    Fena/FeNa.h \
    Feni/FenI.h \
    Feni/ItemPersI.h \
    Feni/LiI.h \
    Fenres/FenRes.h \
    Fenres/WidgBurRes.h \
    Fenro/FenRo.h \
    Fenro/WidgBur.h \
    Fenro/WidgLi.h \
    GlobF.h \
    Mng.h \
    MyThread.h \
    fct_ag/DataZone.h \
    fct_ag/cross_over.h \
    fct_ag/evaluation.h \
    fct_ag/genese.h \
    fct_ag/mutation.h \
    fct_ag/petites_fonctions.h \
    mainwindow.h \
    mes_types.h \
    sclass_et_room.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    README.md
