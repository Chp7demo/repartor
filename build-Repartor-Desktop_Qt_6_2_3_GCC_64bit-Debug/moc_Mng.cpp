/****************************************************************************
** Meta object code from reading C++ file 'Mng.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Repartor/Mng.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Mng.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Mng_t {
    const uint offsetsAndSize[62];
    char stringdata0[364];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_Mng_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_Mng_t qt_meta_stringdata_Mng = {
    {
QT_MOC_LITERAL(0, 3), // "Mng"
QT_MOC_LITERAL(4, 9), // "refreshed"
QT_MOC_LITERAL(14, 0), // ""
QT_MOC_LITERAL(15, 8), // "Elements"
QT_MOC_LITERAL(24, 17), // "std::map<int,int>"
QT_MOC_LITERAL(42, 27), // "refresh_without_circle_disp"
QT_MOC_LITERAL(70, 18), // "cell_pos_refreshed"
QT_MOC_LITERAL(89, 16), // "std::vector<Pos>"
QT_MOC_LITERAL(106, 13), // "std::set<int>"
QT_MOC_LITERAL(120, 18), // "cell_map_refreshed"
QT_MOC_LITERAL(139, 12), // "make_refresh"
QT_MOC_LITERAL(152, 11), // "lancer_calc"
QT_MOC_LITERAL(164, 10), // "place_elem"
QT_MOC_LITERAL(175, 11), // "vector<int>"
QT_MOC_LITERAL(187, 15), // "rfsh_elem_space"
QT_MOC_LITERAL(203, 9), // "new_inter"
QT_MOC_LITERAL(213, 9), // "interType"
QT_MOC_LITERAL(223, 10), // "modif_cell"
QT_MOC_LITERAL(234, 5), // "index"
QT_MOC_LITERAL(240, 3), // "Pos"
QT_MOC_LITERAL(244, 9), // "supr_cell"
QT_MOC_LITERAL(254, 6), // "Combi&"
QT_MOC_LITERAL(261, 4), // "comb"
QT_MOC_LITERAL(266, 8), // "add_cell"
QT_MOC_LITERAL(275, 3), // "pos"
QT_MOC_LITERAL(279, 7), // "add_cpl"
QT_MOC_LITERAL(287, 8), // "supr_cpl"
QT_MOC_LITERAL(296, 16), // "aj_elem_cell_map"
QT_MOC_LITERAL(313, 18), // "elem_cell_map_supr"
QT_MOC_LITERAL(332, 14), // "ad_frozen_cell"
QT_MOC_LITERAL(347, 16) // "supr_frozen_cell"

    },
    "Mng\0refreshed\0\0Elements\0std::map<int,int>\0"
    "refresh_without_circle_disp\0"
    "cell_pos_refreshed\0std::vector<Pos>\0"
    "std::set<int>\0cell_map_refreshed\0"
    "make_refresh\0lancer_calc\0place_elem\0"
    "vector<int>\0rfsh_elem_space\0new_inter\0"
    "interType\0modif_cell\0index\0Pos\0supr_cell\0"
    "Combi&\0comb\0add_cell\0pos\0add_cpl\0"
    "supr_cpl\0aj_elem_cell_map\0elem_cell_map_supr\0"
    "ad_frozen_cell\0supr_frozen_cell"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Mng[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       5,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,  128,    2, 0x06,    1 /* Public */,
       5,    2,  133,    2, 0x06,    4 /* Public */,
       6,    3,  138,    2, 0x06,    7 /* Public */,
       9,    1,  145,    2, 0x06,   11 /* Public */,
      10,    2,  148,    2, 0x06,   13 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
      11,    0,  153,    2, 0x0a,   16 /* Public */,
      12,    1,  154,    2, 0x0a,   17 /* Public */,
      14,    1,  157,    2, 0x0a,   19 /* Public */,
      15,    3,  160,    2, 0x0a,   21 /* Public */,
      17,    2,  167,    2, 0x0a,   25 /* Public */,
      20,    1,  172,    2, 0x0a,   28 /* Public */,
      20,    2,  175,    2, 0x0a,   30 /* Public */,
      23,    1,  180,    2, 0x0a,   33 /* Public */,
      25,    2,  183,    2, 0x0a,   35 /* Public */,
      26,    2,  188,    2, 0x0a,   38 /* Public */,
      27,    2,  193,    2, 0x0a,   41 /* Public */,
      28,    1,  198,    2, 0x0a,   44 /* Public */,
      29,    1,  201,    2, 0x0a,   46 /* Public */,
      30,    1,  204,    2, 0x0a,   48 /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,
    QMetaType::Void, 0x80000000 | 7, 0x80000000 | 4, 0x80000000 | 8,    2,    2,    2,
    QMetaType::Void, 0x80000000 | 4,    2,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 4,    2,    2,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,    2,
    QMetaType::Void, QMetaType::QStringList,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 16,    2,    2,    2,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 19,   18,    2,
    QMetaType::Void, QMetaType::Int,   18,
    QMetaType::Void, QMetaType::Int, 0x80000000 | 21,   18,   22,
    QMetaType::Void, 0x80000000 | 19,   24,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::Int,    2,    2,
    QMetaType::Void, QMetaType::QString,    2,
    QMetaType::Void, QMetaType::Int,    2,
    QMetaType::Void, QMetaType::Int,    2,

       0        // eod
};

