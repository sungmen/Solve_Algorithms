class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        vector<int> cost(costs.size(), 0);
        sort(costs.begin(), costs.end());
        cost[0] = costs[0];
        if (cost[0] > coins) return 0;
        int ans = 1;
        for (int i = 1; i < costs.size(); i++) {
            cost[i] += (costs[i] + cost[i-1]);
            if (cost[i] <= coins) {
                ans = 1+i;
            } else {
                break;
            }
        }
        return ans;
    }
};