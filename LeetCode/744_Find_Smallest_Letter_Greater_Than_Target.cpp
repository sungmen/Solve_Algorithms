class Solution 
{
public:
    char nextGreatestLetter(vector<char>& letters, char target) 
    {
        int l = 0, r = letters.size() - 1, res = 0;
        while (l <= r)
        {
            int m = (l + r) / 2;
            if (letters[m] <= target)
            {
                l = m + 1;
            }
            else
            {
                r = m - 1;
                res = m;
            }
        }
        return letters[res];
    }
};
