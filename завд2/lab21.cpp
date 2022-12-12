#include <iostream>
#include <fstream>
#include <cstdint>

int main() {
    const char *filename = "text.txt";
    std::cout << "Reading text from file: " << filename << "\n";
    std::ifstream fin(filename);
    if (!fin.is_open()) {
        std::cout << "Error opening file " << filename << "!\n";
        return -1;
    }
    std::string strs[4];
    for (size_t i = 0; i < 4; i++) {
        std::getline(fin, strs[i]);
        while (strs[i].length() < 16)
            strs[i].push_back(' ');
    }

    const char *output = "data.bin";
    std::ofstream fout(output, std::ios::binary);
    if (!fout.is_open()) {
        std::cout << "Error opening file " << output << "!\n";
        return -1;
    }
    for (size_t i = 0; i < 4; i++) {
        for (size_t j = 0; j < strs[i].size(); j++) {
            const unsigned char ch = strs[i][j];
            uint16_t code = ch & 15;
            code |= i << 4;
            code |= j << 6;
            code |= ((ch >> 4) & 15) << 10;
            code |= (i & 1) << 14;
            code |= (ch & 1) << 15;
            fout.write(reinterpret_cast<char*>(&code), sizeof code);
        }
    }
    std::cout << "OK. Data was encoded & saved to file " << output << "\n";
    return 0;
}

