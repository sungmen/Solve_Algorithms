class Solution 
{
public:
    vector<int> smallestSufficientTeam(vector<string>& req_skills, vector<vector<string>>& people) 
    {
        unordered_map<string, int> um;
        int r = 0;
        for (int i = 0; i < req_skills.size(); i++)
        {
            um[req_skills[i]] = i;
            r += (1<<i);
        }
        int rVal = (1 << req_skills.size()) - 1;
        map<int, vector<int>> req;
        for (int i = 0; i < people.size(); i++)
        {
            int p = 0;
            for (auto c : people[i])
            {
                p += (1<<um[c]);
            }
            map<int, vector<int>> tmp = req;
            for (auto it = tmp.begin(); it != tmp.end(); it++)
            {
                int f = it->first;
                vector<int> tp = it->second;
                int nextVal = p | f;
                if (req.find(nextVal) == req.end())
                {
                    tp.push_back(i);
                    req[nextVal] = tp;
                }
                else
                {
                    if (tp.size() + 1 < req[nextVal].size())
                    {
                        tp.push_back(i);
                        req[nextVal] = tp;
                    }
                }
            }
            req[p] = {i};
        }
        return req[(1<<req_skills.size())-1];
    }
};