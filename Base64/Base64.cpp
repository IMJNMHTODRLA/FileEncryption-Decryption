#include "Base64.hpp"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

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

static const std::string base64_chars =
             "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
             "abcdefghijklmnopqrstuvwxyz"
             "0123456789+/";

std::string base64_encode(const std::vector<uint8_t>& data) {
    std::string result;
    int val = 0, valb = -6;

    for (uint8_t c : data) {
        val = (val << 8) + c;
        valb += 8;
        while (valb >= 0) {
            result.push_back(base64_chars[(val >> valb) & 0x3F]);
            valb -= 6;
        }
    }
    if (valb > -6) {
        result.push_back(base64_chars[((val << 8) >> (valb + 8)) & 0x3F]);
    }
    while (result.size() % 4) {
        result.push_back('=');
    }
    return result;
}

void Base64_Encryption(const std::string& FileName) {

    std::cout << "Start Encryption(Type Base64)"<< std::endl;

    std::cout << "Opening file..." << std::endl;

    std::ifstream inFile(FileName, std::ios::binary);
    if (!inFile) {
        std::cerr << "Failed to open file." << std::endl;
        return;
    }

    std::cout << "Opened file successfully." << std::endl;

    std::vector<uint8_t> fileData((std::istreambuf_iterator<char>(inFile)),
                                   std::istreambuf_iterator<char>());
    inFile.close();

    std::string encoded = base64_encode(fileData);

    std::cout << "Opening output file..." << std::endl;

    std::ofstream outFile(FileName + "-Encryption.txt");
    if (!outFile) {
        std::cerr << "Failed to open output file." << std::endl;
        return;
    }

    std::cout << "Successfully opened the output file." << std::endl;

    outFile << encoded;
    outFile.close();

    std::cout << "Encryption completed (Type Base64)" << std::endl;
}

void Base64_Decryption(std::string FileName) {
    std::cout << "Is Decryption";
    return;
}