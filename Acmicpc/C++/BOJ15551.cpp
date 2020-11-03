#include <iostream>
int main() {
    int n; std::cin >> n;
    std::string str(n-2, '!');
    std::cout << str+"^^" << '\n' << str+"]}";
}