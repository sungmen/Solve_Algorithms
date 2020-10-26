#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    bool d[n+1][n+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[i][j] = false;
    for (int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        d[a][b] = true;
    }
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) for (int k = 1; k <= n; k++) if (d[j][i] && d[i][k]) d[j][k] = true;
    int res = 0;
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if (d[i][j] || d[j][i]) cnt++;
        }
        if (cnt == n - 1) ++res;
    }
    cout << res;
    return 0;
}