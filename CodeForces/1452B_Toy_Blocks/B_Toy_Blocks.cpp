#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for (cin >> t; t--; ) {
        int tc;
        cin >> tc;
        vector<long long> v(tc);
        long long max_v = 0, sum = 0;
        for (int i = 0; i < tc; i++) {
            cin >> v[i];
            sum += v[i];
            max_v = max(max_v, v[i]);
        } 
        long long ans = 0;
        if (!(sum % (tc - 1))) ans = sum;
        else ans = sum - sum % (tc - 1) + tc - 1;
        if (ans < max_v * (tc - 1)) ans = max_v * (tc - 1);
        cout << ans - sum << '\n';
    }
    return 0;
}