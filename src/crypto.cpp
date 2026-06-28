#include "crypto.h"
#include <algorithm>

JdatCrypto::JdatCrypto() {
}

JdatCrypto::~JdatCrypto() {
    current_key.clear();
}

bool JdatCrypto::set_key(const std::string& key) {
    if (key.empty()) return false;
    current_key = key;
    return true;
}

std::vector<uint8_t> JdatCrypto::encrypt(const std::string& plaintext) {
    std::vector<uint8_t> result;
    if (current_key.empty() || plaintext.empty()) return result;

    std::vector<uint8_t> S(256);
    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + current_key[i % current_key.length()]) % 256;
        std::swap(S[i], S[j]);
    }

    int i = 0;
    j = 0;
    for (size_t n = 0; n < plaintext.length(); n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        std::swap(S[i], S[j]);
        int K = S[(S[i] + S[j]) % 256];
        result.push_back(plaintext[n] ^ K);
    }

    return result;
}

std::string JdatCrypto::decrypt(const std::vector<uint8_t>& ciphertext) {
    std::string result = "";
    if (current_key.empty() || ciphertext.empty()) return result;

    std::vector<uint8_t> S(256);
    for (int i = 0; i < 256; i++) {
        S[i] = i;
    }

    int j = 0;
    for (int i = 0; i < 256; i++) {
        j = (j + S[i] + current_key[i % current_key.length()]) % 256;
        std::swap(S[i], S[j]);
    }

    int i = 0;
    j = 0;
    for (size_t n = 0; n < ciphertext.size(); n++) {
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        std::swap(S[i], S[j]);
        int K = S[(S[i] + S[j]) % 256];
        result += static_cast<char>(ciphertext[n] ^ K);
    }

    return result;
}