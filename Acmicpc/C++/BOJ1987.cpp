#include <bits/stdc++.h>
using namespace std;
int pos[2][4] = {{-1, 0, 1, 0},{0, -1, 0, 1}};
int ans, r_, s_;
int v[21][21];
void dfs(vector<int> &ch_s, int x, int y, int idx) {
    for(int i = 0; i < 4; i++) {
        int x_ = x + pos[0][i],  y_ = y + pos[1][i];
        if(x_ >= 0 && x_ < r_ && y_ >= 0 && y_ < s_) {
            if(ch_s[int(v[x_][y_])-65]==1) {
                if(ans < idx) ans = idx;
            } else {
                ch_s[int(v[x_][y_])-65]=1;
                dfs(ch_s, x_, y_, idx+1);
                ch_s[int(v[x_][y_])-65]=0;
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);
    int r, s;
    cin >> r >> s;
    r_ = r;
    s_ = s;
    for(int i = 0; i < r; i++) {
        char str[21];
        cin >> str;
        for (int j = 0; j < s; j++) {
            v[i][j] = str[j];
        }
    }
    ans = 0;
    vector<int> ch_s(26, 0);
    ch_s[int(v[0][0])-65] = 1;
    dfs(ch_s, 0, 0, 1);
    cout << ans;
    return 0;
}