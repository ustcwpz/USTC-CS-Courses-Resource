#include "zevin.h"
#include "ui_zevin.h"
#include <QMessageBox>
#include <QDebug>
#include "QZXing/QZXing.h"
#include "downloader.h"


zevin::zevin(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::zevin)
{
    ui->setupUi(this);
    connect(ui->lineEdit, SIGNAL(textEdited(QString)), this, SLOT(printText(QString)));
    connect(ui->lineEdit_2, SIGNAL(textEdited(QString)), this, SLOT(printText(QString)));
    connect(this, SIGNAL(output(QString)), ui->textBrowser, SLOT(setText(QString)));
    connect(this, SIGNAL(close()), this, SLOT(exit()));
    link_local = "./QRCode.bmp";
    link_network = "http://img3.epanshi.com/7526/upload/%E4%B8%AD%E5%8D%97%E5%B9%95%E5%A2%99%E4%BA%8C%E7%BB%B4%E7%A0%81.png";

}

zevin::~zevin()
{
    delete ui;
}

void zevin::printText(const QString& text)
{
    link_network = text;
    link_local = text;
}

void zevin::on_pushButton_clicked()
{
    QImage img;
    bool flag = img.load(link_local);
    qDebug()<<img.width()<<img.height();
    QZXing zxing;
    QString str = zxing.decodeImage(img);
    qDebug()<<str;
    emit output(str);
    if(flag == true)
        QMessageBox::information(this,tr(" "),tr("完成！"));
    else
        QMessageBox::information(this,tr(" "),tr("错误！"));
}

void zevin::on_pushButton_2_clicked()
{
    QImage img;
    downloadURL(
            link_network,
            "./networka");
    bool flag = img.load("./networka");
    remove("./networka");
    qDebug()<<img.width()<<img.height();
    QZXing zxing;
    QString str = zxing.decodeImage(img);
    qDebug()<<str;
    emit output(str);
    if(flag == true)
        QMessageBox::information(this,tr(" "),tr("完成！"));
    else
        QMessageBox::information(this,tr(" "),tr("错误！"));
}

void zevin::closeEvent(QCloseEvent *event)
{
    QMessageBox::information(this,tr(" "),tr("真的要退出吗！\n金泽文这么萌，要不要给他一个A呢！"));
    QMessageBox::information(this,tr(" "),tr("司虎老师么么哒！"));
}
