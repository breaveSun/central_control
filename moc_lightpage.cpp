/****************************************************************************
** Meta object code from reading C++ file 'lightpage.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "lightpage.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'lightpage.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_lightPage_t {
    QByteArrayData data[16];
    char stringdata0[159];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_lightPage_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_lightPage_t qt_meta_stringdata_lightPage = {
    {
QT_MOC_LITERAL(0, 0, 9), // "lightPage"
QT_MOC_LITERAL(1, 10, 12), // "goBackSignal"
QT_MOC_LITERAL(2, 23, 0), // ""
QT_MOC_LITERAL(3, 24, 8), // "PageBack"
QT_MOC_LITERAL(4, 33, 2), // "pb"
QT_MOC_LITERAL(5, 36, 7), // "houseId"
QT_MOC_LITERAL(6, 44, 7), // "spaceId"
QT_MOC_LITERAL(7, 52, 6), // "roomId"
QT_MOC_LITERAL(8, 59, 10), // "goBackSlot"
QT_MOC_LITERAL(9, 70, 12), // "closeAllSlot"
QT_MOC_LITERAL(10, 83, 11), // "ligthSwitch"
QT_MOC_LITERAL(11, 95, 10), // "acceptPush"
QT_MOC_LITERAL(12, 106, 16), // "deviceDataStruct"
QT_MOC_LITERAL(13, 123, 4), // "data"
QT_MOC_LITERAL(14, 128, 21), // "colorTxtMouseReleased"
QT_MOC_LITERAL(15, 150, 8) // "focusOut"

    },
    "lightPage\0goBackSignal\0\0PageBack\0pb\0"
    "houseId\0spaceId\0roomId\0goBackSlot\0"
    "closeAllSlot\0ligthSwitch\0acceptPush\0"
    "deviceDataStruct\0data\0colorTxtMouseReleased\0"
    "focusOut"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_lightPage[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    4,   49,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    0,   58,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,
      10,    0,   60,    2, 0x08 /* Private */,
      11,    1,   61,    2, 0x08 /* Private */,
      14,    0,   64,    2, 0x08 /* Private */,
      15,    0,   65,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3, QMetaType::Int, QMetaType::Int, QMetaType::Int,    4,    5,    6,    7,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 12,   13,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void lightPage::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<lightPage *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->goBackSignal((*reinterpret_cast< PageBack(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        case 1: _t->goBackSlot(); break;
        case 2: _t->closeAllSlot(); break;
        case 3: _t->ligthSwitch(); break;
        case 4: _t->acceptPush((*reinterpret_cast< deviceDataStruct(*)>(_a[1]))); break;
        case 5: _t->colorTxtMouseReleased(); break;
        case 6: _t->focusOut(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< deviceDataStruct >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (lightPage::*)(PageBack , int , int , int );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&lightPage::goBackSignal)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject lightPage::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_lightPage.data,
    qt_meta_data_lightPage,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *lightPage::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *lightPage::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_lightPage.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int lightPage::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void lightPage::goBackSignal(PageBack _t1, int _t2, int _t3, int _t4)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t3))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t4))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
