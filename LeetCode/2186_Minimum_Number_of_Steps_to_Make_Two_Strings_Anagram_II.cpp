class Solution {
public:
    int minSteps(string s, string t) {
        map<char, int> m;
        int k = 0;
        for (auto c : s)
        {
            k++;
            m[c]++;
        }
        int res = 0;
        for (auto c : t)
        {
            if (m.find(c) == m.end())
            {
                ++res;
            }
            else
            {
                m[c]--;
                k--;
                if (0 == m[c])
                {
                    m.erase(c);
                }
            }
        }
        return res + k;
    }
};