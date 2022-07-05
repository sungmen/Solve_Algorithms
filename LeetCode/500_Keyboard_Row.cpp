class Solution 
{
public:
    vector<string> findWords(vector<string>& words) 
    {
        map<char, int> m;
        m['Q'] = 1;m['W'] = 1;m['E'] = 1;m['R'] = 1;m['T'] = 1;m['Y'] = 1;m['U'] = 1;m['I'] = 1;m['O'] = 1;m['P'] = 1;
        m['A'] = 2;m['S'] = 2;m['D'] = 2;m['F'] = 2;m['G'] = 2;m['H'] = 2;m['J'] = 2;m['K'] = 2;m['L'] = 2;
        m['Z'] = 3;m['X'] = 3;m['C'] = 3;m['V'] = 3;m['B'] = 3;m['N'] = 3;m['M'] = 3;
        
        vector<string> ans;
        
        for (auto word : words)
        {
            int b = 0;
            if (word[0] >= 'a' && word[0] <= 'z')
            {
                b = m[word[0] - 32];
            }
            else
            {
                b = m[word[0]];
            }
            bool chk = 1;
            for (int i = 1; i < word.size(); i++)
            {
                int t = 0;
                if (word[i] >= 'a' && word[i] <= 'z')
                {
                    t = m[word[i] - 32];
                }
                else
                {
                    t = m[word[i]];
                }
                if (t != b)
                {
                    chk = 0;
                    break;
                }
            }
            if (chk)
            {
                ans.push_back(word);
            }
        }
        
        return ans;
    }
};