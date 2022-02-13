#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, t, k, res = 0, px, py; 
    cin >> n >> m >> t >> k;
    vector<pair<int, int>> v(t);
    for (int i = 0; i < t; i++) {
        int x, y; cin >> x >> y;
        v[i] = {x, y};
    }
    for (auto i : v) {
        for (auto j : v) {
            int cnt = 0, nx = (i.first+k>n?n-k:i.first) , ny = (j.second+k>m?m-k:j.second);
            for (auto l : v) {
                if (l.first >= nx && l.first <= nx+k && l.second >= ny && l.second <= ny+k) cnt++;
            }
            if (cnt > res) {
                res = cnt, px = nx, py = ny+k;
            }
        }
    }
    cout << px << ' ' << py << '\n' << res;
    return 0;
}
