#include <bits/stdc++.h>
using namespace std;
#define ll long long
const ll MOD = 1000000007;
ll dp[4000001];
ll fac(ll n, ll k) {
    k = k - 2;
    ll ret = 1;
    while (k) {
        if (k % 2) {
            ret *= n;
            ret %= MOD;
        }
        n = (n*n) % MOD;
        k >>= 1;
    }
    return ret;
}
int main(){
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    dp[0] = 1;
    for (int i = 1; i <= 4000000; i++) dp[i] = (dp[i-1] * i) % MOD;
    int m;
    for(cin>>m;m--;) {
        ll n, k; cin >> n >> k;
        cout << ((dp[n] * fac(dp[k], MOD)) % MOD)*fac(dp[n-k], MOD) % MOD << '\n';
    }
    return 0;
}