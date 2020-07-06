#include <iostream>
#include <vector>
#include <limits.h>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    int n, s;
    std::cin >> n >> s;

    std::vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        std::cin >> arr[i];
    }

    int sum = arr[0], s_ = 0, e_ = 0, cnt = INT_MAX;
    while (e_ < n) {
        sum += sum <= s ? arr[++e_] : -(arr[s_++]);
        cnt = sum >= s ? cnt > e_ - s_ + 1 ? e_ - s_ + 1 : cnt : cnt;
    }
    std::cout << (cnt == INT_MAX ? 0 : cnt) << '\n';

    return 0;
}