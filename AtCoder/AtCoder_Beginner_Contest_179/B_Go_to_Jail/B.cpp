#include <bits/stdc++.h>
using namespace std;

int main() {
    // freopen("input.txt", "r", stdin);
    int n; cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) {
        int a, b; cin>> a >> b;
        if(a == b) {
            v[i] = 1;
        } else { 
            v[i] = 0;
        }
    }
    int cnt =0 ;
    for (int i = 0; i < n; i++ ){
        if(v[i]) {
            cnt++;
        } else {
            cnt = 0;
        }
        if (cnt  == 3) {
            cout << "Yes";
            return 0;
        }
    }
    cout << "No";
    return 0;
}