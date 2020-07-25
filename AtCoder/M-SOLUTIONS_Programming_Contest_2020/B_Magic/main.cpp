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
    vector<int> v(3);
    int k;
    cin >> v[0] >> v[1] >> v[2] >> k;
    int t = 0;
    int chk = 1;
    for(int i = 0; i < k; i++)
    {
        if(v[0]>= v[1] && v[1] < v[2])
        {
            v[1] *= 2;
        }
        else if (v[1] >= v[2])
        {
            v[2] *= 2;
        }
    }
    if(v[0] >= v[1] || v[1] >= v[2])
    {
        cout << "No" << "\n";
    }
    else
    {
        cout << "Yes" << "\n";
    }


    return 0;
}
