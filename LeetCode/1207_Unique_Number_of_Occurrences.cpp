class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> m;
        for (auto a : arr)
        {
            m[a] ++;
        }
        set<int> s;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (s.find(it->second) != s.end())
                return false;
            s.insert(it->second);
        }
        return true;
    }
};