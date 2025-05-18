#include "Base64.hpp"
#include <iostream>

void Base64_Check(std::string Name, std::string FileName) {
    if (Name == "Encryption" || Name == "En") {
        Base64_Encryption(FileName);
        return;
    }

    if (Name == "Decryption" || Name == "De") {
        Base64_Decryption(FileName);
        return;
    }

    std::cout << "Please use Encryption or Decryption." << std::endl;
    std::cout << "(Error 1)" << std::endl;
    return;
}

void Base64_Encryption(std::string FileName) {
    std::cout << "Is Encryptionㅏ";
    return;
}

void Base64_Decryption(std::string FileName) {
    std::cout << "Is Decryption";
    return;
}