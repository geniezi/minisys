/********************************************************************************
** Form generated from reading UI file 'settingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.12.10
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGWINDOW_H
#define UI_SETTINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QListView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_SettingWindow
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QLineEdit *lineEdit;
    QListView *listView;
    QVBoxLayout *verticalLayout_4;
    QGroupBox *groupBox;
    QHBoxLayout *horizontalLayout_2;
    QPushButton *setting_apply;
    QSpacerItem *horizontalSpacer;
    QPushButton *setting_ok;
    QPushButton *setting_cancel;

    void setupUi(QDialog *SettingWindow)
    {
        if (SettingWindow->objectName().isEmpty())
            SettingWindow->setObjectName(QString::fromUtf8("SettingWindow"));
        SettingWindow->resize(604, 414);
        SettingWindow->setStyleSheet(QString::fromUtf8("background:rgb(45, 44, 48);\n"
"color:rgb(255, 255, 255);\n"
"margin:0;\n"
"padding:0;\n"
"Spacing:0;"));
        verticalLayout_3 = new QVBoxLayout(SettingWindow);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        lineEdit = new QLineEdit(SettingWindow);
        lineEdit->setObjectName(QString::fromUtf8("lineEdit"));

        verticalLayout->addWidget(lineEdit);

        listView = new QListView(SettingWindow);
        listView->setObjectName(QString::fromUtf8("listView"));

        verticalLayout->addWidget(listView);


        horizontalLayout->addLayout(verticalLayout);

        verticalLayout_4 = new QVBoxLayout();
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        groupBox = new QGroupBox(SettingWindow);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));

        verticalLayout_4->addWidget(groupBox);


        horizontalLayout->addLayout(verticalLayout_4);

        horizontalLayout->setStretch(0, 1);
        horizontalLayout->setStretch(1, 2);

        verticalLayout_3->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        setting_apply = new QPushButton(SettingWindow);
        setting_apply->setObjectName(QString::fromUtf8("setting_apply"));
        setting_apply->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_2->addWidget(setting_apply);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);

        setting_ok = new QPushButton(SettingWindow);
        setting_ok->setObjectName(QString::fromUtf8("setting_ok"));
        setting_ok->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_2->addWidget(setting_ok);

        setting_cancel = new QPushButton(SettingWindow);
        setting_cancel->setObjectName(QString::fromUtf8("setting_cancel"));
        setting_cancel->setStyleSheet(QString::fromUtf8("QPushButton\n"
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

        horizontalLayout_2->addWidget(setting_cancel);


        verticalLayout_3->addLayout(horizontalLayout_2);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 1);

        retranslateUi(SettingWindow);

        QMetaObject::connectSlotsByName(SettingWindow);
    } // setupUi

    void retranslateUi(QDialog *SettingWindow)
    {
        SettingWindow->setWindowTitle(QApplication::translate("SettingWindow", "\350\256\276\347\275\256", nullptr));
        groupBox->setTitle(QApplication::translate("SettingWindow", "\350\256\276\347\275\256", nullptr));
        setting_apply->setText(QApplication::translate("SettingWindow", "Apply", nullptr));
        setting_ok->setText(QApplication::translate("SettingWindow", "OK", nullptr));
        setting_cancel->setText(QApplication::translate("SettingWindow", "Cancel", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SettingWindow: public Ui_SettingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGWINDOW_H
