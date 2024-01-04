/********************************************************************************
** Form generated from reading UI file 'newprojectwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_NEWPROJECTWINDOW_H
#define UI_NEWPROJECTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QTreeView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_NewProjectWindow
{
public:
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout_6;
    QTreeView *treeView_model;
    QWidget *tab_2;
    QVBoxLayout *verticalLayout_3;
    QGroupBox *project_define;
    QGridLayout *gridLayout;
    QTextBrowser *model_desc;
    QGroupBox *groupBox_3;
    QVBoxLayout *verticalLayout_5;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label;
    QLineEdit *lineEdit_ProjectName;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *lineEdit_path;
    QPushButton *pushButton;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QDialog *NewProjectWindow)
    {
        if (NewProjectWindow->objectName().isEmpty())
            NewProjectWindow->setObjectName(QString::fromUtf8("NewProjectWindow"));
        NewProjectWindow->resize(490, 367);
        NewProjectWindow->setStyleSheet(QString::fromUtf8("background:rgb(45,44,48);\n"
"color:rgb(255,255,255);"));
        horizontalLayout = new QHBoxLayout(NewProjectWindow);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        tabWidget = new QTabWidget(NewProjectWindow);
        tabWidget->setObjectName(QString::fromUtf8("tabWidget"));
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
"}"));
        tab = new QWidget();
        tab->setObjectName(QString::fromUtf8("tab"));
        verticalLayout_6 = new QVBoxLayout(tab);
        verticalLayout_6->setObjectName(QString::fromUtf8("verticalLayout_6"));
        treeView_model = new QTreeView(tab);
        treeView_model->setObjectName(QString::fromUtf8("treeView_model"));
        treeView_model->setFocusPolicy(Qt::NoFocus);
        treeView_model->setFrameShape(QFrame::NoFrame);
        treeView_model->setIndentation(0);
        treeView_model->setHeaderHidden(true);
        treeView_model->header()->setVisible(false);
        treeView_model->header()->setCascadingSectionResizes(true);
        treeView_model->header()->setHighlightSections(true);
        treeView_model->header()->setProperty("showSortIndicator", QVariant(true));

        verticalLayout_6->addWidget(treeView_model);

        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QString::fromUtf8("tab_2"));
        tabWidget->addTab(tab_2, QString());

        verticalLayout->addWidget(tabWidget);


        horizontalLayout_2->addLayout(verticalLayout);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        project_define = new QGroupBox(NewProjectWindow);
        project_define->setObjectName(QString::fromUtf8("project_define"));
        gridLayout = new QGridLayout(project_define);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        model_desc = new QTextBrowser(project_define);
        model_desc->setObjectName(QString::fromUtf8("model_desc"));
        model_desc->setFrameShape(QFrame::NoFrame);

        gridLayout->addWidget(model_desc, 0, 0, 1, 1);


        verticalLayout_3->addWidget(project_define);

        groupBox_3 = new QGroupBox(NewProjectWindow);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        verticalLayout_5 = new QVBoxLayout(groupBox_3);
        verticalLayout_5->setObjectName(QString::fromUtf8("verticalLayout_5"));
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        label = new QLabel(groupBox_3);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_4->addWidget(label);

        lineEdit_ProjectName = new QLineEdit(groupBox_3);
        lineEdit_ProjectName->setObjectName(QString::fromUtf8("lineEdit_ProjectName"));

        horizontalLayout_4->addWidget(lineEdit_ProjectName);


        verticalLayout_5->addLayout(horizontalLayout_4);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        label_2 = new QLabel(groupBox_3);
        label_2->setObjectName(QString::fromUtf8("label_2"));

        horizontalLayout_3->addWidget(label_2);

        lineEdit_path = new QLineEdit(groupBox_3);
        lineEdit_path->setObjectName(QString::fromUtf8("lineEdit_path"));
        lineEdit_path->setAutoFillBackground(false);

        horizontalLayout_3->addWidget(lineEdit_path);

        pushButton = new QPushButton(groupBox_3);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font:13px;\n"
"color:white; \n"
"border:none;\n"
"background:rgb(51, 51, 51);\n"
"height:20px;\n"
"width:75px;\n"
"}\n"
"QPushButton:selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}\n"
"QPushButton:!selected\n"
"{\n"
"background:rgb(51, 51, 51);\n"
"}\n"
"QPushButton:hover:!selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}"));

        horizontalLayout_3->addWidget(pushButton);


        verticalLayout_5->addLayout(horizontalLayout_3);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        pushButton_2 = new QPushButton(groupBox_3);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font:13px;\n"
"color:white; \n"
"border:none;\n"
"background:rgb(51, 51, 51);\n"
"height:20px;\n"
"width:75px;\n"
"}\n"
"QPushButton:selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}\n"
"QPushButton:!selected\n"
"{\n"
"background:rgb(51, 51, 51);\n"
"}\n"
"QPushButton:hover:!selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}"));

        horizontalLayout_5->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(groupBox_3);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton\n"
"{\n"
"font:13px;\n"
"color:white; \n"
"border:none;\n"
"background:rgb(51, 51, 51);\n"
"height:20px;\n"
"width:75px;\n"
"}\n"
"QPushButton:selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}\n"
"QPushButton:!selected\n"
"{\n"
"background:rgb(51, 51, 51);\n"
"}\n"
"QPushButton:hover:!selected\n"
"{\n"
"background:rgb(35, 35, 38);\n"
"}"));

        horizontalLayout_5->addWidget(pushButton_3);


        verticalLayout_5->addLayout(horizontalLayout_5);


        verticalLayout_3->addWidget(groupBox_3);

        verticalLayout_3->setStretch(0, 6);
        verticalLayout_3->setStretch(1, 4);

        horizontalLayout_2->addLayout(verticalLayout_3);

        horizontalLayout_2->setStretch(0, 4);
        horizontalLayout_2->setStretch(1, 6);

        horizontalLayout->addLayout(horizontalLayout_2);


        retranslateUi(NewProjectWindow);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(NewProjectWindow);
    } // setupUi

    void retranslateUi(QDialog *NewProjectWindow)
    {
        NewProjectWindow->setWindowTitle(QApplication::translate("NewProjectWindow", "\346\226\260\345\273\272\351\241\271\347\233\256", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("NewProjectWindow", "\346\234\254\345\234\260\346\250\241\347\211\210", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("NewProjectWindow", "\345\234\250\347\272\277\346\250\241\347\211\210", nullptr));
        project_define->setTitle(QApplication::translate("NewProjectWindow", "\345\256\232\344\271\211", nullptr));
        groupBox_3->setTitle(QApplication::translate("NewProjectWindow", "\351\241\271\347\233\256", nullptr));
        label->setText(QApplication::translate("NewProjectWindow", "\351\241\271\347\233\256:", nullptr));
        label_2->setText(QApplication::translate("NewProjectWindow", "\350\267\257\345\276\204\357\274\232", nullptr));
        pushButton->setText(QApplication::translate("NewProjectWindow", "\346\265\217\350\247\210", nullptr));
        pushButton_2->setText(QApplication::translate("NewProjectWindow", "\345\217\226\346\266\210", nullptr));
        pushButton_3->setText(QApplication::translate("NewProjectWindow", "\345\210\233\345\273\272", nullptr));
    } // retranslateUi

};

namespace Ui {
    class NewProjectWindow: public Ui_NewProjectWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_NEWPROJECTWINDOW_H
