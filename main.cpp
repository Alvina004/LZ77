#include <iostream>
#include <cstring>
#include "RLE.h"

using namespace std;

int main() {
    unsigned char src[1024], dest[1024], decrypt[1024];
    unsigned int size, outSize;

    cout << "Enter a string to encrypt (compress): ";
    cin.getline((char*)src, 1024);

    size = strlen((const char*)src);
    RLE rleObj;

    if (rleObj.Encrypt(src, size, dest, outSize)) {
        cout << "Failed to encrypt (compress)...\n";
        return -1;
    }

    dest[outSize] = '\0';
    cout << "Compressed string: " << dest << endl;

    if (rleObj.Decrypt(dest, outSize, decrypt, size)) {
        cout << "Failed to decrypt (decompress)...\n";
        return -2;
    }

    decrypt[size] = '\0';
    cout << "Decompressed string: " << decrypt << endl;

    return 0;
}
