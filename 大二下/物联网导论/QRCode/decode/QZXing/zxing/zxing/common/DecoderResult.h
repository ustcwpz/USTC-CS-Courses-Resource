#ifndef __DECODER_RESULT_H__
#define __DECODER_RESULT_H__

/*
 *  DecoderResult.h
 *  zxing
 *
 *  Copyright 2010 ZXing authors All rights reserved.
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

#include <zxing/common/Counted.h>
#include <zxing/common/Array.h>
#include <string>
#include <zxing/common/Str.h>
#include <zxing/common/Types.h>

namespace zxing {

class DecoderResult : public Counted {
private:
  ArrayRef<byte> rawBytes_;
  Ref<String> text_;
  ArrayRef< ArrayRef<byte> > byteSegments_;
  std::string ecLevel_;
  std::string charSet_;

public:
  DecoderResult(ArrayRef<byte> rawBytes,
                Ref<String> text,
                ArrayRef< ArrayRef<byte> >& byteSegments,
                std::string const& ecLevel,
                std::string charSet = "");

  DecoderResult(ArrayRef<byte> rawBytes, Ref<String> text);

  ArrayRef<byte> getRawBytes();
  Ref<String> getText();
  std::string charSet();
};

}

#endif // __DECODER_RESULT_H__
