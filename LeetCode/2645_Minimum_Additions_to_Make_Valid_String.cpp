class Solution {
public:
    int addMinimum(string word) {
        int res = 0;
        int idx = 0;
        while(idx < word.size())
        {
            if (word[idx] == 'a')
            {
                if (idx + 1 < word.size())
                {
                    if (word[idx + 1] == 'b')
                    {
                        if (idx + 2 < word.size() && word[idx + 2] == 'c')
                        {
                            idx++;
                        }
                        else
                            res++;
                        idx++;
                    }
                    else if (word[idx + 1] == 'c')
                    {
                        res++;
                        idx++;
                    }
                    else
                    {
                        res+=2;
                    }
                    idx++;
                }
                else
                {
                    idx++;
                    res+=2;
                }
            }
            else if (word[idx] == 'b')
            {
                if ((idx - 1 >= 0 && word[idx - 1] != 'a') || idx - 1 < 0)
                    res++;
                if ((idx + 1 < word.size() && word[idx + 1] == 'c'))
                {
                    idx++;
                }
                else
                    res++;
                idx++;
            }
            else if (word[idx] == 'c')
            {
                res += 2;
                idx++;
            }
        }
        return res;
    }
};