#include "RLE.h"
#include <cstring>
#include <sstream>
#include <iostream>
using namespace std;

RLE::RLE() {}

RLE::~RLE() {}

int RLE::Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) {
    if (!pSrc || !pOut || SrcSz == 0) {
        return -1; // Error: Invalid input
    }

    stringstream compressed;
    for (unsigned int i = 0; i < SrcSz; ++i) {
        unsigned int count = 1;
        while (i + 1 < SrcSz && pSrc[i] == pSrc[i + 1]) {
            ++count;
            ++i;
        }
        compressed << count << pSrc[i];
    }

    string result = compressed.str();
    OutSz = result.size();
    if (OutSz > SrcSz) {
        return -2; // Error: Compression resulted in larger size
    }

    memcpy(pOut, result.c_str(), OutSz);
    return 0; // Success
}

int RLE::Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) {
    if (!pSrc || !pOut || SrcSz == 0) {
        return -1; // Error: Invalid input
    }

    stringstream decompressed;
    for (unsigned int i = 0; i < SrcSz; ++i) {
        if (isdigit(pSrc[i])) {
            unsigned int count = pSrc[i] - '0'; // Convert char to integer
            ++i;
            while (i + 1 < SrcSz && isdigit(pSrc[i + 1])) { // Handle multi-digit counts
                count = count * 10 + (pSrc[i + 1] - '0');
                ++i;
            }
            decompressed << string(count, pSrc[i]); // Repeat character `count` times
        } else {
            return -2; // Error: Invalid compressed format
        }
    }

    string result = decompressed.str();
    OutSz = result.size();
    memcpy(pOut, result.c_str(), OutSz);
    return 0; // Success
}
