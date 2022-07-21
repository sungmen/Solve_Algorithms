class Solution {
public:
    string maxValue(string n, int x) {
        string ans = "";
        char xchr = x + '0';
        int i;
        if (n[0] == '-')
        {
            for (i = 1; i < n.size(); i++)
            {
                if (n[i] > xchr)
                {
                    break;
                }
            }
        }
        else
        {
            for (i = 0; i < n.size(); i++)
            {
                if (n[i] < xchr)
                {
                    break;
                }
            }
        }
        ans = n.substr(0, i) + xchr + n.substr(i);
        return ans;
    }
};