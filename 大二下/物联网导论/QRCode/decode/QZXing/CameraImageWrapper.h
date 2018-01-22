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

#ifndef CAMERAIMAGE_H
#define CAMERAIMAGE_H

#include <QImage>
#include <QString>
#include <zxing/zxing/common/GreyscaleLuminanceSource.h>

using namespace zxing;

class CameraImageWrapper : public LuminanceSource
{
public:
    CameraImageWrapper();
    CameraImageWrapper(const QImage& sourceImage);
    CameraImageWrapper(CameraImageWrapper& otherInstance);
    ~CameraImageWrapper();

    static CameraImageWrapper* Factory(const QImage& image, int maxWidth=-1, int maxHeight=-1, bool smoothTransformation=false);
    
    ArrayRef<ArrayRef<byte> > getOriginalImage();
    Ref<GreyscaleLuminanceSource> getDelegate() { return delegate; }

    ArrayRef<zxing::byte> getRow(int y, ArrayRef<zxing::byte> row) const;
    ArrayRef<zxing::byte> getMatrix() const;

    bool isCropSupported() const;
    Ref<LuminanceSource> crop(int left, int top, int width, int height) const;
    bool isRotateSupported() const;
    Ref<LuminanceSource> invert() const;
    Ref<LuminanceSource> rotateCounterClockwise() const;

    inline byte gray(unsigned int r, unsigned int g, unsigned int b);
  
private:
    ArrayRef<zxing::byte> getRowP(int y, ArrayRef<zxing::byte> row) const;
    ArrayRef<zxing::byte> getMatrixP() const;
    void updateImageAsGrayscale(const QImage &origin);

    Ref<GreyscaleLuminanceSource> delegate;
    ArrayRef<ArrayRef<byte>> imageBytesPerRow;
    ArrayRef<byte> imageBytes;

    static const byte B_TO_GREYSCALE[256];
    static const byte G_TO_GREYSCALE[256];
    static const byte R_TO_GREYSCALE[256];
};

#endif //CAMERAIMAGE_H
