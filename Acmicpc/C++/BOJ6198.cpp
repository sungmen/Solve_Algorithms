#include <bits/stdc++.h>
using namespace std;
long long  arr[80001];
int main() {
    // freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n; cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    stack<pair<long long , long long>> stk;
    long long ans = 0;
    stk.push({arr[n - 1], 1});
    for (int i = n - 2; i >= 0; --i) {
        long long  second = 1;
        while (!stk.empty() && arr[i] > stk.top().first) {
            second += stk.top().second;
            ans += stk.top().second;
            stk.pop();
        }
        stk.push({arr[i], second});
    }
    cout << ans;
    return 0;
}