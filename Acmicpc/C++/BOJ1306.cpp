#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, m; cin >> n >> m;
    vector<int> v(n+1);
    for (int i = 1; i <= n; i++) cin >> v[i];
    map<int, int> mi;
    for (int i = 1; i <= 2 * m - 1; i++) {
        mi[-v[i]]++;
    }
    cout << (-mi.begin()->first) << ' ';
    for (int i = 2 * m; i <= n; i++) {
        if (mi[-v[i - (2 * m - 1)]] == 1) {
            mi.erase(-v[i-(2*m-1)]);
        } else {
            mi[-v[i-(2*m-1)]]--;
        }
        mi[-v[i]]++;
        cout << (-mi.begin()->first) << ' ';
    }
    return 0;
}
