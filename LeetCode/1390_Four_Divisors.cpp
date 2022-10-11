class Solution 
{
public:
    int sumFourDivisors(vector<int>& nums) 
    {
        pair<int, int> arr[100001];
        int result = 0;
        for (int i = 1; i <= 100000; i++)
        {
            for (int j = i; j <= 100000; j += i)
            {
                arr[j].first++;
                arr[j].second += i;
            }
        }
        for (auto num : nums)
        {
            if (arr[num].first == 4)
            {
                result += arr[num].second;
            }
        }
        return result;
    }
};