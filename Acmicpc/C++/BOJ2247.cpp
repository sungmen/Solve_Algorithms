#include <bits/stdc++.h>
using namespace std;
const int MOD = 1e6;
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long n; cin >> n;
    long long ans = 0;
    for (int i = 2; i <= n/2; ++i) {
        ans += (i * ((n / i) - 1));
        ans %= MOD;
    }
    cout << ans % MOD;
    return 0;
}
