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
        int a, b;
        cin >> a >> b;
        int c = abs(a-b);
        int ans = c / 10;
        if(c%10) {
            ans += 1;
        }
        cout << ans << '\n';
    }
}