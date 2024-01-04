/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtGui/QIcon>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew_Project;
    QAction *actionOpen_Project;
    QAction *actionExit;
    QAction *actionSetting;
    QAction *actionExit_2;
    QAction *actionFile;
    QAction *actionEditor;
    QAction *actionDebuger;
    QAction *actionConsole;
    QAction *actionClass;
    QAction *actionOutput;
    QAction *actionStatus;
    QAction *actionTopBar;
    QAction *actionComplier;
    QAction *actionRun;
    QAction *actionDebug;
    QAction *actionSave;
    QAction *actionSaveAll;
    QAction *actionConfig;
    QAction *actionPackage;
    QAction *actionAbout;
    QAction *actionStop;
    QAction *actionOpenFile;
    QAction *actionNewFile;
    QAction *actionSelf;
    QAction *actionOpenFolder;
    QWidget *centralWidget;
    QVBoxLayout *verticalLayout_12;
    QVBoxLayout *verticalLayout_9;
    QHBoxLayout *horizontalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QVBoxLayout *verticalLayout_11;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *projectName;
    QGroupBox *groupBox_5;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_2;
    QPushButton *pushButton;
    QGroupBox *groupBox;
    QVBoxLayout *verticalLayout_13;
    QTreeView *treeViewProject;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_15;
    QListView *markList;
    QWidget *tab_2;
    QTabWidget *tabWidget_3;
    QWidget *tab_3;
    QVBoxLayout *verticalLayout_14;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit;
    QPushButton *pushButton_4;
    QListView *listView_undo;
    QWidget *tab_8;
    QVBoxLayout *verticalLayout_16;
    QListView *listView_doing;
    QWidget *tab_4;
    QVBoxLayout *verticalLayout_17;
    QListView *listView_done;
    QVBoxLayout *verticalLayout_3;
    QVBoxLayout *verticalLayout_5;
    QVBoxLayout *verticalLayout_6;
    QHBoxLayout *edit_title;
    QFrame *line;
    QGroupBox *groupBox_6;
    QHBoxLayout *horizontalLayout_10;
    QTextEdit *textEdit;
    QVBoxLayout *verticalLayout_7;
    QTabWidget *tabWidget_2;
    QWidget *tab_5;
    QVBoxLayout *verticalLayout_4;
    QPlainTextEdit *plainTextEdit_2;
    QWidget *tab_6;
    QGridLayout *gridLayout;
    QTextBrowser *textBrowser_output;
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout_8;
    QHBoxLayout *horizontalLayout_8;
    QPushButton *pushButton_12;
    QGroupBox *groupBox_4;
    QVBoxLayout *verticalLayout_10;
    QTreeView *treeView_2;
    QMenuBar *menuBar;
    QMenu *menu_file;
    QMenu *menu_view;
    QMenu *menu_code;
    QMenu *menu_tools;
    QMenu *menu_help;
    QStatusBar *statusBar;
    QToolBar *toolBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(1049, 720);
        QPalette palette;
        QBrush brush(QColor(58, 58, 58, 255));
        brush.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush1(QColor(227, 227, 227, 255));
        brush1.setStyle(Qt::SolidPattern);
        palette.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette.setBrush(QPalette::Active, QPalette::Text, brush);
        palette.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush2(QColor(58, 58, 58, 128));
        brush2.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Active, QPalette::PlaceholderText, brush2);
#endif
        palette.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush3(QColor(58, 58, 58, 128));
        brush3.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush3);
#endif
        palette.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush4(QColor(58, 58, 58, 128));
        brush4.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush4);
