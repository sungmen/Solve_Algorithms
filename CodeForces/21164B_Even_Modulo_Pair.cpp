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
        vector<int> v(n);
        int b_ = 0;
        int c_ = 0;
        for (int i = 0; i < n; i++)
        {
            cin >> v[i];
            if (v[i]%2 == 0 && b_ == 0)
            {
                b_ = v[i];
            }
            else if (v[i]%2 == 0 && b_ != 0 && c_ == 0)
            {
                c_ = v[i];
            }
        }
        if (b_ != 0 && c_ != 0)
        {
            cout << b_ << " " << c_ << "\n";
            continue;
        }
        vector<int> odd;
        bool bo_ = false;
        for (int i = 0; i < n; i++)
        {
            if (v[i]%2 == 0)
            {
                if (odd.empty()) continue;
                for (int j = 0; j < odd.size(); j++)
                {
                    if ( (v[i] % odd[j]) % 2 == 0)
                    {
                        cout << odd[j] << " " << v[i] << "\n";
                        bo_ = true;
                        break;
                    }
                }
                if (bo_) break;
            }
            else
            {
                for (int j = odd.size() - 1; j >= 0; j--)
                {
                    if ( (v[i] % odd[j]) % 2 == 0)
                    {
                        cout << odd[j] << " " << v[i] << "\n";
                        bo_ = true;
                        break;
                    }
                }
                if (bo_) break;
                odd.pb(v[i]);
            }
        }
        if (!bo_)
        {
            cout << -1 << "\n";
        }
    }
}