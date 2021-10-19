#include <bits/stdc++.h>
using namespace std;
const int pos[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str[12];
    for (int i = 0; i < 12; ++i) {
        cin >> str[i];
    }
    int res = 0;
    bool chk = true;
    vector<pair<int,int>> v;
    while(chk) {
        chk = false;
        vector<vector<bool>> schk(12, vector<bool>(6, false));
        for (int i = 0; i < 12; i++) {
            for (int j = 0; j < 6; j++) {
                if (str[i][j] != '.' && !schk[i][j]) {
                    v.clear();
                    queue<pair<int,int>> q;
                    q.push({i ,j});
                    v.push_back({i, j});
                    schk[i][j] = 1;
                    while (!q.empty()) {
                        pair<int,int> cur = q.front();
                        q.pop();
                        for (int k = 0; k < 4; ++k) {
                            pair<int,int> next = {cur.first + pos[k][0], cur.second + pos[k][1]};
                            if (next.first >= 0 && next.first < 12 && next.second >= 0 && next.second < 6 && !schk[next.first][next.second] && str[next.first][next.second] == str[i][j]) {
                                q.push(next);
                                schk[next.first][next.second] = 1;
                                v.push_back(next);
                            }
                        }
                    }
                    if (v.size() >= 4) {
                        chk = 1;
                        for (auto vp : v) {
                            str[vp.first][vp.second] = '.';
                        }
                    }
                }
            }
        }
        for (int i = 11; i >= 0; --i) {
            for (int j = 0; j < 6; ++j) {
                if (str[i][j] != '.') {
                    int y = i, x = j;
                    while (y < 11) {
                        if (str[y + 1][x] == '.') {
                            swap(str[y + 1][x], str[y][x]);
                            y = y + 1;
                        } else {
                            break;
                        }
                    }
                }
            }
        }
        if (chk) {
            ++res;
        }
    }
    cout << res;
    return 0;
}
