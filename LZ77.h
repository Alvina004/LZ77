#pragma once
#include "Crypto.h"

class RLE : public Crypto {
public:
    RLE();
    virtual ~RLE();

    // Override the virtual functions for RLE compression and decompression
    virtual int Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) override;
    virtual int Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) override;
};
