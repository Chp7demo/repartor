/****************************************************************************
** Meta object code from reading C++ file 'FenRo.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Repartor/Fenro/FenRo.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenRo.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaGraphicsView_t {
    const uint offsetsAndSize[34];
    char stringdata0[140];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MaGraphicsView_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MaGraphicsView_t qt_meta_stringdata_MaGraphicsView = {
    {
QT_MOC_LITERAL(0, 14), // "MaGraphicsView"
QT_MOC_LITERAL(15, 10), // "modif_cell"
QT_MOC_LITERAL(26, 0), // ""
QT_MOC_LITERAL(27, 5), // "index"
QT_MOC_LITERAL(33, 3), // "Pos"
QT_MOC_LITERAL(37, 3), // "pos"
QT_MOC_LITERAL(41, 9), // "supr_cell"
QT_MOC_LITERAL(51, 8), // "add_cell"
QT_MOC_LITERAL(60, 7), // "add_cpl"
QT_MOC_LITERAL(68, 8), // "supr_cpl"
QT_MOC_LITERAL(77, 6), // "resize"
QT_MOC_LITERAL(84, 8), // "rotation"
QT_MOC_LITERAL(93, 12), // "index_du_wiB"
QT_MOC_LITERAL(106, 7), // "setMode"
QT_MOC_LITERAL(114, 8), // "ViewMode"
QT_MOC_LITERAL(123, 2), // "vM"
QT_MOC_LITERAL(126, 13) // "effectuer_rot"

    },
    "MaGraphicsView\0modif_cell\0\0index\0Pos\0"
    "pos\0supr_cell\0add_cell\0add_cpl\0supr_cpl\0"
    "resize\0rotation\0index_du_wiB\0setMode\0"
    "ViewMode\0vM\0effectuer_rot"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaGraphicsView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       7,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   68,    2, 0x06,    1 /* Public */,
       6,    1,   73,    2, 0x06,    4 /* Public */,
       7,    1,   76,    2, 0x06,    6 /* Public */,
       8,    2,   79,    2, 0x06,    8 /* Public */,
       9,    2,   84,    2, 0x06,   11 /* Public */,
      10,    1,   89,    2, 0x06,   14 /* Public */,
      11,    1,   92,    2, 0x06,   16 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      13,    1,   95,    2, 0x0a,   18 /* Public */,
      16,    1,   98,    2, 0x0a,   20 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QReal,    2,
    QMetaType::Void, QMetaType::Int,   12,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 14,   15,
    QMetaType::Void, QMetaType::Int,   12,

       0        // eod
};

void MaGraphicsView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MaGraphicsView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->modif_cell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Pos(*)>(_a[2]))); break;
        case 1: _t->supr_cell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->add_cell((*reinterpret_cast< Pos(*)>(_a[1]))); break;
        case 3: _t->add_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->supr_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->resize((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 6: _t->rotation((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->setMode((*reinterpret_cast< ViewMode(*)>(_a[1]))); break;
        case 8: _t->effectuer_rot((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MaGraphicsView::*)(int , Pos );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaGraphicsView::modif_cell)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MaGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaGraphicsView::supr_cell)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (MaGraphicsView::*)(Pos );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaGraphicsView::add_cell)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (MaGraphicsView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaGraphicsView::add_cpl)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (MaGraphicsView::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaGraphicsView::supr_cpl)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (MaGraphicsView::*)(qreal );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaGraphicsView::resize)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (MaGraphicsView::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaGraphicsView::rotation)) {
                *result = 6;
                return;
            }
        }
    }
}

const QMetaObject MaGraphicsView::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_MaGraphicsView.offsetsAndSize,
    qt_meta_data_MaGraphicsView,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MaGraphicsView_t
