#include <bits/stdc++.h>
using namespace std;
const int MAX = 2e5+1;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n, w; cin >> n >> w;
    vector<long long> s(n), t(n), p(n), ans(MAX, 0);
    for (int i = 0; i < n; i++) cin >> s[i] >> t[i] >> p[i];
    for (int i = 0; i < n; i++) {
        ans[s[i]] += p[i];
        ans[t[i]] -= p[i];
    }
    long long result = 0;
    for (auto i : ans) {
        result += i;
        if (result > w) {
            cout << "No";
            return 0;
        }
    }
    cout << "Yes";
    return 0;
}