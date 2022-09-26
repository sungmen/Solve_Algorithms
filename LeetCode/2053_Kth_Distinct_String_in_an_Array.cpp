class Solution 
{
public
    string kthDistinct(vectorstring& arr, int k) 
    {
        unordered_mapstring, int um;
        
        for (auto str  arr)
        {
            um[str] ++;
        }
        
        for (auto str  arr)
        {
            if (1 == um[str])
            {
                if (1 == k)
                {
                    return str;
                }
                else
                {
                    k--;
                }
            }
        }
        
        return ;
    }
};