/****************************************************************************
** Meta object code from reading C++ file 'FenI.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.2.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../Repartor/Feni/FenI.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'FenI.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.2.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MaGraphicsViewI_t {
    const uint offsetsAndSize[20];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MaGraphicsViewI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MaGraphicsViewI_t qt_meta_stringdata_MaGraphicsViewI = {
    {
QT_MOC_LITERAL(0, 15), // "MaGraphicsViewI"
QT_MOC_LITERAL(16, 10), // "nouv_inter"
QT_MOC_LITERAL(27, 0), // ""
QT_MOC_LITERAL(28, 9), // "interType"
QT_MOC_LITERAL(38, 4), // "sous"
QT_MOC_LITERAL(43, 10), // "aff_cercle"
QT_MOC_LITERAL(54, 6), // "SClass"
QT_MOC_LITERAL(61, 7), // "setMode"
QT_MOC_LITERAL(69, 9), // "ViewModeI"
QT_MOC_LITERAL(79, 2) // "vM"

    },
    "MaGraphicsViewI\0nouv_inter\0\0interType\0"
    "sous\0aff_cercle\0SClass\0setMode\0ViewModeI\0"
    "vM"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MaGraphicsViewI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   38,    2, 0x06,    1 /* Public */,
       4,    0,   45,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   46,    2, 0x0a,    6 /* Public */,
       7,    1,   49,    2, 0x0a,    8 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, 0x80000000 | 8,    9,

       0        // eod
};

void MaGraphicsViewI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MaGraphicsViewI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nouv_inter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< interType(*)>(_a[3]))); break;
        case 1: _t->sous(); break;
        case 2: _t->aff_cercle((*reinterpret_cast< SClass(*)>(_a[1]))); break;
        case 3: _t->setMode((*reinterpret_cast< ViewModeI(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MaGraphicsViewI::*)(QString , QString , interType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaGraphicsViewI::nouv_inter)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (MaGraphicsViewI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MaGraphicsViewI::sous)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject MaGraphicsViewI::staticMetaObject = { {
    QMetaObject::SuperData::link<QGraphicsView::staticMetaObject>(),
    qt_meta_stringdata_MaGraphicsViewI.offsetsAndSize,
    qt_meta_data_MaGraphicsViewI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MaGraphicsViewI_t
, QtPrivate::TypeAndForceComplete<MaGraphicsViewI, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<interType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SClass, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ViewModeI, std::false_type>


>,
    nullptr
} };


const QMetaObject *MaGraphicsViewI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MaGraphicsViewI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MaGraphicsViewI.stringdata0))
        return static_cast<void*>(this);
    return QGraphicsView::qt_metacast(_clname);
}

int MaGraphicsViewI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void MaGraphicsViewI::nouv_inter(QString _t1, QString _t2, interType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MaGraphicsViewI::sous()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
struct qt_meta_stringdata_FenDesI_t {
    const uint offsetsAndSize[18];
    char stringdata0[82];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FenDesI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FenDesI_t qt_meta_stringdata_FenDesI = {
    {
QT_MOC_LITERAL(0, 7), // "FenDesI"
QT_MOC_LITERAL(8, 10), // "nouv_inter"
QT_MOC_LITERAL(19, 0), // ""
QT_MOC_LITERAL(20, 9), // "interType"
QT_MOC_LITERAL(30, 7), // "setMode"
QT_MOC_LITERAL(38, 9), // "ViewModeI"
QT_MOC_LITERAL(48, 10), // "aff_cercle"
QT_MOC_LITERAL(59, 6), // "SClass"
QT_MOC_LITERAL(66, 15) // "pass_nouv_inter"

    },
    "FenDesI\0nouv_inter\0\0interType\0setMode\0"
    "ViewModeI\0aff_cercle\0SClass\0pass_nouv_inter"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenDesI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   38,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       4,    1,   45,    2, 0x0a,    5 /* Public */,
       6,    1,   48,    2, 0x0a,    7 /* Public */,
       8,    3,   51,    2, 0x0a,    9 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 3,    2,    2,    2,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 5,    2,
    QMetaType::Void, 0x80000000 | 7,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 3,    2,    2,    2,

       0        // eod
};

void FenDesI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenDesI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nouv_inter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< interType(*)>(_a[3]))); break;
        case 1: _t->setMode((*reinterpret_cast< ViewModeI(*)>(_a[1]))); break;
        case 2: _t->aff_cercle((*reinterpret_cast< SClass(*)>(_a[1]))); break;
        case 3: _t->pass_nouv_inter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< interType(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FenDesI::*)(QString , QString , interType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenDesI::nouv_inter)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FenDesI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FenDesI.offsetsAndSize,
    qt_meta_data_FenDesI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FenDesI_t
, QtPrivate::TypeAndForceComplete<FenDesI, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<interType, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ViewModeI, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SClass, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<interType, std::false_type>


>,
    nullptr
} };


const QMetaObject *FenDesI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenDesI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenDesI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FenDesI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 4;
    }
    return _id;
}

