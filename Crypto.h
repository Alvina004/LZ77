#pragma once

class Crypto {
public:
    // Pure virtual functions for encryption and decryption
    virtual int Encrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) = 0;
    virtual int Decrypt(const unsigned char* pSrc, unsigned int SrcSz, unsigned char* pOut, unsigned int& OutSz) = 0;

    virtual ~Crypto() {} // Virtual destructor
};
