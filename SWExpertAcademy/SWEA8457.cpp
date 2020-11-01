// title : 8457. 알 덴테 스파게티
#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    for (int tc = 1; tc <= t; tc++) {
        int n, b, e; cin >> n >> b >> e;
        int ans = 0;
        for (int tn = 0; tn < n; tn++) {
            int p; cin >> p;
            if(b % p <= e) ans++;
            else {
                int tmp = b / p;
                if ((p * (tmp + 1) - b) <= e) ans++;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
    return 0;
}