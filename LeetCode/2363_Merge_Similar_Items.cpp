class Solution 
{
public:
    vector<vector<int>> mergeSimilarItems(vector<vector<int>>& items1, vector<vector<int>>& items2) 
    {
        map<int, int> m;
        for (auto item : items1)
        {
            m[item[0]] += item[1];
        }
        for (auto item : items2)
        {
            m[item[0]] += item[1];
        }
        vector<vector<int>> v;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            v.push_back({it->first, it->second});
        }        
        return v;
    }
};