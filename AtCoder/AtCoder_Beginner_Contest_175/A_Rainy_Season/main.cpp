#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string str;
    cin >> str;
    int r = 0;
    int sum = 0;
    vector<int> j;
    for (int i = 0; i < str.size();i++) {
        if(str[i] == 'R') {
            r++;
        } else {
            sum=max(sum,r);
            r = 0;
        }
    }
    sum = max(sum,r);
    cout << sum;
}