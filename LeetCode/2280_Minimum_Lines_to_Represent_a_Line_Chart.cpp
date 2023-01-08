class Solution {
public:
    bool comp(vector<int>& a, vector<int>& b)
    {
        return a[0] < b[0];
    }
    int minimumLines(vector<vector<int>>& stockPrices) {
        int result = 0;

        sort(stockPrices.begin(), stockPrices.end());
        long double back = DBL_MAX;
        for (int i = 0; i < stockPrices.size() - 1; i++)
        {
            long double ret = (long double)(stockPrices[i+1][1] - stockPrices[i][1]) / (long double)(stockPrices[i+1][0] - stockPrices[i][0]);
            if (ret != back)
            {
                back = ret;
                ++result;
            }
        }

        return result;
    }
};