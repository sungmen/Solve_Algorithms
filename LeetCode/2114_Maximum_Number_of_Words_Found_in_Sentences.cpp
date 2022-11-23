class Solution 
{
public:
    int mostWordsFound(vector<string>& sentences) 
    {
        int result = 0;
        for (string str : sentences) {
            int space = 0;
            int i = 0;
            while (i < str.size())
            {
                if (' ' == str[i])
                {
                    space++;
                }
                ++i;
            }
            result = max(result, space);
        }
        return result + 1;
    }
};