#endif
        MainWindow->setPalette(palette);
        QIcon icon;
        icon.addFile(QString::fromUtf8(":/icon/logo.ico"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        MainWindow->setStyleSheet(QString::fromUtf8("background:rgb(227, 227, 227);\n"
"color:rgb(58, 58, 58);\n"
"margin:0;\n"
"padding:0;\n"
"Spacing:0;\n"
""));
        actionNew_Project = new QAction(MainWindow);
        actionNew_Project->setObjectName(QString::fromUtf8("actionNew_Project"));
        QIcon icon1;
        icon1.addFile(QString::fromUtf8(":/icon/new_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew_Project->setIcon(icon1);
        actionOpen_Project = new QAction(MainWindow);
        actionOpen_Project->setObjectName(QString::fromUtf8("actionOpen_Project"));
        QIcon icon2;
        icon2.addFile(QString::fromUtf8(":/icon/open_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen_Project->setIcon(icon2);
        actionExit = new QAction(MainWindow);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionSetting = new QAction(MainWindow);
        actionSetting->setObjectName(QString::fromUtf8("actionSetting"));
        QIcon icon3;
        icon3.addFile(QString::fromUtf8(":/icon/build.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSetting->setIcon(icon3);
        actionExit_2 = new QAction(MainWindow);
        actionExit_2->setObjectName(QString::fromUtf8("actionExit_2"));
        actionFile = new QAction(MainWindow);
        actionFile->setObjectName(QString::fromUtf8("actionFile"));
        actionEditor = new QAction(MainWindow);
        actionEditor->setObjectName(QString::fromUtf8("actionEditor"));
        actionDebuger = new QAction(MainWindow);
        actionDebuger->setObjectName(QString::fromUtf8("actionDebuger"));
        actionConsole = new QAction(MainWindow);
        actionConsole->setObjectName(QString::fromUtf8("actionConsole"));
        actionClass = new QAction(MainWindow);
        actionClass->setObjectName(QString::fromUtf8("actionClass"));
        actionOutput = new QAction(MainWindow);
        actionOutput->setObjectName(QString::fromUtf8("actionOutput"));
        actionStatus = new QAction(MainWindow);
        actionStatus->setObjectName(QString::fromUtf8("actionStatus"));
        actionTopBar = new QAction(MainWindow);
        actionTopBar->setObjectName(QString::fromUtf8("actionTopBar"));
        actionComplier = new QAction(MainWindow);
        actionComplier->setObjectName(QString::fromUtf8("actionComplier"));
        actionComplier->setIcon(icon3);
        actionRun = new QAction(MainWindow);
        actionRun->setObjectName(QString::fromUtf8("actionRun"));
        QIcon icon4;
        icon4.addFile(QString::fromUtf8(":/icon/run.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionRun->setIcon(icon4);
        actionDebug = new QAction(MainWindow);
        actionDebug->setObjectName(QString::fromUtf8("actionDebug"));
        QIcon icon5;
        icon5.addFile(QString::fromUtf8(":/icon/bug.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDebug->setIcon(icon5);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QString::fromUtf8("actionSave"));
        QIcon icon6;
        icon6.addFile(QString::fromUtf8(":/icon/save_file.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon6);
        actionSaveAll = new QAction(MainWindow);
        actionSaveAll->setObjectName(QString::fromUtf8("actionSaveAll"));
        QIcon icon7;
        icon7.addFile(QString::fromUtf8(":/icon/save_all.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSaveAll->setIcon(icon7);
        actionConfig = new QAction(MainWindow);
        actionConfig->setObjectName(QString::fromUtf8("actionConfig"));
        actionPackage = new QAction(MainWindow);
        actionPackage->setObjectName(QString::fromUtf8("actionPackage"));
        actionAbout = new QAction(MainWindow);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionStop = new QAction(MainWindow);
        actionStop->setObjectName(QString::fromUtf8("actionStop"));
        QIcon icon8;
        icon8.addFile(QString::fromUtf8(":/icon/stop.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionStop->setIcon(icon8);
        actionOpenFile = new QAction(MainWindow);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionOpenFile->setIcon(icon2);
        actionNewFile = new QAction(MainWindow);
        actionNewFile->setObjectName(QString::fromUtf8("actionNewFile"));
        actionNewFile->setIcon(icon1);
        actionSelf = new QAction(MainWindow);
        actionSelf->setObjectName(QString::fromUtf8("actionSelf"));
        actionSelf->setCheckable(true);
        QIcon icon9;
        icon9.addFile(QString::fromUtf8(":/icon/264251323.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSelf->setIcon(icon9);
        actionSelf->setPriority(QAction::HighPriority);
        actionOpenFolder = new QAction(MainWindow);
        actionOpenFolder->setObjectName(QString::fromUtf8("actionOpenFolder"));
        actionOpenFolder->setIcon(icon2);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        centralWidget->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        QPalette palette1;
        palette1.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Text, brush);
        palette1.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush5(QColor(58, 58, 58, 128));
        brush5.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Active, QPalette::PlaceholderText, brush5);
#endif
        palette1.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush6(QColor(58, 58, 58, 128));
        brush6.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush6);
#endif
        palette1.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette1.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette1.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush7(QColor(58, 58, 58, 128));
        brush7.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette1.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush7);
#endif
        centralWidget->setPalette(palette1);
        centralWidget->setAcceptDrops(true);
        verticalLayout_12 = new QVBoxLayout(centralWidget);
        verticalLayout_12->setSpacing(6);
        verticalLayout_12->setContentsMargins(11, 11, 11, 11);
        verticalLayout_12->setObjectName(QString::fromUtf8("verticalLayout_12"));
        verticalLayout_9 = new QVBoxLayout();
        verticalLayout_9->setSpacing(0);
        verticalLayout_9->setObjectName(QString::fromUtf8("verticalLayout_9"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));

        verticalLayout_9->addLayout(horizontalLayout_3);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout->setContentsMargins(-1, -1, -1, 0);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        verticalLayout_11 = new QVBoxLayout();
        verticalLayout_11->setSpacing(0);
        verticalLayout_11->setObjectName(QString::fromUtf8("verticalLayout_11"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(0);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        projectName = new QPushButton(centralWidget);
        projectName->setObjectName(QString::fromUtf8("projectName"));
        projectName->setEnabled(true);
        projectName->setLayoutDirection(Qt::LeftToRight);
        projectName->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:rgb(231, 231, 231);\n"
"margin:0;\n"
"padding:1px;"));

        horizontalLayout_5->addWidget(projectName);

        groupBox_5 = new QGroupBox(centralWidget);
        groupBox_5->setObjectName(QString::fromUtf8("groupBox_5"));
        QPalette palette2;
        palette2.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush8(QColor(51, 51, 51, 255));
        brush8.setStyle(Qt::SolidPattern);
        palette2.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Text, brush);
        palette2.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette2.setBrush(QPalette::Active, QPalette::Window, brush8);
        QBrush brush9(QColor(58, 58, 58, 128));
        brush9.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Active, QPalette::PlaceholderText, brush9);
#endif
        palette2.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette2.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        QBrush brush10(QColor(58, 58, 58, 128));
        brush10.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush10);
#endif
        palette2.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette2.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette2.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        QBrush brush11(QColor(58, 58, 58, 128));
        brush11.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette2.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush11);
#endif
        groupBox_5->setPalette(palette2);
        groupBox_5->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:rgb(51, 51, 51);\n"
"margin:0;\n"
"padding:0px;\n"
"\n"
""));
        horizontalLayout_2 = new QHBoxLayout(groupBox_5);
        horizontalLayout_2->setSpacing(0);
        horizontalLayout_2->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        pushButton_3 = new QPushButton(groupBox_5);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("padding:1px;"));
        QIcon icon10;
        icon10.addFile(QString::fromUtf8(":/icon/refresh.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_3->setIcon(icon10);

        horizontalLayout_2->addWidget(pushButton_3);

        pushButton_2 = new QPushButton(groupBox_5);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("padding:1px;"));
        QIcon icon11;
        icon11.addFile(QString::fromUtf8(":/icon/new_task.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_2->setIcon(icon11);

        horizontalLayout_2->addWidget(pushButton_2);

        pushButton = new QPushButton(groupBox_5);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("padding:1px;"));
        QIcon icon12;
        icon12.addFile(QString::fromUtf8(":/icon/switch.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon12);

        horizontalLayout_2->addWidget(pushButton);


        horizontalLayout_5->addWidget(groupBox_5);


        verticalLayout_11->addLayout(horizontalLayout_5);

        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        QPalette palette3;
        palette3.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Text, brush);
        palette3.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush12(QColor(58, 58, 58, 128));
        brush12.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Active, QPalette::PlaceholderText, brush12);
#endif
        palette3.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush13(QColor(58, 58, 58, 128));
        brush13.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush13);
#endif
        palette3.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette3.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette3.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush14(QColor(58, 58, 58, 128));
        brush14.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette3.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush14);
#endif
        groupBox->setPalette(palette3);
        verticalLayout_13 = new QVBoxLayout(groupBox);
        verticalLayout_13->setSpacing(0);
        verticalLayout_13->setContentsMargins(11, 11, 11, 11);
        verticalLayout_13->setObjectName(QString::fromUtf8("verticalLayout_13"));
        verticalLayout_13->setContentsMargins(0, 0, 0, 0);
        treeViewProject = new QTreeView(groupBox);
        treeViewProject->setObjectName(QString::fromUtf8("treeViewProject"));
        sizePolicy.setHeightForWidth(treeViewProject->sizePolicy().hasHeightForWidth());
        treeViewProject->setSizePolicy(sizePolicy);
        QPalette palette4;
        palette4.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Text, brush);
        palette4.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush15(QColor(58, 58, 58, 128));
        brush15.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Active, QPalette::PlaceholderText, brush15);
#endif
        palette4.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush16(QColor(58, 58, 58, 128));
        brush16.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush16);
#endif
        palette4.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette4.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette4.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush17(QColor(58, 58, 58, 128));
        brush17.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette4.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush17);
#endif
        treeViewProject->setPalette(palette4);
        treeViewProject->setFocusPolicy(Qt::NoFocus);
        treeViewProject->setStyleSheet(QString::fromUtf8(""));
        treeViewProject->setFrameShape(QFrame::NoFrame);
        treeViewProject->setFrameShadow(QFrame::Plain);
        treeViewProject->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOn);
        treeViewProject->setHeaderHidden(true);
        treeViewProject->header()->setVisible(false);
        treeViewProject->header()->setStretchLastSection(true);

        verticalLayout_13->addWidget(treeViewProject);

        verticalLayout_13->setStretch(0, 10);

        verticalLayout_11->addWidget(groupBox);

        verticalLayout_11->setStretch(1, 10);

        verticalLayout->addLayout(verticalLayout_11);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
        tabWidget->setEnabled(true);
        QPalette palette5;
        palette5.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Text, brush);
        palette5.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush18(QColor(58, 58, 58, 128));
        brush18.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Active, QPalette::PlaceholderText, brush18);
#endif
        palette5.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush19(QColor(58, 58, 58, 128));
        brush19.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush19);
#endif
        palette5.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette5.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette5.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush20(QColor(58, 58, 58, 128));
        brush20.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette5.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush20);
