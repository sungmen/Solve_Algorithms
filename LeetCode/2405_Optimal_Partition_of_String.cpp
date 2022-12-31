class Solution {
public:
    int partitionString(string s) {
        map<int, int> m;
        int res = 1;
        for (auto c : s)
        {
            if (m.find(c) != m.end())
            {
                res++;
                m.clear();
            }
            ++m[c];
        }
        return res;
    }
};