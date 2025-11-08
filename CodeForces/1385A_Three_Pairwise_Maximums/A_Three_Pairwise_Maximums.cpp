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

    int t;
    cin >> t;
    while(t--)
    {
        ll x, y, z;
        cin >> x >> y >> z;
        vector<int> v(3);
        v[0]=x;
        v[1]=y;
        v[2]=z;
        sort(v.begin(), v.end());
        
        if(v[1]==v[2])
        {
            v[1]= v[0];
        }

        int chk = 1;
        do {
            if(x==max(v[0], v[1]) && y==max(v[1],v[2]) && z==max(v[0], v[2]))
            {
                cout << "YES\n" << v[0] << " " << v[1] << " " << v[2] << "\n";
                chk = 0;
                break;
            }
        }while(next_permutation(v.begin(), v.end()));
        if(chk)
        {
            cout << "NO\n";
        }
    }

    return 0;
}