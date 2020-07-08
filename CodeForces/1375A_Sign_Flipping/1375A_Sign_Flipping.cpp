#include <iostream>

int main() {
    int t;
    std::cin >> t;
    int n;
    for (int i = 0; i < t; i++) {
        std::cin >> n;
        for (int j = 0; j < n; j++) {
            int x;
            std::cin >> x;
            std::cout << (j % 2 ? -abs(x) : abs(x)) << ' ';
        }
        std::cout << std::endl;
    }
}