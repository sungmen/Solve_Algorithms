#include <bits/stdc++.h>
using namespace std;
bool comp (pair<int,int> &a, pair<int,int> &b) {
    if (a.second != b.second) return a.second < b.second;
    return a.first < b.first;
}
int main() {
    // freopen("input.txt", "r", stdin);
    vector<pair<int,int>> v;
    int n;
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        int h, o;
        scanf("%d%d",&h,&o);
        if(o > h) v.push_back({h,o});
        else v.push_back({o,h});
    }
    int d;
    scanf("%d", &d);
    sort(v.begin(), v.end(), comp);
    int cnt = 0;
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;
    for (int i = 0; i < n; i++) {
        if (v[i].second-v[i].first>d) continue;
        else q.push(v[i]);
        while(!q.empty() && q.top().first < v[i].second - d) q.pop();
        if (cnt < q.size()) cnt = q.size();
    }
    printf("%d", cnt);
    return 0;
}