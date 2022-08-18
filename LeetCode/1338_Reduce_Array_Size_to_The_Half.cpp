class Solution 
{
public:
    int minSetSize(vector<int>& arr) 
    {
        int halfsize = arr.size() / 2;
        unordered_map<int, int> um;
        priority_queue<int> pq;
        int res = 0, sum = 0;
        
        for (auto i : arr)
        {
            um[i]++;
        }
        
        for (auto m : um)
        {
            pq.push(m.second);
        }
        
        while (!pq.empty())
        {
            sum += pq.top();
            pq.pop();
            res++;
            if (sum >= halfsize) break;
        }
        
        return res;
    }
};