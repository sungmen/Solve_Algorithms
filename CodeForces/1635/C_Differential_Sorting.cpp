#include <bits/stdc++.h>
using namespace std;
signed main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while (t--) {
        int n; cin >> n;
        vector<int> a(n);
        for (int i = 0; i < n; i++) cin >> a[i];
        if (is_sorted(a.begin(), a.end())) {
            cout << "0\n";
            continue;
        }
        else if (a[n-1]<a[n-2] || a[n-2]-a[n-1]>a[n-2]) {
            cout << "-1\n";
            continue;
        } else {
            cout << n-2 << "\n";
            for (int i = 0; i < n-2; i++) {
                cout << i+1 << " " << n-1 << " " << n << "\n";
            }
        }
    }
}
 