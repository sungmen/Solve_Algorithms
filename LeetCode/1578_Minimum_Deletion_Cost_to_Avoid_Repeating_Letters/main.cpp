class Solution {
public:
    int minCost(string s, vector<int>& cost) {
        char chr = s[0];
        int cur = 1, res = 0, tmp = cost[0];
        while (cur < cost.size()) {
            if (s[cur] == chr) {
                res += min(tmp, cost[cur]);
                tmp = max(tmp, cost[cur]);
            } else {
                tmp = cost[cur];
            }
            chr = s[cur++];
        }
        return res;
    }
};