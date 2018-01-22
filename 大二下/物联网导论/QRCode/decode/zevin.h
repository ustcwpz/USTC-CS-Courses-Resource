#ifndef ZEVIN_H
#define ZEVIN_H

#include <QWidget>
#include <QCloseEvent>

namespace Ui {
class zevin;
}

class zevin : public QWidget
{
    Q_OBJECT

public:
    explicit zevin(QWidget *parent = 0);
    ~zevin();
signals:
    void output(QString text);

public slots:
    void printText(const QString& text);

private slots:
    void on_pushButton_clicked();
    void on_pushButton_2_clicked();

    void closeEvent(QCloseEvent *event);

private:
    Ui::zevin *ui;
    QString link_local;
    QString link_network;
};

#endif // ZEVIN_H
