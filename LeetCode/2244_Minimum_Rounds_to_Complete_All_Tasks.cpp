class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> m;
        for (auto task : tasks)
        {
            m[task]++;
        }
        int res = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (1 == it->second)
            {
                return -1;
            }
            if (0 == it->second%3)
            {
                res += it->second / 3;
            }
            else if (1 == it->second % 3)
            {
                res += it->second / 3;
                res--;
                res += 2;
            }
            else if (2 == it->second % 3)
            {
                res += it->second / 3;
                res += 1;
            }
        }
        return res;
    }
};