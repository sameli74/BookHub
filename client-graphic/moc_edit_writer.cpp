/****************************************************************************
** Meta object code from reading C++ file 'edit_writer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../A7-92417/edit_writer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'edit_writer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_edit_writer_t {
    QByteArrayData data[6];
    char stringdata0[99];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_edit_writer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_edit_writer_t qt_meta_stringdata_edit_writer = {
    {
QT_MOC_LITERAL(0, 0, 11), // "edit_writer"
QT_MOC_LITERAL(1, 12, 35), // "on_changeToWriterComboBox_act..."
QT_MOC_LITERAL(2, 48, 0), // ""
QT_MOC_LITERAL(3, 49, 5), // "index"
QT_MOC_LITERAL(4, 55, 21), // "on_buttonBox_rejected"
QT_MOC_LITERAL(5, 77, 21) // "on_buttonBox_accepted"

    },
    "edit_writer\0on_changeToWriterComboBox_activated\0"
    "\0index\0on_buttonBox_rejected\0"
    "on_buttonBox_accepted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_edit_writer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x08 /* Private */,
       4,    0,   32,    2, 0x08 /* Private */,
       5,    0,   33,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void edit_writer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        edit_writer *_t = static_cast<edit_writer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_changeToWriterComboBox_activated((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 1: _t->on_buttonBox_rejected(); break;
        case 2: _t->on_buttonBox_accepted(); break;
        default: ;
        }
    }
}

const QMetaObject edit_writer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_edit_writer.data,
      qt_meta_data_edit_writer,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *edit_writer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *edit_writer::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_edit_writer.stringdata0))
        return static_cast<void*>(const_cast< edit_writer*>(this));
    return QDialog::qt_metacast(_clname);
}

int edit_writer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
