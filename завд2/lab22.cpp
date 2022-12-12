#include <iostream>
#include <fstream>
#include <cstdint>

int main() {
    const char *input = "data.bin";
    std::ifstream fin(input, std::ios::binary);
    if (!fin.is_open()) {
        std::cout << "Error reading data from file " << input << "\n";
        return -1;
    }
    std::cout << "Decode data from file " << input << "\n";
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 16; j++) {
            uint16_t code;
            fin.read(reinterpret_cast<char*>(&code), sizeof code);
            unsigned char ch = code & 15;
            ch |= ((code >> 10) & 15) << 4;
            std::cout << ch;
        }
        std::cout << '\n';
    }
    return 0;
}
