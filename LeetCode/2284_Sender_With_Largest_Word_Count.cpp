class Solution {
public:
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        map<string, int> m;
        for (int i = 0; i < messages.size(); i++)
        {
            int j = 0;
            int cnt = 1;
            while (j < messages[i].size())
            {
                if (messages[i][j] == ' ')
                {
                    cnt++;
                }
                j++;
            }
            m[senders[i]] += cnt;
        }
        string result = "";
        int res = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second >= res)
            {
                res = it->second;
                result = it->first;
            }
        }
        return result;
    }
};