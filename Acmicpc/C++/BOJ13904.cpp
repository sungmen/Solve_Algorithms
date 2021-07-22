#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int, int>> v(n);
    for (int i = 0; i < n; i++) cin >> v[i].second >> v[i].first;
    sort(v.rbegin(), v.rend());
    map<int, int> m;
    int res = 0;
    for (int i = 0; i < n; i++) {
        if (!m[v[i].second]) {
            m[v[i].second] = 1;
            res += v[i].first;
        } else {
            int tmp = v[i].second;
            while (--tmp > 0 && m[tmp]);
            if (tmp) {
                m[tmp] = 1;
                res += v[i].first;
            }
        }
    }
    cout << res;
    return 0;
}