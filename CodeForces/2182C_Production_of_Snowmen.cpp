#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define endl "\n"
#define ll long long

ll count_snowman(vector<ll> &a, vector<ll> &b, const ll &n)
{
    ll res = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[0] >= b[i])
            continue;
        bool bCount = true;
        for (int j = 0; j < n; j++)
        {
            if (a[j] >= b[(i+j)%n])
            {
                bCount = false;
                break;
            }
        }   
        if (bCount)
            res++;
    }
    return res;
}

void sol()
{
    ll n;
    cin >> n;
    vector<ll> a(n), b(n), c(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0; i < n; i++)
        cin >> b[i];
    for (int i = 0; i < n; i++)
        cin >> c[i];

    ll ans = n * count_snowman(a, b, n) * count_snowman(b, c, n);
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