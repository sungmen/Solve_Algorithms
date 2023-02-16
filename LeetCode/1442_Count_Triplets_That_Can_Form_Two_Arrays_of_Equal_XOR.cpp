class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        map <int, vector<int>> m;
        int t = 0;
        m[0].push_back(0);
        for (int i = 0; i < n; i++)
        {
            t = t ^ arr[i];
            m[t].push_back(i + 1);
        }
        int res = 0;
        for (auto it = m.begin(); it != m.end(); it++)
        {
            if (it->second.size() == 1) continue;
            vector<int> tmp = it->second;
            for (int i = 0; i < tmp.size() - 1; i++)
            {
                for (int j = i + 1; j < tmp.size(); j++)
                {
                    if (tmp[j] - tmp[i] > 1)
                        res += tmp[j] - tmp[i] - 1;
                }
            }
        }
        return res;
    }
};