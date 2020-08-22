#include <bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    string n;cin >> n;
    unsigned long long sum = 0;
    for(int i = 0; i < n.size(); i++)sum += int(n[i]-'0');
    if(!(sum % 9)) cout << "Yes";
    else cout << "No";
}