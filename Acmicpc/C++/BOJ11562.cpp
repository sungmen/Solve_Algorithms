#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int d[n+1][n+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) d[i][j] = INF;
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (int i = 0; i < m; i++) {
        int u, v, b; cin >> u >> v >> b;
        if(b) {
            d[u][v] = 0;
            d[v][u] = 0;
        } else {
            d[u][v] = 0;
            d[v][u] = 1;
        }
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
    int k; cin >> k;
    for (int i = 0; i < k; i++) {
        int s, e; cin >> s >> e;
        cout << d[s][e] << '\n';
    }
    return 0;
}