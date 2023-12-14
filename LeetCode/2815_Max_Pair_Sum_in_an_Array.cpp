class Solution 
{
public:
    int maxSum(vector<int>& nums) 
    {
        vector<map<int, int>> v(10);
        for (auto num : nums)
        {
            string str = to_string(num);
            char ch = '0';
            for (char it : str)
            {
                if (ch < it)
                {
                    ch = it;
                }
            }
            v[ch-'0'][-num]++;
        }
        int ans = -1;
        for (int i = 0; i < 10; i++)
        {
            map<int, int> m = v[i];
            if (m.size() < 1 || (m.size() == 1 && m.begin()->second < 2)) continue;
            auto it = m.begin();
            if (it->second > 1) ans = max(ans, -(it->first * 2));
            else
            {
                auto next = it;
                next++;
                ans = max(ans, -(it->first + next->first));
            }
        }
        return ans; 
    }
};
