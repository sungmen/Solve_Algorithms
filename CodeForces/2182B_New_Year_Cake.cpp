#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define endl "\n"
#define ll long long

vector<ll> v(22, 0);

void sol()
{
    ll a, b;
    cin >> a >> b;
    v[0] = 0;
    v[1] = (1<<0);
    for (ll i = 2; i < 22; i++)
    {
        v[i] = v[i-2] + (1<<i-1);
    }
    if (a < b)
    {
        swap(a, b);
    }
    ll ans = 0;
    for (ll i = 21; i >= 1; i--)
    {
        if (a >= v[i] && b >= v[i-1])
        {
            ans = i;
            break;
        }
    }
    cout << ans << endl;
}

int main() {
    fast
    int tc;
    for(cin>>tc; tc--;)
    {
        sol();
    }
}