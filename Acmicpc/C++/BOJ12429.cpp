#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    for (int test_case = 1; test_case <= t; ++test_case) {
        int n, res = 0;
        cin >> n;
        vector<pair<int, int>> v(n);
        for (int t_case = 0; t_case < n; ++t_case) cin >> v[t_case].first >> v[t_case].second;
        sort(v.begin(), v.end());
        do {
            int sum = 0;
            for (auto i : v) {
                if (i.first >= sum) {
                    sum += i.second;
                } else break;
            }
            res = sum > res ? sum : res;
        } while(next_permutation(v.begin(), v.end()));
        cout << "Case #" << test_case << ": " << res << '\n';
    }

    return 0;    
}