#include <bits/stdc++.h>

using namespace std;
#define ll long long

ll mat(ll a, ll b) {
    ll res = ceil(sqrt((a*a)+(b*b)));
    return res;
}

int main() {
    int n;
    int d;
    cin >> n >> d;
    vector<pair<ll, ll>> v(n);
    for (int i = 0; i<n;i++) {
        cin >> v[i].first >> v[i].second;
    }
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        if(d >= mat(v[i].first, v[i].second)) {
            cnt++;
        }
    }
    cout << cnt;
    return 0;
}
