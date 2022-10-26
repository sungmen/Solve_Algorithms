class Solution {
private:
    vector<bitset<26>> b;
    
public:
    int dfs(bitset<26> t, int res, int cur)
    {
        for (int i = cur + 1; i < b.size(); i++)
        {
            bitset<26> next;
            if ((t & b[i]).count() == 0)
            {
                next = (t | b[i]);
            }
            else
                continue;
            res = max(res, (int)next.count());
            res = max(res, dfs(next, res, i));
        }
        return res;
    }
    
    int maxLength(vector<string>& arr) {
        int res = 0;
        for (auto it : arr)
        {
            bitset<26> tmp;
            bool chk = true;
            for (auto i : it)
            {
                int a = (i - 'a');
                if (tmp[a])
                {
                    chk = false;
                    break;
                }
                tmp[a] = 1;
            }
            if (chk)
            {
                res = max(res, (int)tmp.count());
                b.push_back(tmp);
            }
        }
        for (int i = 0; i < b.size(); i++)
        {
            res = max(res, dfs(b[i], 0, i));
        }
        
        return res;
    }
};