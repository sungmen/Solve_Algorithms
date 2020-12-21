/*
	Runtime: 8 ms, faster than 94.57% of C++ online submissions for Best Time to Buy and Sell Stock.
	Memory Usage: 13.2 MB, less than 84.45% of C++ online submissions for Best Time to Buy and Sell Stock.
*/

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.size() <= 1) return 0;
        int max_value = 0;
        int l = 0, r;
        for (int r = 1; r < prices.size(); r++) {
            if (prices[l] < prices[r] && max_value < prices[r] - prices[l]) max_value = prices[r] - prices[l];
            if (prices[r] < prices[l]) l = r;
        }
        return max_value;
    }
};
