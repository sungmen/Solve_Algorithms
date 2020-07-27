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

    int x;
    cin >> x;

    if(x >= 1800)
        cout << 1 << "\n";
    else if(x >= 1600)
        cout << 2 << "\n";
    else if(x >= 1400)
        cout << 3 << "\n";
    else if(x >= 1200)
        cout << 4 << "\n";
    else if(x >= 1000)
        cout << 5 << "\n";
    else if(x >= 800)
        cout << 6 << "\n";
    else if(x >= 600)
        cout << 7 << "\n";
    else if(x >= 400)
        cout << 8 << "\n";

    return 0;
}
