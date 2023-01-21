class Solution 
{
public:
    int longestSubsequence(vector<int>& arr, int difference) 
    {
        vector<int> v(arr.size(), 1);
        int res = 1;
        unordered_map<int, map<int, int>> um;
        for (int i = 0; i < arr.size(); i++)
        {
            if (um.find(arr[i] - difference) != um.end())
            {
                int n = -(um[arr[i]-difference].begin()->first);
                v[i] += n;
                if (v[i] > res)
                    res = v[i];
            }
            um[arr[i]][-v[i]] = 1;
        }
        return res;
    }
};