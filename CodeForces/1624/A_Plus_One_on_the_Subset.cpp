#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        int re = 0, re2 = INT_MAX;
        for (int i = 0; i < n; ++i) {
            int m; cin >> m;
            re = max(re, m);
            re2 = min(re2, m);
        }
        cout << re - re2 << '\n';
    }
    return 0;
}
