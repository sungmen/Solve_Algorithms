#include <queue>
#include <vector>
using namespace std;
int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    priority_queue<int, vector<int>, less<int>> pq;
    int answer = 0, idx = 0, i = 0;
    while(k > i){
        if (dates[idx] == i++) {
            pq.push(supplies[idx]);
            idx++;
        }
        if (!stock) {
            stock = pq.top(); pq.pop();
            ++answer;
        }
        --stock;
    }
    return answer;
}