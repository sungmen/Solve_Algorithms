class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        cardPoints.insert(cardPoints.begin(), 0);
        int n = cardPoints.size();
        for (int i = 1; i < n; i++)
            cardPoints[i] += cardPoints[i-1];
        int res = 0;
        int p = k;
        for (int i = n - 1; i >= n-k-1; i--)
        {
            int t = cardPoints[n-1]-cardPoints[i] + cardPoints[p--];
            res = max(res, t);
        }
        return res;
    }
};