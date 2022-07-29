class Solution 
{
public:
    vector<string> removeAnagrams(vector<string>& words) 
    {
        vector<string> ans;
        ans.push_back(words[0]);
        sort(words[0].begin(), words[0].end());
        for (int i = 1; i < words.size(); i++)
        {
            string tmp = words[i];
            sort(words[i].begin(), words[i].end());
            if (words[i-1] != words[i])
            {
                ans.push_back(tmp);
            }
        }
        
        return ans;
    }
};