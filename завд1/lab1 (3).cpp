#include <iostream>

int main() {
    int a, b, c, d;
    std::cout << "a = ";
    std::cin >> a;
    std::cout << "b = ";
    std::cin >> b;
    std::cout << "c = ";
    std::cin >> c;
    std::cout << "d = ";
    std::cin >> d;
    int b1024 = b << 10;
    int d15 = (d << 4) - d;
    int a12 = (a << 2) + (a << 3);
    int c4097 = (c << 12) + c;
    int d13 = (d << 4) - (d << 1) - d;
    int result = b1024 + ((d15 + a12) >> 9) - c4097 + d13;
    int check = 1024 * b + (d * 15 + 12 * a) / 512 - 4097 * c + d * 13;
    std::cout << "Result: " << result << '\n';
    std::cout << " Check: " << check << '\n';
    return 0;
}

