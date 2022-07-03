class Solution 
{
public:
    long long countVowels(string word) 
    {
        long long ans = 0;
        long long m = word.size();
        for (long long i = 0; i < m ; i++)
        {
            char w = word[i];
            if (w == 'a' || w == 'e' || w == 'i' || w == 'o' || w == 'u')
            {
                ans += (i + 1) * (m - i);
            }
        }
        
        return ans;
    }
};