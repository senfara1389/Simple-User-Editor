/****************************************************************************
** Meta object code from reading C++ file 'usersbrieftableview.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../headers/usersbrieftableview.h"
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'usersbrieftableview.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_UsersBriefTableView_t {
    uint offsetsAndSizes[14];
    char stringdata0[20];
    char stringdata1[23];
    char stringdata2[1];
    char stringdata3[17];
    char stringdata4[12];
    char stringdata5[12];
    char stringdata6[15];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_UsersBriefTableView_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_UsersBriefTableView_t qt_meta_stringdata_UsersBriefTableView = {
    {
        QT_MOC_LITERAL(0, 19),  // "UsersBriefTableView"
        QT_MOC_LITERAL(20, 22),  // "clearDetailedTableView"
        QT_MOC_LITERAL(43, 0),  // ""
        QT_MOC_LITERAL(44, 16),  // "loadSelectedUser"
        QT_MOC_LITERAL(61, 11),  // "QModelIndex"
        QT_MOC_LITERAL(73, 11),  // "selectedRow"
        QT_MOC_LITERAL(85, 14)   // "deleteSelected"
    },
    "UsersBriefTableView",
    "clearDetailedTableView",
    "",
    "loadSelectedUser",
    "QModelIndex",
    "selectedRow",
    "deleteSelected"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_UsersBriefTableView[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags, initial metatype offsets
       1,    0,   32,    2, 0x06,    1 /* Public */,

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       3,    1,   33,    2, 0x0a,    2 /* Public */,
       6,    0,   36,    2, 0x0a,    4 /* Public */,

 // signals: parameters
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,

       0        // eod
};

Q_CONSTINIT const QMetaObject UsersBriefTableView::staticMetaObject = { {
    QMetaObject::SuperData::link<QTableView::staticMetaObject>(),
    qt_meta_stringdata_UsersBriefTableView.offsetsAndSizes,
    qt_meta_data_UsersBriefTableView,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_UsersBriefTableView_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<UsersBriefTableView, std::true_type>,
        // method 'clearDetailedTableView'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        // method 'loadSelectedUser'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<const QModelIndex &, std::false_type>,
        // method 'deleteSelected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>
    >,
    nullptr
} };

void UsersBriefTableView::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<UsersBriefTableView *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->clearDetailedTableView(); break;
        case 1: _t->loadSelectedUser((*reinterpret_cast< std::add_pointer_t<QModelIndex>>(_a[1]))); break;
        case 2: _t->deleteSelected(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (UsersBriefTableView::*)();
            if (_t _q_method = &UsersBriefTableView::clearDetailedTableView; *reinterpret_cast<_t *>(_a[1]) == _q_method) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject *UsersBriefTableView::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *UsersBriefTableView::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_UsersBriefTableView.stringdata0))
        return static_cast<void*>(this);
    return QTableView::qt_metacast(_clname);
}

int UsersBriefTableView::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QTableView::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void UsersBriefTableView::clearDetailedTableView()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE