#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    int d[n][m];
    for (int i = 0 ; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            d[i][j] = str[j] - '0';
        }
    }
    int max = 0;
    for (int i = 0; i < n; i++) if (d[i][0] > max) max = d[i][0];
    for (int i = 0; i < m; i++) if (d[0][i] > max) max = d[i][0];
    for (int i = 1; i < n; i++) {
        for (int j = 1; j < m; j++) {
            if (d[i][j] == 1) d[i][j] = min(d[i-1][j], min(d[i][j-1], d[i-1][j-1])) + 1;
            if (max < d[i][j]) max = d[i][j];
        }
    }
    cout << max * max;
}