#endif
        tabWidget->setPalette(palette5);
        tabWidget->setStyleSheet(QString::fromUtf8("QTabBar::tab\n"
"{\n"
"font:13px;\n"
"color:white; \n"
"border:none;\n"
"background:rgb(51, 51, 51);\n"
"height:20px;\n"
"width:75px;\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}\n"
"QTabBar::tab:!selected\n"
"{\n"
"background:rgb(51, 51, 51);\n"
"}\n"
"QTabBar::tab:hover:!selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}\n"
"QTabWidget::pane { /* The tab widget frame */  \n"
"   padding:0;\n"
"}  "));
        tabWidget->setTabPosition(QTabWidget::North);
        tabWidget->setTabShape(QTabWidget::Triangular);
        tabWidget->setElideMode(Qt::ElideLeft);
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_15 = new QVBoxLayout(tab);
        verticalLayout_15->setSpacing(6);
        verticalLayout_15->setContentsMargins(11, 11, 11, 11);
        verticalLayout_15->setObjectName(QString::fromUtf8("verticalLayout_15"));
        markList = new QListView(tab);
        markList->setObjectName(QString::fromUtf8("markList"));
        QPalette palette6;
        palette6.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Text, brush);
        palette6.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush21(QColor(58, 58, 58, 128));
        brush21.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Active, QPalette::PlaceholderText, brush21);
#endif
        palette6.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush22(QColor(58, 58, 58, 128));
        brush22.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush22);
#endif
        palette6.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette6.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette6.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush23(QColor(58, 58, 58, 128));
        brush23.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette6.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush23);
#endif
        markList->setPalette(palette6);
        markList->setFocusPolicy(Qt::NoFocus);
        markList->setStyleSheet(QString::fromUtf8("border:none;"));
        markList->setAutoScrollMargin(0);

        verticalLayout_15->addWidget(markList);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);

        tabWidget_3 = new QTabWidget(centralWidget);
        tabWidget_3->setObjectName(QString::fromUtf8("tabWidget_3"));
        QPalette palette7;
        palette7.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Text, brush);
        palette7.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush24(QColor(58, 58, 58, 128));
        brush24.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Active, QPalette::PlaceholderText, brush24);
#endif
        palette7.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush25(QColor(58, 58, 58, 128));
        brush25.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush25);
#endif
        palette7.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette7.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette7.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush26(QColor(58, 58, 58, 128));
        brush26.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette7.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush26);
