class Solution 
{
public:
    vector<string> split(string s)
    {
        stringstream ss(s);
        string cur;
        vector<string> v;
        while (getline(ss, cur, ' '))
        {
            v.push_back(cur);
        }
        return v;
    }
    string sortSentence(string s) {
        vector<string> ss = split(s);
        vector<string> str(ss.size());
        for (auto c : ss)
        {
            str[c[c.size()-1]-'0'-1] = c.substr(0, c.size()-1);
        }
        string res = "";
        for (int i = 0; i < str.size(); i++)
        {
            res += str[i];
            if (i != str.size()-1) res += ' ';
        }
        return res;
    }
};