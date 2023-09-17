class Solution 
{
public:

    int totalHammingDistance(vector<int>& nums) 
    {
        int answer = 0;
        int n = nums.size();
        
        for (int i = 0; i < 30; i++)
        {
            int a = 0;
            for (auto n : nums)
            {
                int c = (n >> i) & 1;
                if (c) a++;
            }
            answer += a * (n - a);
        }

        return answer;
    }
};