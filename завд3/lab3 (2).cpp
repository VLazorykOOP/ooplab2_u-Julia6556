#include <iostream>

int main() {
    std::cout << "Enter 8 real numbers\n";
    int crcCheck = 0;
    for (int i = 0; i < 8; i++) {
        double x;
        std::cin >> x;
        if (x >= 0)
            crcCheck |= 1 << i;
    }
    std::cout << "Enter CRC byte(0..255): ";
    int crc;
    std::cin >> crc;
    if (crc == crcCheck)
        std::cout << "CRC checking: correct!\n";
    else
        std::cout << "CRC checking: error!\n";
    return 0;
}

