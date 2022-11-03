class Solution 
{
public:
    int minMutation(string start, string end, vector<string>& bank) 
    {
        vector<bool> chk(bank.size(), 0);
        unordered_map<string, int> um;
        for (auto b : bank)
        {
            um[b] = 1;
        }
        queue<string> q;
        q.push(start);
        int t = 0;
        while(!q.empty())
        {
            int si = q.size();
            while(si--)
            {
                string cur = q.front();
                q.pop();
                if (cur == end)
                {
                    return t;
                }
                for (int i = 0; i < 8; i++)
                {
                    string next = cur;
                    next[i] = 'A';
                    if (um.find(next) != um.end() && um[next] == 1)
                    {
                        um[next] = 2;
                        q.push(next);
                    }
                    next[i] = 'C';
                    if (um.find(next) != um.end() && um[next] == 1)
                    {
                        um[next] = 2;
                        q.push(next);
                    }
                    next[i] = 'G';
                    if (um.find(next) != um.end() && um[next] == 1)
                    {
                        um[next] = 2;
                        q.push(next);
                    }
                    next[i] = 'T';
                    if (um.find(next) != um.end() && um[next] == 1)
                    {
                        um[next] = 2;
                        q.push(next);
                    }
                }
            }
            t++;
        }
        return -1;
    }
};