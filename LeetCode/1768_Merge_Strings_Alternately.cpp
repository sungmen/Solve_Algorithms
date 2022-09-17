class Solution 
{
public:
    string mergeAlternately(string word1, string word2) 
    {
        string str = "";
        for (int i = 0; i < min(word1.size(), word2.size()); i++)
        {
            str += word1[i];
            str += word2[i];
        }
        if (word1.size() < word2.size())
        {
            for (int i = word1.size(); i < word2.size(); i++)
            {
                str += word2[i];
            }
        }
        else
        {
            for (int i = word2.size(); i < word1.size(); i++)
            {
                str += word1[i];
            }
        }
        return str;
    }
};