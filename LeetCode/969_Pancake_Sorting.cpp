class Solution 
{
public:
    vector<int> pancakeSort(vector<int>& arr) 
    {
        vector<int> comp = arr;
        sort(comp.begin(), comp.end());
        vector<int> res;
        for (int idx = comp.size() - 1; idx >= 0; idx--)
        {
            int curMax = comp[idx];
            int it = 0;
            for (int j = 0; j <= idx; j++)
            {
                if (curMax == arr[j])
                {
                    it = j;
                    break;
                }
            }
            if (it != idx)
            {
                res.push_back(it + 1);
                res.push_back(idx + 1);
                reverse(arr.begin(), arr.begin() + it + 1);
                reverse(arr.begin(), arr.begin() + idx + 1);
            }
        }
        return res;
    }
};