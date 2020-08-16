#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int c;
    for(cin>>c;c--;){
         int n;
        cin >> n;
        vector<long long> v(n);
        set<long long> s;
        for(int i= 0; i < n; i ++) {
            cin >> v[i];
            s.insert(v[i]);
        }
        if(s.size() != 1)  {
            cout << 1 << '\n';
        } else {
            cout << n << '\n';
        }
    }
}