#endif
        tabWidget_3->setPalette(palette7);
        tabWidget_3->setStyleSheet(QString::fromUtf8("QTabBar::tab\n"
"{\n"
"font:13px;\n"
"color:white; \n"
"border:none;\n"
"background:rgb(51, 51, 51);\n"
"height:20px;\n"
"width:50px;\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}\n"
"QTabBar::tab:!selected\n"
"{\n"
"background:rgb(51, 51, 51);\n"
"}\n"
"QTabBar::tab:hover:!selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}\n"
"QTabWidget::pane { /* The tab widget frame */  \n"
"   padding:0;\n"
"padding:-10px;\n"
"}  "));
        tabWidget_3->setElideMode(Qt::ElideLeft);
        tab_3 = new QWidget();
        tab_3->setObjectName(QString::fromUtf8("tab_3"));
        tab_3->setStyleSheet(QString::fromUtf8(""));
        verticalLayout_14 = new QVBoxLayout(tab_3);
        verticalLayout_14->setSpacing(6);
        verticalLayout_14->setContentsMargins(11, 11, 11, 11);
        verticalLayout_14->setObjectName(QString::fromUtf8("verticalLayout_14"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(0);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        lineEdit = new QLineEdit(tab_3);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));
        lineEdit->setFocusPolicy(Qt::ClickFocus);
        lineEdit->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:rgb(50,129,247);"));

        horizontalLayout_4->addWidget(lineEdit);

        pushButton_4 = new QPushButton(tab_3);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));
        pushButton_4->setStyleSheet(QString::fromUtf8("border:none;\n"
"margin:0;\n"
"padding:0;"));
        pushButton_4->setIcon(icon11);

        horizontalLayout_4->addWidget(pushButton_4);

        horizontalLayout_4->setStretch(0, 5);
        horizontalLayout_4->setStretch(1, 1);

        verticalLayout_14->addLayout(horizontalLayout_4);

        listView_undo = new QListView(tab_3);
        listView_undo->setObjectName(QString::fromUtf8("listView_undo"));
        QPalette palette8;
        palette8.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Text, brush);
        palette8.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush27(QColor(58, 58, 58, 128));
        brush27.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Active, QPalette::PlaceholderText, brush27);
#endif
        palette8.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush28(QColor(58, 58, 58, 128));
        brush28.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush28);
#endif
        palette8.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette8.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette8.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush29(QColor(58, 58, 58, 128));
        brush29.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette8.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush29);
#endif
        listView_undo->setPalette(palette8);
        listView_undo->setFocusPolicy(Qt::NoFocus);
        listView_undo->setStyleSheet(QString::fromUtf8("border:none;"));
        listView_undo->setAutoScrollMargin(0);

        verticalLayout_14->addWidget(listView_undo);

        verticalLayout_14->setStretch(0, 1);
        verticalLayout_14->setStretch(1, 5);
        tabWidget_3->addTab(tab_3, QString());
        tab_8 = new QWidget();
        tab_8->setObjectName(QString::fromUtf8("tab_8"));
        verticalLayout_16 = new QVBoxLayout(tab_8);
        verticalLayout_16->setSpacing(6);
        verticalLayout_16->setContentsMargins(11, 11, 11, 11);
        verticalLayout_16->setObjectName(QString::fromUtf8("verticalLayout_16"));
        listView_doing = new QListView(tab_8);
        listView_doing->setObjectName(QString::fromUtf8("listView_doing"));
        listView_doing->setFocusPolicy(Qt::NoFocus);
        listView_doing->setStyleSheet(QString::fromUtf8("border:none;"));
        listView_doing->setAutoScrollMargin(0);

        verticalLayout_16->addWidget(listView_doing);

        tabWidget_3->addTab(tab_8, QString());
        tab_4 = new QWidget();
        tab_4->setObjectName(QString::fromUtf8("tab_4"));
        verticalLayout_17 = new QVBoxLayout(tab_4);
        verticalLayout_17->setSpacing(6);
        verticalLayout_17->setContentsMargins(11, 11, 11, 11);
        verticalLayout_17->setObjectName(QString::fromUtf8("verticalLayout_17"));
        listView_done = new QListView(tab_4);
        listView_done->setObjectName(QString::fromUtf8("listView_done"));
        listView_done->setFocusPolicy(Qt::NoFocus);
        listView_done->setStyleSheet(QString::fromUtf8("border:none;"));
        listView_done->setAutoScrollMargin(0);

        verticalLayout_17->addWidget(listView_done);

        tabWidget_3->addTab(tab_4, QString());

        verticalLayout->addWidget(tabWidget_3);

        verticalLayout->setStretch(0, 5);
        verticalLayout->setStretch(1, 4);
        verticalLayout->setStretch(2, 4);

        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_5 = new QVBoxLayout();
        verticalLayout_5->setSpacing(6);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        verticalLayout_5->setContentsMargins(10, -1, -1, -1);
        verticalLayout_6 = new QVBoxLayout();
        verticalLayout_6->setSpacing(0);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        edit_title = new QHBoxLayout();
        edit_title->setSpacing(1);
        edit_title->setObjectName(QString::fromUtf8("edit_title"));

        verticalLayout_6->addLayout(edit_title);

        line = new QFrame(centralWidget);
        line->setObjectName(QString::fromUtf8("line"));
        line->setStyleSheet(QString::fromUtf8("background:rgb(0, 128, 255);\n"
"margin:0;\n"
"padding:0;\n"
"margin-top:-10px;"));
        line->setFrameShadow(QFrame::Sunken);
        line->setFrameShape(QFrame::HLine);

        verticalLayout_6->addWidget(line);

        groupBox_6 = new QGroupBox(centralWidget);
        groupBox_6->setObjectName(QString::fromUtf8("groupBox_6"));
        horizontalLayout_10 = new QHBoxLayout(groupBox_6);
        horizontalLayout_10->setSpacing(0);
        horizontalLayout_10->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        horizontalLayout_10->setContentsMargins(0, 0, 0, 0);
        textEdit = new QTextEdit(groupBox_6);
        textEdit->setObjectName(QString::fromUtf8("textEdit"));
        QPalette palette9;
        palette9.setBrush(QPalette::Active, QPalette::WindowText, brush);
        QBrush brush30(QColor(247, 247, 247, 255));
        brush30.setStyle(Qt::SolidPattern);
        palette9.setBrush(QPalette::Active, QPalette::Button, brush30);
        palette9.setBrush(QPalette::Active, QPalette::Text, brush);
        palette9.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Active, QPalette::Base, brush30);
        palette9.setBrush(QPalette::Active, QPalette::Window, brush30);
        QBrush brush31(QColor(58, 58, 58, 128));
        brush31.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Active, QPalette::PlaceholderText, brush31);
