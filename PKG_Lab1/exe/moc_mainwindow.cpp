/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.6.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../PKG_Lab1/mainwindow.h"
#include <QtGui/qtextcursor.h>
#include <QtGui/qscreen.h>
#include <QtCore/qmetatype.h>

#if __has_include(<QtCore/qtmochelpers.h>)
#include <QtCore/qtmochelpers.h>
#else
QT_BEGIN_MOC_NAMESPACE
#endif


#include <memory>

#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.6.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
QT_WARNING_DISABLE_GCC("-Wuseless-cast")
namespace {

#ifdef QT_MOC_HAS_STRINGDATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {};
static constexpr auto qt_meta_stringdata_CLASSMainWindowENDCLASS = QtMocHelpers::stringData(
    "MainWindow",
    "r_rgb_spin_valueChanged",
    "",
    "arg1",
    "g_rgb_spin_valueChanged",
    "b_rgb_spin_valueChanged",
    "l_lab_spin_valueChanged",
    "a_lab_spin_valueChanged",
    "b_lab_spin_valueChanged",
    "c_cmyk_spin_valueChanged",
    "m_cmyk_spin_valueChanged",
    "y_cmyk_spin_valueChanged",
    "k_cmyk_spin_valueChanged",
    "h_hsl_spin_valueChanged",
    "s_hsl_spin_valueChanged",
    "l_hsl_spin_valueChanged",
    "h_hsv_spin_valueChanged",
    "s_hsv_spin_valueChanged",
    "v_hsv_spin_valueChanged",
    "x_xyz_spin_valueChanged",
    "y_xyz_spin_valueChanged",
    "z_xyz_spin_valueChanged",
    "r_rgb_slider_valueChanged",
    "value",
    "g_rgb_slider_valueChanged",
    "b_rgb_slider_valueChanged",
    "l_lab_slider_valueChanged",
    "a_lab_slider_valueChanged",
    "b_lab_slider_valueChanged",
    "c_cmyk_slider_valueChanged",
    "m_cmyk_slider_valueChanged",
    "y_cmyk_slider_valueChanged",
    "k_cmyk_slider_valueChanged",
    "h_hsl_slider_valueChanged",
    "s_hsl_slider_valueChanged",
    "l_hsl_slider_valueChanged",
    "h_hsv_slider_valueChanged",
    "s_hsv_slider_valueChanged",
    "v_hsv_slider_valueChanged",
    "x_xyz_slider_valueChanged",
    "y_xyz_slider_valueChanged",
    "z_xyz_slider_valueChanged",
    "on_comboBox_currentIndexChanged",
    "index",
    "color_selected",
    "color"
);
#else  // !QT_MOC_HAS_STRING_DATA
struct qt_meta_stringdata_CLASSMainWindowENDCLASS_t {
    uint offsetsAndSizes[92];
    char stringdata0[11];
    char stringdata1[24];
    char stringdata2[1];
    char stringdata3[5];
    char stringdata4[24];
    char stringdata5[24];
    char stringdata6[24];
    char stringdata7[24];
    char stringdata8[24];
    char stringdata9[25];
    char stringdata10[25];
    char stringdata11[25];
    char stringdata12[25];
    char stringdata13[24];
    char stringdata14[24];
    char stringdata15[24];
    char stringdata16[24];
    char stringdata17[24];
    char stringdata18[24];
    char stringdata19[24];
    char stringdata20[24];
    char stringdata21[24];
    char stringdata22[26];
    char stringdata23[6];
    char stringdata24[26];
    char stringdata25[26];
    char stringdata26[26];
    char stringdata27[26];
    char stringdata28[26];
    char stringdata29[27];
    char stringdata30[27];
    char stringdata31[27];
    char stringdata32[27];
    char stringdata33[26];
    char stringdata34[26];
    char stringdata35[26];
    char stringdata36[26];
    char stringdata37[26];
    char stringdata38[26];
    char stringdata39[26];
    char stringdata40[26];
    char stringdata41[26];
    char stringdata42[32];
    char stringdata43[6];
    char stringdata44[15];
    char stringdata45[6];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_CLASSMainWindowENDCLASS_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_CLASSMainWindowENDCLASS_t qt_meta_stringdata_CLASSMainWindowENDCLASS = {
    {
        QT_MOC_LITERAL(0, 10),  // "MainWindow"
        QT_MOC_LITERAL(11, 23),  // "r_rgb_spin_valueChanged"
        QT_MOC_LITERAL(35, 0),  // ""
        QT_MOC_LITERAL(36, 4),  // "arg1"
        QT_MOC_LITERAL(41, 23),  // "g_rgb_spin_valueChanged"
        QT_MOC_LITERAL(65, 23),  // "b_rgb_spin_valueChanged"
        QT_MOC_LITERAL(89, 23),  // "l_lab_spin_valueChanged"
        QT_MOC_LITERAL(113, 23),  // "a_lab_spin_valueChanged"
        QT_MOC_LITERAL(137, 23),  // "b_lab_spin_valueChanged"
        QT_MOC_LITERAL(161, 24),  // "c_cmyk_spin_valueChanged"
        QT_MOC_LITERAL(186, 24),  // "m_cmyk_spin_valueChanged"
        QT_MOC_LITERAL(211, 24),  // "y_cmyk_spin_valueChanged"
        QT_MOC_LITERAL(236, 24),  // "k_cmyk_spin_valueChanged"
        QT_MOC_LITERAL(261, 23),  // "h_hsl_spin_valueChanged"
        QT_MOC_LITERAL(285, 23),  // "s_hsl_spin_valueChanged"
        QT_MOC_LITERAL(309, 23),  // "l_hsl_spin_valueChanged"
        QT_MOC_LITERAL(333, 23),  // "h_hsv_spin_valueChanged"
        QT_MOC_LITERAL(357, 23),  // "s_hsv_spin_valueChanged"
        QT_MOC_LITERAL(381, 23),  // "v_hsv_spin_valueChanged"
        QT_MOC_LITERAL(405, 23),  // "x_xyz_spin_valueChanged"
        QT_MOC_LITERAL(429, 23),  // "y_xyz_spin_valueChanged"
        QT_MOC_LITERAL(453, 23),  // "z_xyz_spin_valueChanged"
        QT_MOC_LITERAL(477, 25),  // "r_rgb_slider_valueChanged"
        QT_MOC_LITERAL(503, 5),  // "value"
        QT_MOC_LITERAL(509, 25),  // "g_rgb_slider_valueChanged"
        QT_MOC_LITERAL(535, 25),  // "b_rgb_slider_valueChanged"
        QT_MOC_LITERAL(561, 25),  // "l_lab_slider_valueChanged"
        QT_MOC_LITERAL(587, 25),  // "a_lab_slider_valueChanged"
        QT_MOC_LITERAL(613, 25),  // "b_lab_slider_valueChanged"
        QT_MOC_LITERAL(639, 26),  // "c_cmyk_slider_valueChanged"
        QT_MOC_LITERAL(666, 26),  // "m_cmyk_slider_valueChanged"
        QT_MOC_LITERAL(693, 26),  // "y_cmyk_slider_valueChanged"
        QT_MOC_LITERAL(720, 26),  // "k_cmyk_slider_valueChanged"
        QT_MOC_LITERAL(747, 25),  // "h_hsl_slider_valueChanged"
        QT_MOC_LITERAL(773, 25),  // "s_hsl_slider_valueChanged"
        QT_MOC_LITERAL(799, 25),  // "l_hsl_slider_valueChanged"
        QT_MOC_LITERAL(825, 25),  // "h_hsv_slider_valueChanged"
        QT_MOC_LITERAL(851, 25),  // "s_hsv_slider_valueChanged"
        QT_MOC_LITERAL(877, 25),  // "v_hsv_slider_valueChanged"
        QT_MOC_LITERAL(903, 25),  // "x_xyz_slider_valueChanged"
        QT_MOC_LITERAL(929, 25),  // "y_xyz_slider_valueChanged"
        QT_MOC_LITERAL(955, 25),  // "z_xyz_slider_valueChanged"
        QT_MOC_LITERAL(981, 31),  // "on_comboBox_currentIndexChanged"
        QT_MOC_LITERAL(1013, 5),  // "index"
        QT_MOC_LITERAL(1019, 14),  // "color_selected"
        QT_MOC_LITERAL(1034, 5)   // "color"
    },
    "MainWindow",
    "r_rgb_spin_valueChanged",
    "",
    "arg1",
    "g_rgb_spin_valueChanged",
    "b_rgb_spin_valueChanged",
    "l_lab_spin_valueChanged",
    "a_lab_spin_valueChanged",
    "b_lab_spin_valueChanged",
    "c_cmyk_spin_valueChanged",
    "m_cmyk_spin_valueChanged",
    "y_cmyk_spin_valueChanged",
    "k_cmyk_spin_valueChanged",
    "h_hsl_spin_valueChanged",
    "s_hsl_spin_valueChanged",
    "l_hsl_spin_valueChanged",
    "h_hsv_spin_valueChanged",
    "s_hsv_spin_valueChanged",
    "v_hsv_spin_valueChanged",
    "x_xyz_spin_valueChanged",
    "y_xyz_spin_valueChanged",
    "z_xyz_spin_valueChanged",
    "r_rgb_slider_valueChanged",
    "value",
    "g_rgb_slider_valueChanged",
    "b_rgb_slider_valueChanged",
    "l_lab_slider_valueChanged",
    "a_lab_slider_valueChanged",
    "b_lab_slider_valueChanged",
    "c_cmyk_slider_valueChanged",
    "m_cmyk_slider_valueChanged",
    "y_cmyk_slider_valueChanged",
    "k_cmyk_slider_valueChanged",
    "h_hsl_slider_valueChanged",
    "s_hsl_slider_valueChanged",
    "l_hsl_slider_valueChanged",
    "h_hsv_slider_valueChanged",
    "s_hsv_slider_valueChanged",
    "v_hsv_slider_valueChanged",
    "x_xyz_slider_valueChanged",
    "y_xyz_slider_valueChanged",
    "z_xyz_slider_valueChanged",
    "on_comboBox_currentIndexChanged",
    "index",
    "color_selected",
    "color"
};
#undef QT_MOC_LITERAL
#endif // !QT_MOC_HAS_STRING_DATA
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_CLASSMainWindowENDCLASS[] = {

 // content:
      12,       // revision
       0,       // classname
       0,    0, // classinfo
      40,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    1,  254,    2, 0x08,    1 /* Private */,
       4,    1,  257,    2, 0x08,    3 /* Private */,
       5,    1,  260,    2, 0x08,    5 /* Private */,
       6,    1,  263,    2, 0x08,    7 /* Private */,
       7,    1,  266,    2, 0x08,    9 /* Private */,
       8,    1,  269,    2, 0x08,   11 /* Private */,
       9,    1,  272,    2, 0x08,   13 /* Private */,
      10,    1,  275,    2, 0x08,   15 /* Private */,
      11,    1,  278,    2, 0x08,   17 /* Private */,
      12,    1,  281,    2, 0x08,   19 /* Private */,
      13,    1,  284,    2, 0x08,   21 /* Private */,
      14,    1,  287,    2, 0x08,   23 /* Private */,
      15,    1,  290,    2, 0x08,   25 /* Private */,
      16,    1,  293,    2, 0x08,   27 /* Private */,
      17,    1,  296,    2, 0x08,   29 /* Private */,
      18,    1,  299,    2, 0x08,   31 /* Private */,
      19,    1,  302,    2, 0x08,   33 /* Private */,
      20,    1,  305,    2, 0x08,   35 /* Private */,
      21,    1,  308,    2, 0x08,   37 /* Private */,
      22,    1,  311,    2, 0x08,   39 /* Private */,
      24,    1,  314,    2, 0x08,   41 /* Private */,
      25,    1,  317,    2, 0x08,   43 /* Private */,
      26,    1,  320,    2, 0x08,   45 /* Private */,
      27,    1,  323,    2, 0x08,   47 /* Private */,
      28,    1,  326,    2, 0x08,   49 /* Private */,
      29,    1,  329,    2, 0x08,   51 /* Private */,
      30,    1,  332,    2, 0x08,   53 /* Private */,
      31,    1,  335,    2, 0x08,   55 /* Private */,
      32,    1,  338,    2, 0x08,   57 /* Private */,
      33,    1,  341,    2, 0x08,   59 /* Private */,
      34,    1,  344,    2, 0x08,   61 /* Private */,
      35,    1,  347,    2, 0x08,   63 /* Private */,
      36,    1,  350,    2, 0x08,   65 /* Private */,
      37,    1,  353,    2, 0x08,   67 /* Private */,
      38,    1,  356,    2, 0x08,   69 /* Private */,
      39,    1,  359,    2, 0x08,   71 /* Private */,
      40,    1,  362,    2, 0x08,   73 /* Private */,
      41,    1,  365,    2, 0x08,   75 /* Private */,
      42,    1,  368,    2, 0x08,   77 /* Private */,
      44,    1,  371,    2, 0x0a,   79 /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,    3,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   23,
    QMetaType::Void, QMetaType::Int,   43,
    QMetaType::Void, QMetaType::QColor,   45,

       0        // eod
};

Q_CONSTINIT const QMetaObject MainWindow::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_CLASSMainWindowENDCLASS.offsetsAndSizes,
    qt_meta_data_CLASSMainWindowENDCLASS,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_CLASSMainWindowENDCLASS_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<MainWindow, std::true_type>,
        // method 'r_rgb_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'g_rgb_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'b_rgb_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'l_lab_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'a_lab_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'b_lab_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'c_cmyk_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'm_cmyk_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'y_cmyk_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'k_cmyk_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'h_hsl_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 's_hsl_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'l_hsl_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'h_hsv_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 's_hsv_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'v_hsv_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'x_xyz_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'y_xyz_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'z_xyz_spin_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'r_rgb_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'g_rgb_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'b_rgb_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'l_lab_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'a_lab_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'b_lab_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'c_cmyk_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'm_cmyk_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'y_cmyk_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'k_cmyk_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'h_hsl_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 's_hsl_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'l_hsl_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'h_hsv_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 's_hsv_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'v_hsv_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'x_xyz_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'y_xyz_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'z_xyz_slider_valueChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'on_comboBox_currentIndexChanged'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        // method 'color_selected'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<QColor, std::false_type>
    >,
    nullptr
} };

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<MainWindow *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->r_rgb_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 1: _t->g_rgb_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 2: _t->b_rgb_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 3: _t->l_lab_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 4: _t->a_lab_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 5: _t->b_lab_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 6: _t->c_cmyk_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 7: _t->m_cmyk_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 8: _t->y_cmyk_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 9: _t->k_cmyk_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 10: _t->h_hsl_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 11: _t->s_hsl_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 12: _t->l_hsl_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 13: _t->h_hsv_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 14: _t->s_hsv_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 15: _t->v_hsv_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 16: _t->x_xyz_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 17: _t->y_xyz_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 18: _t->z_xyz_spin_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 19: _t->r_rgb_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 20: _t->g_rgb_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 21: _t->b_rgb_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 22: _t->l_lab_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 23: _t->a_lab_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 24: _t->b_lab_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 25: _t->c_cmyk_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 26: _t->m_cmyk_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 27: _t->y_cmyk_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 28: _t->k_cmyk_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 29: _t->h_hsl_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 30: _t->s_hsl_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 31: _t->l_hsl_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 32: _t->h_hsv_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 33: _t->s_hsv_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 34: _t->v_hsv_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 35: _t->x_xyz_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 36: _t->y_xyz_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 37: _t->z_xyz_slider_valueChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 38: _t->on_comboBox_currentIndexChanged((*reinterpret_cast< std::add_pointer_t<int>>(_a[1]))); break;
        case 39: _t->color_selected((*reinterpret_cast< std::add_pointer_t<QColor>>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_CLASSMainWindowENDCLASS.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 40)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 40;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 40)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 40;
    }
    return _id;
}
QT_WARNING_POP
