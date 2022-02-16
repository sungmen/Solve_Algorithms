#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m, c; cin >> n >> m >> c;
    vector<int> v(n+1), res;
    map<int, int> mi;
    for (int i = 1; i <= n; i++) cin >> v[i];
    for (int i = 1; i <= n; i++) {
        if (i > m) {
            mi[v[i - m]]--;
            if (!mi[v[i-m]]) mi.erase(v[i-m]);
        }
        mi[v[i]]++;
        if (i >= m) {
            auto it = mi.end();
            it--;
            if (it->first - mi.begin()->first <= c) res.push_back(i - m + 1);
        }
    }
    if (res.empty()) {
        cout << "NONE";
    } else {
        for (auto r : res) cout << r << '\n';
    }
    return 0;
}