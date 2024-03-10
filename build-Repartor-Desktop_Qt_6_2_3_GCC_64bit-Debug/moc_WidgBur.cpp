/****************************************************************************
** Meta object code from reading C++ file 'WidgBur.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Repartor/Fenro/WidgBur.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'WidgBur.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_WidgBur_t {
    const uint offsetsAndSize[16];
    char stringdata0[77];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_WidgBur_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_WidgBur_t qt_meta_stringdata_WidgBur = {
    {
QT_MOC_LITERAL(0, 7), // "WidgBur"
QT_MOC_LITERAL(8, 10), // "constr_cpl"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 12), // "clean_others"
QT_MOC_LITERAL(33, 12), // "aj_cpl_actif"
QT_MOC_LITERAL(46, 15), // "bar_oth_en_cour"
QT_MOC_LITERAL(62, 5), // "clean"
QT_MOC_LITERAL(68, 8) // "rotation"

    },
    "WidgBur\0constr_cpl\0\0clean_others\0"
    "aj_cpl_actif\0bar_oth_en_cour\0clean\0"
    "rotation"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_WidgBur[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   50,    2, 0x06,    1 /* Public */,
       3,    0,   51,    2, 0x06,    2 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   52,    2, 0x0a,    3 /* Public */,
       5,    0,   55,    2, 0x0a,    5 /* Public */,
       6,    0,   56,    2, 0x0a,    6 /* Public */,
       7,    0,   57,    2, 0x0a,    7 /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Bool,    2,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void WidgBur::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<WidgBur *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->constr_cpl(); break;
        case 1: _t->clean_others(); break;
        case 2: _t->aj_cpl_actif((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->bar_oth_en_cour(); break;
        case 4: _t->clean(); break;
        case 5: _t->rotation(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (WidgBur::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgBur::constr_cpl)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (WidgBur::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&WidgBur::clean_others)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject WidgBur::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsObject::staticMetaObject>(),
    qt_meta_stringdata_WidgBur.offsetsAndSize,
    qt_meta_data_WidgBur,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_WidgBur_t
, QtPrivate::TypeAndForceComplete<WidgBur, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<bool, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *WidgBur::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *WidgBur::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_WidgBur.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsObject::qt_metacast(_clname);
}

int WidgBur::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void WidgBur::constr_cpl()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void WidgBur::clean_others()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
