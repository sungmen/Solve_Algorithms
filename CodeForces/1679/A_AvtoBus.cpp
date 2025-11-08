#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        long long n; cin >> n;
        if (n % 2 || n <= 3) {
            cout << -1 << '\n';
            continue;
        } else {
            int two = 4, three = 6;
            long long min_ = n / three;
            if (min_ > 0 && n%three == 2) {
                min_--;
                min_ += ((n%three) + 6) / two;
            } else {
                min_ += (n % three) / two;
            }
            long long max_ = n / two;
            if (n%two == 2) {
                max_--;
                max_ += ((n%two)+4) / three;
            } else {
                max_ += (n%two) / three;
            }
            cout << min_ << ' ' << max_ << '\n';
        }
    }
    return 0;
}
