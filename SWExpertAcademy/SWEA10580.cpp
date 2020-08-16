#include <bits/stdc++.h>
using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
    return (a.second > b.second);
}

int main() {
    ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);
    int c;
    cin >> c;
    for(int t = 1; t <= c; t++){
        int n;
        cin >> n;
        vector<pair<int ,int>>v(n);
        for (int i = 0; i < n; i++) {
            cin >> v[i].first >> v[i].second;
        }
        sort(v.begin(),v.end(), cmp);
        int cnt = 0;
        for(int i = 0 ; i < n-1; i++) {
            for(int j = i+1; j < n; j++) {
                if(v[i].first < v[j].first) {
                    cnt++;
                }
            }
        }
        cout << '#' << t << ' ' << cnt << '\n';
    }
}