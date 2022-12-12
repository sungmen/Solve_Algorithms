class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        map<int, string> m;
        for (int i = 0; i < names.size(); i++)
        {
            m[-heights[i]] = names[i];
        }
        vector<string> v;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            v.push_back(it->second);
        }
        return v;
    }
};