#include <bits/stdc++.h>
using namespace std;
const int POS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
int chk[101][101];
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    char d[n][m];
    for (int i = 0; i < n; i++) {
        string str; cin >> str;
        for (int j = 0; j < m; j++) {
            d[i][j] = str[j];
        }
    }
    int res = 0;
    for (int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if (d[i][j] == '*' && !chk[i][j]) {
                res++;
                queue<pair<int, int>> q;
                chk[i][j] = true;
                q.push(make_pair(i, j));
                while(!q.empty()) {
                    int x = q.front().first;
                    int y = q.front().second;
                    q.pop();
                    for (int i = 0; i < 4; i++) {
                        int x_ = x + POS[i][0];
                        int y_ = y + POS[i][1];
                        if (x_ < 0 || x_ >= n || y_ < 0 || y_ >= m || chk[x_][y_]) continue;
                        if (d[x_][y_] == '*') {
                            chk[x_][y_] = true;
                            q.push(make_pair(x_, y_));
                        }
                    }
                }
            }
        }
    }
    cout << res;
    return 0;
}