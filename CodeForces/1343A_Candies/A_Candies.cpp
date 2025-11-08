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
        ll n;
        cin >> n;
        int k = 2;
        int cnt = 3;
        while(1) {
            
            if (!(n%cnt))
            {
                cout << n/cnt << "\n";
                break;
            }
            cnt += int(pow(2, k++));
        }
    }

    return 0;
}