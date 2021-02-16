#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int l, w; cin >> l >> w;
    vector<vector<char>> v(l, vector<char>(w));
    queue<pair<int,int>> qp;
    for (int row = 0; row < l; row++) {
        string str; cin >> str;
        for (int col = 0; col < w; col++) {
            v[row][col] = str[col];
            if (v[row][col] == 'L') {
                qp.push({row, col});
            }
        }
    }
    int MAX = 0;
    const int POS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while(!qp.empty()) {
        pair<int, int> s = qp.front();
        qp.pop();
        queue<pair<int,int>> q;
        vector<vector<int>> chk(l, vector<int>(w, 0));
        q.push(s);
        while(!q.empty()) {
            pair<int,int> cur = q.front();
            q.pop();
            for (int i = 0; i < 4; i++) {
                pair<int, int> next = {cur.first + POS[i][0], cur.second + POS[i][1]};
                if (next.first < 0 || next.first >= l || next.second < 0 || next.second >= w || s == next || v[next.first][next.second] != 'L' || (chk[next.first][next.second] && chk[next.first][next.second] <= chk[cur.first][cur.second]+1)) continue;
                chk[next.first][next.second] = chk[cur.first][cur.second] + 1;
                q.push(next);
            }
        }
        for (int row = 0; row < l; row ++) {
            for (int col = 0; col < w; col ++) {
                if (chk[row][col]) {
                    MAX = max(MAX, chk[row][col]);
                }
            }
        }
    }
    cout << MAX;
    return 0;
}