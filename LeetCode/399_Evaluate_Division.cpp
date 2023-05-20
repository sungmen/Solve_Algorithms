class Solution 
{
public:

    double cal(string str, string str2, unordered_map<string, vector<pair<string, double>>> &um, unordered_map<string, int> &visit)
    {
        if (um.find(str) == um.end()) return -1;
        if (str == str2) return 1;
        for (auto it : um[str])
        {
            if (visit.find(it.first) != visit.end()) continue;
            visit[it.first] = 1;
            double ans = cal(it.first, str2, um, visit);
            if (ans == -1) continue;
            return ans * it.second;
        }
        return -1;
    }

    vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) 
    {
        unordered_map<string, vector<pair<string,double>>> um;
        for (int i = 0; i < equations.size(); i++)
        {
            um[equations[i][0]].push_back({equations[i][1], values[i]});
            um[equations[i][1]].push_back({equations[i][0], 1.0/values[i]});
        }
        vector<double> ans;
        for (auto query : queries)
        {
            unordered_map<string, int> visit;
            double cur = cal(query[0], query[1], um, visit);
            ans.push_back(cur);
        }
        return ans;
    }
};