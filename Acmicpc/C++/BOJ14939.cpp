#include <bits/stdc++.h>
using namespace std;
const int MAX = 10;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    const int p[4][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}};
    const int pos[5][2] = {{0, 0}, {1, 1}, {1, -1}, {1, 0}, {2, 0}};
    vector<vector<int>> v(MAX, vector<int>(MAX));
    for (int i = 0; i < MAX; i++) {
        string str; cin >> str;
        for (int j = 0; j < MAX; j++) {
            if (str[j] == '#') v[i][j] = 0;
            else v[i][j] = 1;
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < 1 << MAX; i++) {
        bitset<10> b(i);
        vector<vector<int>> t = v;
        int cnt = 0;
        for (int j = 0; j < MAX; j++) {
            if (b[j]) {
                ++cnt;
                for (int k = 0; k < 4; k++) {
                    pair<int, int> next = {p[k][0], j + p[k][1]};
                    if (next.first >= 0 && next.first < MAX && next.second >= 0 && next.second < MAX) {
                        t[next.first][next.second] ^= 1;
                    }
                }
            }
        }
        for (int j = 0; j < MAX-1; j++) {
            for (int k = 0; k < MAX; k++) {
                if (t[j][k]) {
                    ++cnt;
                    for (int m = 0; m < 5; m++) {
                        pair<int, int> next = {j + pos[m][0], k + pos[m][1]};
                        if (next.first >= 0 && next.first < MAX && next.second >= 0 && next.second < MAX) {
                            t[next.first][next.second] ^= 1;
                        }
                    }
                }
            }
        }
        bool chk = true;
        for (int j = 0; j < MAX; j++) {
            if (t[MAX - 1][j]) {
                chk = false;
                break;
            }
        }
        if (chk && res > cnt) {
            res = cnt;
        }
    }
    cout << (res == INT_MAX ? -1 : res);
    return 0;
}