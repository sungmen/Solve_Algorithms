class Solution {
public:
  struct th {
    double t;
    int i;
    int j;
  };
  struct compare {
    bool operator()(th &a, th &b) {
      if (a.t != b.t) {
        return a.t > b.t;
      }
      if (a.i > b.i)
        return a.i > b.i;
      return a.j > b.j;
    }
  };
  vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k) {
    priority_queue<th, vector<th>, compare> pq;
    int n = arr.size();
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
        if (i == j) {
          continue;
        }
        double t = (double)arr[i] / (double)arr[j];
        pq.push({t, i, j});
      }
    }
    k--;
    while (false == pq.empty() && k--) {
      pq.pop();
    }

    return {arr[pq.top().i], arr[pq.top().j]};
  }
};