#endif
        palette9.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Button, brush30);
        palette9.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Inactive, QPalette::Base, brush30);
        palette9.setBrush(QPalette::Inactive, QPalette::Window, brush30);
        QBrush brush32(QColor(58, 58, 58, 128));
        brush32.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush32);
#endif
        palette9.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Button, brush30);
        palette9.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette9.setBrush(QPalette::Disabled, QPalette::Base, brush30);
        palette9.setBrush(QPalette::Disabled, QPalette::Window, brush30);
        QBrush brush33(QColor(58, 58, 58, 128));
        brush33.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette9.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush33);
#endif
        textEdit->setPalette(palette9);
        QFont font;
        font.setFamily(QString::fromUtf8("Agency FB"));
        font.setPointSize(12);
        textEdit->setFont(font);
        textEdit->setAutoFillBackground(true);
        textEdit->setStyleSheet(QString::fromUtf8("background:rgb(247,247,247);"));
        textEdit->setFrameShape(QFrame::NoFrame);
        textEdit->setFrameShadow(QFrame::Plain);
        textEdit->setReadOnly(false);

        horizontalLayout_10->addWidget(textEdit);


        verticalLayout_6->addWidget(groupBox_6);

        verticalLayout_6->setStretch(2, 20);

        verticalLayout_5->addLayout(verticalLayout_6);

        verticalLayout_7 = new QVBoxLayout();
        verticalLayout_7->setSpacing(0);
        verticalLayout_7->setObjectName(QString::fromUtf8("verticalLayout_7"));
        tabWidget_2 = new QTabWidget(centralWidget);
        tabWidget_2->setObjectName(QString::fromUtf8("tabWidget_2"));
        tabWidget_2->setEnabled(true);
        QPalette palette10;
        palette10.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Text, brush);
        palette10.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush34(QColor(58, 58, 58, 128));
        brush34.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Active, QPalette::PlaceholderText, brush34);
#endif
        palette10.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush35(QColor(58, 58, 58, 128));
        brush35.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush35);
#endif
        palette10.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette10.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette10.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush36(QColor(58, 58, 58, 128));
        brush36.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette10.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush36);
#endif
        tabWidget_2->setPalette(palette10);
        tabWidget_2->setStyleSheet(QString::fromUtf8("QTabBar::tab\n"
"{\n"
"font:13px;\n"
"color:white; \n"
"border:none;\n"
"background:rgb(51, 51, 51);\n"
"height:20px;\n"
"width:210px;\n"
"padding:0;\n"
"margin:0;\n"
"}\n"
"QTabBar::tab:selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}\n"
"QTabBar::tab:!selected\n"
"{\n"
"background:rgb(51, 51, 51);\n"
"}\n"
"QTabBar::tab:hover:!selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}\n"
"\n"
"QTabWidget::pane { /* The tab widget frame */  \n"
"   padding:-10px;\n"
"}  "));
        tabWidget_2->setTabShape(QTabWidget::Triangular);
        tabWidget_2->setElideMode(Qt::ElideLeft);
        tabWidget_2->setDocumentMode(false);
        tabWidget_2->setTabsClosable(false);
        tabWidget_2->setMovable(false);
        tabWidget_2->setTabBarAutoHide(true);
        tab_5 = new QWidget();
        tab_5->setObjectName(QString::fromUtf8("tab_5"));
        verticalLayout_4 = new QVBoxLayout(tab_5);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        plainTextEdit_2 = new QPlainTextEdit(tab_5);
        plainTextEdit_2->setObjectName(QString::fromUtf8("plainTextEdit_2"));
        QPalette palette11;
        QBrush brush37(QColor(255, 0, 0, 255));
        brush37.setStyle(Qt::SolidPattern);
        palette11.setBrush(QPalette::Active, QPalette::WindowText, brush37);
        palette11.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Text, brush37);
        palette11.setBrush(QPalette::Active, QPalette::ButtonText, brush37);
        palette11.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush38(QColor(255, 0, 0, 128));
        brush38.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Active, QPalette::PlaceholderText, brush38);
#endif
        palette11.setBrush(QPalette::Inactive, QPalette::WindowText, brush37);
        palette11.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Text, brush37);
        palette11.setBrush(QPalette::Inactive, QPalette::ButtonText, brush37);
        palette11.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush39(QColor(255, 0, 0, 128));
        brush39.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush39);
#endif
        palette11.setBrush(QPalette::Disabled, QPalette::WindowText, brush37);
        palette11.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Text, brush37);
        palette11.setBrush(QPalette::Disabled, QPalette::ButtonText, brush37);
        palette11.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette11.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush40(QColor(255, 0, 0, 128));
        brush40.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette11.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush40);
#endif
        plainTextEdit_2->setPalette(palette11);
        plainTextEdit_2->setStyleSheet(QString::fromUtf8("border:none;\n"
"color:rgb(255, 0, 0);\n"
"margin:0;\n"
"padding:0;"));
        plainTextEdit_2->setFrameShape(QFrame::NoFrame);
        plainTextEdit_2->setReadOnly(true);

        verticalLayout_4->addWidget(plainTextEdit_2);

        tabWidget_2->addTab(tab_5, QString());
        tab_6 = new QWidget();
        tab_6->setObjectName(QString::fromUtf8("tab_6"));
        gridLayout = new QGridLayout(tab_6);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        textBrowser_output = new QTextBrowser(tab_6);
        textBrowser_output->setObjectName(QString::fromUtf8("textBrowser_output"));
        QPalette palette12;
        palette12.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Text, brush);
        palette12.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush41(QColor(58, 58, 58, 128));
        brush41.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Active, QPalette::PlaceholderText, brush41);
#endif
        palette12.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush42(QColor(58, 58, 58, 128));
        brush42.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush42);
#endif
        palette12.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette12.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette12.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush43(QColor(58, 58, 58, 128));
        brush43.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette12.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush43);
