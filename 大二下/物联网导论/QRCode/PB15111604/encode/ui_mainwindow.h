/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox_3;
    QLineEdit *lineEdit;
    QPushButton *generateButton;
    QGroupBox *groupBox_2;
    QPushButton *saveFileButton;
    QLabel *label;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_encode;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(837, 445);
        QIcon icon;
        icon.addFile(QStringLiteral("C:/Users/zevin/Desktop/QKJEYKFQZY}{@VHETCMKH`M.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(20, 10, 801, 111));
        groupBox_3->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        lineEdit = new QLineEdit(groupBox_3);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 20, 331, 71));
        lineEdit->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        generateButton = new QPushButton(groupBox_3);
        generateButton->setObjectName(QStringLiteral("generateButton"));
        generateButton->setGeometry(QRect(560, 40, 161, 41));
        generateButton->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 120, 801, 271));
        groupBox_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        saveFileButton = new QPushButton(groupBox_2);
        saveFileButton->setObjectName(QStringLiteral("saveFileButton"));
        saveFileButton->setGeometry(QRect(560, 110, 161, 41));
        saveFileButton->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        label = new QLabel(groupBox_2);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(180, 20, 251, 231));
        label->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        label->setFrameShape(QFrame::StyledPanel);
        label->setFrameShadow(QFrame::Sunken);
        label->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralWidget);
        groupBox_2->raise();
        groupBox_3->raise();
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 837, 23));
        menu_encode = new QMenu(menuBar);
        menu_encode->setObjectName(QStringLiteral("menu_encode"));
        MainWindow->setMenuBar(menuBar);

        menuBar->addAction(menu_encode->menuAction());

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\351\207\221\346\263\275\346\226\207_encode", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("MainWindow", "Encode", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("MainWindow", "HSI is the best teacher!", Q_NULLPTR));
        generateButton->setText(QApplication::translate("MainWindow", "Encode", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("MainWindow", "Output", Q_NULLPTR));
        saveFileButton->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        menu_encode->setTitle(QString());
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
