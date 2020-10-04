#include <bits/stdc++.h>
using namespace std;
const int INF = 1e8;
int solution(int n, vector<vector<int>> edge) {
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int d[n+1];
    for (int i = 1; i <= n; i++) d[i] = INF;
    vector<pair<int, int> > v[n+1];
    for (int i = 0; i < edge.size(); i++) {
        v[edge[i][0]].emplace_back(edge[i][1], 1);
        v[edge[i][1]].emplace_back(edge[i][0], 1);
    }
    d[1] = 0;
    priority_queue<pair<int, int> > pq;
    pq.push(make_pair(1, 0));
    while (!pq.empty()) {
        int cur = pq.top().first;
        int dis = -pq.top().second;
        pq.pop();
        if (d[cur] < dis) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nextDis = dis + v[cur][i].second;
            if (nextDis < d[next]) {
                d[next] = nextDis;
                pq.push(make_pair(next, -nextDis));
            }
        }
    }
    int mx = 0;
    int answer = 0;
    for (int i = 2; i <= n; i++) {
        if (mx < d[i]) {
            answer = 1;
            mx = d[i];
        }
        else if (mx == d[i]) {
            answer++;
        }
    }
    return answer;
}