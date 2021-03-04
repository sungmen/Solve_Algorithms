#include <bits/stdc++.h>
using namespace std;
int main() {
    //freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int x, n; 
    while(cin >> x) {
        cin >> n;
        x *= 1e7;
        vector<int> v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i];
        }
        sort(v.begin(), v.end());
        int l = 0, r = v.size()-1;
        int abs_sum = -1;
        pair<int, int> res = {0, 0};
        while(l < r) {        
            int cur_sum = v[l] + v[r];
            if (cur_sum > x) {
                r--;
            } else if (cur_sum < x) {
                l++;
            } else if (cur_sum == x) {
                if (abs_sum < abs(v[l]-v[r])) {
                    res = {v[l], v[r]};
                    abs_sum = abs(v[l]-v[r]);
                }
                r--;
            }
        }
        if (abs_sum == -1) {
            cout << "danger\n";
        } else {
            cout << "yes " << res.first << " " << res.second << '\n';
        }
    }
    return 0;
}