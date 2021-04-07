#include <bits/stdc++.h>
using namespace std;
const int POS[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, k; cin >> n >> k;
    vector<vector<int>> v(n+1, vector<int>(n+1, 0));
    while (k--) {
        int c, r; cin >> c >> r;
        v[c][r] = 1;
    }
    int l; cin >> l;
    vector<int> d(10111, 0);
    vector<int> tmp;
    tmp.push_back(0);
    int tmp_cnt = 0;
    while (l--) {
        int x; char c; cin >> x >> c;
        tmp.push_back(x+1);
        if (c == 'L') {
            switch (d[tmp[tmp_cnt]]) {
            case 0:
                d[x+1] = 3;
                break;
            case 1:
                d[x+1] = 0;
                break;
            case 2:
                d[x+1] = 1;
                break;
            case 3:
                d[x+1] = 2;
                break;
            }
        } else {
            switch (d[tmp[tmp_cnt]]) {
            case 0:
                d[x+1] = 1;
                break;
            case 1:
                d[x+1] = 2;
                break;
            case 2:
                d[x+1] = 3;
                break;
            case 3:
                d[x+1] = 0;
                break;
            }
        }
        tmp_cnt++;
    }
    tmp.push_back(10111);
    for (int i = 1; i < tmp.size() - 1; i++) {
        for (int j = tmp[i]+1; j < tmp[i+1]; j++) {
            d[j] = d[j-1];
        }
    }
    vector<vector<bool>> chk(n+1, vector<bool>(n+1, false));
    deque<pair<int,int>> dq;
    dq.push_back({1, 1});
    chk[1][1] = true;
    int time = 1;
    while(1) {
        pair<int, int> cur = dq.front();
        pair<int, int> next = {cur.first + POS[d[time]][0], cur.second + POS[d[time]][1]};
        if (next.first <= 0 || next.first >= n+1 || next.second <= 0 || next.second >= n+1 || chk[next.first][next.second]) break;
        dq.push_front({next.first, next.second});
        chk[next.first][next.second] = true;
        if (!v[next.first][next.second]) {
            chk[dq.back().first][dq.back().second] = false;
            dq.pop_back();
        } else {
            v[next.first][next.second] = 0;
        }
        time++;
    }
    cout << time;
    return 0;
}
