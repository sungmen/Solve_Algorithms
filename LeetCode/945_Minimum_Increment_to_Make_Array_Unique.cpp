class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        map<int, int> m;
        int n = nums[0];
        vector<int> tmp;
        for (auto num : nums)
        {
            if (m.find(num) == m.end())
                m[num] = 1;
            else
                tmp.push_back(num);
        }
        if (tmp.size() == 0)
            return 0;
        n = tmp[0];
        int res = 0;
        for (auto u : tmp)
        {
            if (n < u)
                n = u;
            while (m.find(n) != m.end())
            {
                n++;
            }
            m[n] = 1;
            res += (n - u);
        }
        return res;
    }
};