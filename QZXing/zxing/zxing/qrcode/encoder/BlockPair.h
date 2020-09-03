#ifndef BLOCKPAIR_H
#define BLOCKPAIR_H

#include <vector>
#include <zxing/common/Array.h>
#include <zxing/common/Types.h>

using namespace std;

namespace zxing {
namespace qrcode {

class BlockPair
{
private:
    ArrayRef<zxing::byte> data_;
    ArrayRef<zxing::byte> errorCorrection_;

public:
    BlockPair(ArrayRef<zxing::byte> data, ArrayRef<zxing::byte> errorCorrection) :
      data_(data), errorCorrection_(errorCorrection)  {}

    BlockPair(const BlockPair& other) : data_(other.data_), errorCorrection_(other.errorCorrection_) {}

    ArrayRef<zxing::byte> getDataBytes() { return data_; }

    ArrayRef<zxing::byte> getErrorCorrectionBytes() { return errorCorrection_; }

    BlockPair& operator=(const BlockPair &other) {
        data_->release();
        errorCorrection_->release();

        data_ = other.data_;
        errorCorrection_ = other.errorCorrection_;

        return *this;
    }
};

}
}

#endif //BLOCKPAIR_H