#endif
        textBrowser_output->setPalette(palette12);
        textBrowser_output->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(textBrowser_output, 0, 0, 1, 1);

        tabWidget_2->addTab(tab_6, QString());

        verticalLayout_7->addWidget(tabWidget_2);


        verticalLayout_5->addLayout(verticalLayout_7);

        verticalLayout_5->setStretch(0, 4);

        verticalLayout_3->addLayout(verticalLayout_5);


        horizontalLayout->addLayout(verticalLayout_3);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(10, -1, -1, -1);
        verticalLayout_8 = new QVBoxLayout();
        verticalLayout_8->setSpacing(0);
        verticalLayout_8->setObjectName(QString::fromUtf8("verticalLayout_8"));
        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        pushButton_12 = new QPushButton(centralWidget);
        pushButton_12->setObjectName(QString::fromUtf8("pushButton_12"));
        QPalette palette13;
        palette13.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Button, brush8);
        palette13.setBrush(QPalette::Active, QPalette::Text, brush);
        palette13.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Active, QPalette::Base, brush8);
        palette13.setBrush(QPalette::Active, QPalette::Window, brush8);
        QBrush brush44(QColor(58, 58, 58, 128));
        brush44.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Active, QPalette::PlaceholderText, brush44);
#endif
        palette13.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Button, brush8);
        palette13.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Inactive, QPalette::Base, brush8);
        palette13.setBrush(QPalette::Inactive, QPalette::Window, brush8);
        QBrush brush45(QColor(58, 58, 58, 128));
        brush45.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush45);
#endif
        palette13.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Button, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette13.setBrush(QPalette::Disabled, QPalette::Base, brush8);
        palette13.setBrush(QPalette::Disabled, QPalette::Window, brush8);
        QBrush brush46(QColor(58, 58, 58, 128));
        brush46.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette13.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush46);
#endif
        pushButton_12->setPalette(palette13);
        pushButton_12->setStyleSheet(QString::fromUtf8("border:none;\n"
"background:rgb(51, 51, 51);\n"
"margin:0;\n"
"padding:1px;"));

        horizontalLayout_8->addWidget(pushButton_12);


        verticalLayout_8->addLayout(horizontalLayout_8);

        groupBox_4 = new QGroupBox(centralWidget);
        groupBox_4->setObjectName(QString::fromUtf8("groupBox_4"));
        verticalLayout_10 = new QVBoxLayout(groupBox_4);
        verticalLayout_10->setSpacing(0);
        verticalLayout_10->setContentsMargins(11, 11, 11, 11);
        verticalLayout_10->setObjectName(QString::fromUtf8("verticalLayout_10"));
        verticalLayout_10->setContentsMargins(0, 0, 0, 0);
        treeView_2 = new QTreeView(groupBox_4);
        treeView_2->setObjectName(QString::fromUtf8("treeView_2"));
        sizePolicy.setHeightForWidth(treeView_2->sizePolicy().hasHeightForWidth());
        treeView_2->setSizePolicy(sizePolicy);
        QPalette palette14;
        palette14.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Text, brush);
        palette14.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush47(QColor(58, 58, 58, 128));
        brush47.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Active, QPalette::PlaceholderText, brush47);
#endif
        palette14.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush48(QColor(58, 58, 58, 128));
        brush48.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush48);
#endif
        palette14.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette14.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette14.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush49(QColor(58, 58, 58, 128));
        brush49.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette14.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush49);
#endif
        treeView_2->setPalette(palette14);
        treeView_2->setFocusPolicy(Qt::NoFocus);
        treeView_2->setStyleSheet(QString::fromUtf8(""));
        treeView_2->setFrameShape(QFrame::NoFrame);
        treeView_2->setFrameShadow(QFrame::Plain);
        treeView_2->setHeaderHidden(true);
        treeView_2->header()->setVisible(false);
        treeView_2->header()->setStretchLastSection(true);

        verticalLayout_10->addWidget(treeView_2);


        verticalLayout_8->addWidget(groupBox_4);

        verticalLayout_8->setStretch(0, 1);
        verticalLayout_8->setStretch(1, 26);

        verticalLayout_2->addLayout(verticalLayout_8);


        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 5);
        horizontalLayout->setStretch(1, 20);
        horizontalLayout->setStretch(2, 4);

        verticalLayout_9->addLayout(horizontalLayout);

        verticalLayout_9->setStretch(1, 20);

        verticalLayout_12->addLayout(verticalLayout_9);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1049, 26));
        menu_file = new QMenu(menuBar);
        menu_file->setObjectName(QString::fromUtf8("menu_file"));
        QPalette palette15;
        palette15.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Text, brush);
        palette15.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush50(QColor(58, 58, 58, 128));
        brush50.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Active, QPalette::PlaceholderText, brush50);
#endif
        palette15.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush51(QColor(58, 58, 58, 128));
        brush51.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush51);
#endif
        palette15.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette15.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette15.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush52(QColor(58, 58, 58, 128));
        brush52.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette15.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush52);
#endif
        menu_file->setPalette(palette15);
        menu_view = new QMenu(menuBar);
        menu_view->setObjectName(QString::fromUtf8("menu_view"));
        menu_code = new QMenu(menuBar);
        menu_code->setObjectName(QString::fromUtf8("menu_code"));
        QPalette palette16;
        palette16.setBrush(QPalette::Active, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Text, brush);
        palette16.setBrush(QPalette::Active, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Active, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Active, QPalette::Window, brush1);
        QBrush brush53(QColor(58, 58, 58, 128));
        brush53.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Active, QPalette::PlaceholderText, brush53);
#endif
        palette16.setBrush(QPalette::Inactive, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Text, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Inactive, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Inactive, QPalette::Window, brush1);
        QBrush brush54(QColor(58, 58, 58, 128));
        brush54.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush54);
#endif
        palette16.setBrush(QPalette::Disabled, QPalette::WindowText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::Button, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Text, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::ButtonText, brush);
        palette16.setBrush(QPalette::Disabled, QPalette::Base, brush1);
        palette16.setBrush(QPalette::Disabled, QPalette::Window, brush1);
        QBrush brush55(QColor(58, 58, 58, 128));
        brush55.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette16.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush55);
