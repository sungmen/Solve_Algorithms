#include <bits/stdc++.h>
using namespace std;
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int t; cin >> t;
    vector<int> v;
    for (int i = 1; i <= 9; i++) v.push_back(i);
    for (int i = 11; i <= 99; i+=11) v.push_back(i);
    for (int i = 111; i <= 999; i+=111) v.push_back(i);
    for (int i = 1111; i <= 9999; i+=1111) v.push_back(i);
    for (int i = 11111; i <= 99999; i+=11111) v.push_back(i);
    for (int i = 111111; i <= 999999; i+=111111) v.push_back(i);
    for (int i = 1111111; i <= 9999999; i+=1111111) v.push_back(i);
    for (int i = 11111111; i <= 99999999; i+=11111111) v.push_back(i);
    for (int i = 111111111; i <= 999999999; i+=111111111) v.push_back(i);
    sort(v.begin(), v.end());
    while(t--) {
        vector<int>::iterator up;
        int n; cin >> n;
        up = upper_bound(v.begin(), v.end(), n);
        cout << (up-v.begin()) << '\n';
    }
    return 0;
}