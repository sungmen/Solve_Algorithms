class Solution 
{
public:
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) 
    {
        map<int, vector<int>> m;
        for (int i = 0; i < spells.size(); i++)
        {
            m[-spells[i]].push_back(i);
        }
        vector<long long> v;
        sort(potions.begin(), potions.end());
        for (int i = 0; i < potions.size(); i++)
        {
            v.push_back(ceil(success / (double)potions[i]));
        }
        v.push_back(INT_MAX);
        vector<int> res(spells.size(), 0);
        int c = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            while (c < v.size() && v[c] > -it->first)
            {
                c++;
            }
            int cur = v.size() - c;
            cur = (cur != 0 ? cur - 1 : 0);
            for (auto i : it->second)
            {
                res[i] = cur;
            }
        }
        return res;
    }
};
