#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<bool> v(n + 1);
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            int m;
            cin >> m;
            while (m > n) {
                m /= 2;
            }
            while (v[m]) {
                m /= 2;
            }
            if (m > 0 && !v[m]) {
                v[m] = 1;
                cnt++;
            }
        }
        cout << (cnt == n ? "YES" : "NO") << '\n';
    }
    return 0;
}
