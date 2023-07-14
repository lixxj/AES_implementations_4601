#include "AESfunctions.h"
#include <vector>
#include <string>

void testAES(const std::string& plaintext, const std::vector<unsigned char>& key) {
    unsigned short Nk = key.size() / 4;
    unsigned short CipherKeyLength = Nk * rows;
    unsigned short Nr = (Nk > Nb) ? Nk + 6 : Nb + 6;
    unsigned short ExtdCipherKeyLength = (Nr + 1) * stt_lng;

    unsigned char expandedKey[ExtdCipherKeyLength_max];
    KeyExpansion(key.data(), Nk, expandedKey);

    unsigned char ciphertext[stt_lng];
    AES_Encrypt((unsigned char*)plaintext.data(), expandedKey, Nr, ciphertext);

    unsigned char decrypted_plaintext[stt_lng];
    AES_Decrypt(ciphertext, expandedKey, Nr, decrypted_plaintext);

    // Add code here to check if decrypted_plaintext matches plaintext and print the result
}

int main() {
    std::vector<std::vector<unsigned char>> keys = {
        {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15},
        {15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1, 0}
        // Add more keys here
    };

    std::vector<std::string> plaintexts = {
        "ABCDEFGHIJKLMNOP",
        "HELLOAESHELLOAES"
        // Add more plaintexts here
    };

    for (const auto& key : keys) {
        for (const auto& plaintext : plaintexts) {
            testAES(plaintext, key);
        }
    }

    return 0;
}
