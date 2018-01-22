/*
 * Copyright 2011 QZXing authors
 *
 * Licensed under the Apache License, Version 2.0 (the "License");
 * you may not use this file except in compliance with the License.
 * You may obtain a copy of the License at
 *
 *      http://www.apache.org/licenses/LICENSE-2.0
 *
 * Unless required by applicable law or agreed to in writing, software
 * distributed under the License is distributed on an "AS IS" BASIS,
 * WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
 * See the License for the specific language governing permissions and
 * limitations under the License.
 */

#ifndef QZXINGIMAGEPROVIDER_H
#define QZXINGIMAGEPROVIDER_H

#include <QObject>
#include <QQuickImageProvider>
#include <QImage>

class QZXingImageProvider : public QQuickImageProvider
{
private:
    QPixmap storedPixmap;
    static QZXingImageProvider *singletonInstance_ptr_;
protected:
    QZXingImageProvider();
public:
    QPixmap requestPixmap(const QString &id, QSize *size, const QSize &requestedSize);
    void storeImage(const QImage& providedImage);

    static QZXingImageProvider* getInstance();
};

#endif // QZXINGIMAGEPROVIDER_H
