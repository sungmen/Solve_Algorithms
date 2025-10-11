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
        ll a;
        map<ll, ll> m;
        for (int i = 0; i < n; i++)
        {
            cin >> a;
            m[a]++;
        }
        ll sum = 0;
        ll bigger = 0;
        vector<ll> v;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (0 == it->second % 2)
            {
                sum += it->first * it->second;
                bigger = it->first;
            }
            else if (0 != it->second - 1)
            {
                sum += it->first * (it->second - 1);
                v.pb(it->first);
                bigger = it->first;
            }
            else
            {
                v.pb(it->first);
            }
        }
        if (0 == sz(v))
        {
            if (sum - bigger <= bigger)
            {
                cout << 0 << '\n';
            }
            else 
            {
                cout << sum << '\n';
            }
        }
        else if (1 == sz(v))
        {
            if (sum > v[0])
            {
                sum += v[0];
                if (bigger < v[0])
                {
                    bigger = v[0];
                }
            }
            if (sum - bigger <= bigger)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << sum << '\n';
            }
        }
        else if (1 < sz(v))
        {
            int index = sz(v) - 1;
            ll rootB = 0;
            bool bFindB = false;
            bool bFindA = false;
            ll rootAUp = 0;
            ll rootADown = 0;
            while (!bFindA && index >= 0)
            {
                if (!bFindB)
                {
                    if (sum > v[index])
                    {
                        bFindB = true;
                        rootB = v[index];
                    }
                }
                if (index == 0)
                    break;
                ll tmp = v[index];
                ll tmp2 = v[index - 1];
                if (sum + tmp2 > tmp)
                {
                    bFindA = true;
                    rootAUp = tmp;
                    rootADown = tmp2;
                }

                index--;
            }
            if (rootB < rootAUp + rootADown)
            {
                sum += rootAUp + rootADown;
                if (bigger < rootAUp)
                {
                    bigger = rootAUp;
                }
            }
            else
            {
                sum += rootB;
                if (bigger < rootB)
                {
                    bigger = rootB;
                }
            }
            
            if (sum - bigger <= bigger)
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << sum << '\n';
            }
        }
        else 
        {
            cout << 0 << '\n';
        }
    }
}
