class Solution 
{
public:
    string greatestLetter(string s) 
    {
        string ans = "";
        int arr[26];
        int arr_u[26];
        memset(arr, 0, sizeof(arr));
        memset(arr_u, 0, sizeof(arr_u));
        for (auto c : s)
        {
            if (c >= 'a' && c <= 'z')
            {
                arr[c-'a']++;
            }
            else
            {
                arr_u[c-'A']++;
            }
        }
        for (int i = 0; i < 26; i++)
        {
            if (arr[i] && arr_u[i])
            {
                ans = ('A' + i);
            }
        }
        return ans;
    }
};