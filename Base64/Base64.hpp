#include <string>

#pragma once

#ifndef Base64_H
#define Base64_H

void Base64_Check(std::string arg, std::string FileName);

void Base64_Encryption(std::string FileName);
void Base64_Decryption(std::string FileName);

#endif