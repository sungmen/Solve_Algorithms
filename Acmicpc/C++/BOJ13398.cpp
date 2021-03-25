#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<pair<int,int>> v(n);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (i == 0) {
            cin >> v[i].first;
            ans = v[i].second = v[i].first;
        } else {
            cin >> v[i].first;
            int tmp = max(v[i-1].first + v[i].first, v[i].first);
            v[i].second = max(v[i-1].first, v[i-1].second + v[i].first);
            v[i].first = tmp;
            ans = max(ans, max(v[i].first, v[i].second));
        }
    }
    cout << ans;
    return 0;
}