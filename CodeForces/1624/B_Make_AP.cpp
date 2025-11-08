#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int a, b, c; cin >> a >> b >> c;
        if (a > c) swap(a, c);
        int ret = c - a;
        int d = (c-a)/2;
        int p = c - b;
        int p2 = b - a;
        if (p == p2) {
            cout << "YES\n";continue;
        }
        if (!((a+c)%(2*b))) {
            cout << "YES\n";
            continue;
        }
        int f = b - c;
        int g = b + f;
        if (g > 0 && !(g%a)) {
            cout << "YES\n";
            continue;
        }
        f = b - a;
        g = b + f;
        if (g > 0 && !(g%c)) {
            cout << "YES\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
