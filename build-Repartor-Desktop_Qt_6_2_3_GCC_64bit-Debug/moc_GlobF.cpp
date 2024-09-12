/****************************************************************************
** Meta object code from reading C++ file 'GlobF.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Repartor/GlobF.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GlobF.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MonBoutGlob_t {
    const uint offsetsAndSize[10];
    char stringdata0[52];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MonBoutGlob_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MonBoutGlob_t qt_meta_stringdata_MonBoutGlob = {
    {
QT_MOC_LITERAL(0, 11), // "MonBoutGlob"
QT_MOC_LITERAL(12, 11), // "mon_clicked"
QT_MOC_LITERAL(24, 0), // ""
QT_MOC_LITERAL(25, 12), // "MonBoutGlob*"
QT_MOC_LITERAL(38, 13) // "envoyer_click"

    },
    "MonBoutGlob\0mon_clicked\0\0MonBoutGlob*\0"
    "envoyer_click"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MonBoutGlob[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    0,   29,    2, 0x0a,    3 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void,

       0        // eod
};

void MonBoutGlob::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MonBoutGlob *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mon_clicked((*reinterpret_cast< MonBoutGlob*(*)>(_a[1]))); break;
        case 1: _t->envoyer_click(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MonBoutGlob* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MonBoutGlob::*)(MonBoutGlob * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonBoutGlob::mon_clicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MonBoutGlob::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_MonBoutGlob.offsetsAndSize,
    qt_meta_data_MonBoutGlob,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MonBoutGlob_t
, QtPrivate::TypeAndForceComplete<MonBoutGlob, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MonBoutGlob *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MonBoutGlob::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonBoutGlob::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonBoutGlob.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int MonBoutGlob::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QPushButton::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void MonBoutGlob::mon_clicked(MonBoutGlob * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FenGlobBut_t {
    const uint offsetsAndSize[12];
    char stringdata0[49];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FenGlobBut_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FenGlobBut_t qt_meta_stringdata_FenGlobBut = {
    {
QT_MOC_LITERAL(0, 10), // "FenGlobBut"
QT_MOC_LITERAL(11, 7), // "aj_mode"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 8), // "GlobMode"
QT_MOC_LITERAL(29, 6), // "aj_but"
QT_MOC_LITERAL(36, 12) // "MonBoutGlob*"

    },
    "FenGlobBut\0aj_mode\0\0GlobMode\0aj_but\0"
    "MonBoutGlob*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenGlobBut[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   26,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   29,    2, 0x0a,    3 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,

       0        // eod
};

void FenGlobBut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenGlobBut *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->aj_mode((*reinterpret_cast< GlobMode(*)>(_a[1]))); break;
        case 1: _t->aj_but((*reinterpret_cast< MonBoutGlob*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MonBoutGlob* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FenGlobBut::*)(GlobMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenGlobBut::aj_mode)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FenGlobBut::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FenGlobBut.offsetsAndSize,
    qt_meta_data_FenGlobBut,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FenGlobBut_t
, QtPrivate::TypeAndForceComplete<FenGlobBut, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<GlobMode, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MonBoutGlob *, std::false_type>


>,
    nullptr
} };


const QMetaObject *FenGlobBut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenGlobBut::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenGlobBut.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FenGlobBut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 2)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void FenGlobBut::aj_mode(GlobMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_GlobF_t {
    const uint offsetsAndSize[56];
    char stringdata0[229];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_GlobF_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_GlobF_t qt_meta_stringdata_GlobF = {
    {
QT_MOC_LITERAL(0, 5), // "GlobF"
QT_MOC_LITERAL(6, 7), // "setMode"
QT_MOC_LITERAL(14, 0), // ""
QT_MOC_LITERAL(15, 8), // "GlobMode"
QT_MOC_LITERAL(24, 10), // "aff_cercle"
QT_MOC_LITERAL(35, 8), // "Elements"
QT_MOC_LITERAL(44, 2), // "sc"
QT_MOC_LITERAL(47, 21), // "add_cpt_freeze_fenres"
QT_MOC_LITERAL(69, 21), // "sub_cpt_freeze_fenres"
QT_MOC_LITERAL(91, 15), // "rfsh_elem_space"
QT_MOC_LITERAL(107, 1), // "l"
QT_MOC_LITERAL(109, 9), // "new_inter"
QT_MOC_LITERAL(119, 1), // "s"
QT_MOC_LITERAL(121, 2), // "s2"
QT_MOC_LITERAL(124, 9), // "interType"
QT_MOC_LITERAL(134, 2), // "it"
QT_MOC_LITERAL(137, 10), // "modif_cell"
QT_MOC_LITERAL(148, 1), // "i"
QT_MOC_LITERAL(150, 3), // "Pos"
QT_MOC_LITERAL(154, 1), // "p"
QT_MOC_LITERAL(156, 9), // "supr_cell"
QT_MOC_LITERAL(166, 8), // "add_cell"
QT_MOC_LITERAL(175, 7), // "add_cpl"
QT_MOC_LITERAL(183, 2), // "i2"
QT_MOC_LITERAL(186, 8), // "supr_cpl"
QT_MOC_LITERAL(195, 12), // "make_refresh"
QT_MOC_LITERAL(208, 17), // "std::map<int,int>"
QT_MOC_LITERAL(226, 2) // "mp"

    },
    "GlobF\0setMode\0\0GlobMode\0aff_cercle\0"
    "Elements\0sc\0add_cpt_freeze_fenres\0"
    "sub_cpt_freeze_fenres\0rfsh_elem_space\0"
    "l\0new_inter\0s\0s2\0interType\0it\0modif_cell\0"
    "i\0Pos\0p\0supr_cell\0add_cell\0add_cpl\0"
    "i2\0supr_cpl\0make_refresh\0std::map<int,int>\0"
    "mp"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_GlobF[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,   86,    2, 0x0a,    1 /* Public */,
       4,    1,   89,    2, 0x0a,    3 /* Public */,
       7,    0,   92,    2, 0x0a,    5 /* Public */,
       8,    0,   93,    2, 0x0a,    6 /* Public */,
       9,    1,   94,    2, 0x0a,    7 /* Public */,
      11,    3,   97,    2, 0x0a,    9 /* Public */,
      16,    2,  104,    2, 0x0a,   13 /* Public */,
      20,    1,  109,    2, 0x0a,   16 /* Public */,
      21,    1,  112,    2, 0x0a,   18 /* Public */,
      22,    2,  115,    2, 0x0a,   20 /* Public */,
      24,    2,  120,    2, 0x0a,   23 /* Public */,
      25,    2,  125,    2, 0x0a,   26 /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    2,
    QMetaType::Void, 0x80000000 | 5,    6,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList,   10,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 14,   12,   13,   15,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 18,   17,   19,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void, 0x80000000 | 18,   19,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   23,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   17,   23,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 26,    6,   27,

       0        // eod
};

