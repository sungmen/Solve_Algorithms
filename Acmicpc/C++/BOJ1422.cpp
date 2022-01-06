#include <bits/stdc++.h>
using namespace std;
bool comp(string a, string b) {
    return a + b > b + a;
}
int main() {
    //freopen("input.in", "r", stdin);
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int k, n; cin >> k >> n;
    string str, back = "", answer = "";
    vector<string> v;
    for (int i = 0; i < k; ++i) {
        cin >> str;
        if (str.size() > back.size() || (str.size() == back.size() && str > back)) back = str;
        v.push_back(str);
    }
    for (int i = k; i < n; ++i) v.push_back(back);
    sort(v.begin(), v.end(), comp);
    for (auto s : v) {
        answer += s;
    }
    cout << answer;
    return 0;
}
