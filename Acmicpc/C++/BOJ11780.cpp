#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;
int path[101][101];
int cnt = 0;
void countPath(int start, int end) {
    if (path[start-1][end - 1] != -1) {
        countPath(start, path[start - 1][end - 1]);
        cnt++;
        countPath(path[start - 1][end - 1], end);
    }
}
void printPath(int start, int end) {
    if (path[start-1][end - 1] != -1) {
        printPath(start, path[start - 1][end - 1]);
        cout << path[start - 1][end - 1] -1 << ' ';
        printPath(path[start - 1][end - 1], end);
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    int d[n+1][n+1];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) { d[i][j] = INF; path[i][j]=-1;}
    for (int i = 1; i <= n; i++) d[i][i] = 0;
    int m;
    for (cin>>m;m--;) {
        int a, b, c; cin >> a >> b >> c;
        if(d[a][b] > c) d[a][b] = c;
    }
    for (int k = 1; k <= n; k++) for(int i = 1; i <= n; i++) for (int j = 1; j <= n; j++) if (d[i][k] + d[k][j] < d[i][j]){ path[i][j] = k+1; d[i][j] = d[i][k] + d[k][j];}
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cout << d[i][j] << ' ';
        }
        cout << '\n';
    }
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            if (d[i][j] == 0 || d[i][j] ==INF) {
                cout << 0 << '\n';
            } else {
                cnt = 2;
                countPath(i+1, j+1);
                cout << cnt << ' ';
                cout << i << ' ';
                printPath(i+1, j+1);
                cout << j << '\n';
            }
        }
    }
    return 0;
}