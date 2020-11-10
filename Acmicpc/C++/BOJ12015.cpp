#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    vector<int> v;
    int k;
    for (int i = 0; i < n; i++) {
        cin >> k;
        if (i == 0) v.push_back(k);
        if (v.back() < k) v.push_back(k);
        else {
            auto l = lower_bound(v.begin(), v.end(), k);
            *l = k;
        }
    }    
    cout << v.size();
}