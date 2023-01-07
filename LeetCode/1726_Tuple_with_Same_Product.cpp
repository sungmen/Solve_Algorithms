class Solution {
public:
    int tupleSameProduct(vector<int>& nums) {
        int res = 0;
        map<int, int> m;
        for (int i = 0; i < nums.size() - 1; i++)
        {
            for (int j = i + 1; j < nums.size(); j++)
            {
                m[nums[i]*nums[j]]++;
            }
        }
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second < 2)
                continue;
            int m = it->second;
            int dsum = (m * (m - 1)) / 2;
            res += dsum * 8;
        }
        return res;
    }
};