#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n>> m;
    int low[n+1][n+1];
    int big[n+1][n+1];
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            low[i][j] = INF;
            big[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++) {
        low[i][i] = 0;
        big[i][i] = 0;
    }
    for (int t = 0 ; t < m; t++) {
        int a, b; cin >> a >> b;
        low[a][b] = 1;
        big[b][a] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j<= n; j++) {
                if(low[i][k] + low[k][j] < low[i][j]) {
                    low[i][j] = low[i][k] + low[k][j];
                }
                if(big[i][k] + big[k][j] < big[i][j]) {
                    big[i][j] = big[i][k] + big[k][j];
                }
            }
        }
    }
    int d[n+1];
    for (int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j <= n; j++) {
            if(min(low[i][j], big[i][j]) != INF) cnt++;
        }
        d[i] = cnt;
    }
    for (int i = 1; i <= n; i++) cout << n - d[i] << '\n';
}