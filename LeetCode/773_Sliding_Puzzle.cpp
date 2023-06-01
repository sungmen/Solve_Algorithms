class Solution {
public:
    unordered_map<string, int> um;
    bool check(string& str, int n, int next)
    {
        swap(str[n], str[next]);
        if (um[str]) return false;
        um[str] = 1;
        return true;
    }
    int slidingPuzzle(vector<vector<int>>& board) {
        string b = "";
        string ans = "123450";
        for (auto boar : board)
        {
            for (auto bo : boar)
            {
                b += (bo+'0');
            }
        }
        queue<pair<string, int>> q;
        int c = 0;
        for (int i = 0; i < 6; i++) {
            if (b[i] == '0') {
                c = i;
                break;
            }
        }
        q.push({b, c});
        um[b] = 1;
        int res = 0;
        while (!q.empty())
        {
            int si = q.size();
            while (si--)
            {
                string cur = q.front().first;
                int num = q.front().second;
                q.pop();
                if (cur == ans) return res;
                if (num + 3 < 6){
                    string tmp = cur;
                    if (check(tmp, num, num+3))
                        q.push({tmp, num+3});
                }
                if (num - 3 >= 0)
                {
                    string tmp = cur;
                    if (check(tmp, num, num-3))
                        q.push({tmp, num-3});
                }
                if ((num%3)!=2)
                {
                    string tmp =cur;
                    if (check(tmp, num, num+1))
                        q.push({tmp, num+1});
                }
                if ((num%3)!=0)
                {
                    string tmp = cur;
                    if (check(tmp, num, num-1))
                        q.push({tmp, num-1});
                }
            }
            res++;
        }
        return -1;
    }
};