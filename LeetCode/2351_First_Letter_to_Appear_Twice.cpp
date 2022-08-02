class Solution 
{
public:
    char repeatedCharacter(string s) 
    {
        char arr[26];
        memset(arr, 0, sizeof(arr));
        for (auto c : s)
        {
            arr[c-'a']++;
            if (arr[c-'a'] == 2)
            {
                return c;
            }
        }
        return 'a';
    }
};