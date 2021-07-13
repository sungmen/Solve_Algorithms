#include <bits/stdc++.h>
using namespace std;
int kmp(string t) {
    int i = 1, j = 0, res = 0; 
    vector<int> arr(t.size(), 0);
    for (i = 1; i < t.size(); i++) {
        while(j > 0 && t[i] != t[j]) {
            j = arr[j-1];
        }
        if (t[i] == t[j]) {
            res = max(res, arr[i] = ++j);
        }
    }
    return res;
}
int main() {
    // freopen("input.txt", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    string str; cin >> str;
    int res = 0;
    for (int i = 0; i < str.size(); i++) {
        res = max(res, kmp(str.substr(i)));
    }
    cout << res;
    return 0;
}