#endif
        menu_code->setPalette(palette16);
        menu_tools = new QMenu(menuBar);
        menu_tools->setObjectName(QString::fromUtf8("menu_tools"));
        menu_help = new QMenu(menuBar);
        menu_help->setObjectName(QString::fromUtf8("menu_help"));
        MainWindow->setMenuBar(menuBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        statusBar->setAutoFillBackground(false);
        statusBar->setStyleSheet(QString::fromUtf8("background:rgb(0, 128, 255)"));
        MainWindow->setStatusBar(statusBar);
        toolBar = new QToolBar(MainWindow);
        toolBar->setObjectName(QString::fromUtf8("toolBar"));
        QSizePolicy sizePolicy1(QSizePolicy::Fixed, QSizePolicy::Preferred);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(toolBar->sizePolicy().hasHeightForWidth());
        toolBar->setSizePolicy(sizePolicy1);
        QPalette palette17;
        QBrush brush56(QColor(238, 238, 238, 255));
        brush56.setStyle(Qt::SolidPattern);
        palette17.setBrush(QPalette::Active, QPalette::WindowText, brush56);
        QBrush brush57(QColor(35, 35, 38, 255));
        brush57.setStyle(Qt::SolidPattern);
        palette17.setBrush(QPalette::Active, QPalette::Button, brush57);
        palette17.setBrush(QPalette::Active, QPalette::Text, brush56);
        palette17.setBrush(QPalette::Active, QPalette::ButtonText, brush56);
        palette17.setBrush(QPalette::Active, QPalette::Base, brush57);
        palette17.setBrush(QPalette::Active, QPalette::Window, brush57);
        QBrush brush58(QColor(238, 238, 238, 128));
        brush58.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Active, QPalette::PlaceholderText, brush58);
#endif
        palette17.setBrush(QPalette::Inactive, QPalette::WindowText, brush56);
        palette17.setBrush(QPalette::Inactive, QPalette::Button, brush57);
        palette17.setBrush(QPalette::Inactive, QPalette::Text, brush56);
        palette17.setBrush(QPalette::Inactive, QPalette::ButtonText, brush56);
        palette17.setBrush(QPalette::Inactive, QPalette::Base, brush57);
        palette17.setBrush(QPalette::Inactive, QPalette::Window, brush57);
        QBrush brush59(QColor(238, 238, 238, 128));
        brush59.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Inactive, QPalette::PlaceholderText, brush59);
#endif
        palette17.setBrush(QPalette::Disabled, QPalette::WindowText, brush56);
        palette17.setBrush(QPalette::Disabled, QPalette::Button, brush57);
        palette17.setBrush(QPalette::Disabled, QPalette::Text, brush56);
        palette17.setBrush(QPalette::Disabled, QPalette::ButtonText, brush56);
        palette17.setBrush(QPalette::Disabled, QPalette::Base, brush57);
        palette17.setBrush(QPalette::Disabled, QPalette::Window, brush57);
        QBrush brush60(QColor(238, 238, 238, 128));
        brush60.setStyle(Qt::NoBrush);
#if QT_VERSION >= QT_VERSION_CHECK(5, 12, 0)
        palette17.setBrush(QPalette::Disabled, QPalette::PlaceholderText, brush60);
#endif
        toolBar->setPalette(palette17);
        toolBar->setContextMenuPolicy(Qt::DefaultContextMenu);
        toolBar->setAcceptDrops(true);
        toolBar->setAutoFillBackground(false);
        toolBar->setStyleSheet(QString::fromUtf8("background:rgb(35, 35, 38);\n"
"color:#eee;\n"
"border: none\357\274\233"));
        toolBar->setMovable(true);
        toolBar->setAllowedAreas(Qt::AllToolBarAreas);
        toolBar->setIconSize(QSize(32, 32));
        toolBar->setToolButtonStyle(Qt::ToolButtonTextUnderIcon);
        toolBar->setFloatable(true);
        MainWindow->addToolBar(Qt::LeftToolBarArea, toolBar);

        menuBar->addAction(menu_file->menuAction());
        menuBar->addAction(menu_view->menuAction());
        menuBar->addAction(menu_code->menuAction());
        menuBar->addAction(menu_tools->menuAction());
        menuBar->addAction(menu_help->menuAction());
        menu_file->addAction(actionNewFile);
        menu_file->addAction(actionOpenFile);
        menu_file->addAction(actionOpenFolder);
        menu_file->addAction(actionSave);
        menu_file->addAction(actionSaveAll);
        menu_file->addAction(actionSetting);
        menu_file->addAction(actionExit_2);
        menu_view->addAction(actionFile);
        menu_view->addAction(actionEditor);
        menu_view->addAction(actionDebuger);
        menu_view->addAction(actionClass);
        menu_view->addAction(actionOutput);
        menu_view->addAction(actionStatus);
        menu_view->addAction(actionTopBar);
        menu_code->addAction(actionComplier);
        menu_code->addAction(actionRun);
        menu_code->addAction(actionDebug);
        menu_code->addAction(actionConfig);
        menu_code->addAction(actionStop);
        menu_tools->addAction(actionPackage);
        menu_help->addAction(actionAbout);
        toolBar->addSeparator();
        toolBar->addAction(actionNewFile);
        toolBar->addAction(actionSave);
        toolBar->addAction(actionSaveAll);
        toolBar->addSeparator();
        toolBar->addAction(actionComplier);
        toolBar->addAction(actionRun);
        toolBar->addAction(actionDebug);
        toolBar->addAction(actionStop);
        toolBar->addSeparator();

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(0);
        tabWidget_3->setCurrentIndex(0);
        tabWidget_2->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "IDE", nullptr));
        actionNew_Project->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
#ifndef QT_NO_SHORTCUT
        actionNew_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+N", nullptr));
