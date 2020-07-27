#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <set>
#include <stack>
#define endl    '\n'
using namespace std;
typedef long long ll;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int n;
    cin >> n;
    vector<ll> v(n);
    for(int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
    ll ans = 1000;
    ll i = 0;
    for (i = 0; i + 1 < n; ++i)
    {
        if(v[i] < v[i+1])
        {
            ll m = ans / v[i];
            ans -= m * v[i];
            ans += m * v[i+1];
        }
    }
    cout << ans;

    return 0;
}
