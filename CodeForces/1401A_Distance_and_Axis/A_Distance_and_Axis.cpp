#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int c;
    for(cin>>c;c--;){
        int a, b;
        cin >> a >> b;
        if(b) {
            if(b > a)
                cout << abs(b - a) << '\n';
            else
                if (abs(b-a) & 1) cout << 1 << '\n';
                else cout << 0 << '\n';
        } else {
            if(a&1) cout << 1 << '\n';
            else cout << 0 << '\n';
        }
    }
}