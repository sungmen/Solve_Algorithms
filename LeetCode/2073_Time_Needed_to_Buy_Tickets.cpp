class Solution {
public:
  int timeRequiredToBuy(vector<int> &tickets, int k) {
    int cur = tickets[k];
    int n = tickets.size();
    int ans = cur;
    for (int i = 0; i < k; i++) {
      ans += min(tickets[i], cur);
    }
    for (int i = k + 1; i < n; i++) {
      ans += min(tickets[i], cur - 1);
    }
    return ans;
  }
};
