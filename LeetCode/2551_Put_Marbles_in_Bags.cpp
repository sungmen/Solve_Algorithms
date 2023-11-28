class Solution {
public:
  long long putMarbles(vector<int> &weights, int k) {
    long long ans = 0;
    int n = weights.size();
    priority_queue<long long> pq, mpq;
    for (int i = 1; i < n; i++) {
      long long tmp = weights[i - 1] + weights[i];
      pq.push(tmp);
      mpq.push(-tmp);
      if (pq.size() >= k) {
        pq.pop();
        mpq.pop();
      }
    }
    while (!pq.empty()) {
      ans -= pq.top() + mpq.top();
      pq.pop();
      mpq.pop();
    }
    return ans;
  }
};
