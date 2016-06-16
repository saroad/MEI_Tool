/****************************************************************************
** Meta object code from reading C++ file 'klfblockprocess.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../klfbackend/klfblockprocess.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'klfblockprocess.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KLFBlockProcess_t {
    QByteArrayData data[10];
    char stringdata0[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KLFBlockProcess_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KLFBlockProcess_t qt_meta_stringdata_KLFBlockProcess = {
    {
QT_MOC_LITERAL(0, 0, 15), // "KLFBlockProcess"
QT_MOC_LITERAL(1, 16, 12), // "startProcess"
QT_MOC_LITERAL(2, 29, 0), // ""
QT_MOC_LITERAL(3, 30, 3), // "cmd"
QT_MOC_LITERAL(4, 34, 9), // "stdindata"
QT_MOC_LITERAL(5, 44, 3), // "env"
QT_MOC_LITERAL(6, 48, 16), // "readStderrString"
QT_MOC_LITERAL(7, 65, 16), // "readStdoutString"
QT_MOC_LITERAL(8, 82, 13), // "ourProcExited"
QT_MOC_LITERAL(9, 96, 22) // "ourProcGotOurStdinData"

    },
    "KLFBlockProcess\0startProcess\0\0cmd\0"
    "stdindata\0env\0readStderrString\0"
    "readStdoutString\0ourProcExited\0"
    "ourProcGotOurStdinData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KLFBlockProcess[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    3,   54,    2, 0x0a /* Public */,
       1,    2,   61,    2, 0x2a /* Public | MethodCloned */,
       1,    2,   66,    2, 0x0a /* Public */,
       1,    1,   71,    2, 0x2a /* Public | MethodCloned */,
       6,    0,   74,    2, 0x0a /* Public */,
       7,    0,   75,    2, 0x0a /* Public */,
       8,    0,   76,    2, 0x08 /* Private */,
       9,    0,   77,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Bool, QMetaType::QStringList, QMetaType::QByteArray, QMetaType::QStringList,    3,    4,    5,
    QMetaType::Bool, QMetaType::QStringList, QMetaType::QByteArray,    3,    4,
    QMetaType::Bool, QMetaType::QStringList, QMetaType::QStringList,    3,    5,
    QMetaType::Bool, QMetaType::QStringList,    3,
    QMetaType::QString,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void KLFBlockProcess::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KLFBlockProcess *_t = static_cast<KLFBlockProcess *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { bool _r = _t->startProcess((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])),(*reinterpret_cast< QStringList(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: { bool _r = _t->startProcess((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QByteArray(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: { bool _r = _t->startProcess((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< QStringList(*)>(_a[2])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 3: { bool _r = _t->startProcess((*reinterpret_cast< QStringList(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 4: { QString _r = _t->readStderrString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 5: { QString _r = _t->readStdoutString();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = _r; }  break;
        case 6: _t->ourProcExited(); break;
        case 7: _t->ourProcGotOurStdinData(); break;
        default: ;
        }
    }
}

const QMetaObject KLFBlockProcess::staticMetaObject = {
    { &QProcess::staticMetaObject, qt_meta_stringdata_KLFBlockProcess.data,
      qt_meta_data_KLFBlockProcess,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KLFBlockProcess::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KLFBlockProcess::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KLFBlockProcess.stringdata0))
        return static_cast<void*>(const_cast< KLFBlockProcess*>(this));
    return QProcess::qt_metacast(_clname);
}

int KLFBlockProcess::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QProcess::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
