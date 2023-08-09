class Solution 
{
public:
    int findTheDistanceValue(vector<int>& arr1, vector<int>& arr2, int d) 
    {
        unordered_map<int, int> um;
        for (auto it : arr2)    um[it]++;
        int ans = 0;
        for (auto it : arr1)
        {
            bool chk = 1;
            for (int i = d; i >= 0; i--)
            {
                if (um.find(it+i) != um.end()) 
                {
                    chk = 0;
                }
                else if (um.find(it-i) != um.end())
                {
                    chk = 0;
                }
            }
            if (chk) ans++;
        }
        

        return ans;
    }
};