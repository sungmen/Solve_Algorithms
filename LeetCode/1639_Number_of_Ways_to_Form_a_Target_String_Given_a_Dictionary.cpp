class Solution {
public:
    int numWays(vector<string>& words, string target) {
        int MOD = 1e9 + 7;
        vector<vector<long long>> v(target.size(), vector<long long>(words[0].size(), 0));
        map<char, map<long long, long long>> m;
        for (int i = 0; i < words.size(); i++)
        {
            for (int j = 0; j < words[i].size(); j++)
            {
                m[words[i][j]][j]++;
            }
        }
        v[0][0] = m[target[0]][0];
        for (int i = 1; i < words[0].size(); i++)
            v[0][i] = (m[target[0]][i] + v[0][i-1]) % MOD;
        for (int i = 1; i < target.size(); i++)
        {
            for (int j = i; j < words[0].size(); j++)
            {
                v[i][j] = (v[i][j - 1] + ((v[i-1][j-1] * m[target[i]][j]) % MOD) % MOD);
            }
        }


        return v[target.size() - 1][words[0].size()-1] % MOD;
    }
};