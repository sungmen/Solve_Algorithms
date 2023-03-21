class Solution {
public:
    string bestHand(vector<int>& ranks, vector<char>& suits) {
        bool chk = 1;
        for (int i = 0; i < 4; i++)
            if (suits[i] != suits[i + 1]) chk = 0;
        if (chk) return "Flush";
        map<int, int> m;
        for (auto rank : ranks)
            m[rank]++;
        vector<int> v;
        for (auto it = m.begin(); it != m.end(); ++it)
        {
            v.push_back(it->second);
        }
        sort(v.begin(), v.end(), greater<int>());
        for (auto i : v)
            if (i >= 3)
                return "Three of a Kind";
            else if (i == 2)
                return "Pair";
        return "High Card";
    }
};