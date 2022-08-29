class Solution 
{
public:
    struct cmp
    {
        constexpr bool operator()(pair<int, string> const& a, pair<int, string> const& b) const noexcept
        {
            if (a.first < b.first)
            {
                return a.first < b.first;
            }
            else if (a.first == b.first)
            {
                return a.second > b.second;
            }
            return a.first < b.first;
        }
    };
    
    vector<string> topKFrequent(vector<string>& words, int k) 
    {
        map<string, int> m;
        for (auto word : words)
        {
            m[word] ++;
        }
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, cmp> pq;
        
        for (auto it = m.begin(); it != m.end(); it++)
        {
            pq.push({it->second, it->first});
        }
        
        vector<string> result;
        
        while (!pq.empty() && k--)
        {
            result.push_back(pq.top().second);
            pq.pop();
        }
        
        return result;
    }
};