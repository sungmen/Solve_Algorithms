class Solution 
{
public:
    string longestWord(vector<string>& words) 
    {
        unordered_map<string, int> um;
        sort(begin(words), end(words));
        string res = "";
        for (auto w : words)
        {
            if (w.size() != 1 && um.find(w.substr(0, w.size() - 1)) == um.end()) continue;
            res = (res.size() < w.size()) ? w : res;
            um[w] = 1;
        }
        return res;
    }
};