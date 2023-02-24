class Solution 
{
public:
    int minimumDeviation(vector<int>& nums) 
    {
        priority_queue<int> pq;
        int nMin = INT_MAX;
        int ans = INT_MAX;
        for (auto n : nums)
        {
            int tmp = (n%2?n*2:n);
            nMin = min(nMin, tmp);
            pq.push(tmp);
        }
        while (!pq.empty())
        {
            int cur = pq.top();
            pq.pop();
            ans = min(ans, cur - nMin);
            if (cur % 2) return ans;
            cur /= 2;
            nMin = min(nMin, cur);
            pq.push(cur);
        }
        return ans;
    }
};