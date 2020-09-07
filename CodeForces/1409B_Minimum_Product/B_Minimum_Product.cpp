#include <bits/stdc++.h>
using namespace std;
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
#define ll long long
#define ul unsigned long long
#define lb(x) lower_bound(x)
#define ub(x) upper_bound(x)
#define mp make_pair
#define pb push_back
#define ppb pop_back
#define endl "\n"
#define in(x) insert(x)
#define sz(x) (int)x.size()
#define loop(x,n) for(int x = 0; x < n; ++x)
#define rep(x,y,z) for(int x=y;x<=z;x++)
#define per(x,y,z) for(int x=y;x>=z;x--)
#define all(x) x.begin(),x.end()
int main() {
    fast
    int t;
    for(cin>>t;t--;){
        ll a, b, x, y, n; cin >> a >> b >> x >> y >> n;
        if(max(a-n, x) < max(b-n, y)) {
            ll tmp = max(a-n, x);
            tmp = n - (a - tmp);
            cout << max(a-n, x) * max(b-tmp, y) << '\n';
        } else {
            ll tmp = max(b-n, y);
            tmp = n - (b - tmp);
            cout << max(a-tmp, x) * max(b-n, y) << '\n'; 
        }
    }
}