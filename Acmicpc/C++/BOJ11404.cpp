#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int d[n+1][n+1];
    for(int i = 1; i <= n; i ++) {
        for (int j = 1; j <= n; j++) {
            d[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++) d[i][i] = 0;
    int m;
    for (cin >> m; m--;) {
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = min(c, d[a][b]);
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] != INF) cout << d[i][j] << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }
}