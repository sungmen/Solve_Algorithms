#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <cmath>
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
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fast
    int c;
    for(cin>>c;c--;){
        int n;
        cin >> n;
        int min_ = 1e9;
        int max_ = -1e9;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            min_ = min(min_, a);
            max_ = max(max_, a);
        }
        int t;
        cin >> t;
        if (max_ >= t && min_ <= t)
            cout << "YES" << '\n';
        else
            cout << "NO" << '\n';
        
    }
}