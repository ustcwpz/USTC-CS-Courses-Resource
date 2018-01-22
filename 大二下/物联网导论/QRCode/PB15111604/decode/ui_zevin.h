/********************************************************************************
** Form generated from reading UI file 'zevin.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ZEVIN_H
#define UI_ZEVIN_H

#include <QtCore/QLocale>
#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_zevin
{
public:
    QGroupBox *groupBox;
    QLabel *label_2;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QLabel *label_4;
    QLineEdit *lineEdit_2;
    QLineEdit *lineEdit;
    QGroupBox *groupBox_2;
    QTextBrowser *textBrowser;

    void setupUi(QWidget *zevin)
    {
        if (zevin->objectName().isEmpty())
            zevin->setObjectName(QStringLiteral("zevin"));
        zevin->resize(837, 445);
        QIcon icon;
        icon.addFile(QStringLiteral("C:/Users/zevin/Desktop/QKJEYKFQZY}{@VHETCMKH`M.png"), QSize(), QIcon::Normal, QIcon::Off);
        zevin->setWindowIcon(icon);
        zevin->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        groupBox = new QGroupBox(zevin);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(20, 10, 801, 291));
        groupBox->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 221, 51));
        label_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        pushButton = new QPushButton(groupBox);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(560, 180, 161, 41));
        pushButton->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        pushButton_2 = new QPushButton(groupBox);
        pushButton_2->setObjectName(QStringLiteral("pushButton_2"));
        pushButton_2->setGeometry(QRect(560, 40, 161, 41));
        pushButton_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 180, 111, 16));
        label_4->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        lineEdit_2 = new QLineEdit(groupBox);
        lineEdit_2->setObjectName(QStringLiteral("lineEdit_2"));
        lineEdit_2->setGeometry(QRect(140, 170, 331, 71));
        lineEdit_2->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        lineEdit_2->setDragEnabled(true);
        lineEdit = new QLineEdit(groupBox);
        lineEdit->setObjectName(QStringLiteral("lineEdit"));
        lineEdit->setGeometry(QRect(140, 30, 331, 71));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(9);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(lineEdit->sizePolicy().hasHeightForWidth());
        lineEdit->setSizePolicy(sizePolicy);
        lineEdit->setAutoFillBackground(true);
        lineEdit->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        lineEdit->setDragEnabled(true);
        groupBox_2 = new QGroupBox(zevin);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        groupBox_2->setGeometry(QRect(20, 300, 801, 111));
        textBrowser = new QTextBrowser(groupBox_2);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(140, 20, 331, 71));
        textBrowser->setLocale(QLocale(QLocale::Chinese, QLocale::China));
        textBrowser->raise();
        pushButton->raise();
        lineEdit_2->raise();
        label_4->raise();
        pushButton->raise();
        lineEdit_2->raise();
        label_4->raise();
        groupBox_2->raise();
        groupBox->raise();

        retranslateUi(zevin);

        QMetaObject::connectSlotsByName(zevin);
    } // setupUi

    void retranslateUi(QWidget *zevin)
    {
        zevin->setWindowTitle(QApplication::translate("zevin", "\351\207\221\346\263\275\346\226\207_decode", Q_NULLPTR));
        groupBox->setTitle(QApplication::translate("zevin", "Decode", Q_NULLPTR));
        label_2->setText(QApplication::translate("zevin", "http link: \n"
"or drag the \n"
"picture here:", Q_NULLPTR));
        pushButton->setText(QApplication::translate("zevin", "Decode_local_file", Q_NULLPTR));
        pushButton_2->setText(QApplication::translate("zevin", "Decode_network", Q_NULLPTR));
        label_4->setText(QApplication::translate("zevin", "local path:", Q_NULLPTR));
        lineEdit_2->setText(QApplication::translate("zevin", "./QRCode.bmp", Q_NULLPTR));
        lineEdit->setText(QApplication::translate("zevin", "http://img3.epanshi.com/7526/upload/%E4%B8%AD%E5%8D%97%E5%B9%95%E5%A2%99%E4%BA%8C%E7%BB%B4%E7%A0%81.png", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("zevin", "Output", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class zevin: public Ui_zevin {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ZEVIN_H
