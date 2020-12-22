#include <bits/stdc++.h>
using namespace std;
int main() {
    freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    int64_t k; cin >> k;
    bitset<64> b(k-1);
    vector<int> v;
    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '1' || str[i] == '2' || str[i] == '6' || str[i] == '7') v.emplace_back(i);
    }
    long long pol = (long long) pow(2, v.size());
    if (pol < k || k < 1) {
        cout << -1;
        return 0;
    }
    int t = v.size() - 1;
    for (int i = 0; i < v.size(); i++) {
        if (str[v[t]] == '1' || str[v[t]] == '6') {
            if(b[i] == 0) str[v[t]] = '1';
            else str[v[t]] = '6';
        } else {
            if(b[i] == 0) str[v[t]] = '2';
            else str[v[t]] = '7';
        }
        t--;
    }
    cout << str;
    return 0;
}