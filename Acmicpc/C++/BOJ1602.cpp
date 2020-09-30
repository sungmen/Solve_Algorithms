#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int tall[n+1][n+1];
    int sht[n+1][n+1];
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++){ 
            tall[i][j] = INF;
            sht[i][j] = INF;
        }
    }
    for(int i = 1; i <= n; i++) {
        tall[i][i] = 0;sht[i][i] = 0;
    }
    for(int i = 0; i < m; i++) {
        int a, b; cin >> a >> b;
        tall[b][a] = 1;
        sht[a][b] = 1;
    }
    for (int k = 1; k <= n; k++) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                if (tall[i][k] + tall[k][j] < tall[i][j]) {
                    tall[i][j] = tall[i][k] + tall[k][j];
                }
                if (sht[i][k] + sht[k][j] < sht[i][j]) {
                    sht[i][j] = sht[i][k] + sht[k][j];
                }
            }
        }
    }
    int res[n+1][n+1];
    int result = 0;
    for(int i = 1; i <= n; i++) {
        int cnt = 0;
        for (int j = 1; j<= n; j++) {
            res[i][j] = min(tall[i][j], sht[i][j]);
            if(res[i][j] != INF) cnt++;
        }
        if(cnt == n) {
            result++;
        }
    }
    cout << result;
    return 0;
}