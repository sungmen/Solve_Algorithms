#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    ll t;cin>>t;
    ll n; cin >> n; vector<ll> v(n);  
    for(int i = 0; i < n; i++) cin >> v[i];
    ll n2; cin >> n2; vector<ll> v2(n2);
    for(int i = 0; i < n2; i++) cin >> v2[i];
    map<ll, ll> res;
    for (int i = 0; i < n; i++) {
        ll tmp = 0;
        for (int j = i; j < n; j++) {
            tmp += v[j];
            res[tmp]++;
        }
    }
    ll ans = 0;
    for (int i = 0; i < n2; i++) {
        ll tmp = t;
        for (int j = i; j < n2; j++) {
            tmp -= v2[j];
            ans += res[tmp];
        }
    }
    cout << ans;
    return 0;
}