#endif // QT_NO_SHORTCUT
        actionOpen_Project->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\351\241\271\347\233\256", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpen_Project->setShortcut(QApplication::translate("MainWindow", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("MainWindow", "Exit", nullptr));
        actionSetting->setText(QApplication::translate("MainWindow", "\350\256\276\347\275\256", nullptr));
        actionExit_2->setText(QApplication::translate("MainWindow", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit_2->setShortcut(QApplication::translate("MainWindow", "Meta+Ctrl+E", nullptr));
#endif // QT_NO_SHORTCUT
        actionFile->setText(QApplication::translate("MainWindow", "\350\247\243\345\206\263\346\226\271\346\241\210\350\247\206\345\233\276", nullptr));
        actionEditor->setText(QApplication::translate("MainWindow", "\347\274\226\350\276\221\345\231\250", nullptr));
        actionDebuger->setText(QApplication::translate("MainWindow", "\350\260\203\350\257\225\345\231\250", nullptr));
        actionConsole->setText(QApplication::translate("MainWindow", "\347\273\210\347\253\257", nullptr));
        actionClass->setText(QApplication::translate("MainWindow", "\347\261\273\350\247\206\345\233\276", nullptr));
        actionOutput->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272", nullptr));
        actionStatus->setText(QApplication::translate("MainWindow", "\347\212\266\346\200\201\346\240\217", nullptr));
        actionTopBar->setText(QApplication::translate("MainWindow", "\351\241\266\351\203\250\346\240\217", nullptr));
        actionComplier->setText(QApplication::translate("MainWindow", "\347\274\226\350\257\221", nullptr));
#ifndef QT_NO_SHORTCUT
        actionComplier->setShortcut(QApplication::translate("MainWindow", "F5", nullptr));
#endif // QT_NO_SHORTCUT
        actionRun->setText(QApplication::translate("MainWindow", "\350\277\220\350\241\214", nullptr));
#ifndef QT_NO_SHORTCUT
        actionRun->setShortcut(QApplication::translate("MainWindow", "Ctrl+R", nullptr));
#endif // QT_NO_SHORTCUT
        actionDebug->setText(QApplication::translate("MainWindow", "\350\260\203\350\257\225", nullptr));
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSave->setShortcut(QApplication::translate("MainWindow", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        actionSaveAll->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230\345\205\250\351\203\250", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSaveAll->setShortcut(QApplication::translate("MainWindow", "Ctrl+S, Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionConfig->setText(QApplication::translate("MainWindow", "\346\236\204\345\273\272\351\205\215\347\275\256", nullptr));
#ifndef QT_NO_SHORTCUT
        actionConfig->setShortcut(QApplication::translate("MainWindow", "Ctrl+C", nullptr));
#endif // QT_NO_SHORTCUT
        actionPackage->setText(QApplication::translate("MainWindow", "\345\214\205\347\256\241\347\220\206\345\231\250", nullptr));
#ifndef QT_NO_SHORTCUT
        actionPackage->setShortcut(QApplication::translate("MainWindow", "Alt+P", nullptr));
#endif // QT_NO_SHORTCUT
        actionAbout->setText(QApplication::translate("MainWindow", "\345\205\263\344\272\216", nullptr));
#ifndef QT_NO_SHORTCUT
        actionAbout->setShortcut(QApplication::translate("MainWindow", "Ctrl+A", nullptr));
#endif // QT_NO_SHORTCUT
        actionStop->setText(QApplication::translate("MainWindow", "\344\270\255\346\255\242", nullptr));
        actionOpenFile->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266", nullptr));
        actionNewFile->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", nullptr));
        actionSelf->setText(QApplication::translate("MainWindow", "NeroYang", nullptr));
        actionOpenFolder->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200\346\226\207\344\273\266\345\244\271", nullptr));
        projectName->setText(QApplication::translate("MainWindow", "\351\241\271\347\233\256\345\220\215", nullptr));
        groupBox_5->setTitle(QString());
        pushButton_3->setText(QString());
        pushButton_2->setText(QString());
        pushButton->setText(QString());
        groupBox->setTitle(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("MainWindow", "\346\240\207\347\255\276", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("MainWindow", "\346\217\220\347\244\272", nullptr));
        lineEdit->setPlaceholderText(QApplication::translate("MainWindow", "\346\267\273\345\212\240Task", nullptr));
        pushButton_4->setText(QString());
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_3), QApplication::translate("MainWindow", "\346\234\252\345\274\200\345\247\213", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_8), QApplication::translate("MainWindow", "\345\267\245\344\275\234\344\270\255", nullptr));
        tabWidget_3->setTabText(tabWidget_3->indexOf(tab_4), QApplication::translate("MainWindow", "\345\267\262\345\256\214\346\210\220", nullptr));
        groupBox_6->setTitle(QString());
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Agency FB'; font-size:12pt; font-weight:400; font-style:normal;\">\n"
"<p style=\" margin-top:12px; margin-bottom:12px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><span style=\" font-family:'.SF NS Text'; font-size:24pt; font-weight:600;\">\346\254\242\350\277\216\344\275\277\347\224\250IDE</span><span style=\" font-family:'.SF NS Text'; font-size:13pt;\"><br /><br /></span></p></body></html>", nullptr));
        plainTextEdit_2->setDocumentTitle(QString());
        plainTextEdit_2->setPlainText(QString());
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_5), QApplication::translate("MainWindow", "\350\260\203\350\257\225", nullptr));
        tabWidget_2->setTabText(tabWidget_2->indexOf(tab_6), QApplication::translate("MainWindow", "\350\276\223\345\207\272", nullptr));
        pushButton_12->setText(QApplication::translate("MainWindow", "\347\261\273\350\247\206\345\233\276", nullptr));
        groupBox_4->setTitle(QString());
        menu_file->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266", nullptr));
        menu_view->setTitle(QApplication::translate("MainWindow", "\350\247\206\345\233\276", nullptr));
        menu_code->setTitle(QApplication::translate("MainWindow", "\350\260\203\350\257\225", nullptr));
        menu_tools->setTitle(QApplication::translate("MainWindow", "\345\267\245\345\205\267", nullptr));
        menu_help->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251", nullptr));
        toolBar->setWindowTitle(QApplication::translate("MainWindow", "toolBar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
