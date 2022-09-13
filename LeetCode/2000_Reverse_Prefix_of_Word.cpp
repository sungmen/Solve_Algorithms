class Solution 
{
public:
    string reversePrefix(string word, char ch) 
    {
        int i = 0;
        
        while (i < word.size() && ch != word[i])
        {
            i++;
        }
        
        if (word.size() == i)
        {
            return word;
        }
        
        string rev = word.substr(0, i+1);
        reverse(rev.begin(), rev.end());
        
        return rev + word.substr(i+1);
    }
};