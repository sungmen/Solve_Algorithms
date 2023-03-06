class Solution 
{
public:
    long long minimalKSum(vector<int>& nums, int k) 
    {

        set<long long> s(nums.begin(), nums.end());
        long long ans = 0;
        
        long long back = 1;
        for (auto it = s.begin(); k > 0 && it != s.end(); it++)
        {
            int sum = min(k, (int)*it - (int)back);
            ans += ((back + sum) * (back + sum - 1) / 2) - (back * (back - 1) / 2);
            k -= sum;
            back = *it + 1;
        }
        if (k)
        {
            ans += ((back + k) * (back + k - 1) / 2) - (back * (back - 1) / 2);
        }

        return ans;
    }
};
