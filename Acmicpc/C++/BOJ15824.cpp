#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1e9+7;
ll dp_pow[300001];
int main() {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int n;cin>>n;
    vector<int> v(n);
    for(int i =0; i<n;i ++) cin >> v[i];
    sort(v.begin(), v.end());
    dp_pow[0] = 1;
    for (int i = 1; i < 300001; i++) dp_pow[i] = dp_pow[i-1] * 2 % MOD;
    ll sum = 0;
    for(int i = 0; i < n; i++) {
        sum = (sum +( dp_pow[i] - dp_pow[n-1-i] + MOD) % MOD * v[i])%MOD;
    }
    cout << sum;
    return 0;
}