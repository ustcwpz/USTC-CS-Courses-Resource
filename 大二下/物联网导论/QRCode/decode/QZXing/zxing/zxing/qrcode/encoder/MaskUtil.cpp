#include "MaskUtil.h"
#include <zxing/common/IllegalArgumentException.h>
#include <stdlib.h>

namespace zxing {
namespace qrcode {

// Penalty weights from section 6.8.2.1
const int MaskUtil::N1 = 3;
const int MaskUtil::N2 = 3;
const int MaskUtil::N3 = 40;
const int MaskUtil::N4 = 10;

/**
   * Apply mask penalty rule 1 and return the penalty. Find repetitive cells with the same color and
   * give penalty to them. Example: 00000 or 11111.
   */
int MaskUtil::applyMaskPenaltyRule1(const ByteMatrix& matrix)
{
    return applyMaskPenaltyRule1Internal(matrix, true) + applyMaskPenaltyRule1Internal(matrix, false);
}

/**
   * Apply mask penalty rule 2 and return the penalty. Find 2x2 blocks with the same color and give
   * penalty to them. This is actually equivalent to the spec's rule, which is to find MxN blocks and give a
   * penalty proportional to (M-1)x(N-1), because this is the number of 2x2 blocks inside such a block.
   */
int MaskUtil::applyMaskPenaltyRule2(const ByteMatrix& matrix)
{
    int penalty = 0;
    const std::vector<std::vector<byte> >& array = matrix.getArray();
    int width = matrix.getWidth();
    int height = matrix.getHeight();
    for (int y = 0; y < height - 1; y++) {
        for (int x = 0; x < width - 1; x++) {
            int value = array[y][x];
            if (value == array[y][x + 1] && value == array[y + 1][x] && value == array[y + 1][x + 1]) {
                penalty++;
            }
        }
    }
    return N2 * penalty;
}

/**
   * Apply mask penalty rule 3 and return the penalty. Find consecutive runs of 1:1:3:1:1:4
   * starting with black, or 4:1:1:3:1:1 starting with white, and give penalty to them.  If we
   * find patterns like 000010111010000, we give penalty once.
   */
int MaskUtil::applyMaskPenaltyRule3(const ByteMatrix& matrix)
{
    int numPenalties = 0;
    const std::vector<std::vector<byte> >& array = matrix.getArray();
    int width = matrix.getWidth();
    int height = matrix.getHeight();
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            const std::vector<byte>& arrayY = array[y];  // We can at least optimize this access
            if (x + 6 < width &&
                    arrayY[x] == 1 &&
                    arrayY[x +  1] == 0 &&
                    arrayY[x +  2] == 1 &&
                    arrayY[x +  3] == 1 &&
                    arrayY[x +  4] == 1 &&
                    arrayY[x +  5] == 0 &&
                    arrayY[x +  6] == 1 &&
                    (isWhiteHorizontal(arrayY, x - 4, x) || isWhiteHorizontal(arrayY, x + 7, x + 11))) {
                numPenalties++;
            }
            if (y + 6 < height &&
                    array[y][x] == 1  &&
                    array[y +  1][x] == 0  &&
                    array[y +  2][x] == 1  &&
                    array[y +  3][x] == 1  &&
                    array[y +  4][x] == 1  &&
                    array[y +  5][x] == 0  &&
                    array[y +  6][x] == 1 &&
                    (isWhiteVertical(array, x, y - 4, y) || isWhiteVertical(array, x, y + 7, y + 11))) {
                numPenalties++;
            }
        }
    }
    return numPenalties * N3;
}

bool MaskUtil::isWhiteHorizontal(const std::vector<byte>& rowArray, int from, int to)
{
    for (int i = from; i < to; i++) {
        if (i >= 0 && i < rowArray.size() && rowArray[i] == 1) {
            return false;
        }
    }
    return true;
}

bool MaskUtil::isWhiteVertical(const std::vector<std::vector<byte> > &array, int col, int from, int to)
{
    for (int i = from; i < to; i++) {
        if (i >= 0 && i < array.size() && array[i][col] == 1) {
            return false;
        }
    }
    return true;
}

/**
   * Apply mask penalty rule 4 and return the penalty. Calculate the ratio of dark cells and give
   * penalty if the ratio is far from 50%. It gives 10 penalty for 5% distance.
   */
int MaskUtil::applyMaskPenaltyRule4(const ByteMatrix& matrix)
{
    int numDarkCells = 0;
    const std::vector<std::vector<byte> >& array = matrix.getArray();
    int width = matrix.getWidth();
    int height = matrix.getHeight();
    for (int y = 0; y < height; y++) {
        const std::vector<byte>& arrayY = array[y];
        for (size_t x = 0; x < width; x++) {
            if (arrayY[x] == 1) {
                numDarkCells++;
            }
        }
    }
    int numTotalCells = matrix.getHeight() * matrix.getWidth();
    int fivePercentVariances = abs(numDarkCells * 2 - numTotalCells) * 10 / numTotalCells;
    return fivePercentVariances * N4;
}

/**
   * Return the mask bit for "getMaskPattern" at "x" and "y". See 8.8 of JISX0510:2004 for mask
   * pattern conditions.
   */
bool MaskUtil::getDataMaskBit(int maskPattern, int x, int y)
{
    int intermediate;
    int temp;
    switch (maskPattern) {
    case 0:
        intermediate = (y + x) & 0x1;
        break;
    case 1:
        intermediate = y & 0x1;
        break;
    case 2:
        intermediate = x % 3;
        break;
    case 3:
        intermediate = (y + x) % 3;
        break;
    case 4:
        intermediate = ((((unsigned int)y) >> 1) + (x / 3)) & 0x1;
        break;
    case 5:
        temp = y * x;
        intermediate = (temp & 0x1) + (temp % 3);
        break;
    case 6:
        temp = y * x;
        intermediate = ((temp & 0x1) + (temp % 3)) & 0x1;
        break;
    case 7:
        temp = y * x;
        intermediate = ((temp % 3) + ((y + x) & 0x1)) & 0x1;
        break;
    default:
        throw IllegalArgumentException("Invalid mask pattern: " + maskPattern);
    }
    return intermediate == 0;
}

/**
   * Helper function for applyMaskPenaltyRule1. We need this for doing this calculation in both
   * vertical and horizontal orders respectively.
   */
int MaskUtil::applyMaskPenaltyRule1Internal(const ByteMatrix& matrix, bool isHorizontal)
{
    int penalty = 0;
    int iLimit = isHorizontal ? matrix.getHeight() : matrix.getWidth();
    int jLimit = isHorizontal ? matrix.getWidth() : matrix.getHeight();
    const std::vector<std::vector<byte> >& array = matrix.getArray();
    for (size_t i = 0; i < iLimit; i++) {
        int numSameBitCells = 0;
        int prevBit = -1;
        for (int j = 0; j < jLimit; j++) {
            int bit = isHorizontal ? array[i][j] : array[j][i];
            if (bit == prevBit) {
                numSameBitCells++;
            } else {
                if (numSameBitCells >= 5) {
                    penalty += N1 + (numSameBitCells - 5);
                }
                numSameBitCells = 1;  // Include the cell itself.
                prevBit = bit;
            }
        }
        if (numSameBitCells >= 5) {
            penalty += N1 + (numSameBitCells - 5);
        }
    }
    return penalty;
}

}
}
