#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int main(){
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n;
    int d[n+1][n+1];
    for (int i = 1; i <= n; i++) for (int  j = 1; j <= n; j++) d[i][j] = INF;
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    for (cin>>k; k--;) {
        int a, b; cin >> a >> b;
        d[a][b] = 1;
    }
    for (k = 1; k <= n; k++) for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (d[i][k] + d[k][j] < d[i][j]) d[i][j] = d[i][k] + d[k][j];
    int s;
    for (cin>>s;s--;) {
        int a, b; cin >> a >> b;
        if(d[a][b] == INF && d[b][a] == INF) cout << 0 << '\n';
        else if (d[b][a] == INF && d[a][b] < INF) cout << -1 << '\n';
        else if (d[a][b] == INF && d[b][a] < INF) cout << 1 << '\n';
    }
    return 0;
}