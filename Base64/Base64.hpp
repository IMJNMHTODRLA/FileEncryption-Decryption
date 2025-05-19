#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <cstdint>

#pragma once

void Base64_Check(std::string arg, std::string FileName);

std::string base64_encode(const std::vector<uint8_t>& data);
void Base64_Encryption(const std::string& FileName);
void Base64_Decryption(std::string FileName);
