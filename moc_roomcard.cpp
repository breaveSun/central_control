/****************************************************************************
** Meta object code from reading C++ file 'roomcard.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "roomcard.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'roomcard.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_roomCard_t {
    QByteArrayData data[15];
    char stringdata0[118];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_roomCard_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_roomCard_t qt_meta_stringdata_roomCard = {
    {
QT_MOC_LITERAL(0, 0, 8), // "roomCard"
QT_MOC_LITERAL(1, 9, 6), // "goPage"
QT_MOC_LITERAL(2, 16, 0), // ""
QT_MOC_LITERAL(3, 17, 8), // "PageBack"
QT_MOC_LITERAL(4, 26, 2), // "pb"
QT_MOC_LITERAL(5, 29, 7), // "houseId"
QT_MOC_LITERAL(6, 37, 7), // "spaceId"
QT_MOC_LITERAL(7, 45, 6), // "roomId"
QT_MOC_LITERAL(8, 52, 8), // "slipLeft"
QT_MOC_LITERAL(9, 61, 9), // "slipRight"
QT_MOC_LITERAL(10, 71, 11), // "checkDevice"
QT_MOC_LITERAL(11, 83, 11), // "changeScene"
QT_MOC_LITERAL(12, 95, 2), // "id"
QT_MOC_LITERAL(13, 98, 13), // "sliderChanged"
QT_MOC_LITERAL(14, 112, 5) // "value"

    },
    "roomCard\0goPage\0\0PageBack\0pb\0houseId\0"
    "spaceId\0roomId\0slipLeft\0slipRight\0"
    "checkDevice\0changeScene\0id\0sliderChanged\0"
    "value"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_roomCard[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       6,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   44,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   53,    2, 0x08 /* Private */,
       9,    0,   54,    2, 0x08 /* Private */,
      10,    0,   55,    2, 0x08 /* Private */,
      11,    1,   56,    2, 0x08 /* Private */,
      13,    1,   59,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   12,
    QMetaType::Void, QMetaType::Int,   14,

       0        // eod
};

void roomCard::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<roomCard *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->goPage((*reinterpret_cast< PageBack(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->slipLeft(); break;
        case 2: _t->slipRight(); break;
        case 3: _t->checkDevice(); break;
        case 4: _t->changeScene((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 5: _t->sliderChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (roomCard::*)(PageBack , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&roomCard::goPage)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject roomCard::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_roomCard.data,
    qt_meta_data_roomCard,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *roomCard::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *roomCard::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_roomCard.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int roomCard::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 6)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 6;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 6)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 6;
    }
    return _id;
}

// SIGNAL 0
void roomCard::goPage(PageBack _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
