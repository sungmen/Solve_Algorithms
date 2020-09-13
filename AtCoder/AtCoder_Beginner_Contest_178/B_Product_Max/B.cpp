#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define fast ios_base::sync_with_stdio(false),cin.tie(nullptr),cout.tie(nullptr);
int main() {
    fast
    ll a, b, x, y;
    cin >>a >> b >> x >> y;
    ll n1 = b*x, n2 = b*y, n3 =a*y, n4 = a*x;
    cout << max(max(n1,n2),max(n3,n4));
}