, QtPrivate::TypeAndForceComplete<MaGraphicsView, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ViewMode, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *MaGraphicsView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaGraphicsView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MaGraphicsView.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int MaGraphicsView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void MaGraphicsView::modif_cell(int _t1, Pos _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MaGraphicsView::supr_cell(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MaGraphicsView::add_cell(Pos _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MaGraphicsView::add_cpl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void MaGraphicsView::supr_cpl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}

// SIGNAL 5
void MaGraphicsView::resize(qreal _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 5, _a);
}

// SIGNAL 6
void MaGraphicsView::rotation(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 6, _a);
}
struct qt_meta_stringdata_FenRoDes_t {
    const uint offsetsAndSize[40];
    char stringdata0[185];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FenRoDes_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FenRoDes_t qt_meta_stringdata_FenRoDes = {
    {
QT_MOC_LITERAL(0, 8), // "FenRoDes"
QT_MOC_LITERAL(9, 10), // "modif_cell"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 5), // "index"
QT_MOC_LITERAL(27, 3), // "Pos"
QT_MOC_LITERAL(31, 3), // "pos"
QT_MOC_LITERAL(35, 9), // "supr_cell"
QT_MOC_LITERAL(45, 8), // "add_cell"
QT_MOC_LITERAL(54, 7), // "add_cpl"
QT_MOC_LITERAL(62, 3), // "i_1"
QT_MOC_LITERAL(66, 3), // "i_2"
QT_MOC_LITERAL(70, 8), // "supr_cpl"
QT_MOC_LITERAL(79, 7), // "setMode"
QT_MOC_LITERAL(87, 8), // "ViewMode"
QT_MOC_LITERAL(96, 6), // "resize"
QT_MOC_LITERAL(103, 17), // "emetre_modif_cell"
QT_MOC_LITERAL(121, 16), // "emetre_supr_cell"
QT_MOC_LITERAL(138, 15), // "emetre_add_cell"
QT_MOC_LITERAL(154, 14), // "emetre_add_cpl"
QT_MOC_LITERAL(169, 15) // "emetre_supr_cpl"

    },
    "FenRoDes\0modif_cell\0\0index\0Pos\0pos\0"
    "supr_cell\0add_cell\0add_cpl\0i_1\0i_2\0"
    "supr_cpl\0setMode\0ViewMode\0resize\0"
    "emetre_modif_cell\0emetre_supr_cell\0"
    "emetre_add_cell\0emetre_add_cpl\0"
    "emetre_supr_cpl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenRoDes[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   86,    2, 0x06,    1 /* Public */,
       6,    1,   91,    2, 0x06,    4 /* Public */,
       7,    1,   94,    2, 0x06,    6 /* Public */,
       8,    2,   97,    2, 0x06,    8 /* Public */,
      11,    2,  102,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    1,  107,    2, 0x0a,   14 /* Public */,
      14,    1,  110,    2, 0x0a,   16 /* Public */,
      15,    2,  113,    2, 0x0a,   18 /* Public */,
      16,    1,  118,    2, 0x0a,   21 /* Public */,
      17,    1,  121,    2, 0x0a,   23 /* Public */,
      18,    2,  124,    2, 0x0a,   25 /* Public */,
      19,    2,  129,    2, 0x0a,   28 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::QReal,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

       0        // eod
};

void FenRoDes::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenRoDes *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->modif_cell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Pos(*)>(_a[2]))); break;
        case 1: _t->supr_cell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->add_cell((*reinterpret_cast< Pos(*)>(_a[1]))); break;
        case 3: _t->add_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->supr_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->setMode((*reinterpret_cast< ViewMode(*)>(_a[1]))); break;
        case 6: _t->resize((*reinterpret_cast< qreal(*)>(_a[1]))); break;
        case 7: _t->emetre_modif_cell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Pos(*)>(_a[2]))); break;
        case 8: _t->emetre_supr_cell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 9: _t->emetre_add_cell((*reinterpret_cast< Pos(*)>(_a[1]))); break;
        case 10: _t->emetre_add_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 11: _t->emetre_supr_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FenRoDes::*)(int , Pos );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRoDes::modif_cell)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FenRoDes::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRoDes::supr_cell)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FenRoDes::*)(Pos );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRoDes::add_cell)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FenRoDes::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRoDes::add_cpl)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FenRoDes::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRoDes::supr_cpl)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject FenRoDes::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FenRoDes.offsetsAndSize,
    qt_meta_data_FenRoDes,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FenRoDes_t
, QtPrivate::TypeAndForceComplete<FenRoDes, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ViewMode, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<qreal, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *FenRoDes::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenRoDes::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenRoDes.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FenRoDes::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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

