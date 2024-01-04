/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.12.10)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../IDE/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.12.10. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[19];
    char stringdata0[425];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_MainWindow_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10), // "MainWindow"
QT_MOC_LITERAL(1, 11, 30), // "on_actionNew_Project_triggered"
QT_MOC_LITERAL(2, 42, 0), // ""
QT_MOC_LITERAL(3, 43, 26), // "on_actionSetting_triggered"
QT_MOC_LITERAL(4, 70, 31), // "on_actionOpen_Project_triggered"
QT_MOC_LITERAL(5, 102, 23), // "on_textEdit_textChanged"
QT_MOC_LITERAL(6, 126, 26), // "on_treeViewProject_clicked"
QT_MOC_LITERAL(7, 153, 11), // "QModelIndex"
QT_MOC_LITERAL(8, 165, 5), // "index"
QT_MOC_LITERAL(9, 171, 12), // "onTopClicked"
QT_MOC_LITERAL(10, 184, 24), // "on_actionAbout_triggered"
QT_MOC_LITERAL(11, 209, 23), // "on_actionSave_triggered"
QT_MOC_LITERAL(12, 233, 27), // "on_actionOpenFile_triggered"
QT_MOC_LITERAL(13, 261, 29), // "on_actionOpenFolder_triggered"
QT_MOC_LITERAL(14, 291, 26), // "on_actionNewFile_triggered"
QT_MOC_LITERAL(15, 318, 22), // "on_actionRun_triggered"
QT_MOC_LITERAL(16, 341, 27), // "on_actionCompiler_triggered"
QT_MOC_LITERAL(17, 369, 29), // "on_tabWidget_2_currentChanged"
QT_MOC_LITERAL(18, 399, 25) // "on_actionExit_2_triggered"

    },
    "MainWindow\0on_actionNew_Project_triggered\0"
    "\0on_actionSetting_triggered\0"
    "on_actionOpen_Project_triggered\0"
    "on_textEdit_textChanged\0"
    "on_treeViewProject_clicked\0QModelIndex\0"
    "index\0onTopClicked\0on_actionAbout_triggered\0"
    "on_actionSave_triggered\0"
    "on_actionOpenFile_triggered\0"
    "on_actionOpenFolder_triggered\0"
    "on_actionNewFile_triggered\0"
    "on_actionRun_triggered\0"
    "on_actionCompiler_triggered\0"
    "on_tabWidget_2_currentChanged\0"
    "on_actionExit_2_triggered"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      15,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   89,    2, 0x08 /* Private */,
       3,    0,   90,    2, 0x08 /* Private */,
       4,    0,   91,    2, 0x08 /* Private */,
       5,    0,   92,    2, 0x08 /* Private */,
       6,    1,   93,    2, 0x08 /* Private */,
       9,    1,   96,    2, 0x08 /* Private */,
      10,    0,   99,    2, 0x08 /* Private */,
      11,    0,  100,    2, 0x08 /* Private */,
      12,    0,  101,    2, 0x08 /* Private */,
      13,    0,  102,    2, 0x08 /* Private */,
      14,    0,  103,    2, 0x08 /* Private */,
      15,    0,  104,    2, 0x08 /* Private */,
      16,    0,  105,    2, 0x08 /* Private */,
      17,    1,  106,    2, 0x08 /* Private */,
      18,    0,  109,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 7,    8,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->on_actionNew_Project_triggered(); break;
        case 1: _t->on_actionSetting_triggered(); break;
        case 2: _t->on_actionOpen_Project_triggered(); break;
        case 3: _t->on_textEdit_textChanged(); break;
        case 4: _t->on_treeViewProject_clicked((*reinterpret_cast< const QModelIndex(*)>(_a[1]))); break;
        case 5: _t->onTopClicked((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_actionAbout_triggered(); break;
        case 7: _t->on_actionSave_triggered(); break;
        case 8: _t->on_actionOpenFile_triggered(); break;
        case 9: _t->on_actionOpenFolder_triggered(); break;
        case 10: _t->on_actionNewFile_triggered(); break;
        case 11: _t->on_actionRun_triggered(); break;
        case 12: _t->on_actionCompiler_triggered(); break;
        case 13: _t->on_tabWidget_2_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 14: _t->on_actionExit_2_triggered(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject MainWindow::staticMetaObject = { {
    &QMainWindow::staticMetaObject,
    qt_meta_stringdata_MainWindow.data,
    qt_meta_data_MainWindow,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 15)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 15;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 15)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 15;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
