class Solution {
public:
    bool strongPasswordCheckerII(string password) {
        if (password.size() < 8) return false;
        map<int, int> m;
        m['!'] = 4;m['@'] = 4;m['\''] = 4;m['#'] = 4;m['$'] = 4;m['%'] = 4;m['^']=4;m['&']=4;m['*']=4;m['(']=4;m[')']=4;m['-']=4;m['+']=4;
        for (int i = 0; i < 26; i++)
        {
            m['a'+i] = 1;
            m['A'+i] = 2;
        }
        for (int i = 0; i <= 9; i++)
        {
            m[i + '0'] = 3;
        }
            
        int tmp = 0;
        bool chk[4] = {0,};
        char back = '_';
        for (auto pass : password)
        {
            if (back == pass) return false;
            back = pass;
            if (!chk[m[pass]-1]) 
            {
                chk[m[pass]-1] = 1;
                tmp++;
            }
        }
        if (4 == tmp)
        {
            return true;
        }
        return false;
    }
};