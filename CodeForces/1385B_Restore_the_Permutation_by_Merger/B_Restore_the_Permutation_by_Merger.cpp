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

// Reference https://www.python2.net/questions-129871.htm 
template<typename t>
t remove_v (t first, t last)
{
    auto new_l = first;
    for (auto cur = first; cur != last; ++ cur)
    {
        if (find(first, new_l, *cur) == new_l)
        {
            if (new_l != cur) 
                *new_l = *cur;
            ++new_l;
        }
    }
    return new_l;
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vector<int> v;
        int cnt = 1;
        for (int i = 0; i < 2 * n; i++)
        {
            int number;
            cin >> number;
            v.emplace_back(number);
        }
        v.erase(remove_v(v.begin(), v.end()),v.end());
        
        for(int i = 0; i < v.size(); i++)
        {
            cout << v[i] << " ";
        }
        cout << "\n";
    }

    return 0;
}