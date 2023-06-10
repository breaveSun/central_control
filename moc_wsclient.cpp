/****************************************************************************
** Meta object code from reading C++ file 'wsclient.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.5)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "wsclient.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'wsclient.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.5. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_wsClient_t {
    QByteArrayData data[17];
    char stringdata0[208];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_wsClient_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_wsClient_t qt_meta_stringdata_wsClient = {
    {
QT_MOC_LITERAL(0, 0, 8), // "wsClient"
QT_MOC_LITERAL(1, 9, 7), // "notices"
QT_MOC_LITERAL(2, 17, 0), // ""
QT_MOC_LITERAL(3, 18, 16), // "deviceDataStruct"
QT_MOC_LITERAL(4, 35, 5), // "datas"
QT_MOC_LITERAL(5, 41, 13), // "messageStruct"
QT_MOC_LITERAL(6, 55, 15), // "sendTextMessage"
QT_MOC_LITERAL(7, 71, 7), // "message"
QT_MOC_LITERAL(8, 79, 17), // "sendBinaryMessage"
QT_MOC_LITERAL(9, 97, 4), // "data"
QT_MOC_LITERAL(10, 102, 12), // "on_connected"
QT_MOC_LITERAL(11, 115, 15), // "on_disconnected"
QT_MOC_LITERAL(12, 131, 8), // "on_error"
QT_MOC_LITERAL(13, 140, 28), // "QAbstractSocket::SocketError"
QT_MOC_LITERAL(14, 169, 5), // "error"
QT_MOC_LITERAL(15, 175, 22), // "on_textMessageReceived"
QT_MOC_LITERAL(16, 198, 9) // "reconnect"

    },
    "wsClient\0notices\0\0deviceDataStruct\0"
    "datas\0messageStruct\0sendTextMessage\0"
    "message\0sendBinaryMessage\0data\0"
    "on_connected\0on_disconnected\0on_error\0"
    "QAbstractSocket::SocketError\0error\0"
    "on_textMessageReceived\0reconnect"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_wsClient[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   59,    2, 0x06 /* Public */,
       1,    1,   62,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    1,   65,    2, 0x08 /* Private */,
       8,    1,   68,    2, 0x08 /* Private */,
      10,    0,   71,    2, 0x08 /* Private */,
      11,    0,   72,    2, 0x08 /* Private */,
      12,    1,   73,    2, 0x08 /* Private */,
      15,    1,   76,    2, 0x08 /* Private */,
      16,    0,   79,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 5,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void, QMetaType::QByteArray,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 13,   14,
    QMetaType::Void, QMetaType::QString,    7,
    QMetaType::Void,

       0        // eod
};

void wsClient::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<wsClient *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->notices((*reinterpret_cast< deviceDataStruct(*)>(_a[1]))); break;
        case 1: _t->notices((*reinterpret_cast< messageStruct(*)>(_a[1]))); break;
        case 2: _t->sendTextMessage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 3: _t->sendBinaryMessage((*reinterpret_cast< const QByteArray(*)>(_a[1]))); break;
        case 4: _t->on_connected(); break;
        case 5: _t->on_disconnected(); break;
        case 6: _t->on_error((*reinterpret_cast< QAbstractSocket::SocketError(*)>(_a[1]))); break;
        case 7: _t->on_textMessageReceived((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 8: _t->reconnect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 0:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< deviceDataStruct >(); break;
            }
            break;
        case 1:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< messageStruct >(); break;
            }
            break;
        case 6:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QAbstractSocket::SocketError >(); break;
            }
            break;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (wsClient::*)(deviceDataStruct );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wsClient::notices)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (wsClient::*)(messageStruct );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&wsClient::notices)) {
                *result = 1;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject wsClient::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_wsClient.data,
    qt_meta_data_wsClient,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *wsClient::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *wsClient::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_wsClient.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int wsClient::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void wsClient::notices(deviceDataStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void wsClient::notices(messageStruct _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