void Mng::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Mng *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->refreshed((*reinterpret_cast< Elements(*)>(_a[1])),(*reinterpret_cast< std::map<int,int>(*)>(_a[2]))); break;
        case 1: _t->refresh_without_circle_disp((*reinterpret_cast< Elements(*)>(_a[1])),(*reinterpret_cast< std::map<int,int>(*)>(_a[2]))); break;
        case 2: _t->cell_pos_refreshed((*reinterpret_cast< std::vector<Pos>(*)>(_a[1])),(*reinterpret_cast< std::map<int,int>(*)>(_a[2])),(*reinterpret_cast< std::set<int>(*)>(_a[3]))); break;
        case 3: _t->cell_map_refreshed((*reinterpret_cast< std::map<int,int>(*)>(_a[1]))); break;
        case 4: _t->make_refresh((*reinterpret_cast< Elements(*)>(_a[1])),(*reinterpret_cast< std::map<int,int>(*)>(_a[2]))); break;
        case 5: _t->lancer_calc(); break;
        case 6: _t->place_elem((*reinterpret_cast< vector<int>(*)>(_a[1]))); break;
        case 7: _t->rfsh_elem_space((*reinterpret_cast< QList<QString>(*)>(_a[1]))); break;
        case 8: _t->new_inter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< interType(*)>(_a[3]))); break;
        case 9: _t->modif_cell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Pos(*)>(_a[2]))); break;
        case 10: _t->supr_cell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: _t->supr_cell((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< Combi(*)>(_a[2]))); break;
        case 12: _t->add_cell((*reinterpret_cast< Pos(*)>(_a[1]))); break;
        case 13: _t->add_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 14: _t->supr_cpl((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 15: _t->aj_elem_cell_map((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 16: _t->elem_cell_map_supr((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 17: _t->ad_frozen_cell((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 18: _t->supr_frozen_cell((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Mng::*)(Elements , std::map<int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mng::refreshed)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Mng::*)(Elements , std::map<int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mng::refresh_without_circle_disp)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Mng::*)(std::vector<Pos> , std::map<int,int> , std::set<int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mng::cell_pos_refreshed)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Mng::*)(std::map<int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mng::cell_map_refreshed)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Mng::*)(Elements , std::map<int,int> );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Mng::make_refresh)) {
                *result = 4;
                return;
            }
        }
    }
}

const QMetaObject Mng::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Mng.offsetsAndSize,
    qt_meta_data_Mng,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_Mng_t
, QtPrivate::TypeAndForceComplete<Mng, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Elements, std::false_type>, QtPrivate::TypeAndForceComplete<std::map<int,int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Elements, std::false_type>, QtPrivate::TypeAndForceComplete<std::map<int,int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::vector<Pos>, std::false_type>, QtPrivate::TypeAndForceComplete<std::map<int,int>, std::false_type>, QtPrivate::TypeAndForceComplete<std::set<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<std::map<int,int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Elements, std::false_type>, QtPrivate::TypeAndForceComplete<std::map<int,int>, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<vector<int>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QList<QString>, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<interType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<Combi &, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<Pos, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<int, std::false_type>


>,
    nullptr
} };


const QMetaObject *Mng::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Mng::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Mng.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Mng::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 19;
    }
    return _id;
}

// SIGNAL 0
void Mng::refreshed(Elements _t1, std::map<int,int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Mng::refresh_without_circle_disp(Elements _t1, std::map<int,int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Mng::cell_pos_refreshed(std::vector<Pos> _t1, std::map<int,int> _t2, std::set<int> _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Mng::cell_map_refreshed(std::map<int,int> _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Mng::make_refresh(Elements _t1, std::map<int,int> _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 4, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
