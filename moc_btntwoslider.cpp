/****************************************************************************
** Meta object code from reading C++ file 'btntwoslider.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "btntwoslider.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'btntwoslider.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_btnTwoSlider_t {
    QByteArrayData data[14];
    char stringdata0[181];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_btnTwoSlider_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_btnTwoSlider_t qt_meta_stringdata_btnTwoSlider = {
    {
QT_MOC_LITERAL(0, 0, 12), // "btnTwoSlider"
QT_MOC_LITERAL(1, 13, 11), // "lightSwitch"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 21), // "colorTxtMouseReleased"
QT_MOC_LITERAL(4, 48, 8), // "focusOut"
QT_MOC_LITERAL(5, 57, 13), // "statusChanged"
QT_MOC_LITERAL(6, 71, 2), // "id"
QT_MOC_LITERAL(7, 74, 7), // "checked"
QT_MOC_LITERAL(8, 82, 15), // "rgbValueChanged"
QT_MOC_LITERAL(9, 98, 22), // "brightnessValueChanged"
QT_MOC_LITERAL(10, 121, 28), // "colorTemperatureValueChanged"
QT_MOC_LITERAL(11, 150, 15), // "editingFinished"
QT_MOC_LITERAL(12, 166, 10), // "textEdited"
QT_MOC_LITERAL(13, 177, 3) // "txt"

    },
    "btnTwoSlider\0lightSwitch\0\0"
    "colorTxtMouseReleased\0focusOut\0"
    "statusChanged\0id\0checked\0rgbValueChanged\0"
    "brightnessValueChanged\0"
    "colorTemperatureValueChanged\0"
    "editingFinished\0textEdited\0txt"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_btnTwoSlider[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    0,   60,    2, 0x06 /* Public */,
       4,    0,   61,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    2,   62,    2, 0x08 /* Private */,
       8,    0,   67,    2, 0x08 /* Private */,
       9,    0,   68,    2, 0x08 /* Private */,
      10,    0,   69,    2, 0x08 /* Private */,
      11,    0,   70,    2, 0x08 /* Private */,
      12,    1,   71,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Short, QMetaType::Bool,    6,    7,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   13,

       0        // eod
};

void btnTwoSlider::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<btnTwoSlider *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->lightSwitch(); break;
        case 1: _t->colorTxtMouseReleased(); break;
        case 2: _t->focusOut(); break;
        case 3: _t->statusChanged((*reinterpret_cast< qint16(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 4: _t->rgbValueChanged(); break;
        case 5: _t->brightnessValueChanged(); break;
        case 6: _t->colorTemperatureValueChanged(); break;
        case 7: _t->editingFinished(); break;
        case 8: _t->textEdited((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (btnTwoSlider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnTwoSlider::lightSwitch)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (btnTwoSlider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnTwoSlider::colorTxtMouseReleased)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (btnTwoSlider::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&btnTwoSlider::focusOut)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject btnTwoSlider::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_btnTwoSlider.data,
    qt_meta_data_btnTwoSlider,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *btnTwoSlider::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *btnTwoSlider::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_btnTwoSlider.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int btnTwoSlider::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void btnTwoSlider::lightSwitch()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void btnTwoSlider::colorTxtMouseReleased()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void btnTwoSlider::focusOut()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
