class Solution 
{
public:
    bool digitCount(string num) 
    {
        vector<int> arr(10, 0);
    
        for (auto n : num)
        {
            arr[n - '0']++;
        }
        
        for (int i = 0; i < num.size(); i++)
        {
            if (arr[i] != (num[i] - '0'))
            {
                return false;
            }
        }
        
        return true;
    }
};