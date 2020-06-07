#include <vector>
#include <queue>
#include <iostream>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int, vector<int>, greater<int>> pq;
    for (int n : scoville)
        pq.push(n);
    while(pq.top() < K) {
        int f, s;
        if (!pq.empty()) { 
            f = pq.top(); pq.pop();
        } else {
            return -1;
        }
        if (!pq.empty()) {
            s = pq.top(); pq.pop();
        } else {
            return -1;
        }
        pq.push(f + (s * 2));
        answer++;
    }

    return answer;
}