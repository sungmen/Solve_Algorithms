#include <bits/stdc++.h>
using namespace std;

int main(){
    long long a, b, c, d; cin >> a >> b >> c >> d;
    if(b >= c && d >= a) {
        cout << "Yes";
    } else {
        cout << "No";
    }
    return 0;
}