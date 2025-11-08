#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long t; cin >> t;
    while (t--) {
        long long n, x, y; cin >> n >> x >> y;
        y %= 2;
        x %= 2;
        for (int i = 0; i < n; i++) {
            long long a; cin >> a;
            x = (x + a) % 2;
        }
        cout << (x != y ? "Bob" : "Alice") << '\n';
    }
    return 0;
}
