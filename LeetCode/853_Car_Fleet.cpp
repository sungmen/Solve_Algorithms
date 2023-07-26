class Solution 
{
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) 
    {
        vector<pair<int, int>> v;
        for (int i = 0; i < position.size(); i++)
        {
            v.push_back({position[i], speed[i]});
        }
        sort(v.begin(), v.end());
        stack<double> stk;
        for (auto i : v)
        {
            double cur = ((target-i.first) / (double)i.second);
            while (!stk.empty() && cur >= stk.top()) stk.pop();
            stk.push(cur);
        }
        return stk.size();
    }
};