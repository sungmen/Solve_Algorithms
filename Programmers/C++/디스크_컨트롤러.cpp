#include <bits/stdc++.h>
using namespace std;
int solution(vector<vector<int>> jobs) {
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    sort(jobs.begin(), jobs.end());
    int answer = 0, i = 0, t = 0;
    while(i < jobs.size() || !pq.empty()) {
        while (i < jobs.size() && jobs[i][0] <= t) pq.push({jobs[i][1], jobs[i++][0]});
        if (pq.empty()) t = jobs[i][0];
        else {
            pair<int, int> p = pq.top();
            pq.pop();
            answer += t - p.second + p.first;
            t += p.first;
        }
    }
    return answer / jobs.size();
}