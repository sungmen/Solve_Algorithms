#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int c;
    for(cin>>c;c--;){
        int n;
        long long k;
        cin >> n >> k;
        vector<long long> v(n);
        for (int i = 0 ; i < n; i++) cin >> v[i];
        auto max_val = *max_element(v.begin(), v.end());
        if(k % 2) {
            for_each(v.begin(), v.end(), [max_val](auto& x) {x = max_val - x;});
        } else {
            for_each(v.begin(), v.end(), [max_val](auto& x) {x = max_val - x;});
            auto max_val = *max_element(v.begin(), v.end());
            for_each(v.begin(), v.end(), [max_val](auto& x) {x = max_val - x;});
        }
        for(auto i : v) cout << i << ' ';
        cout << '\n';
    }
}