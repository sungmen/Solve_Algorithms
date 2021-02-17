#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, l, r; cin >> n >> l >> r;
    vector<vector<int>> v(n, vector<int>(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> v[i][j];
        }
    }
    int cnt = 0;
    const int POS[4][2] = {{0,1},{0,-1},{1,0},{-1,0}};
    while (1) {
        vector<vector<bool>> chk(n, vector<bool>(n, false));
        bool next_chk = false;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (!chk[i][j]) {
                    int sum = 0, cnt_tmp = 0;
                    queue<pair<int, int>> q;
                    q.push({i,j});
                    vector<pair<int,int>> tmp;
                    while(!q.empty()) {
                        pair<int, int> cur = q.front();
                        q.pop();
                        chk[cur.first][cur.second] = true;
                        tmp.push_back({cur.first,cur.second});
                        sum += v[cur.first][cur.second];
                        cnt_tmp++;
                        for (int i = 0; i < 4; i++) {
                            pair<int,int> next = {cur.first+POS[i][0], cur.second+POS[i][1]};
                            if (next.first<0||next.first>=n||next.second<0||next.second>=n||chk[next.first][next.second]||abs(v[next.first][next.second]-v[cur.first][cur.second])<l||abs(v[next.first][next.second]-v[cur.first][cur.second])>r) continue;
                            chk[next.first][next.second] = true;
                            q.push({next.first,next.second});
                        }
                    }
                    if(cnt_tmp>1) {
                        next_chk = true;
                        int res = sum/cnt_tmp;
                        for (auto t : tmp) {
                            v[t.first][t.second] = res;
                        }
                    }
                }
            }
        }
        if (next_chk) {
            cnt++;
        } else {
            break;
        }
    }
    cout << cnt;
    return 0;
}