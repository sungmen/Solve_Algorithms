#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin>>n;
    int d[n][n];
    for(int i = 0; i < n; i++) for (int j = 0; j < n; j++) d[i][j] = INF;
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            int p; cin >> p;
            if(p) d[i][j] = 1;
        }
    }
    for (int k = 0; k < n; k++) for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if(d[i][j] && d[i][j] < INF) cout << 1 << ' ';
            else cout << 0 << ' ';
        }
        cout << '\n';
    }
    return 0;
}