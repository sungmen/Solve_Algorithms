#include <vector>
#include <queue>
using namespace std;
int solution(int n, vector<vector<int>> costs) {
    int answer = 0;
    vector<bool> chk(n, false);
    vector<pair<int, int>> v[n];
    for (int i = 0; i < costs.size(); i++) {
        v[costs[i][0]].emplace_back(make_pair(costs[i][2], costs[i][1]));
        v[costs[i][1]].emplace_back(make_pair(costs[i][2], costs[i][0]));
    }
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    pq.push(pair<int, int>(0, 1));
    while(!pq.empty()) {
        pair<int, int> cur = pq.top();
        pq.pop();
        if (chk[cur.second]) continue;
        else chk[cur.second] = true;
        answer += cur.first;
        for (int i = 0; i < v[cur.second].size(); i++) if (!chk[v[cur.second][i].second]) pq.push(v[cur.second][i]);
    }
    return answer;
}