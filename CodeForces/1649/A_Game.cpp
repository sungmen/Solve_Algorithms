#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n; cin >> n;
        int l = 0, r = n - 1;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        while(l < n && v[l] == 1) l++;
        while(r >= 0 && v[r] == 1) r--;
        l--, r++;
        if (l >= r) cout << 0 << '\n';
        else {
            cout << r - l << '\n';
        }
    }
    return 0;
}
