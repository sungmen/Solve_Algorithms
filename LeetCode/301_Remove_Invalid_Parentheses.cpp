class Solution 
{
public:
    struct th
    {
        int l = 0;
        int r = 0;
        string str = "";
    };
    vector<string> removeInvalidParentheses(string s) 
    {
        queue<th> q;
        q.push({0, 0, ""});
        for (auto c : s)
        {
            queue<th> next;
            while (! q.empty())
            {
                th cur = q.front();
                q.pop();
                if (c == '(')
                {
                    next.push({cur.l + 1, cur.r, cur.str + c});
                }
                else if (c == ')')
                {
                    if (cur.l >= cur.r + 1)
                        next.push({cur.l, cur.r + 1, cur.str + c});
                }
                if (c != '(' && c != ')')
                    next.push({cur.l, cur.r, cur.str + c});
                else
                    next.push(cur);
            }
            q = next;
        }
        vector<string> ans;
        int lans = 0;
        int strlen = 0;
        while (!q.empty())
        {
            th cur = q.front();
            q.pop();
            if (cur.l != cur.r) continue;
            if (lans <= cur.l)
            {
                if (lans < cur.l || (lans == cur.l && strlen < cur.str.size())) ans.clear();
                lans = cur.l;
                strlen = cur.str.size();
                ans.push_back(cur.str);
            }
        }
        sort(ans.begin(), ans.end());
        ans.erase(unique(ans.begin(), ans.end()), ans.end());
        return ans;
    }
};