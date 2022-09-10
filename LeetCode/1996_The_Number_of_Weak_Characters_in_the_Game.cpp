class Solution 
{
public:
    int numberOfWeakCharacters(vector<vector<int>>& properties) 
    {
        priority_queue<pair<int, int>> pq;
        for (auto proper : properties)
        {
            pq.push({proper[0], proper[1]});
        }
        int pq_second = 0, tmp_back = 0;
        int p = pq.top().first;
        int s = pq.top().second;
        pq.pop();
        int cnt = 0;
        while (!pq.empty())
        {
            int p_ = pq.top().first;
            int s_ = pq.top().second;
            pq.pop();
            if (p_ != p)
            {
                pq_second = max(pq_second, max(tmp_back, s));
            }
            tmp_back = max(tmp_back, s);
            p = p_;
            s = s_;
            if (pq_second > s_)
            {
                cnt++;
            }
        }
        
        return cnt;
    }
}; 