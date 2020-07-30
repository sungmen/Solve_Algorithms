#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> v(n+1);
    v[0] = v[1] = 0;
    for(int i = 2; i <= n; i++) {
        v[i] = v[i-1] + 1;
        if(i % 2 == 0 && v[i] > v[i/2] + 1) {
            v[i] = v[i/2] + 1;
        }
        if(i%3 == 0 && v[i] > v[i/3] + 1) {
            v[i] = v[i/3] + 1;
        }
    }
    cout << v[n] << "\n"; 
    string s = "";
    int cnt = 0;
    while(n > 0) {
        s += to_string(n);
        s += " ";
        if(n % 3 == 0 && v[n] == v[n/3] + 1) {
            n /= 3;
        } else if (n % 2 == 0 && v[n] == v[n/2] + 1) {
            n /= 2;
        } else if (n - 1 >= 0) {
            n -= 1;
        }
    }
    cout << s;
    return 0;
}