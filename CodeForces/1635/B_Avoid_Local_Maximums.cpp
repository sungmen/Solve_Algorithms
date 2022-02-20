#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        long long n; cin >> n;
        vector<long long> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        int ans = 0;
        for (int i = 1; i < n - 2; i++) {
            if (v[i] > v[i+1] && v[i-1] < v[i]) {
                v[i+1] = max(v[i], v[i+2]);
                ans++;
            }
        }
        if (v[n-2] >v[n-3]&&v[n-2]>v[n-1]) {
            v[n-2] = max(v[n-3],v[n-1]);
            ans++;
        }
        cout << ans << '\n'; 
        for (auto i : v) {
            cout << i << ' ';
        }
        cout << '\n';
    }
    return 0;
}
