class Solution {
public:
    void minu(map<int, int> & m, int idx)
    {
        m[idx]--;
        if (m[idx] == 0)
            m.erase(idx);
    }
    bool sol(string & str, map<int, int> & m, int idx)
    {
        for (; idx >= 0; idx--)
        {
            if (m.find(idx) != m.end())
            {
                str += (idx + '0');
                minu(m, idx);
                return 1;
            }
        }
        return 0;
    }
    string largestTimeFromDigits(vector<int>& arr) {
        string str = "";
        map<int, int> backup;
        for (auto it : arr)
            backup[it]++;
        vector<int> back(4, 0);
        back[0] = 2, back[1] = 9, back[2] = 5, back[3] = 9;
        while (1)
        {
            str = "";
            map<int, int> m = backup;
            if (back[0] < 0 || !sol(str, m, back[0]))
                return "";
            if (back[1] < 0 || !sol(str, m, (str == "2" ? min(3, back[1]) : back[1])))
            {
                back[0]--;
                back[1] = 9;
                back[2] = 5;
                continue;
            }
            str += ':';
            if (back[2] < 0 ||!sol(str, m, 5))
            {
                back[1]--;
                back[2] = 5;
                continue;
            }
            if (back[3] < 0 || !sol(str, m, 9))
            {
                back[2]--;
                continue;
            }
            else
            {
                break;
            }
        }
        return str;
    }
};