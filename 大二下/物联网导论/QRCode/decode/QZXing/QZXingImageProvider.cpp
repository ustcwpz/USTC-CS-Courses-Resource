#include "QZXingImageProvider.h"

QZXingImageProvider *QZXingImageProvider::singletonInstance_ptr_ = NULL;

QZXingImageProvider::QZXingImageProvider() : QQuickImageProvider(QQuickImageProvider::Pixmap)
{
}

QPixmap QZXingImageProvider::requestPixmap(const QString &id, QSize *size, const QSize &requestedSize)
{
    if(id == "latestEncoded")
        return storedPixmap;
    else
        return QPixmap();
}

void QZXingImageProvider::storeImage(const QImage &providedImage)
{
    storedPixmap = QPixmap::fromImage(providedImage);
}

QZXingImageProvider *QZXingImageProvider::getInstance()
{
    if(!singletonInstance_ptr_)
        singletonInstance_ptr_ = new QZXingImageProvider();

    return singletonInstance_ptr_;
}
