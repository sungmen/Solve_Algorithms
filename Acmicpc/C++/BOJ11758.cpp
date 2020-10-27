#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int x1,y1,x2,y2,x3,y3;cin>>x1>>y1>>x2>>y2>>x3>>y3;
    int s=(x2-x1)*(y3-y1)-(y2-y1)*(x3-x1);
    cout << (s>0?1:s<0?-1:0);
}