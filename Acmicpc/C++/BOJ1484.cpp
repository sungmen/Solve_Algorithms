#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    long long w; cin >> w;
    long long dp[50001], tmp = 5;
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 4;
    for (int i = 3; i <= 50000; i++) {
        dp[i] = dp[i-1] + tmp;
        tmp += 2;
    }
    long long l = 1, r = 2;
    vector <long long> ans;
    bool chk = false;
    while (l<r) {
        long long curr_sum = dp[r] - dp[l];
        if (curr_sum > w) {
            l++;
        } else if (curr_sum < w) {
            r++;
        } else {
            cout << r << '\n';
            chk = true;
            r++;
        }
    }
    if (!chk) {
        cout << -1;
    } 
    return 0;
}