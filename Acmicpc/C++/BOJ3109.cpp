#include <bits/stdc++.h>
using namespace std;
const int POS[3][2] = {{-1,1},{0,1},{1,1}};
vector<vector<bool>> chk(10001, vector<bool>(501, false));
vector<string> v(10001);
int r, c;
int cnt = 0;
void dfs(pair<int,int> start, int start_num) {
    chk[start.first][start.second] = true;
    if (start.second == c-1) {
        cnt++;
        return;
    }
    for (int i = 0; i < 3; i++) {
        pair<int,int> next = {start.first+POS[i][0], start.second+POS[i][1]};
        if (next.first < 0 || next.first >= r || next.second < 0 || next.second >= c || chk[next.first][next.second] || v[next.first][next.second] == 'x') continue;
        dfs(next, start_num);
        if (start_num != cnt) return;
    }
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    cin >> r >> c;
    for (int i = 0; i < r; i++) {
        cin >> v[i];
    }
    for (int i = 0; i < r; i++) {
        dfs({i,0}, cnt);
    }
    cout << cnt << '\n';
    return 0;
}