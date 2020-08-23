#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int n;cin>>n;
    int before;
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        if(i==0) {
            before = a;
        } else {
            if(before > a) sum += (before - a);
            else before = a;
        }
    }
    cout << sum;
}