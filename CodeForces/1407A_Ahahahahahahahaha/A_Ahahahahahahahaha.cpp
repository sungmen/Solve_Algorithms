#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t;
    for(cin>>t;t--;) {
        int n; cin >> n;
        vector<int> v;
        for(int i = 0; i < n; i+=2) {
            int t1, t2;cin >> t1 >> t2;
            if(t1 == t2) {
                v.emplace_back(t1);v.emplace_back(t2);
            } else {
                v.emplace_back(0);
            }
        }
        cout << v.size() << '\n';
        for(auto &t : v) cout << t << ' ';
        cout << '\n';
    }
}

