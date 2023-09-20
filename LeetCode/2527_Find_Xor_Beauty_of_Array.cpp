class Solution 
{
public:
    int xorBeauty(vector<int>& nums) 
    {
        int answer = 0;
        for (auto i : nums)
            answer ^= i;
        return answer;
    }
};