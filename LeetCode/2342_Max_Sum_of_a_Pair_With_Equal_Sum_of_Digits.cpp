class Solution 
{
public:
    int maximumSum(vector<int>& nums) 
    {
        map<int, priority_queue<int>> m;
        for (auto num : nums)
        {
            int num_tmp = num;
            int val = 0;
            while(num_tmp) 
            {
                val += num_tmp % 10;
                num_tmp /= 10;
            }
            m[val].push(num);
        }
        int res = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            int tmp = 0;
            if (it->second.size() > 1)
            {
                tmp += it->second.top();
                it->second.pop();
                tmp += it->second.top();
            }
            res = max(res, tmp);
        }
        return (0 == res ? -1 : res);
    }
};