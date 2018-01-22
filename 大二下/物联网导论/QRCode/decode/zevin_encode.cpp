#include "zevin_encode.h"
#include "ui_zevin_encode.h"

zevin_encode::zevin_encode(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::zevin_encode)
{
    ui->setupUi(this);
}

zevin_encode::~zevin_encode()
{
    delete ui;
}

void zevin_encode::on_generateButton_pressed()
{
    QByteArray tempstring = ui->lineEdit->text().toLatin1().constData();
    //qDebug("InputString : %s", tempstring.constData());

    QRController* controller = new QRController(tempstring.constData(), eclMedium, 250, 250, evAuto);

    vector<char> tempBitmapArray;
    controller->SaveToByteArray(tempBitmapArray);
    QByteArray tempQArray(tempBitmapArray.data(), tempBitmapArray.size());

    QPixmap QRCodeBitmap;
    bool loadresult = false;
    loadresult = QRCodeBitmap.loadFromData(tempQArray, "BMP");

    if (true == loadresult){
        //qDebug("QRCodeImage Load Complete.");

        ui->label->setPixmap(QRCodeBitmap);
    }
    else{
        //qDebug("QRCodeImage Load Failed!!!");
    }

    delete controller;
}

void zevin_encode::on_saveFileButton_pressed()
{
    QByteArray tempstring = ui->lineEdit->text().toLatin1().constData();

    QRController* controller = new QRController(tempstring.constData(), eclMedium, 250, 250, evAuto);

    vector<char> tempBitmapArray;
    controller->SaveToByteArray(tempBitmapArray);
    QByteArray tempQArray(tempBitmapArray.data(), tempBitmapArray.size());

    QPixmap QRCodeBitmap;
    bool loadresult = false;
    loadresult = QRCodeBitmap.loadFromData(tempQArray, "BMP");

    if (true == loadresult){
        //qDebug("QRCodeImage Load Complete.");

        ui->label->setPixmap(QRCodeBitmap);

        QString imageType = ui->comboBox->currentText();

        QString filetypeStr;
        if (imageType == QString("BMP")){
            filetypeStr = QString(".bmp");
        }
        else if (imageType == QString("JPG")){
            filetypeStr = QString(".jpg");
        }
        else if (imageType == QString("PNG")){
            filetypeStr = QString(".png");
        }
        else{
            filetypeStr = QString(".bmp");
        }

        QString savefileName = QString("QRCode") + filetypeStr;
        QRCodeBitmap.save(savefileName);
    }
    else{
        //qDebug("QRCodeImage Load Failed!!!");
    }

    delete controller;
}
