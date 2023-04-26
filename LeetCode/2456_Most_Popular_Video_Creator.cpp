class Solution 
{
public:
    vector<vector<string>> mostPopularCreator(vector<string>& creators, vector<string>& ids, vector<int>& views) 
    {
        unordered_map<string, long long> um;
        unordered_map<string, int> umi;
        unordered_map<string, vector<string>> ums;
        int n = creators.size();
        for (int i = 0; i < n; i++)
        {
            string creator = creators[i];
            string id = ids[i];
            int view = views[i];
            um[creator] += view;
            if (umi.find(creator) == umi.end() || (umi.find(creator) != umi.end() && umi[creator] < view))
            {
                umi[creator] = view;
                ums[creator].clear();
                ums[creator].push_back(id);
            }
            else if (umi[creator] == view)
            {
                ums[creator].push_back(id);
            }
        }
        vector<string> v;
        int t = 0;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            if (it->second > t)
            {
                t = it->second;
                v.clear();
                v.push_back(it->first);
            }else if (it->second == t)
            {
                v.push_back(it->first);
            }
        }
        vector<vector<string>> ans;
        for (auto i : v)
        {
            vector<string> vecs = ums[i];
            sort(vecs.begin(), vecs.end());
            ans.push_back({i, vecs[0]});
        }
        return ans;
    }
};