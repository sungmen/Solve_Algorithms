class Solution {
public:
    int countPoints(string rings) {
        map<char, map<char, int>> m;
        int i = 0;
        while (i < rings.size())
        {
            m[rings[i + 1]][rings[i]] = 1;
            i += 2;
        }
        int res = 0;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            cout << it->second.size() << '\n';
            res += (it->second.size() == 3 ? 1 : 0);
        }
        return res;
    }
};