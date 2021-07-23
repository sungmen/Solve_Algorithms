#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    const int p[4][2] = {{0, 0}, {0, 1}, {0, -1}, {1, 0}};
    const int pos[5][2] = {{0, 0}, {1, 1}, {1, -1}, {1, 0}, {2, 0}};
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int res = INT_MAX;
    for (int i = 0; i < pow(2, n); i++) {
        bitset<18> b(i);
        vector<vector<int>> t = v;
        int cnt = 0;
        for (int j = 0; j < n; j++) {
            if (b[j]) {
                ++cnt;
                for (int k = 0; k < 4; k++) {
                    pair<int, int> next = {p[k][0], j + p[k][1]};
                    if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < n) {
                        t[next.first][next.second] ^= 1;
                    }
                
                }
            }
        }
        for (int j = 0; j < n - 1; j++) {
            for (int k = 0; k < n; k++) {
                if (t[j][k]) {
                    ++cnt;
                    for (int m = 0; m < 5; m++) {
                        pair<int, int> next = {j + pos[m][0], k + pos[m][1]};
                        if (next.first >= 0 && next.first < n && next.second >= 0 && next.second < n) {
                            t[next.first][next.second] ^= 1;
                        }
                    }
                }
            }
        }
        bool chk = true;
        for (int j = 0; j < n; j++) {
            if (t[n-1][j]) {
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