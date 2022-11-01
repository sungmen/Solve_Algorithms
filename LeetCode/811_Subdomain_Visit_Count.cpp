class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> um;
        for (auto cp : cpdomains)
        {
            int num = 0;
            int i = 0;
            while (cp[i] != ' ')
            {
                num *= 10;
                num += (cp[i++] - '0');
            }
            i++;
            um[cp.substr(i)] += num;
            while (i < cp.size())
            {
                if (cp[i] == '.')
                {
                    i++;
                    um[cp.substr(i)] += num;
                }
                i++;
            }
        }
        vector<string> vs;
        for (auto it = um.begin(); it != um.end(); it++)
        {
            string res = "";
            res += to_string(it->second);
            res += ' ';
            res += it->first;
            vs.push_back(res);
        }
        return vs;
    }
};