// SIGNAL 0
void FenDesI::nouv_inter(QString _t1, QString _t2, interType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_MonBoutI_t {
    const uint offsetsAndSize[10];
    char stringdata0[46];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_MonBoutI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_MonBoutI_t qt_meta_stringdata_MonBoutI = {
    {
QT_MOC_LITERAL(0, 8), // "MonBoutI"
QT_MOC_LITERAL(9, 11), // "mon_clicked"
QT_MOC_LITERAL(21, 0), // ""
QT_MOC_LITERAL(22, 9), // "MonBoutI*"
QT_MOC_LITERAL(32, 13) // "envoyer_click"

    },
    "MonBoutI\0mon_clicked\0\0MonBoutI*\0"
    "envoyer_click"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MonBoutI[] = {

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

void MonBoutI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MonBoutI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->mon_clicked((*reinterpret_cast< MonBoutI*(*)>(_a[1]))); break;
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
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MonBoutI* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (MonBoutI::*)(MonBoutI * );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&MonBoutI::mon_clicked)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject MonBoutI::staticMetaObject = { {
    QMetaObject::SuperData::link<QPushButton::staticMetaObject>(),
    qt_meta_stringdata_MonBoutI.offsetsAndSize,
    qt_meta_data_MonBoutI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_MonBoutI_t
, QtPrivate::TypeAndForceComplete<MonBoutI, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MonBoutI *, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *MonBoutI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MonBoutI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MonBoutI.stringdata0))
        return static_cast<void*>(this);
    return QPushButton::qt_metacast(_clname);
}

int MonBoutI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void MonBoutI::mon_clicked(MonBoutI * _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FenButI_t {
    const uint offsetsAndSize[12];
    char stringdata0[44];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FenButI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FenButI_t qt_meta_stringdata_FenButI = {
    {
QT_MOC_LITERAL(0, 7), // "FenButI"
QT_MOC_LITERAL(8, 7), // "aj_mode"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 9), // "ViewModeI"
QT_MOC_LITERAL(27, 6), // "aj_but"
QT_MOC_LITERAL(34, 9) // "MonBoutI*"

    },
    "FenButI\0aj_mode\0\0ViewModeI\0aj_but\0"
    "MonBoutI*"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenButI[] = {

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

void FenButI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenButI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->aj_mode((*reinterpret_cast< ViewModeI(*)>(_a[1]))); break;
        case 1: _t->aj_but((*reinterpret_cast< MonBoutI*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType(); break;
            case 0:
                *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType::fromType< MonBoutI* >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FenButI::*)(ViewModeI );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenButI::aj_mode)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject FenButI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FenButI.offsetsAndSize,
    qt_meta_data_FenButI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FenButI_t
, QtPrivate::TypeAndForceComplete<FenButI, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<ViewModeI, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<MonBoutI *, std::false_type>


>,
    nullptr
} };


const QMetaObject *FenButI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenButI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenButI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FenButI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
void FenButI::aj_mode(ViewModeI _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
struct qt_meta_stringdata_FenI_t {
    const uint offsetsAndSize[18];
    char stringdata0[97];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(offsetof(qt_meta_stringdata_FenI_t, stringdata0) + ofs), len 
static const qt_meta_stringdata_FenI_t qt_meta_stringdata_FenI = {
    {
QT_MOC_LITERAL(0, 4), // "FenI"
QT_MOC_LITERAL(5, 10), // "nouv_inter"
QT_MOC_LITERAL(16, 0), // ""
QT_MOC_LITERAL(17, 9), // "interType"
QT_MOC_LITERAL(27, 22), // "sous_cpt_freeze_fenres"
QT_MOC_LITERAL(50, 10), // "aff_cercle"
QT_MOC_LITERAL(61, 6), // "SClass"
QT_MOC_LITERAL(68, 15), // "pass_nouv_inter"
QT_MOC_LITERAL(84, 12) // "emettre_sous"

    },
    "FenI\0nouv_inter\0\0interType\0"
    "sous_cpt_freeze_fenres\0aff_cercle\0"
    "SClass\0pass_nouv_inter\0emettre_sous"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_FenI[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    3,   44,    2, 0x06,    1 /* Public */,
       4,    0,   51,    2, 0x06,    5 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       5,    1,   52,    2, 0x0a,    6 /* Public */,
       7,    3,   55,    2, 0x0a,    8 /* Public */,
       8,    0,   62,    2, 0x0a,   12 /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 6,    2,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, 0x80000000 | 3,    2,    2,    2,
    QMetaType::Void,

       0        // eod
};

void FenI::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<FenI *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->nouv_inter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< interType(*)>(_a[3]))); break;
        case 1: _t->sous_cpt_freeze_fenres(); break;
        case 2: _t->aff_cercle((*reinterpret_cast< SClass(*)>(_a[1]))); break;
        case 3: _t->pass_nouv_inter((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2])),(*reinterpret_cast< interType(*)>(_a[3]))); break;
        case 4: _t->emettre_sous(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (FenI::*)(QString , QString , interType );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenI::nouv_inter)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (FenI::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&FenI::sous_cpt_freeze_fenres)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject FenI::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_FenI.offsetsAndSize,
    qt_meta_data_FenI,
    qt_static_metacall,
    nullptr,
qt_incomplete_metaTypeArray<qt_meta_stringdata_FenI_t
, QtPrivate::TypeAndForceComplete<FenI, std::true_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<interType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>
, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<SClass, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<QString, std::false_type>, QtPrivate::TypeAndForceComplete<interType, std::false_type>, QtPrivate::TypeAndForceComplete<void, std::false_type>


>,
    nullptr
} };


const QMetaObject *FenI::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *FenI::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_FenI.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int FenI::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void FenI::nouv_inter(QString _t1, QString _t2, interType _t3)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void FenI::sous_cpt_freeze_fenres()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
