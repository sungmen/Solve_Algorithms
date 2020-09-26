#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, r; cin >> n >> m >> r;
    int d[n][n];
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n;j++) {
            d[i][j] = INF;
        }
    }
    for(int i = 0; i < n; i++)d[i][i] = 0;
    int item[n];
    for(int i = 0; i < n; i++) cin >> item[i];
    for(int i = 0; i < r; i++) {
        int a, b, l; cin >> a >> b >> l;
        d[a-1][b-1] = l;
        d[b-1][a-1] = l;
    }
    for(int k = 0; k < n; k++){
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if(d[i][k] + d[k][j] < d[i][j]) {
                    d[i][j] = d[i][k] + d[k][j];
                }
            }
        }
    }
    int max = 0;
    for(int i = 0; i < n; i++) {
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if(d[i][j] <= m) {
                cnt += item[j];
            }
        }
        if(max < cnt) {
            max = cnt;
        }
    }
    cout << max;
    return 0;
}