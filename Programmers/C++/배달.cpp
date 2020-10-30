#include <bits/stdc++.h>
using namespace std;
const int INF = INT_MAX;
int solution(int N, vector<vector<int> > road, int K) {
    int answer = 0;
    vector<pair<int, int>> v[N+1];
    int d[N+1];
    for(int i = 1; i <=N; i++) d[i] =INF;
    for (int i = 0; i < road.size(); i++) {
        int a = road[i][0], b = road[i][1], c = road[i][2];
        v[a].emplace_back(b, c);
        v[b].emplace_back(a, c);
    }
    d[1] = 0;
    priority_queue<pair<int, int>> pq;
    pq.push(make_pair(1, 0));
    while(!pq.empty()) {
        int cur = pq.top().first;
        int dis = -pq.top().second;
        pq.pop();
        if (d[cur] < dis) continue;
        for (int i = 0; i < v[cur].size(); i++) {
            int next = v[cur][i].first;
            int nextDis = dis+v[cur][i].second;
            if (nextDis < d[next]) {
                d[next] = nextDis;
                pq.push(make_pair(next, -nextDis));
            }
        }
    }
    for(int i = 1; i <= N; i++) if (d[i] <= K) answer++;
    return answer;
}