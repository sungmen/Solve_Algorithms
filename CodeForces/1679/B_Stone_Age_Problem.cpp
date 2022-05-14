#include <bits/stdc++.h>
using namespace std;
bool chk[200001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, q; cin >> n >> q;
    vector<long long> arr(n + 1);
    
    long long ans = 0;
    int back = -1;
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
        ans += arr[i];
    }
    memset(chk, 1, sizeof(chk));
    while(q--) {
        long long t; cin >> t;
        if (t == 1) {
            long long i, x; cin >> i >> x;
            if (chk[i]) {
                ans += x - arr[i];
                arr[i] = x;
            } else {
                ans += x - back;
                arr[i] = x;
                chk[i] = 1;
            }
            cout << ans << '\n';
        } else {
            long long x; cin >> x;
            ans = x * n;
            cout << ans << '\n';
            memset(chk, 0, sizeof(chk));
            back = x;
        }
    }
    return 0;
}
