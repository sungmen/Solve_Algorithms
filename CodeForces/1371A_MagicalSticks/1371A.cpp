#include <iostream>
#include <cstdio>
#include <algorithm>
#include <queue>
#include <cmath>
#include <cstring>
#include <vector>
#include <map>
#include <stack>
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
        ll n;
        cin >> n;
        if(n%2)
        {
            n+=1;
            cout << n / 2 << "\n";
        }
        else
        {
            cout << n / 2 << "\n";
        }

    }

    return 0;
}