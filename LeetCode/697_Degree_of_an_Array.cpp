class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        unordered_map<int, vector<int>> um;
        for (int i = 0; i < nums.size(); i++)
        {
            um[nums[i]].push_back(i);
        }
        int cnt = 0;
        int res = 0;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second.size() >= cnt)
            {
                if (it->second.size() > cnt)
                {
                    res = (it->second.back()-it->second[0]+1);
                    cnt = it->second.size();
                }
                else
                {
                    res = min(res, it->second.back()-it->second[0]+1);
                }
                cout << res << '\n';
            }
        }
        return res;
    }
};