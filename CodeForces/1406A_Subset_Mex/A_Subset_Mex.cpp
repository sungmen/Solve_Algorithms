#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for (cin>>t;t--;){
        size_t n; cin >> n;
        vector<int> v(n);
        for (int i = 0; i < n; i++) cin >> v[i];
        sort(v.begin(), v.end());
        int ans = 0, res = 0;
        for(auto &i : v) {
            if (i == ans) ans++;
            else if (i == res) res++; 
        }
        cout << ans + res << '\n';
    }
    return 0;
}