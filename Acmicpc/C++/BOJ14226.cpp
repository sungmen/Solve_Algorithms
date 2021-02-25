#include <bits/stdc++.h>
using namespace std;
struct th {
    int a, b, c;
};
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int s; cin >> s;
    queue<th> q;
    q.push({1,0,0});
    vector<vector<bool>> chk(2000, vector<bool>(2000, false));
    while(!q.empty()) {
        th cur = q.front();
        q.pop();
        if (cur.a == s) {
            cout << cur.c;
            return 0;
        }
        if (cur.a > 0 && cur.a < 2000 && !chk[cur.a][cur.a]) { 
            q.push({cur.a, cur.a, cur.c+1});
            chk[cur.a][cur.a] = true;
        }
        if (cur.b > 0 && cur.a + cur.b < 2000 && !chk[cur.a + cur.b][cur.b]) {
            q.push({cur.a + cur.b, cur.b, cur.c+1});
            chk[cur.a+cur.b][cur.b] = true;
        }
        if (cur.a > 0 && cur.a < 2000 && !chk[cur.a-1][cur.b]) {
            q.push({cur.a-1, cur.b, cur.c+1});
            chk[cur.a-1][cur.b] = true;
        }
    }
    return 0;
}