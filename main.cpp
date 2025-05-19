#include <iostream>
#include "Base64/Base64.hpp"

int main(int argc, char* argv[]) {
    //argc == 인자 갯수
    //argv == 인자들이 들어가있는곳
    //실행 예시: main.exe (FileName) base64 Decrypt (Encryption)
    //인자 총 갯수: 4개(main.exe 포함)

    std::string fullPath = argv[0];

    // '/'가 마지막으로 나온 위치를 찾음
    size_t lastSlash = fullPath.find_last_of("/\\"); // 윈도우는 \, 리눅스는 /
    std::string ProgramName = (lastSlash == std::string::npos) ? fullPath : fullPath.substr(lastSlash + 1);

    if (argc != 4) {
        std::cout << ProgramName << " [FileName] [Base64] [Encryption | Decryption]" << std::endl;
        std::cout << "(Error 1)" << std::endl;
        return 1;
    }
    
    if (std::string(argv[2]) == "Base64") {
        Base64_Check(std::string(argv[3]), std::string(argv[1]));
        return 0;
    }
    
    std::cout << ProgramName << " [FileName] [Base64] [Encryption | Decryption]" << std::endl;
    std::cout << "(Error 1)" << std::endl;
    return 1;
}