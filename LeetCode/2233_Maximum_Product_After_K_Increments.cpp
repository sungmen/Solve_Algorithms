class Solution 
{
public:
    const int MOD = 1e9 + 7;

    int maximumProduct(vector<int>& nums, int k) 
    {
        priority_queue<int> pq;
        for (auto n : nums) 
        {
            pq.push(-n);
        }
        while (k--)
        {
            int t= pq.top();
            pq.pop();
            pq.push(t-1);
        }
        long long res = 1;
        while (!pq.empty())
        {
            res *= (-pq.top());
            res %= MOD;
            pq.pop();
        }
        return (int)res;
    }
};