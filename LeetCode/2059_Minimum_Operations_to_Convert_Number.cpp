class Solution 
{
public:
    int minimumOperations(vector<int>& nums, int start, int goal) 
    {
        int answer = 0;
        unordered_map<int, int> um;
        queue<int> q;
        q.push(start);
        while (!q.empty())
        {
            int si = q.size();
            while(si--)
            {
                int cur = q.front();
                q.pop();
                if (cur == goal) return answer;
                if (cur < 0 || cur > 1000 || um.find(cur)!=um.end())continue;
                um[cur]=1;
                for (auto i : nums)
                {
                    q.push(cur+i);
                    q.push(cur-i);
                    q.push(cur^i);
                }
            }
            answer++;
        }

        return -1;    
    }
};
