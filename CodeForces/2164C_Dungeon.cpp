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
bool cmp(pair<int, int> a, pair<int, int> b)
{
    if (a.second == 0 || b.second == 0)
    {
        if (a.second == b.second)
        {
            return a.first < b.first;
        }
        return a.second < b.second;
    }
    if (a.first == b.first)
    {
        return a.second < b.second;
    }
    return a.first > b.first;
}
int main() {
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    fast
    int t;
    for(cin>>t;t--;){
        int n, m;
        cin >> n >> m;
        vector<int> a(n);
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        vector<pair<int, int>> b(m);
        for (int i = 0; i < m; i++)
        {
            cin >> b[i].first;
        }
        for (int i = 0; i < m; i++)
        {
            cin >> b[i].second;
        }
        sort(b.begin(), b.end(), cmp);
        int sum = 0;
        int usingIndex = a.size() - 1;
        multiset<int> ms(a.begin(), a.end());
        for (int i = b.size() - 1; i >= 0; i--)
        {
            if (b[i].second == 0)
            {
                auto it = ms.lower_bound(b[i].first);
                if (it != ms.end())
                {
                    ms.erase(it);
                    sum++;
                }
                continue;
            }
            for (int j = 0; j < a.size(); j++)
            {
                auto it = ms.lower_bound(b[i].first);
                if (it == ms.end()) break;
                int sword = *it;
                ms.erase(it);
                ms.insert(max(sword, b[i].second));
                sum++;
                break;
            }
      
        }
    
        cout << sum << "\n";
    }
}