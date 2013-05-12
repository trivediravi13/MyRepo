/****************************************************************************
** Meta object code from reading C++ file 'xsd.h'
**
** Created:
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../XSD/xsd.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'xsd.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_XSD[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
       5,    4,    4,    4, 0x08,
      32,    4,    4,    4, 0x08,
      64,   56,    4,    4, 0x08,
      92,   56,    4,    4, 0x08,
     120,   56,    4,    4, 0x08,
     146,   56,    4,    4, 0x08,
     174,   56,    4,    4, 0x08,
     202,    4,    4,    4, 0x08,
     226,   56,    4,    4, 0x08,
     260,   56,    4,    4, 0x08,
     288,    4,    4,    4, 0x08,
     313,   56,    4,    4, 0x08,
     339,    4,    4,    4, 0x08,
     353,    4,    4,    4, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_XSD[] = {
    "XSD\0\0on_FolderBrowser_clicked()\0"
    "on_xsdbrowser_clicked()\0checked\0"
    "on_cxx_button_toggled(bool)\0"
    "on_cpp_button_toggled(bool)\0"
    "on_h_button_toggled(bool)\0"
    "on_hpp_button_toggled(bool)\0"
    "on_hxx_button_toggled(bool)\0"
    "on_pushButton_clicked()\0"
    "on_GenSerialization_toggled(bool)\0"
    "on_GenDoxygen_toggled(bool)\0"
    "on_exit_button_clicked()\0"
    "on_checkBox_toggled(bool)\0actionAbout()\0"
    "actionContent()\0"
};

void XSD::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        XSD *_t = static_cast<XSD *>(_o);
        switch (_id) {
        case 0: _t->on_FolderBrowser_clicked(); break;
        case 1: _t->on_xsdbrowser_clicked(); break;
        case 2: _t->on_cxx_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 3: _t->on_cpp_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 4: _t->on_h_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 5: _t->on_hpp_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 6: _t->on_hxx_button_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 7: _t->on_pushButton_clicked(); break;
        case 8: _t->on_GenSerialization_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 9: _t->on_GenDoxygen_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 10: _t->on_exit_button_clicked(); break;
        case 11: _t->on_checkBox_toggled((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 12: _t->actionAbout(); break;
        case 13: _t->actionContent(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData XSD::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject XSD::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_XSD,
      qt_meta_data_XSD, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &XSD::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *XSD::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *XSD::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_XSD))
        return static_cast<void*>(const_cast< XSD*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int XSD::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