void GlobF::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GlobF *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->setMode((*reinterpret_cast< GlobMode(*)>(_a[1]))); break;
        case 1: _t->aff_cercle((*reinterpret_cast< const Elements(*)>(_a[1]))); break;
        case 2: _t->add_cpt_freeze_fenres(); break;
        case 3: _t->sub_cpt_freeze_fenres(); break;
        case 4: _t->rfsh_elem_space((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 5: _t->new_inter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< interType(*)>(_a[3]))); break;
        case 6: _t->modif_cell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Pos(*)>(_a[2]))); break;
        case 7: _t->supr_cell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 8: _t->add_cell((*reinterpret_cast< Pos(*)>(_a[1]))); break;
        case 9: _t->add_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->supr_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->make_refresh((*reinterpret_cast< Elements(*)>(_a[1])),(*reinterpret_cast< std::map<int,int>(*)>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject GlobF::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_GlobF.offsetsAndSize,
    qt_meta_data_GlobF,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_GlobF_t
, QtPrivate::TypeAndForceComplete<GlobF, std::true_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<GlobMode, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<const Elements &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<interType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Elements, std::false_type>, QtPrivate::TypeAndForceComplete<std::map<int,int>, std::false_type>


>,
    nullptr
} };


const QMetaObject *GlobF::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *GlobF::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_GlobF.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int GlobF::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
