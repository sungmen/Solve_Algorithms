class Solution 
{
public:
    bool canMakeArithmeticProgression(vector<int>& arr) 
    {
        map<int, int> um;
        for (auto it : arr)
            um[it]++;
        auto itMap = um.begin();
        int f = itMap->first;
        itMap++;
        if (itMap == um.end()) return true;
        int n = itMap->first;
        int d = n - f;
        sort(arr.begin(), arr.end());
        for (int i = 1; i < arr.size(); i++)
        {
            if (arr[i] - arr[i-1] != d) return 0;
        }
        return 1;
    }
};