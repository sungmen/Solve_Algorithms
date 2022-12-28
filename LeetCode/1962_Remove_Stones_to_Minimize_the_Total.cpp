class Solution 
{
public:
    int minStoneSum(vector<int>& piles, int k) 
    {
        priority_queue<int> pq;
        for (auto pile : piles)
        {
            pq.push(pile);
        }
        for (int i = 0; i < k; i++)
        {
            int cur = pq.top();
            pq.pop();
            pq.push(cur - cur / 2);
        }
        int res = 0;
        while (! pq.empty())
        {
            res += pq.top();
            pq.pop();
        }
        return res;
    }
};