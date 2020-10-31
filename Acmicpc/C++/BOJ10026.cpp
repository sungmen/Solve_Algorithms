#include <bits/stdc++.h>
using namespace std;
int pos [4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
char c[101][101];
char c_[101][101];
void dfs(vector<vector<bool>> &chk, int x, int y, int n) {
    for(int i = 0; i < 4; i++) {
        int x_ = x + pos[i][0];
        int y_ = y + pos[i][1];
        if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n && !chk[x_][y_] && c[x_][y_] == c[x][y]) {
            chk[x_][y_] = true;
            dfs (chk, x_, y_, n);
        }
    }
    return;
}
void dfs_(vector<vector<bool>> &chk, int x, int y, int n) {
    for(int i = 0; i < 4; i++) {
        int x_ = x + pos[i][0];
        int y_ = y + pos[i][1];
        if (x_ >= 0 && x_ < n && y_ >= 0 && y_ < n && !chk[x_][y_] && c_[x_][y_] == c_[x][y]) {
            chk[x_][y_] = true;
            dfs_ (chk, x_, y_, n);
        }
    }
    return;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) {
        cin >> c[i][j];
        if(c[i][j] == 'G') {
            c_[i][j] = 'R';
        } else {
            c_[i][j] = c[i][j];
        }
    }
    vector<vector<bool>> chk(n, vector<bool>(n, false));
    vector<vector<bool>> weak_chk(n, vector<bool>(n, false));
    int res = 0, res_w = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0;j < n; j++) {
            if(!chk[i][j]) {
                res++;
                chk[i][j] = true;
                dfs(chk, i, j, n);
            }
            if(!weak_chk[i][j]) {
                res_w++;
                weak_chk[i][j] = true;
                dfs_(weak_chk, i, j, n);
            }
        }
    }
    cout << res << ' ' << res_w;
    return 0;
}