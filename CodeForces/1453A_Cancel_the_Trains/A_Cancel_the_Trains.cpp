#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for (cin >> t; t--;) {
        int d[101];
        memset(d, 0, sizeof(d));
        int n, m; cin >> n >> m;
        int p;
        int ans = 0;
        for (int i = 0; i < n+m; i++) {
            cin >> p;
            d[p]++;
            if (d[p] == 2) ans++;
        }
        cout << ans << '\n';
    }
    return 0;
}