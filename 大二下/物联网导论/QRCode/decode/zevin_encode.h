#ifndef ZEVIN_ENCODE_H
#define ZEVIN_ENCODE_H

#include <QMainWindow>
#include "QRController.h"

namespace Ui {
class zevin_encode;
}

class zevin_encode : public QMainWindow
{
    Q_OBJECT

public:
    explicit zevin_encode(QWidget *parent = 0);
    ~zevin_encode();

private slots:
    void on_generateButton_pressed();

    void on_saveFileButton_pressed();

private:
    Ui::zevin_encode *ui;
};

#endif // ZEVIN_ENCODE_H
