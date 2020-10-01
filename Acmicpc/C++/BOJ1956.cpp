#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int v, e; cin >> v >> e;
    int d[v+1][v+1];
    for (int i = 1; i <= v; i++) for (int j = 1; j <= v; j++) d[i][j] = INF;
    for (int i = 1; i <= v; i++) d[i][i] = 0;
    for (int t = 0; t < e; t++) {
        int a, b, c; cin >> a >> b >> c;
        d[a][b] = c;
    }
    for (int k = 1; k <= v; k++) {
        for (int i = 1; i <= v; i++) {
            for (int j = 1; j <= v; j++) {
                if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
            }
        }
    }
    int min_v = INT_MAX;
    for (int i = 1; i < v; i++) {
        for (int j = i + 1; j <= v; j++) {
            min_v = min(min_v, d[i][j] + d[j][i]);
        }
    }
    if(min_v >= INF) cout << -1;
    else cout << min_v;
    return 0;
}