#ifndef JDAT_CRYPTO_H
#define JDAT_CRYPTO_H

#include <string>
#include <vector>
#include <cstdint>

class JdatCrypto {
public:
    JdatCrypto();
    ~JdatCrypto();
    
    bool set_key(const std::string& key);
    std::vector<uint8_t> encrypt(const std::string& plaintext);
    std::string decrypt(const std::vector<uint8_t>& ciphertext);

private:
    std::string current_key;
};

#endif