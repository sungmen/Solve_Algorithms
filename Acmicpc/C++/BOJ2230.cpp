#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long n, m; cin >> n >> m;
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    long long res = INT_MAX;
    int l = 0, r = 0;
    sort(a.begin(), a.end());
    while(l <= r) {
        long long curr_sub = a[r] - a[l];
        if (curr_sub < m) {
            r++;
        } else if (curr_sub >= m) {
            if (res > curr_sub) {
                res = curr_sub;
            }
            l++;
        }
        if (r >= n || l >= n || curr_sub == m) {
            break;
        }
    }
    cout << res;
    return 0;
}