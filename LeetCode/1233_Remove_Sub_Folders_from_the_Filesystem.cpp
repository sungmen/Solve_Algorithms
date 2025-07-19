class Solution 
{
public:
    vector<string> removeSubfolders(vector<string>& folder) 
    {
        sort(folder.begin(), folder.end());
        vector<string> answer;
        string base = folder[0];
        answer.push_back(base);
        for (auto f : folder)
        {
            if (0 != f.compare(0, base.size(), base) || (0 == f.compare(0, base.size(), base) && f.size() > base.size() && f[base.size()] != '/'))
            {
                base = f;
                answer.push_back(base);
            }
        }
        return answer;
    }
};