// SIGNAL 0
void FenRoDes::modif_cell(int _t1, Pos _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FenRoDes::supr_cell(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FenRoDes::add_cell(Pos _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FenRoDes::add_cpl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FenRoDes::supr_cpl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
struct qt_meta_stringdata_MonBout_t {
    const uint offsetsAndSize[10];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MonBout_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MonBout_t qt_meta_stringdata_MonBout = {
    {
QT_MOC_LITERAL(0, 7), // "MonBout"
QT_MOC_LITERAL(8, 11), // "mon_clicked"
QT_MOC_LITERAL(20, 0), // ""
QT_MOC_LITERAL(21, 8), // "MonBout*"
QT_MOC_LITERAL(30, 13) // "envoyer_click"

    },
    "MonBout\0mon_clicked\0\0MonBout*\0"
    "envoyer_click"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MonBout[] = {

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

void MonBout::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MonBout *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mon_clicked((*reinterpret_cast< MonBout*(*)>(_a[1]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MonBout* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MonBout::*)(MonBout * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonBout::mon_clicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MonBout::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_MonBout.offsetsAndSize,
    qt_meta_data_MonBout,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MonBout_t
, QtPrivate::TypeAndForceComplete<MonBout, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MonBout *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MonBout::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonBout::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonBout.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int MonBout::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MonBout::mon_clicked(MonBout * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FenRoBut_t {
    const uint offsetsAndSize[12];
    char stringdata0[43];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FenRoBut_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FenRoBut_t qt_meta_stringdata_FenRoBut = {
    {
QT_MOC_LITERAL(0, 8), // "FenRoBut"
QT_MOC_LITERAL(9, 7), // "aj_mode"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 8), // "ViewMode"
QT_MOC_LITERAL(27, 6), // "aj_but"
QT_MOC_LITERAL(34, 8) // "MonBout*"

    },
    "FenRoBut\0aj_mode\0\0ViewMode\0aj_but\0"
    "MonBout*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenRoBut[] = {

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

void FenRoBut::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenRoBut *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->aj_mode((*reinterpret_cast< ViewMode(*)>(_a[1]))); break;
        case 1: _t->aj_but((*reinterpret_cast< MonBout*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MonBout* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FenRoBut::*)(ViewMode );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRoBut::aj_mode)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FenRoBut::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FenRoBut.offsetsAndSize,
    qt_meta_data_FenRoBut,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FenRoBut_t
, QtPrivate::TypeAndForceComplete<FenRoBut, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ViewMode, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MonBout *, std::false_type>


>,
    nullptr
} };


const QMetaObject *FenRoBut::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenRoBut::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenRoBut.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FenRoBut::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FenRoBut::aj_mode(ViewMode _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FenRo_t {
    const uint offsetsAndSize[34];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FenRo_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FenRo_t qt_meta_stringdata_FenRo = {
    {
QT_MOC_LITERAL(0, 5), // "FenRo"
QT_MOC_LITERAL(6, 10), // "modif_cell"
QT_MOC_LITERAL(17, 0), // ""
QT_MOC_LITERAL(18, 5), // "index"
QT_MOC_LITERAL(24, 3), // "Pos"
QT_MOC_LITERAL(28, 3), // "pos"
QT_MOC_LITERAL(32, 9), // "supr_cell"
QT_MOC_LITERAL(42, 8), // "add_cell"
QT_MOC_LITERAL(51, 7), // "add_cpl"
QT_MOC_LITERAL(59, 3), // "i_1"
QT_MOC_LITERAL(63, 3), // "i_2"
QT_MOC_LITERAL(67, 8), // "supr_cpl"
QT_MOC_LITERAL(76, 17), // "emetre_modif_cell"
QT_MOC_LITERAL(94, 16), // "emetre_supr_cell"
QT_MOC_LITERAL(111, 15), // "emetre_add_cell"
QT_MOC_LITERAL(127, 14), // "emetre_add_cpl"
QT_MOC_LITERAL(142, 15) // "emetre_supr_cpl"

    },
    "FenRo\0modif_cell\0\0index\0Pos\0pos\0"
    "supr_cell\0add_cell\0add_cpl\0i_1\0i_2\0"
    "supr_cpl\0emetre_modif_cell\0emetre_supr_cell\0"
    "emetre_add_cell\0emetre_add_cpl\0"
    "emetre_supr_cpl"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenRo[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   74,    2, 0x06,    1 /* Public */,
       6,    1,   79,    2, 0x06,    4 /* Public */,
       7,    1,   82,    2, 0x06,    6 /* Public */,
       8,    2,   85,    2, 0x06,    8 /* Public */,
      11,    2,   90,    2, 0x06,   11 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      12,    2,   95,    2, 0x0a,   14 /* Public */,
      13,    1,  100,    2, 0x0a,   17 /* Public */,
      14,    1,  103,    2, 0x0a,   19 /* Public */,
      15,    2,  106,    2, 0x0a,   21 /* Public */,
      16,    2,  111,    2, 0x0a,   24 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, 0x80000000 | 4,    3,    5,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    9,   10,

       0        // eod
};

void FenRo::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenRo *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->modif_cell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Pos(*)>(_a[2]))); break;
        case 1: _t->supr_cell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 2: _t->add_cell((*reinterpret_cast< Pos(*)>(_a[1]))); break;
        case 3: _t->add_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 4: _t->supr_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 5: _t->emetre_modif_cell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Pos(*)>(_a[2]))); break;
        case 6: _t->emetre_supr_cell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 7: _t->emetre_add_cell((*reinterpret_cast< Pos(*)>(_a[1]))); break;
        case 8: _t->emetre_add_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 9: _t->emetre_supr_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FenRo::*)(int , Pos );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRo::modif_cell)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FenRo::*)(int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRo::supr_cell)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (FenRo::*)(Pos );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRo::add_cell)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (FenRo::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRo::add_cpl)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (FenRo::*)(int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenRo::supr_cpl)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject FenRo::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FenRo.offsetsAndSize,
    qt_meta_data_FenRo,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FenRo_t
, QtPrivate::TypeAndForceComplete<FenRo, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *FenRo::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenRo::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenRo.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FenRo::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 10;
    }
    return _id;
}

// SIGNAL 0
void FenRo::modif_cell(int _t1, Pos _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FenRo::supr_cell(int _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void FenRo::add_cell(Pos _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void FenRo::add_cpl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void FenRo::supr_cpl(int _t1, int _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
