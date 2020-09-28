#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int d[n][n];
    for (int i = 0; i < n ;i++) for (int j = 0; j < n ;j++) d[i][j] = INF;
    for (int i = 0; i < n ;i++) d[i][i] = 0;
    for (int i = 0 ; i < m; i++) {
        int a, b; cin >> a >> b;
        d[a-1][b-1] = 1;
        d[b-1][a-1] = 1;
    }
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
    int MIN = INT_MAX;
    int res = 0;
    for (int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (d[i][j] && d[i][j] < INF) cnt += d[i][j];
        }
        if(MIN > cnt) {
            MIN = cnt;
            res = i;
        }
    }
    cout << res+1;
    return 0;
}