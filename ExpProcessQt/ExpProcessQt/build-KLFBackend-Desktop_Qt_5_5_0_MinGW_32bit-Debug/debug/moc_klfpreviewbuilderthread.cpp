/****************************************************************************
** Meta object code from reading C++ file 'klfpreviewbuilderthread.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.5.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../klfbackend/klfpreviewbuilderthread.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'klfpreviewbuilderthread.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.5.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_KLFPreviewBuilderThread_t {
    QByteArrayData data[11];
    char stringdata0[150];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_KLFPreviewBuilderThread_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_KLFPreviewBuilderThread_t qt_meta_stringdata_KLFPreviewBuilderThread = {
    {
QT_MOC_LITERAL(0, 0, 23), // "KLFPreviewBuilderThread"
QT_MOC_LITERAL(1, 24, 16), // "previewAvailable"
QT_MOC_LITERAL(2, 41, 0), // ""
QT_MOC_LITERAL(3, 42, 7), // "preview"
QT_MOC_LITERAL(4, 50, 10), // "latexerror"
QT_MOC_LITERAL(5, 61, 12), // "inputChanged"
QT_MOC_LITERAL(6, 74, 20), // "KLFBackend::klfInput"
QT_MOC_LITERAL(7, 95, 5), // "input"
QT_MOC_LITERAL(8, 101, 15), // "settingsChanged"
QT_MOC_LITERAL(9, 117, 23), // "KLFBackend::klfSettings"
QT_MOC_LITERAL(10, 141, 8) // "settings"

    },
    "KLFPreviewBuilderThread\0previewAvailable\0"
    "\0preview\0latexerror\0inputChanged\0"
    "KLFBackend::klfInput\0input\0settingsChanged\0"
    "KLFBackend::klfSettings\0settings"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_KLFPreviewBuilderThread[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    1,   34,    2, 0x0a /* Public */,
       8,    1,   37,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QImage, QMetaType::Bool,    3,    4,

 // slots: parameters
    QMetaType::Bool, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,

       0        // eod
};

void KLFPreviewBuilderThread::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        KLFPreviewBuilderThread *_t = static_cast<KLFPreviewBuilderThread *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->previewAvailable((*reinterpret_cast< const QImage(*)>(_a[1])),(*reinterpret_cast< bool(*)>(_a[2]))); break;
        case 1: { bool _r = _t->inputChanged((*reinterpret_cast< const KLFBackend::klfInput(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 2: _t->settingsChanged((*reinterpret_cast< const KLFBackend::klfSettings(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (KLFPreviewBuilderThread::*_t)(const QImage & , bool );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&KLFPreviewBuilderThread::previewAvailable)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject KLFPreviewBuilderThread::staticMetaObject = {
    { &QThread::staticMetaObject, qt_meta_stringdata_KLFPreviewBuilderThread.data,
      qt_meta_data_KLFPreviewBuilderThread,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *KLFPreviewBuilderThread::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *KLFPreviewBuilderThread::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_KLFPreviewBuilderThread.stringdata0))
        return static_cast<void*>(const_cast< KLFPreviewBuilderThread*>(this));
    return QThread::qt_metacast(_clname);
}

int KLFPreviewBuilderThread::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QThread::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void KLFPreviewBuilderThread::previewAvailable(const QImage & _t1, bool _t2)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
