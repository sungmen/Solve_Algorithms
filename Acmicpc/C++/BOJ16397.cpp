#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    int n, t, g; cin >> n >> t >> g;
    queue<pair<int, int>> q;
    bool chk[100000];
    memset(chk, false, sizeof(chk));
    const int MAX = 99999;
    q.push({n, 0});
    while (!q.empty()) {
        pair<int, int> cur = q.front();
        chk[cur.first] = true;;
        q.pop();
        if (cur.first == g) {
            cout << cur.second;
            return 0;
        }
        if (cur.second + 1 > t) continue;
        if (cur.first + 1 <= MAX && !chk[cur.first+1]) q.push({cur.first+1, cur.second+1});
        if (cur.first * 2 > MAX || cur.first == 0) continue;
        int tmp = cur.first * 2;
        int re = 0;
        int tm = 0;
        while(tmp!= 0) {
            tm %= 10;
            tmp/=10;
            re++;
        }
        int r = 1;
        while(--re) {
            r *= 10;
        }
        if (chk[cur.first * 2 - r]) continue;
        q.push({cur.first * 2 - r, cur.second + 1});
    }
    cout << "ANG";
    return 0;
}