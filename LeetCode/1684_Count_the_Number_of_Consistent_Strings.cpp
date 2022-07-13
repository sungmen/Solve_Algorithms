class Solution {
public:
    int countConsistentStrings(string allowed, vector<string>& words) {
        map<char, int> m;
        for (auto allow : allowed)
        {
            m[allow] ++;
        }
        int ans = 0;
        for (auto word : words)
        {
            bool chk = 1;
            for (auto w : word)
            {
                if (0 == m[w])
                {
                    chk = 0;
                    break;
                }
            }
            if (chk)
            {
                ans ++;
            }
        }
        return ans;
    }
};